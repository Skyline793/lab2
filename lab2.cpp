// lab2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>
#include <cmath>
#define PI 3.14159265335
using namespace std;

//класс точка
class Point {
    int X, Y; //координаты точки
public:
    Point(); //конструктор без параметров
    Point(int x, int y); //конструктор с параметрами
    void Init(int x, int y); //метод инициализации
    int GetX(); //метод получения координаты X
    int GetY(); //метод получения координаты Y
    void Display(); //Метод вывода координат
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

//класс вектор
class Vector {
    Point coord; //координаты вектор
public:
    Vector(); //конструктор без параметров
    Vector(int x, int y); //конструктор с параметрами
    void Init(int x, int y); //метод инициализации
    void Display(); //метод вывода 
    void Read(); //метод ввода
    double CalcVectLen(); //метод вычисления длины вектора
    double CalcScalarProd(Vector* v2); //метод вычисления скалярного произведения векторов
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


//класс окружность
class Circle {
    Point Center; //центр окружности
    int R; //радиус
public:
    Circle(); //конструктор без параметров
    Circle(int x, int y, int r); //конструктор с параметрами
    void Init(int x, int y, int r); //метод инициализации
    void Display(); //метод вывода
    void Read(); //метод ввода
    void PrintEquation(); //метод вывода уравнения окружности
    double CalcSquare(); //метод вычисления площади круга
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

double Circle::CalcSquare() {
    double S;
    S = PI * this->R * this->R;
    return S;
}

//класс треугольник
class Triangle { 
    Point A, B, C; //вершины треугольника
public:
    Triangle(); //конструктор без параметров
    Triangle(int x1, int y1, int x2, int y2, int x3, int y3); //конструктор с параметрами 
    void Init(int x1, int y1, int x2, int y2, int x3, int y3); //метод инициализации
    void Read(); //метод ввода
    void Display(); //метод вывода
    double CalcSquare(); //метод вычисления площади
    double CalcPerimeter(); //метод вычисления периметра
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

//класс параллелограмм
class Parallelogram {
    Vector a, b; //вектора, на которых построен параллелограмм
public:
    Parallelogram(); //конструктор без параметров
    Parallelogram(int x1, int y1, int x2, int y2); //конструктор с параметрами
    void Init(int x1, int y1, int x2, int y2); //метод инициализации
    void Read(); //метод ввода
    void Display(); //метод вывода
    double CalcSquare(); //метод вычисления площади 
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
    cout << "Введите координаты первого из векторов, на которых построен параллелограмм (x1, y1): ";
    cin >> x1 >> y1;
    cout << "Введите координаты второго из векторов, на которых построен параллелограмм (x2, y2): ";
    cin >> x2 >> y2;
    a.Init(x1, y1);
    b.Init(x2, y2);
}

void Parallelogram::Display() {
    cout << "параллелограмм, построенный на векторах a и b:" << endl;
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
    //cout << "Тест класса вектор:" << endl;
    //Vector* V1 = new Vector; //динамический объект
    //Vector* V2 = new Vector(4, -3); //динамический объект
    //cout << "\nКонструктор без параметров и с параметрами:" << endl;
    //V1->Display();
    //V2->Display();
    //cout << "\nВвод вектора V1 c клавиатуры:" << endl;
    //V1->Read();
    //V1->Display(); 
    //cout << "\nВвод вектора V2 c клавиатуры:" << endl;
    //V2->Read();
    //V2->Display();
    //cout << "\nТест методов:" << endl;
    //cout << "Модуль вектора |V1|= " << V1->CalcVectLen() << endl;
    //cout << "Модуль вектора |V2|= " << V2->CalcVectLen() << endl;
    //cout << "Скалярное произведение (V1, V2)=" << V1->CalcScalarProd(V2) << endl;
    //delete V1, V2;

    //cout << "\n\nТест класса окружность:" << endl;
    //Circle* circles = new Circle[5]; //динамический массив
    //cout << "\nИнициализация динамического массива окружностей:" << endl;
    //for (int i = 0; i < 5; i++) {
    //    circles[i].Init(i * 2, i - 3, i * i+1);
    //    circles[i].Display();
    //}
    //cout << "\nВвод данных динамического массива окружностей:" << endl;
    //for (int i = 0; i < 5; i++) {
    //    circles[i].Read();
    //}
    //cout << "\nУравнения окружностей динамического массива:" << endl;
    //for (int i = 0; i < 5; i++) {
    //    circles[i].PrintEquation();
    //}
    //cout << "\nПлощади окружностей динамического массива:" << endl;
    //for (int i = 0; i < 5; i++) {
    //    cout << "Площадь круга " << i+1 << " S=" << circles[i].CalcSquare() << endl;
    //}
    //delete[] circles;


    //cout << "\n\nТест класса треугольник:" << endl;
    //Triangle tr(0, 2, 3, -1, -3, 1); //статический объект
    //cout << "\nКонструктор с параметрами:" << endl;
    //tr.Display();
    //cout << "\nВвод координат вершин треугольника:" << endl;
    //tr.Read();
    //cout << "\nТест методов:" << endl;
    //cout << "Площадь треугольника S=" << tr.CalcSquare() << endl;;
    //cout << "Периметр треугольника P=" << tr.CalcPerimeter() << endl;


    cout << "\n\nТест класса параллелограмм:" << endl;
    //массив динамических объектов
    Parallelogram* prgrams[3]; 
    for (int i = 0; i < 3; i++)
        prgrams[i] = new Parallelogram;
    cout << "\nВвод координат векторов, на которых построен параллелограмм:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "параллелограмм " << i+1 << ":" << endl;
        (*prgrams[i]).Read();
    }
    cout << "\nВывод параллелограммов массива:" << endl;
    for (int i = 0; i < 3; i++)
        (*prgrams[i]).Display();
    cout << "\nПлощади параллелограммов массива:" << endl;
    for (int i = 0; i < 3; i++)
        cout << "Площадь параллелограмма " << i + 1 << " S=" << (*prgrams[i]).CalcSquare() << endl;;
    for (int i = 0; i < 3; i++)
        delete prgrams[i];

    cin.get();
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
