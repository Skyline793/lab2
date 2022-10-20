#include "Triangle.h"
#include <iostream>
using namespace std;

Triangle::Triangle() //конструктор без параметров
{
}

Triangle::Triangle(int x1, int y1, int x2, int y2, int x3, int y3): //конструктор с параметрами
    A(x1, y1), B(x2, y2), C(x3, y3) 
{
}

void Triangle::Init(int x1, int y1, int x2, int y2, int x3, int y3) //метод инициализации
{
    this->A = Point(x1, y1);
    this->B = Point(x2, y2);
    this->C = Point(x3, y3);
}

void Triangle::Read() { //метод ввода
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

void Triangle::Display() { //метод вывода
    cout << "Треугольник с вершинами А";
    this->A.Display();
    cout << ", B";
    this->B.Display();
    cout << " и C";
    this->C.Display();
    cout << endl;
}

double Triangle::CalcSquare() { //метод вычисления площади
    int x1 = this->A.GetX(), y1 = this->A.GetY();
    int x2 = this->B.GetX(), y2 = this->B.GetY();
    int x3 = this->C.GetX(), y3 = this->C.GetY();
    double S;
    S = 0.5 * fabs((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1));
    return S;
}

void Triangle::CalcSquare(double* rez) {
    int x1 = this->A.GetX(), y1 = this->A.GetY();
    int x2 = this->B.GetX(), y2 = this->B.GetY();
    int x3 = this->C.GetX(), y3 = this->C.GetY();
    *rez = 0.5 * fabs((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1));
}

void Triangle::CalcSquare(double& rez) {
    int x1 = this->A.GetX(), y1 = this->A.GetY();
    int x2 = this->B.GetX(), y2 = this->B.GetY();
    int x3 = this->C.GetX(), y3 = this->C.GetY();
    rez = 0.5 * fabs((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1));
}

double Triangle::CalcPerimeter() { //метод вычисления периметра
    int x1 = this->A.GetX(), y1 = this->A.GetY();
    int x2 = this->B.GetX(), y2 = this->B.GetY();
    int x3 = this->C.GetX(), y3 = this->C.GetY();
    double AB = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    double AC = sqrt((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1));
    double BC = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
    double P = AB + AC + BC;
    return P;
}

void Triangle::CalcPerimeter(double* rez) {
    int x1 = this->A.GetX(), y1 = this->A.GetY();
    int x2 = this->B.GetX(), y2 = this->B.GetY();
    int x3 = this->C.GetX(), y3 = this->C.GetY();
    double AB = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    double AC = sqrt((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1));
    double BC = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
    *rez = AB + AC + BC;
}

void Triangle::CalcPerimeter(double& rez) {
    int x1 = this->A.GetX(), y1 = this->A.GetY();
    int x2 = this->B.GetX(), y2 = this->B.GetY();
    int x3 = this->C.GetX(), y3 = this->C.GetY();
    double AB = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    double AC = sqrt((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1));
    double BC = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
    rez = AB + AC + BC;
}
