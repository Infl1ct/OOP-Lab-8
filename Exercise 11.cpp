#include <iostream>
#include <string>

using namespace std;

template <typename T>
int element_frequency(T arr[], int size, T search_value) {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] == search_value) {
            count++;
        }
    }
    return count;
}

int main() {
    int int_arr[] = {1, 5, 2, 5, 3, 5, 4};
    int int_size = sizeof(int_arr) / sizeof(int_arr[0]);
    cout << element_frequency(int_arr, int_size, 5) << endl;

    double double_arr[] = {1.1, 2.2, 3.3, 2.2, 4.4};
    int double_size = sizeof(double_arr) / sizeof(double_arr[0]);
    cout << element_frequency(double_arr, double_size, 2.2) << endl;

    string str_arr[] = {"alpha", "beta", "gamma", "alpha", "delta"};
    int str_size = sizeof(str_arr) / sizeof(str_arr[0]);
    cout << element_frequency(str_arr, str_size, string("alpha")) << endl;

    return 0;
}