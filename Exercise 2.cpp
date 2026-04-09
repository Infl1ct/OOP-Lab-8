#include <iostream>

using namespace std;

class Account {
public:
    virtual ~Account() {}
    virtual double calculateInterest() = 0;
};

class SavingsAccount: public Account{
private:
    double balance, rate, time;

public:
    SavingsAccount(double b, double r, double t){
        balance = b;
        rate = r;
        time = t;
    }

    double calculateInterest() override{
        return balance * rate * (time / 12.0);
    }
};

class CheckingAccount: public Account{
private:
    double balance, fee, rate, time;

public:
    CheckingAccount(double b, double f, double r, double t){
        balance = b;
        fee = f;
        rate = r;
        time = t;
    }

    double calculateInterest() override{
        return (balance - fee) * rate * (time / 12.0);
    }
};

int main() {
    SavingsAccount s(5000.0, 0.03, 6);
    CheckingAccount c(3000.0, 10.0, 0.015, 6);

    Account* accounts[2];
    accounts[0] = &s;
    accounts[1] = &c;

    for (int i = 0; i < 2; i++){
        std::cout << "Interest: $" << accounts[i]->calculateInterest() << std::endl;
    }

    return 0;
}