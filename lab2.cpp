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

class Triangle {
    Point A, B, C;
public:
    Triangle();
    Triangle(int x1, int y1, int x2, int y2, int x3, int y3);
    void Init(int x1, int y1, int x2, int y2, int x3, int y3);
    void Read();
    void Display();
    double CalcSquare();
    double CalcPerimeter();
};

Triangle::Triangle() {
    this->A.Init(0, 0);
    this->B.Init(0, 0);
    this->C.Init(0, 0);
}

Triangle::Triangle(int x1, int y1, int x2, int y2, int x3, int y3) {
    this->A.Init(x1, y1);
    this->B.Init(x2, y2);
    this->C.Init(x3, y3);
}

void Triangle::Init(int x1, int y1, int x2, int y2, int x3, int y3) {
    this->A.Init(x1, y1);
    this->B.Init(x2, y2);
    this->C.Init(x3, y3);
}

void Triangle::Read() {
    int x1, y1, x2, y2, x3, y3;
    cout << "Введите координаты точки А треугольника (x1, y1): ";
    cin >> x1 >> y1;
    cout << "Введите координаты точки B треугольника (x2, y2): ";
    cin >> x2 >> y2;
    cout << "Введите координаты точки C треугольника (x3, y3): ";
    cin >> x3 >> y3;
    this->A.Init(x1, y1);
    this->B.Init(x2, y2);
    this->C.Init(x3, y3);
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

class Parallelogram {
    Vector a, b;
public:
    Parallelogram();
    Parallelogram(int x1, int y1, int x2, int y2);
    void Init(int x1, int y1, int x2, int y2);
    void Read();
    void Display();
    double CalcSquare();
};

Parallelogram::Parallelogram() {
    a.Init(0, 0);
    b.Init(0, 0);
};

Parallelogram::Parallelogram(int x1, int y1, int x2, int y2) {
    a.Init(x1, y1);
    b.Init(x2, y2);
}

void Parallelogram::Init(int x1, int y1, int x2, int y2) {
    a.Init(x1, y1);
    b.Init(x2, y2);
}

void Parallelogram::Read() {
    int x1, y1, x2, y2;
    cout << "Введите координаты первого из векторов, на которых построен параллелограм (x1, y1): ";
    cin >> x1 >> y1;
    cout << "Введите координаты второго из векторов, на которых построен параллелограм (x1, y1): ";
    cin >> x2 >> y2;
    a.Init(x1, y1);
    b.Init(x2, y2);
}

void Parallelogram::Display() {
    cout << "Параллелограм, построенный на векторах a и b:" << endl;
    a.Display();
    b.Display();
}

double Parallelogram::CalcSquare() {
    double S, len_a, len_b, prod, cosinus, sinus;
    len_a = a.CalcVectLen();
    len_b = b.CalcVectLen();
    prod = a.CalcScalarProd(&b);
    cosinus = prod / (len_a * len_b);
    sinus = sqrt(1 - cosinus * cosinus);
    S = len_a * len_b * sinus;
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
