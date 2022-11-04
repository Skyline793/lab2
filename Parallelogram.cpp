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

void Parallelogram::Read() { //метод ввода
    cout << "Первый из векторов, на которых построен параллелограмм:" << endl;
    a.Read();
    cout << "Второй из векторов, на которых построен параллелограмм: " << endl;
    b.Read();
}

double Parallelogram::CalcSquare() { //метод вычисления площади
    double S, len_a, len_b, prod, cosinus, sinus;
    len_a = a.CalcVectLen();
    len_b = b.CalcVectLen();
    if (len_a * len_b == 0)
        return 0;
    prod = a.CalcScalarProd(b);
    cosinus = prod / (len_a * len_b);
    sinus = sqrt(1 - cosinus * cosinus);
    S = len_a * len_b * sinus;
    return S;
}

void Parallelogram::CalcSquare(double* rez) { //метод вычисления площади с возвращением параметра через указатель
    if (rez == NULL) throw "Нулевой указатель!";
    double len_a, len_b, prod, cosinus, sinus;
    len_a = a.CalcVectLen();
    len_b = b.CalcVectLen();
    prod = a.CalcScalarProd(b);
    try {
        if (len_a * len_b == 0) throw 0;
        cosinus = prod / (len_a * len_b);
    }
    catch (int) {
        cosinus = 0;
    }
    sinus = sqrt(1 - cosinus * cosinus);
    *rez = len_a * len_b * sinus;
}

void Parallelogram::CalcSquare(double& rez) { //метод вычисления площади с возвращением параметра по ссылке
    double len_a, len_b, prod, cosinus, sinus;
    len_a = a.CalcVectLen();
    len_b = b.CalcVectLen();
    prod = a.CalcScalarProd(b);
    try {
        if (len_a * len_b == 0) throw 0;
        cosinus = prod / (len_a * len_b);
    }
    catch (int) {
        cosinus = 0;
    }
    sinus = sqrt(1 - cosinus * cosinus);
    rez = len_a * len_b * sinus;
}

ostream& operator<< (ostream& out, Parallelogram pr) { //перегруженный оператор вывода
    out << "Параллелограмм, построенный на векторах:" << endl << pr.a << pr.b;
    return out;
}