#include "Triangle.h"
#include <iostream>
using namespace std;

Triangle::Triangle() :
    A(0, 0), B(0, 0), C(0, 0)
{
}

Triangle::Triangle(int x1, int y1, int x2, int y2, int x3, int y3):
    A(x1, y1), B(x2, y2), C(x3, y3) 
{
}

void Triangle::Init(int x1, int y1, int x2, int y2, int x3, int y3)
{
    this->A = Point(x1, y1);
    this->B = Point(x2, y2);
    this->C = Point(x3, y3);
}

void Triangle::Read() {
    int x1, y1, x2, y2, x3, y3;
    cout << "Введите координаты точки А треугольника (x1, y1): ";
    cin >> x1 >> y1;
    cout << "Введите координаты точки B треугольника (x2, y2): ";
    cin >> x2 >> y2;
    cout << "Введите координаты точки C треугольника (x3, y3): ";
    cin >> x3 >> y3;
    this->A = Point(x1, y1);
    this->B = Point(x2, y2);
    this->C = Point(x3, y3);
}

void Triangle::Display() {
    cout << "Треугольник с вершинами А";
    this->A.Display();
    cout << ", B";
    this->B.Display();
    cout << " и C";
    this->C.Display();
    cout << endl;
}

double Triangle::CalcSquare() {
    int x1 = this->A.GetX(), y1 = this->A.GetY();
    int x2 = this->B.GetX(), y2 = this->B.GetY();
    int x3 = this->C.GetX(), y3 = this->C.GetY();
    double S;
    S = 0.5 * fabs((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1));
    return S;
}

double Triangle::CalcPerimeter() {
    int x1 = this->A.GetX(), y1 = this->A.GetY();
    int x2 = this->B.GetX(), y2 = this->B.GetY();
    int x3 = this->C.GetX(), y3 = this->C.GetY();
    double AB = sqrt((x2 - x1) ^ (x2 - x1) + (y2 - y1) ^ (y2 - y1));
    double AC = sqrt((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1));
    double BC = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
    double P = AB + AC + BC;
    return P;
}
