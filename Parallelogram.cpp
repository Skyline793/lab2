#include "Parallelogram.h"
#include <iostream>
using namespace std;

Parallelogram::Parallelogram() //����������� ��� ����������
{
}

Parallelogram::Parallelogram(int x1, int y1, int x2, int y2): //����������� � �����������
    a(x1, y1), b(x2, y2)
{
}

void Parallelogram::Init(int x1, int y1, int x2, int y2) { //����� �������������
    this->a = Vector(x1, y1);
    this->b = Vector(x2, y2);
}

void Parallelogram::Read() { //����� �����
    int x1, y1, x2, y2;
    cout << "������� ���������� ������� �� ��������, �� ������� �������� �������������� (x1, y1): ";
    cin >> x1 >> y1;
    cout << "������� ���������� ������� �� ��������, �� ������� �������� �������������� (x2, y2): ";
    cin >> x2 >> y2;
    this->a = Vector(x1, y1);
    this->b = Vector(x2, y2);
}

void Parallelogram::Display() { //����� ������
    cout << "��������������, ����������� �� �������� a � b:" << endl;
    this->a.Display();
    this->b.Display();
}

double Parallelogram::CalcSquare() { //����� ���������� �������
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