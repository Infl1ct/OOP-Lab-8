#include <iostream>

using namespace std;

class Shape{
    public:
    virtual ~Shape() {}
    virtual double area() = 0;
};

class Circle: public Shape{
    private:
    double radius;

    public:
    Circle(double r){
        radius = r;
    }

    double area() override{
        return 3.14 * (radius*radius);
    }
};

class Rectangle: public Shape{
    private:
    double length, width;

    public:
    Rectangle(double l, double w){
        length = l;
        width = w;
    }

    double area() override{
        return length * width;
    }
};

class Triangle: public Shape{
    private:
    double base, height;

    public:
    Triangle(double b, double h){
        base = b;
        height = h;
    }

    double area() override{
        return 0.5 * base * height;
    }
};

int main(){
    Circle c(5.0);
    Rectangle r(4.0, 6.0);
    Triangle t(3.0, 8.0);

    Shape* shapes[3];
    shapes[0] = &c;
    shapes[1] = &r;
    shapes[2] = &t;

    for (int i = 0; i < 3; i++){
        cout << "Area: " << shapes[i]->area() << endl;
    }

    return 0;
}