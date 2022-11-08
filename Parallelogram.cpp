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

Parallelogram::Parallelogram(int x1, int y1, int x2, int y2, int colorIndex): //����������� � �����������
    a(x1, y1), b(x2, y2)
{
    this->colorIndex = colorIndex;
}

void Parallelogram::Read() { //����� �����
    bool correct = 0;
    string strIndex;
    int index;
    cout << "������ �� ��������, �� ������� �������� ��������������:" << endl;
    a.Read();
    cout << "������ �� ��������, �� ������� �������� ��������������: " << endl;
    b.Read();
    while (!correct) {
        try
        {
            cout << "�������� ���� ������:\n0 - ��� �����\n1 - �������\n2 - �����\n3 - �������\n4 - ������" << endl;
            cin >> strIndex;
            index = stoi(strIndex);
            if (index < 0 || index >= Figure::colors->length()) throw 0;
            correct = 1;
        }
        catch (invalid_argument& e) {
            cout << "������������ ��������. ��������� ����:" << endl;
        }
        catch (int)
        {
            cout << "������� ����� �� 0 �� 4!. ��������� ����:" << endl;
        }
        cin.ignore(1024, '\n');
    }
    colorIndex = index;
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
    if (rez == NULL) throw exception("������� ���������!");
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

double Parallelogram::CalcPerimeter() //����� ���������� ���������
{
    double len_a, len_b, P;
    len_a = a.CalcVectLen();
    len_b = b.CalcVectLen();
    P = 2 * (len_a + len_b);
    return P;
}
void Parallelogram::CalcPerimeter(double* rez) //����� ���������� ��������� � ������������ ��������� ����� ���������
{
    if (rez == NULL) throw exception("������� ���������!");
    double len_a, len_b;
    len_a = a.CalcVectLen();
    len_b = b.CalcVectLen();
    *rez = 2 * (len_a + len_b);
}
void Parallelogram::CalcPerimeter(double& rez) //����� ���������� ��������� � ������������ ��������� �� ������
{
    double len_a, len_b;
    len_a = a.CalcVectLen();
    len_b = b.CalcVectLen();
    rez = 2 * (len_a + len_b);
}

ostream& operator<< (ostream& out, Parallelogram pr) { //������������� �������� ������
    if (pr.colorIndex < 0 || pr.colorIndex >= Figure::colors->length()) throw exception("��������� ������ ����� ��� ���������!");
    out << "��������������, ����������� �� ��������:" << endl << pr.a << pr.b << "���� ������: " << Figure::colors[pr.colorIndex] << endl;
    return out;
}