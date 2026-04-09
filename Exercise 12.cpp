#include <iostream>

using namespace std;

template <typename T>
void sort_array(T arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

template <typename T>
void reverse_array(T arr[], int size) {
    int left = 0;
    int right = size - 1;
    while (left < right) {
        T temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        left++;
        right--;
    }
}

template <typename T>
int binary_search(T arr[], int size, T target) {
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

template <typename T>
void print_array(T arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(arr) / sizeof(arr[0]);

    sort_array(arr, size);
    print_array(arr, size);

    reverse_array(arr, size);
    print_array(arr, size);

    sort_array(arr, size);
    
    int index = binary_search(arr, size, 25);
    cout << index << endl;

    index = binary_search(arr, size, 100);
    cout << index << endl;

    double d_arr[] = {3.14, 1.59, 2.65, 5.89, 9.79};
    int d_size = sizeof(d_arr) / sizeof(d_arr[0]);

    sort_array(d_arr, d_size);
    print_array(d_arr, d_size);

    int d_index = binary_search(d_arr, d_size, 3.14);
    cout << d_index << endl;

    return 0;
}