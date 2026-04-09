#include <iostream>
#include <exception>
#include <limits>

using namespace std; 

class DivisionByZeroException : public exception{
public:
    const char* what() const noexcept override {
        return "Error: Division by zero is not allowed!";
    }
};

double divide(double numerator, double denominator){
    if (denominator == 0.0) {
        throw DivisionByZeroException();
    }
    
    if (denominator < 0.0) {
        cout << "Negative denominator detected. Converting to positive." << endl;
        denominator = -denominator;
    }
    
    return numerator / denominator;
}

int main(){
    double num, den;
    char choice;

    do {
        cout << "Enter numerator and denominator: ";
        
        if (!(cin >> num >> den)) {
            cout << "Invalid input. Please enter numeric values only." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        try {
            double result = divide(num, den);
            cout << "Result: " << result << "" << endl;
        } 
        catch (const DivisionByZeroException& e) {
            cerr << e.what() << "" << endl;
        }

        cout << "Do another operation? (y/n): ";
        
        if (!(cin >> choice)) {
            break; 
        }
        
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    } while(choice == 'y' || choice == 'Y');

    cout << "Program terminated." << endl;
    return 0;
}