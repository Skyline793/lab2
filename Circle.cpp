#include "Circle.h"
#include <iostream>
#define PI 3.14159265335
using namespace std;

Circle::Circle() //����������� ��� ����������
{
    R = 0;
}

Circle::Circle(int x, int y, int R): //����������� � �����������
    Center(x, y)
{
    this->R = R;
}

Circle::Circle(int x, int y, int R, string metka): //����������� � �����������
    Center(x, y, metka)
{
    this->R = R;
}

void Circle::Init(int x, int y, int R) { //����� �������������
    this->Center = Point(x, y);
    this->R = R;
}

void Circle::Read() { //����� �����
    int r;
    cout << "����� ����������:" << endl;
    Center.Read();
    cout << "������� ������ ���������� (R>0): ";
    cin >> r;
    R = r;
}

void Circle::Display() { //����� ������
    cout << "���������� � ������� � ����� ";
    Center.Display();
    cout << " � �������� R=" << R << endl;
}

void Circle::PrintEquation() { //����� ������ ��������� ����������
    int x = Center.GetX();
    int y = Center.GetY();
    int r = this->R;
    cout << "��������� ����������:";
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

double Circle::CalcSquare() { //����� ���������� ������� �����
    double S;
    S = PI * R * R;
    return S;
}

void Circle::CalcSquare(double* rez) { //����� ���������� ������� � ������������ ��������� ����� ���������
    *rez = PI * R * R;
}

void Circle::CalcSquare(double& rez) { //����� ���������� ������� � ������������ ��������� �� ������
    rez = PI * R * R;
}