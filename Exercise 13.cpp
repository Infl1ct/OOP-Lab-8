#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>

using namespace std;

template <typename T>
class Stack {
private:
    vector<T> elements;

public:
    void push(T const& value) {
        elements.push_back(value);
    }

    void pop() {
        if (elements.empty()) {
            throw out_of_range("Stack<>::pop(): empty stack");
        }
        elements.pop_back();
    }

    T top() const {
        if (elements.empty()) {
            throw out_of_range("Stack<>::top(): empty stack");
        }
        return elements.back();
    }

    bool empty() const {
        return elements.empty();
    }
};

int main() {
    try {
        Stack<int> intStack;
        intStack.push(10);
        intStack.push(20);
        cout << "Top element (int): " << intStack.top() << endl;
        intStack.pop();
        cout << "Top element after pop (int): " << intStack.top() << endl;

        Stack<string> stringStack;
        stringStack.push("Hello");
        stringStack.push("World");
        cout << "Top element (string): " << stringStack.top() << endl;

        intStack.pop(); 
        intStack.pop(); 
    } 
    catch (const exception& e) {
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}