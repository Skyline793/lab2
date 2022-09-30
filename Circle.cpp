#include "Circle.h"
#include <iostream>
#define PI 3.14159265335
using namespace std;

Circle::Circle() //����������� ��� ����������
{
    this->R = 0;
}

Circle::Circle(int x, int y, int r): //����������� � �����������
    Center(x, y)
{
    this->R = r;
}

void Circle::Init(int x, int y, int r) { //����� �������������
    this->Center = Point(x, y);
    this->R = r;
}

void Circle::Read() { //����� �����
    int x, y, r;
    cout << "������� ���������� ������ ���������� (x, y): ";
    cin >> x >> y;
    cout << "������� ������ ���������� (R>0): ";
    cin >> r;
    this->Init(x, y, r);
}

void Circle::Display() { //����� ������
    cout << "���������� � ������� � ����� �";
    this->Center.Display();
    cout << " � �������� R=" << this->R << endl;
}

void Circle::PrintEquation() { //����� ������ ��������� ����������
    int x = this->Center.GetX();
    int y = this->Center.GetY();
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
    S = PI * this->R * this->R;
    return S;
}