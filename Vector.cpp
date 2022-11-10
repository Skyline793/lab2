#include "Vector.h"
#include <iostream>
using namespace std;

Vector::Vector() //����������� ��� ����������
{
}

Vector::Vector(int x, int y) : //����������� � �����������
    Point(x, y)
{
}

Vector::Vector(int x, int y, string metka) : //����������� � �����������
    Point(x, y, metka)
{
}

void Vector::Read() { //����� ������
    bool correct = 0;
    int x, y;
    string strX, strY;
    string metka;
    while (!correct) {
        try {
            cout << "������� ���������� ������� (x, y): ";
            cin >> strX >> strY;
            x = stoi(strX);
            y = stoi(strY);
            correct = 1;
        }
        catch (invalid_argument& e) {
            cout << "������������ ��������! ��������� ����:" << endl;
        }
        cin.ignore(1024, '\n');
    }
    cout << "������� ������������� ������� (Enter, ����� �� ��������� �������������): ";
    getline(cin, metka);
    *this = Vector(x, y, metka);
}

double Vector::CalcVectLen() { //����� ���������� ����� �������
    double length;
    length = sqrt(X * X + Y * Y);
    return length;
}

void Vector::CalcVectLen(double* rez) //����� ���������� ����� ������� � ������������ ��������� ����� ���������
{
    if (rez == NULL) throw exception("������� ���������!");

    *rez = sqrt(X * X + Y * Y);
}

void Vector::CalcVectLen(double& rez) //����� ���������� ����� ������� � ������������ ��������� �� ������
{
    rez = sqrt(X * X + Y * Y);
}

double Vector::CalcScalarProd(Vector v2) { //����� ���������� ���������� ������������ ��������
    int x1 = this->X;
    int y1 = this->Y;
    int x2 = v2.X;
    int y2 = v2.Y;
    double prod;
    prod = x1 * x2 + y1 * y2;
    return prod;
}

Vector Vector::operator*(int k) { //������������� �������� ��������� ������� �� ����� ������
    Vector prod = Vector(X * k, Y * k);
    return prod;
}

void Vector::operator= (Point p) { //������������� �������� ������������ 
    this->X = p.GetX();
    this->Y = p.GetY();
    this->metka = p.GetMetka();
}

Vector operator* (int k, Vector v) { //������������� �������� ��������� ������� �� ����� �����
    Vector prod = Vector(v.X * k, v.Y * k);
    return prod;
}

Vector operator+ (Vector v1, Vector v2) { //������������� ������������� �������� �������� ��������
    int x1 = v1.X;
    int y1 = v1.Y;
    int x2 = v2.X;
    int y2 = v2.Y;
    Vector sum = Vector(x1 + x2, y1 + y2);
    return sum;
}

ostream& operator<< (ostream& out, Vector v) { //������������� �������� ������
    cout << "������ " << v.metka << " � ������������: (" << v.X << ", " << v.Y << ")" << endl;
    return out;
}