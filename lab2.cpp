// lab2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>
#include <cmath>
#define PI 3.14159265335
using namespace std;


class Point {
    int X, Y;
public:
    Point();
    Point(int x, int y);
    void Init(int x, int y);
    int GetX();
    int GetY();
    void Display();
};

Point::Point() {
    X = Y = 0;
}

Point::Point(int x, int y) {
    this->X = x;
    this->Y = y;
}

void Point::Init(int x, int y) {
    this->X = x;
    this->Y = y;
}

int Point::GetX() {
    return this->X;
}

int Point::GetY() {
    return this->Y;
}

void Point::Display() {
    cout << "(" << X << "," << Y << ")";
}

class Vector {
    Point coord;
public:
    Vector();
    Vector(int x, int y);
    void Init(int x, int y);
    void Display();
    void Read();
    double CalcVectLen();
    double CalcScalarProd(Vector* v2);
};

Vector::Vector() {
    this->coord.Init(0, 0);
}

Vector::Vector(int x, int y) {
    this->coord.Init(x, y);
}

void Vector::Init(int x, int y) {
    this->coord.Init(x, y);
}

void Vector::Read() {
    int x, y;
    cout << "Введите координаты вектора (x, y): ";
    cin >> x >> y;
    this->coord.Init(x, y);
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

class Circle {
    Point Center;
    int R;
public:
    Circle();
    Circle(int x, int y, int r);
    void Init(int x, int y, int r);
    void Display();
    void Read();
    void PrintEquation();
    double CalcSquare();
};

Circle::Circle() {
    this->Center.Init(0, 0);
    this->R = 0;
}

Circle::Circle(int x, int y, int r) {
    this->Center.Init(x, y);
    this->R = r;
}

void Circle::Init(int x, int y, int r) {
    this->Center.Init(x, y);
    this->R = r;
}

void Circle::Read() {
    int x, y, r;
    cout << "Введите координаты центра окружности (x, y): ";
    cin >> x >> y;
    cout << "Введите радиус окружности (R>0): ";
    cin >> r;
    this->Init(x, y, r);
}

void Circle::Display() {
    cout << "Окружность с центром в точке О";
    this->Center.Display();
    cout << " и радиусом R=" << this->R << endl;
}

void Circle::PrintEquation() {
    int x = this->Center.GetX();
    int y = this->Center.GetY();
    int r = this->R;
    cout << "Уравнение окружности:" << endl;
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

double Circle::CalcSquare() {
    double S;
    S = PI * this->R * this->R;
    return S;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);   
    
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
