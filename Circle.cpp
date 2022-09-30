#include "Circle.h"
#include <iostream>
#define PI 3.14159265335
using namespace std;

Circle::Circle() //конструктор без параметров
{
    this->R = 0;
}

Circle::Circle(int x, int y, int r): //конструктор с параметрами
    Center(x, y)
{
    this->R = r;
}

void Circle::Init(int x, int y, int r) { //метод инициализации
    this->Center = Point(x, y);
    this->R = r;
}

void Circle::Read() { //метод ввода
    int x, y, r;
    cout << "Введите координаты центра окружности (x, y): ";
    cin >> x >> y;
    cout << "Введите радиус окружности (R>0): ";
    cin >> r;
    this->Init(x, y, r);
}

void Circle::Display() { //метод вывода
    cout << "Окружность с центром в точке О";
    this->Center.Display();
    cout << " и радиусом R=" << this->R << endl;
}

void Circle::PrintEquation() { //метод вывода уравнения окружности
    int x = this->Center.GetX();
    int y = this->Center.GetY();
    int r = this->R;
    cout << "Уравнение окружности:";
    if (x > 0) {
        if (y > 0)
            printf("(x-%d)^2+(y-%d)^2=%d\n", x, y, r * r);
        if (y < 0)
            printf("(x-%d)^2+(y+%d)^2=%d\n", x, -y, r * r);
        if (y == 0)
            printf("(x-%d)^2+y^2=%d\n", x, r * r);
    }
    if (x < 0) {
        if (y > 0)
            printf("(x+%d)^2+(y-%d)^2=%d\n", -x, y, r * r);
        if (y < 0)
            printf("(x+%d)^2+(y+%d)^2=%d\n", -x, -y, r * r);
        if (y == 0)
            printf("(x+%d)^2+y^2=%d\n", -x, r * r);
    }
    if (x == 0) {
        if (y > 0)
            printf("x^2+(y-%d)^2=%d\n", y, r * r);
        if (y < 0)
            printf("x^2+(y+%d)^2=%d\n", -y, r * r);
        if (y == 0)
            printf("x^2+y^2=%d\n", r * r);
    }
}

double Circle::CalcSquare() { //метод вычисления площади круга
    double S;
    S = PI * this->R * this->R;
    return S;
}