#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

class Matrix {
private:
    int rows;
    int cols;
    vector<double> data; 

public:
    Matrix(int r, int c) : rows(r), cols(c) {
        if (r <= 0 || c <= 0) {
            throw invalid_argument("Error: Invalid matrix dimensions.");
        }
        data.resize(r * c, 0.0);
    }

    double& operator()(int r, int c) {
        if (r < 0 || r >= rows || c < 0 || c >= cols) {
            throw out_of_range("Error: Out-of-bounds access.");
        }
        return data[r * cols + c];
    }

    const double& operator()(int r, int c) const {
        if (r < 0 || r >= rows || c < 0 || c >= cols) {
            throw out_of_range("Error: Out-of-bounds access.");
        }
        return data[r * cols + c];
    }

    Matrix operator+(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            throw invalid_argument("Error: Incompatible dimensions for addition.");
        }
        Matrix result(rows, cols);
        for (int i = 0; i < rows * cols; ++i) {
            result.data[i] = data[i] + other.data[i];
        }
        return result;
    }
};

int main() {
    try {
        Matrix m1(2, 2);
        Matrix m2(2, 2);
        
        m1(0, 0) = 1; m1(0, 1) = 2;
        m1(1, 0) = 3; m1(1, 1) = 4;
        
        m2(0, 0) = 5; m2(0, 1) = 6;
        m2(1, 0) = 7; m2(1, 1) = 8;
        
        Matrix m3 = m1 + m2;
        
        cout << "Matrix Addition Result:" << endl;
        cout << m3(0, 0) << " " << m3(0, 1) << endl;
        cout << m3(1, 0) << " " << m3(1, 1) << endl;

        cout << "Testing exceptions:" << endl;
        Matrix m4(-1, 5); 
    } 
    catch (const exception& e){
        cout << e.what() << endl;
    }

    try {
        Matrix m1(2, 2);
        cout << m1(5, 5); 
    } 
    catch (const exception& e){
        cout << e.what() << endl;
    }

    try {
        Matrix m1(2, 2);
        Matrix m2(3, 3);
        Matrix m3 = m1 + m2; 
    } 
    catch (const exception& e){
        cout << e.what() << endl;
    }

    return 0;
}