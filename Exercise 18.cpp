#include <iostream>
#include <queue>
#include <vector>
#include <stdexcept>

using namespace std;

template <typename T, typename PriorityFunc = std::less<T>>
class PriorityQueue {
public:
    void insert(const T& element) {
        pq.push(element);
    }

    T getHighestPriority() {
        if (pq.empty()) {
            throw out_of_range("Priority queue is empty.");
        }
        T val = pq.top();
        pq.pop();
        return val;
    }

private:
    priority_queue<T, vector<T>, PriorityFunc> pq;
};

struct CustomCompare {
    bool operator()(const int& a, const int& b) const {
        return a > b;
    }
};

int main() {
    PriorityQueue<int> maxPQ;
    
    maxPQ.insert(42);
    maxPQ.insert(10);
    maxPQ.insert(99);
    
    cout << "Default (Max-Heap) Priority Queue:" << endl;
    cout << maxPQ.getHighestPriority() << endl;
    cout << maxPQ.getHighestPriority() << endl;
    cout << maxPQ.getHighestPriority() << endl;

    PriorityQueue<int, CustomCompare> minPQ;
    
    minPQ.insert(42);
    minPQ.insert(10);
    minPQ.insert(99);
    
    cout << "Custom (Min-Heap) Priority Queue:" << endl;
    cout << minPQ.getHighestPriority() << endl;
    cout << minPQ.getHighestPriority() << endl;
    cout << minPQ.getHighestPriority() << endl;

    return 0;
}