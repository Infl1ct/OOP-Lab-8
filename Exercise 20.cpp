#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

class MemoryPool {
private:
    char* pool;
    char* next;
    size_t totalSize;

public:
    MemoryPool(size_t size) : totalSize(size) {
        pool = new char[totalSize];
        next = pool;
    }

    ~MemoryPool() {
        delete[] pool;
    }

    void* allocate(size_t size) {
        if (next + size > pool + totalSize) {
            return nullptr; 
        }
        void* mem = next;
        next += size;
        return mem;
    }

    void reset() {
        next = pool;
    }
};

struct Packet {
    int id;
    double data[10];
};

int main() {
    const int numAllocations = 1000000;
    
    auto startNew = high_resolution_clock::now();
    for (int i = 0; i < numAllocations; ++i) {
        Packet* p = new Packet();
        delete p;
    }
    auto endNew = high_resolution_clock::now();
    auto durationNew = duration_cast<milliseconds>(endNew - startNew);

    MemoryPool myPool(numAllocations * sizeof(Packet));
    
    auto startPool = high_resolution_clock::now();
    for (int i = 0; i < numAllocations; ++i) {
        Packet* p = (Packet*)myPool.allocate(sizeof(Packet));
    }
    auto endPool = high_resolution_clock::now();
    auto durationPool = duration_cast<milliseconds>(endPool - startPool);

    cout << "Standard New/Delete Time: " << durationNew.count() << "ms" << endl;
    cout << "Memory Pool Allocator Time: " << durationPool.count() << "ms" << endl;
    cout << "Performance Increase: " << (double)durationNew.count() / durationPool.count() << "x faster" << endl;

    return 0;
}