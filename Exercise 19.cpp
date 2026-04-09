#include <iostream>
#include <string>

using namespace std;

class Singleton {
private:
    string data;

    Singleton() {
        data = "Initial Singleton Data";
        cout << "Singleton Instance Created." << endl;
    }

public:
    Singleton(const Singleton&) = delete;
    void operator=(const Singleton&) = delete;

    static Singleton& getInstance() {
        static Singleton instance;
        return instance;
    }

    void setData(string newValue) {
        data = newValue;
    }

    string getData() const {
        return data;
    }
};

int main() {
    cout << "Accessing Singleton for the first time" << endl;
    Singleton& s1 = Singleton::getInstance();
    cout << "Current Data: " << s1.getData() << endl;

    cout << "\nUpdating Data through s1" << endl;
    s1.setData("Updated by Thread/Process A");

    cout << "\nAccessing Singleton through s2" << endl;
    Singleton& s2 = Singleton::getInstance();
    cout << "Data in s2: " << s2.getData() << endl;

    if (&s1 == &s2) {
        cout << "\nValidation: s1 and s2 share the same memory address: " << &s1 << endl;
    }

    return 0;
}