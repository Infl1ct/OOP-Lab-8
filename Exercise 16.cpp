#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

template <typename T>
class SparseMatrix {
private:
    int rows;
    int cols;

    struct Element {
        int row;
        int col;
        T value;
    };

    vector<Element> data;

public:
    SparseMatrix(int r, int c) : rows(r), cols(c) {
        if (r <= 0 || c <= 0) {
            throw invalid_argument("Dimensions must be strictly positive.");
        }
    }

    void insert(int r, int c, T val) {
        if (r < 0 || r >= rows || c < 0 || c >= cols) {
            throw out_of_range("Matrix index out of bounds.");
        }
        
        for (auto& el : data) {
            if (el.row == r && el.col == c) {
                el.value = val;
                return;
            }
        }
        
        if (val != T()) {
            data.push_back({r, c, val});
        }
    }

    T get(int r, int c) const {
        if (r < 0 || r >= rows || c < 0 || c >= cols) {
            throw out_of_range("Matrix index out of bounds.");
        }
        
        for (const auto& el : data) {
            if (el.row == r && el.col == c) {
                return el.value;
            }
        }
        return T();
    }

    SparseMatrix<T> operator+(const SparseMatrix<T>& other) const {
        if (rows != other.rows || cols != other.cols) {
            throw invalid_argument("Dimensions mismatch for addition.");
        }
        
        SparseMatrix<T> result(rows, cols);
        
        for (const auto& el : data) {
            result.insert(el.row, el.col, el.value);
        }
        
        for (const auto& el : other.data) {
            T currentVal = result.get(el.row, el.col);
            result.insert(el.row, el.col, currentVal + el.value);
        }
        
        return result;
    }

    SparseMatrix<T> operator-(const SparseMatrix<T>& other) const {
        if (rows != other.rows || cols != other.cols) {
            throw invalid_argument("Dimensions mismatch for subtraction.");
        }
        
        SparseMatrix<T> result(rows, cols);
        
        for (const auto& el : data) {
            result.insert(el.row, el.col, el.value);
        }
        
        for (const auto& el : other.data) {
            T currentVal = result.get(el.row, el.col);
            result.insert(el.row, el.col, currentVal - el.value);
        }
        
        return result;
    }

    SparseMatrix<T> operator*(const SparseMatrix<T>& other) const {
        if (cols != other.rows) {
            throw invalid_argument("Dimensions mismatch for multiplication.");
        }
        
        SparseMatrix<T> result(rows, other.cols);
        
        for (const auto& el1 : data) {
            for (const auto& el2 : other.data) {
                if (el1.col == el2.row) {
                    T currentVal = result.get(el1.row, el2.col);
                    result.insert(el1.row, el2.col, currentVal + (el1.value * el2.value));
                }
            }
        }
        
        return result;
    }

    void display() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << get(i, j) << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    try {
        SparseMatrix<int> A(3, 3);
        A.insert(0, 0, 1);
        A.insert(0, 2, 2);
        A.insert(1, 1, 3);
        A.insert(2, 0, 4);

        SparseMatrix<int> B(3, 3);
        B.insert(0, 0, 5);
        B.insert(1, 1, 6);
        B.insert(2, 2, 7);

        cout << "Matrix A:\n";
        A.display();
        
        cout << "\nMatrix B:\n";
        B.display();

        cout << "\nA + B:\n";
        SparseMatrix<int> C = A + B;
        C.display();

        cout << "\nA - B:\n";
        SparseMatrix<int> D = A - B;
        D.display();

        cout << "\nA * B:\n";
        SparseMatrix<int> E = A * B;
        E.display();
        
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}