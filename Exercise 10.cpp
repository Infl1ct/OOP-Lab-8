#include <iostream>
#include <string>

using namespace std;

template <typename T>
void swap_values(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 10, y = 20;
    cout << "Before swap: " << x << " " << y << endl;
    swap_values(x, y);
    cout << "After swap: " << x << " " << y << endl;

    double d1 = 3.14, d2 = 9.81;
    cout << "Before swap: " << d1 << " " << d2 << endl;
    swap_values(d1, d2);
    cout << "After swap: " << d1 << " " << d2 << endl;

    string s1 = "apple", s2 = "banana";
    cout << "Before swap: " << s1 << " " << s2 << endl;
    swap_values(s1, s2);
    cout << "After swap: " << s1 << " " << s2 << endl;

    return 0;
}