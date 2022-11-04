#include "Circle.h"
#include <iostream>
#define PI 3.14159265335
using namespace std;

Circle::Circle() //����������� ��� ����������
{
    R = 0;
}

Circle::Circle(int x, int y, double R): //����������� � �����������
    Center(x, y)
{
    this->R = R;
}

Circle::Circle(int x, int y, double R, string metka): //����������� � �����������
    Center(x, y, metka)
{
    this->R = R;
}

void Circle::Read() { //����� �����
    bool correct = 0;
    string strR;
    double r;
    cout << "����� ����������:" << endl;
    Center.Read();
    while (!correct) {
        try
        {
            cout << "������� ������ ���������� (R>0): ";
            cin >> strR;
            r = stod(strR);
            if (r <= 0) throw 0;
            correct = 1;
        }
        catch (invalid_argument& e) {
            cout << "������������ ��������. ��������� ����:" << endl;
        }
        catch (int)
        {
            cout << "������ ������ ���� �������������. ��������� ����:" << endl;
        }
        cin.ignore(1024, '\n');
    }
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
    double r = R;
    cout << "��������� ����������:";
    if (x > 0) {
        if (y > 0)
            printf("(x-%d)^2+(y-%d)^2=%.2lf\n", x, y, r * r);
        if (y < 0)
            printf("(x-%d)^2+(y+%d)^2=%.2lf\n", x, -y, r * r);
        if (y == 0)
            printf("(x-%d)^2+y^2=%.2lf\n", x, r * r);
    }
    if (x < 0) {
        if (y > 0)
            printf("(x+%d)^2+(y-%d)^2=%.2lf\n", -x, y, r * r);
        if (y < 0)
            printf("(x+%d)^2+(y+%d)^2=%.2lf\n", -x, -y, r * r);
        if (y == 0)
            printf("(x+%d)^2+y^2=%.2lf\n", -x, r * r);
    }
    if (x == 0) {
        if (y > 0)
            printf("x^2+(y-%d)^2=%.2lf\n", y, r * r);
        if (y < 0)
            printf("x^2+(y+%d)^2=%.2lf\n", -y, r * r);
        if (y == 0)
            printf("x^2+y^2=%.2lf\n", r * r);
    }
}

double Circle::CalcSquare() { //����� ���������� ������� �����
    double S;
    S = PI * R * R;
    return S;
}

void Circle::CalcSquare(double* rez) { //����� ���������� ������� � ������������ ��������� ����� ���������
    if (rez == NULL) throw "������� ���������!";
    *rez = PI * R * R;
}

void Circle::CalcSquare(double& rez) { //����� ���������� ������� � ������������ ��������� �� ������
    rez = PI * R * R;
}