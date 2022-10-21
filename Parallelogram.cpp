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
    a = Vector(x1, y1);
    b = Vector(x2, y2);
}

void Parallelogram::Read() { //метод ввода
    int x1, y1, x2, y2;
    cout << "Первый из векторов, на которых построен параллелограмм:" << endl;
    a.Read();
    cout << "Второй из векторов, на которых построен параллелограмм: " << endl;
    b.Read();
}

void Parallelogram::Display() { //метод вывода
    cout << "параллелограмм, построенный на векторах:" << endl;
    a.Display();
    b.Display();
}

double Parallelogram::CalcSquare() { //метод вычисления площади
    double S, len_a, len_b, prod, cosinus, sinus;
    len_a = a.CalcVectLen();
    len_b = b.CalcVectLen();
    prod = a.CalcScalarProd(b);
    if (len_a == 0 || len_b == 0)
        cosinus = 0;
    else
        cosinus = prod / (len_a * len_b);
    sinus = sqrt(1 - cosinus * cosinus);
    S = len_a * len_b * sinus;
    return S;
}

void Parallelogram::CalcSquare(double* rez) { //метод вычисления площади с возвращением параметра через указатель
    double len_a, len_b, prod, cosinus, sinus;
    len_a = a.CalcVectLen();
    len_b = b.CalcVectLen();
    prod = a.CalcScalarProd(b);
    if (len_a == 0 || len_b == 0)
        cosinus = 0;
    else
        cosinus = prod / (len_a * len_b);
    sinus = sqrt(1 - cosinus * cosinus);
    *rez = len_a * len_b * sinus;
}

void Parallelogram::CalcSquare(double& rez) { //метод вычисления площади с возвращением параметра по ссылке
    double len_a, len_b, prod, cosinus, sinus;
    len_a = a.CalcVectLen();
    len_b = b.CalcVectLen();
    prod = a.CalcScalarProd(b);
    if (len_a == 0 || len_b == 0)
        cosinus = 0;
    else
        cosinus = prod / (len_a * len_b);
    sinus = sqrt(1 - cosinus * cosinus);
    rez = len_a * len_b * sinus;
}