#include "Circle.h"
#include <iostream>
#include <exception>
#define PI 3.14159265335
using namespace std;

Circle::Circle() //����������� ��� ����������
{
    R = 0;
}

Circle::Circle(int x, int y, double R): //����������� � �����������
    Center(x, y)
{
    if (R <= 0) throw invalid_argument("������ ������ ���� �������������!");
    this->R = R;
}

Circle::Circle(int x, int y, double R, int colorIndex): //����������� � �����������
    Center(x, y)
{
    if (R <= 0) throw invalid_argument("������ ������ ���� �������������!");
    if (colorIndex < 0 || colorIndex >= Figure::colors->length()) throw invalid_argument("������ ����� ��� ���������");
    this->colorIndex = colorIndex;
    this->R = R;
}

Circle::Circle(int x, int y, double R, string metka, int colorIndex): //����������� � �����������
    Center(x, y, metka)
{
    if (R <= 0) throw invalid_argument("������ ������ ���� �������������!");
    if (colorIndex < 0 || colorIndex >= Figure::colors->length()) throw invalid_argument("������ ����� ��� ���������");
    this->colorIndex = colorIndex;
    this->R = R;
}

void Circle::SetR(double R) //����� ��������� �������
{
    if (R <= 0) throw invalid_argument("������ ������ ���� �������������!");
    this->R = R;
}

void Circle::Read() { //����� �����
    bool correct = 0;
    string strR, strIndex;
    double r;
    int index;
    cout << "����� ����������:" << endl;
    Center.Read();
    while (!correct) {
        try
        {
            cout << "������� ������ ���������� (R>0): ";
            cin >> strR;
            r = stod(strR);
            SetR(r);
            correct = 1;
        }
        catch (invalid_argument& e) {
            cout << e.what() << " ��������� ���� : " << endl;
        }
        cin.ignore(1024, '\n');
    }
    correct = 0;
    while (!correct) {
        try
        {
            cout << "�������� ���� ������:\n0 - ��� �����\n1 - �������\n2 - �����\n3 - �������\n4 - ������" << endl;
            cin >> strIndex;
            index = stoi(strIndex);
            SetColorIndex(index);
            correct = 1;
        }
        catch (invalid_argument& e) {
            cout << e.what() << " ��������� ����:" << endl;
        }
        cin.ignore(1024, '\n');
    }
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
    if (rez == NULL) throw exception("������� ���������!");
    *rez = PI * R * R;
}

void Circle::CalcSquare(double& rez) { //����� ���������� ������� � ������������ ��������� �� ������
    rez = PI * R * R;
}

double Circle::CalcPerimeter() { //����� ���������� ��������� �����
    double P;
    P = 2 * PI * R;
    return P;
}

void Circle::CalcPerimeter(double* rez) { //����� ���������� ��������� � ������������ ��������� ����� ���������
    if (rez == NULL) throw exception("������� ���������!");
    *rez = 2 * PI * R;
}

void Circle::CalcPerimeter(double& rez) { //����� ���������� ��������� � ������������ ��������� �� ������
    rez = 2 * PI * R;
}

ostream& operator<< (ostream& out, Circle c) { //������������� �������� ������
    out << "���������� � ������� � ����� " << c.Center << " � �������� R=" << c.R << ". ���� ������: " << Figure::colors[c.colorIndex] << endl;
    return out;
}