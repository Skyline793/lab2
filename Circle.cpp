#include "Circle.h"
#include <iostream>
#include <exception>
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

Circle::Circle(int x, int y, double R, int colorIndex): //конструктор с параметрами
    Center(x, y)
{
    this->colorIndex = colorIndex;
    this->R = R;
}

Circle::Circle(int x, int y, double R, string metka, int colorIndex): //конструктор с параметрами
    Center(x, y, metka)
{
    this->colorIndex = colorIndex;
    this->R = R;
}

void Circle::Read() { //метод ввода
    bool correct = 0;
    string strR, strIndex;
    double r;
    int index;
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
    correct = 0;
    while (!correct) {
        try
        {
            cout << "Выберите цвет фигуры:\n0 - без цвета\n1 - красный\n2 - синий\n3 - зеленый\n4 - желтый" << endl;
            cin >> strIndex;
            index = stoi(strIndex);
            if (index < 0 || index > 4) throw 0;
            correct = 1;
        }
        catch (invalid_argument& e) {
            cout << "Некорректное значение. Повторите ввод:" << endl;
        }
        catch (int)
        {
            cout << "Введите число от 0 до 4!. Повторите ввод:" << endl;
        }
        cin.ignore(1024, '\n');
    }
    R = r;
    colorIndex = index;
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
    if (rez == NULL) throw exception("Нулевой указатель!");
    *rez = PI * R * R;
}

void Circle::CalcSquare(double& rez) { //метод вычисления площади с возвращением параметра по ссылке
    rez = PI * R * R;
}

double Circle::CalcPerimeter() { //метод вычисления периметра круга
    double P;
    P = 2 * PI * R;
    return P;
}

void Circle::CalcPerimeter(double* rez) { //метод вычисления периметра с возвращением параметра через указатель
    if (rez == NULL) throw exception("Нулевой указатель!");
    *rez = 2 * PI * R;
}

void Circle::CalcPerimeter(double& rez) { //метод вычисления периметра с возвращением параметра по ссылке
    rez = 2 * PI * R;
}

ostream& operator<< (ostream& out, Circle c) { //перегруженный оператор вывода
    if (c.colorIndex < 0 || c.colorIndex > 4) throw exception("Выбранный индекс цвета вне диапазона!");
    out << "Окружность с центром в точке " << c.Center << " и радиусом R=" << c.R << ". Цвет фигуры: " << Figure::colors[c.colorIndex] << endl;
    return out;
}