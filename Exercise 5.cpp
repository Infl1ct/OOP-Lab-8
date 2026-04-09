#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    Person(string n, int a) : name(n), age(a) {
        if (a < 0) {
            throw invalid_argument("Age cannot be negative.");
        }
        cout << "Person constructor called." << endl;
    }

    virtual ~Person() {
        cout << "Person destructor called." << endl;
    }

    virtual void display() const {
        cout << "Name: " << name << ", Age: " << age << endl;
    }

    virtual string getRole() const {
        return "Person";
    }
};

class Student : virtual public Person {
public:
    Student(string n, int a) : Person(n, a) {
        cout << "Student constructor called." << endl;
    }

    ~Student() override {
        cout << "Student destructor called." << endl;
    }

    void display() const override {
        cout << "Student - Name: " << name << ", Age: " << age << endl;
    }

    string getRole() const override {
        return "Student";
    }
};

class Employee : virtual public Person {
public:
    Employee(string n, int a) : Person(n, a) {
        cout << "Employee constructor called." << endl;
    }

    ~Employee() override {
        cout << "Employee destructor called." << endl;
    }

    void display() const override {
        cout << "Employee - Name: " << name << ", Age: " << age << endl;
    }

    string getRole() const override {
        return "Employee";
    }
};

class TeachingAssistant : public Student, public Employee {
public:
    TeachingAssistant(string n, int a) : Person(n, a), Student(n, a), Employee(n, a) {
        cout << "TeachingAssistant constructor called." << endl;
    }

    ~TeachingAssistant() override {
        cout << "TeachingAssistant destructor called." << endl;
    }

    void display() const override {
        cout << "Teaching Assistant - Name: " << name << ", Age: " << age << endl;
    }

    string getRole() const override {
        return "TeachingAssistant";
    }
};

void testDiamondProblem() {
    cout << "Testing Valid Instantiation:" << endl;
    try {
        TeachingAssistant ta("John Doe", 22);
        
        cout << "Demonstrating Polymorphism:" << endl;
        Person* p = &ta;
        p->display();
        cout << "Role: " << p->getRole() << endl;
    } 
    catch (const exception& e) {
        cout << "Exception caught: " << e.what() << endl;
    }

    cout << "Testing Negative Age Exception:" << endl;
    try {
        TeachingAssistant ta_invalid("Jane Doe", -5);
    } 
    catch (const exception& e) {
        cout << "Exception caught: " << e.what() << endl;
    }
    cout << endl;
}

int main() {
    testDiamondProblem();
    return 0;
}