#include <iostream>
#include <string>

using namespace std;

template <typename T>
T max_value(T a, T b, T c) {
    T max_val = a;
    
    if (b > max_val) {
        max_val = b;
    }
    if (c > max_val) {
        max_val = c;
    }
    
    return max_val;
}

int main() {
    cout << max_value(10, 25, 15) << endl;
    
    cout << max_value(3.14, 2.71, 9.81) << endl;
    
    cout << max_value('a', 'x', 'm') << endl;
    
    string str1 = "apple";
    string str2 = "zebra";
    string str3 = "mango";
    cout << max_value(str1, str2, str3) << endl;

    return 0;
}