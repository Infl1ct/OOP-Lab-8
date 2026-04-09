#include <iostream>
#include <string>

using namespace std;

class PoweredSystem {
protected:
    int power;

public:
    PoweredSystem(int p) : power(p) {}
    virtual ~PoweredSystem() {}
    
    void displayPower() const {
        cout << "System Power: " << power << " HP" << endl;
    }
};

class Vehicle : virtual public PoweredSystem {
protected:
    string vehicleType;

public:
    Vehicle(int p, string type) : PoweredSystem(p), vehicleType(type) {}
};

class Engine : virtual public PoweredSystem {
protected:
    string engineType;

public:
    Engine(int p, string type) : PoweredSystem(p), engineType(type) {}
};

class Car : public Vehicle, public Engine {
private:
    string model;

public:
    Car(int p, string vType, string eType, string m) 
        : PoweredSystem(p), Vehicle(p, vType), Engine(p, eType), model(m) {}

    void displayDetails() const {
        cout << "Model: " << model << endl;
        cout << "Vehicle Type: " << vehicleType << endl;
        cout << "Engine Type: " << engineType << endl;
        displayPower(); 
    }
};

int main() {
    Car myCar(500, "Coupe", "V8 Twin-Turbo", "McLaren 720S");
    myCar.displayDetails();
    return 0;
}