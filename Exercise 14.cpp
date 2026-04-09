#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

template <typename T>
class Queue {
private:
    T* arr;
    int frontIndex;
    int rearIndex;
    int capacity;

public:
    Queue(int size = 100) {
        arr = new T[size];
        capacity = size;
        frontIndex = 0;
        rearIndex = -1;
    }

    ~Queue() {
        delete[] arr;
    }

    void enqueue(T const& value) {
        if (rearIndex == capacity - 1) {
            cout << "Queue overflow! Cannot enqueue.\n";
            return;
        }
        arr[++rearIndex] = value;
    }

    void dequeue() {
        if (frontIndex > rearIndex) {
            cout << "Queue underflow! Cannot dequeue.\n";
            return;
        }
        frontIndex++;
    }

    T front() const {
        if (frontIndex > rearIndex) {
            throw out_of_range("Queue is empty!"); 
        }
        return arr[frontIndex];
    }

    bool empty() const {
        return frontIndex > rearIndex;
    }
};

int main() {
    try {
        Queue<int> intQueue(5); 
        
        intQueue.enqueue(10);
        intQueue.enqueue(20);
        
        cout << "Front element (int): " << intQueue.front() << "\n";
        
        intQueue.dequeue();
        cout << "Front element after dequeue (int): " << intQueue.front() << "\n\n";

        Queue<string> stringQueue(5);
        stringQueue.enqueue("Hello");
        stringQueue.enqueue("World");
        
        cout << "Front element (string): " << stringQueue.front() << "\n";

        intQueue.dequeue(); 
        intQueue.front(); 
        
    } 
    catch (const exception& e) {
        cout << "Exception caught: " << e.what() << "\n";
    }

    return 0;
}