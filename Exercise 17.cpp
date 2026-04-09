#include <iostream>
#include <vector>

using namespace std;

template <typename T, typename BinaryOperation>
vector<vector<T>> matrix_operation(
    const vector<vector<T>>& m1,
    const vector<vector<T>>& m2,
    size_t rows, size_t cols,
    BinaryOperation op) {
    
    vector<vector<T>> result(rows, vector<T>(cols));
    
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            result[i][j] = op(m1[i][j], m2[i][j]);
        }
    }
    
    return result;
}

int main() {
    size_t rows = 2;
    size_t cols = 3;

    vector<vector<int>> m1 = {
        {1, 2, 3},
        {4, 5, 6}
    };

    vector<vector<int>> m2 = {
        {7, 8, 9},
        {10, 11, 12}
    };

    auto add = [](const auto& a, const auto& b) { 
        return a + b; 
    };

    vector<vector<int>> result_add = matrix_operation<int>(m1, m2, rows, cols, add);

    cout << "Addition Result:\n";
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            cout << result_add[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << "\nMultiplication Result (Extra Demo):\n";
    auto multiply = [](const auto& a, const auto& b) { 
        return a * b; 
    };
    
    vector<vector<int>> result_mult = matrix_operation<int>(m1, m2, rows, cols, multiply);

    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            cout << result_mult[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}