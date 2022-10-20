#include "Parallelogram.h"
#include <iostream>
using namespace std;

Parallelogram::Parallelogram() //конструктор без параметров
{
}

Parallelogram::Parallelogram(int x1, int y1, int x2, int y2): //конструктор с параметрами
    a(x1, y1), b(x2, y2)
{
}

void Parallelogram::Init(int x1, int y1, int x2, int y2) { //метод инициализации
    this->a = Vector(x1, y1);
    this->b = Vector(x2, y2);
}

void Parallelogram::Read() { //метод ввода
    int x1, y1, x2, y2;
    cout << "Введите координаты первого из векторов, на которых построен параллелограмм (x1, y1): ";
    cin >> x1 >> y1;
    cout << "Введите координаты второго из векторов, на которых построен параллелограмм (x2, y2): ";
    cin >> x2 >> y2;
    this->a = Vector(x1, y1);
    this->b = Vector(x2, y2);
}

void Parallelogram::Display() { //метод вывода
    cout << "параллелограмм, построенный на векторах a и b:" << endl;
    this->a.Display();
    this->b.Display();
}

double Parallelogram::CalcSquare() { //метод вычисления площади
    double S, len_a, len_b, prod, cosinus, sinus;
    len_a = a.CalcVectLen();
    len_b = b.CalcVectLen();
    prod = a.CalcScalarProd(b);
    cosinus = prod / (len_a * len_b);
    sinus = sqrt(1 - cosinus * cosinus);
    S = len_a * len_b * sinus;
    return S;
}

void Parallelogram::CalcSquare(double* rez) {
    double len_a, len_b, prod, cosinus, sinus;
    len_a = a.CalcVectLen();
    len_b = b.CalcVectLen();
    prod = a.CalcScalarProd(b);
    cosinus = prod / (len_a * len_b);
    sinus = sqrt(1 - cosinus * cosinus);
    *rez = len_a * len_b * sinus;
}

void Parallelogram::CalcSquare(double& rez) {
    double len_a, len_b, prod, cosinus, sinus;
    len_a = a.CalcVectLen();
    len_b = b.CalcVectLen();
    prod = a.CalcScalarProd(b);
    cosinus = prod / (len_a * len_b);
    sinus = sqrt(1 - cosinus * cosinus);
    rez = len_a * len_b * sinus;
}