#include "Circle.h"
#include <iostream>
#define PI 3.14159265335
using namespace std;

Circle::Circle() //конструктор без параметров
{
    R = 0;
}

Circle::Circle(int x, int y, double R): //конструктор с параметрами
    Center(x, y)
{
    this->R = R;
}

Circle::Circle(int x, int y, double R, string metka): //конструктор с параметрами
    Center(x, y, metka)
{
    this->R = R;
}

void Circle::Read() { //метод ввода
    bool correct = 0;
    string strR;
    double r;
    cout << "Центр окружности:" << endl;
    Center.Read();
    while (!correct) {
        try
        {
            cout << "Введите радиус окружности (R>0): ";
            cin >> strR;
            r = stod(strR);
            if (r <= 0) throw 0;
            correct = 1;
        }
        catch (invalid_argument& e) {
            cout << "Некорректное значение. Повторите ввод:" << endl;
        }
        catch (int)
        {
            cout << "Радиус должен быть положительным. Повторите ввод:" << endl;
        }
        cin.ignore(1024, '\n');
    }
    R = r;
}

void Circle::Display() { //метод вывода
    cout << "Окружность с центром в точке ";
    Center.Display();
    cout << " и радиусом R=" << R << endl;
}

void Circle::PrintEquation() { //метод вывода уравнения окружности
    int x = Center.GetX();
    int y = Center.GetY();
    double r = R;
    cout << "Уравнение окружности:";
    if (x > 0) {
        if (y > 0)
            printf("(x-%d)^2+(y-%d)^2=%.2lf\n", x, y, r * r);
        if (y < 0)
            printf("(x-%d)^2+(y+%d)^2=%.2lf\n", x, -y, r * r);
        if (y == 0)
            printf("(x-%d)^2+y^2=%.2lf\n", x, r * r);
    }
    if (x < 0) {
        if (y > 0)
            printf("(x+%d)^2+(y-%d)^2=%.2lf\n", -x, y, r * r);
        if (y < 0)
            printf("(x+%d)^2+(y+%d)^2=%.2lf\n", -x, -y, r * r);
        if (y == 0)
            printf("(x+%d)^2+y^2=%.2lf\n", -x, r * r);
    }
    if (x == 0) {
        if (y > 0)
            printf("x^2+(y-%d)^2=%.2lf\n", y, r * r);
        if (y < 0)
            printf("x^2+(y+%d)^2=%.2lf\n", -y, r * r);
        if (y == 0)
            printf("x^2+y^2=%.2lf\n", r * r);
    }
}

double Circle::CalcSquare() { //метод вычисления площади круга
    double S;
    S = PI * R * R;
    return S;
}

void Circle::CalcSquare(double* rez) { //метод вычисления площади с возвращением параметра через указатель
    if (rez == NULL) throw "Нулевой указатель!";
    *rez = PI * R * R;
}

void Circle::CalcSquare(double& rez) { //метод вычисления площади с возвращением параметра по ссылке
    rez = PI * R * R;
}