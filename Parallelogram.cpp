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

void Parallelogram::Read() { //����� �����
    cout << "������ �� ��������, �� ������� �������� ��������������:" << endl;
    a.Read();
    cout << "������ �� ��������, �� ������� �������� ��������������: " << endl;
    b.Read();
}

double Parallelogram::CalcSquare() { //����� ���������� �������
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

void Parallelogram::CalcSquare(double* rez) { //����� ���������� ������� � ������������ ��������� ����� ���������
    if (rez == NULL) throw "������� ���������!";
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

void Parallelogram::CalcSquare(double& rez) { //����� ���������� ������� � ������������ ��������� �� ������
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

ostream& operator<< (ostream& out, Parallelogram pr) { //������������� �������� ������
    out << "��������������, ����������� �� ��������:" << endl << pr.a << pr.b;
    return out;
}