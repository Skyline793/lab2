#include "Vector.h"
#include <iostream>
using namespace std;

Vector::Vector() //конструктор без параметров
{
}

Vector::Vector(int x, int y): //конструктор с параметрами
    coord(x, y)
{
}

void Vector::Init(int x, int y) { //метод инициализации
    this->coord = Point(x, y);
}

void Vector::Read() { //метод вывода
    int x, y;
    cout << "Введите координаты вектора (x, y): ";
    cin >> x >> y;
    this->coord = Point(x, y);
}

void Vector::Display() { //метод ввода
    cout << "Вектор с координатами: ";
    this->coord.Display();
    cout << endl;
}

double Vector::CalcVectLen() { //метод вычисления длины вектора
    int x = this->coord.GetX(), y = this->coord.GetY();
    double length;
    length = sqrt(x * x + y * y);
    return length;
}

void Vector::CalcVectLen(double* rez)
{
    int x = this->coord.GetX(), y = this->coord.GetY();
    *rez = sqrt(x * x + y * y);
}

void Vector::CalcVectLen(double& rez)
{
    int x = this->coord.GetX(), y = this->coord.GetY();
    rez = sqrt(x * x + y * y);
}

double Vector::CalcScalarProd(Vector v2) { //метод вычисления скалярного произведения векторов
    int x1 = this->coord.GetX();
    int y1 = this->coord.GetY();
    int x2 = v2.coord.GetX();
    int y2 = v2.coord.GetY();
    double prod;
    prod = x1 * x2 + y1 * y2;
    return prod;
}

Vector Vector::operator*(int k) {
    int x = coord.GetX(), y = coord.GetY();
    Vector prod = Vector(x * 3, y * 3);
    return prod;
}

Vector operator* (int k, Vector v) {
    int x = v.coord.GetX(), y = v.coord.GetY();
    Vector prod = Vector(x * 3, y * 3);
    return prod;
}

Vector operator+ (Vector v1, Vector v2) {
    int x1 = v1.coord.GetX();
    int y1 = v1.coord.GetY();
    int x2 = v2.coord.GetX();
    int y2 = v2.coord.GetY();
    Vector sum = Vector(x1 + x2, y1 + y2);
    return sum;
}