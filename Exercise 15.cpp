#include <iostream>
#include <string>

using namespace std;

template <typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(T val) : data(val), next(nullptr) {}
    };
    
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    void insert(T value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void deleteNode(T value) {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        while (current->next != nullptr && current->next->data != value) {
            current = current->next;
        }

        if (current->next != nullptr) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        } else {
            cout << "Value " << value << " not found in the list.\n";
        }
    }

    void traverse() const {
        Node* temp = head;
        if (temp == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    LinkedList<int> intList;
    
    intList.insert(10);
    intList.insert(20);
    intList.insert(30);
    intList.insert(40);
    
    cout << "Integer List: ";
    intList.traverse();
    
    intList.deleteNode(20);
    cout << "After deleting 20: ";
    intList.traverse();

    intList.deleteNode(100); 
    
    cout << endl;

    LinkedList<string> stringList;
    
    stringList.insert("Alice");
    stringList.insert("Bob");
    stringList.insert("Charlie");
    
    cout << "String List: ";
    stringList.traverse();
    
    stringList.deleteNode("Alice");
    cout << "After deleting Alice: ";
    stringList.traverse();

    return 0;
}