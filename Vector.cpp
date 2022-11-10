#include "Vector.h"
#include <iostream>
using namespace std;

Vector::Vector() //конструктор без параметров
{
}

Vector::Vector(int x, int y) : //конструктор с параметрами
    Point(x, y)
{
}

Vector::Vector(int x, int y, string metka) : //конструктор с параметрами
    Point(x, y, metka)
{
}

void Vector::Read() { //метод вывода
    bool correct = 0;
    int x, y;
    string strX, strY;
    string metka;
    while (!correct) {
        try {
            cout << "Введите координаты вектора (x, y): ";
            cin >> strX >> strY;
            x = stoi(strX);
            y = stoi(strY);
            correct = 1;
        }
        catch (invalid_argument& e) {
            cout << "Некорректное значение! Повторите ввод:" << endl;
        }
        cin.ignore(1024, '\n');
    }
    cout << "Введите идентификатор вектора (Enter, чтобы не создавать идентификатор): ";
    getline(cin, metka);
    *this = Vector(x, y, metka);
}

double Vector::CalcVectLen() { //метод вычисления длины вектора
    double length;
    length = sqrt(X * X + Y * Y);
    return length;
}

void Vector::CalcVectLen(double* rez) //метод вычисления длины вектора с возвращением параметра через указатель
{
    if (rez == NULL) throw exception("Нулевой указатель!");

    *rez = sqrt(X * X + Y * Y);
}

void Vector::CalcVectLen(double& rez) //метод вычисления длины вектора с возвращением параметра по ссылке
{
    rez = sqrt(X * X + Y * Y);
}

double Vector::CalcScalarProd(Vector v2) { //метод вычисления скалярного произведения векторов
    int x1 = this->X;
    int y1 = this->Y;
    int x2 = v2.X;
    int y2 = v2.Y;
    double prod;
    prod = x1 * x2 + y1 * y2;
    return prod;
}

Vector Vector::operator*(int k) { //перегруженный оператор умножения вектора на число справа
    Vector prod = Vector(X * k, Y * k);
    return prod;
}

void Vector::operator= (Point p) { //перегруженный оператор присваивания 
    this->X = p.GetX();
    this->Y = p.GetY();
    this->metka = p.GetMetka();
}

Vector operator* (int k, Vector v) { //перегруженный оператор умножения вектора на число слева
    Vector prod = Vector(v.X * k, v.Y * k);
    return prod;
}

Vector operator+ (Vector v1, Vector v2) { //дружественный перегруженный оператор сложения векторов
    int x1 = v1.X;
    int y1 = v1.Y;
    int x2 = v2.X;
    int y2 = v2.Y;
    Vector sum = Vector(x1 + x2, y1 + y2);
    return sum;
}

ostream& operator<< (ostream& out, Vector v) { //перегруженный оператор вывода
    cout << "Вектор " << v.metka << " с координатами: (" << v.X << ", " << v.Y << ")" << endl;
    return out;
}