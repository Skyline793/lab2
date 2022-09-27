#include "Vector.h"
#include <iostream>
using namespace std;

Vector::Vector() :
    coord(0, 0)
{
}

Vector::Vector(int x, int y):
    coord(x, y)
{
}

void Vector::Init(int x, int y) {
    this->coord = Point(x, y);
}

void Vector::Read() {
    int x, y;
    cout << "Введите координаты вектора (x, y): ";
    cin >> x >> y;
    this->coord = Point(x, y);
}

void Vector::Display() {
    cout << "Вектор с координатами: ";
    this->coord.Display();
    cout << endl;
}

double Vector::CalcVectLen() {
    int x = this->coord.GetX(), y = this->coord.GetY();
    double length;
    length = sqrt(x * x + y * y);
    return length;
}

double Vector::CalcScalarProd(Vector* v2) {
    int x1 = this->coord.GetX();
    int y1 = this->coord.GetY();
    int x2 = v2->coord.GetX();
    int y2 = v2->coord.GetY();
    double prod;
    prod = x1 * x2 + y1 * y2;
    return prod;
}