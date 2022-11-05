#include "Triangle.h"
#include <iostream>
using namespace std;

Triangle::Triangle() //����������� ��� ����������
{
}

Triangle::Triangle(int x1, int y1, int x2, int y2, int x3, int y3): //����������� � �����������
    A(x1, y1), B(x2, y2), C(x3, y3) 
{
}

Triangle::Triangle(int x1, int y1, int x2, int y2, int x3, int y3, int colorIndex): //����������� � �����������
    A(x1, y1), B(x2, y2), C(x3, y3)
{
    this->colorIndex = colorIndex;
}


void Triangle::Read() { //����� �����
    bool correct = 0;
    string strIndex;
    int index;
    cout << "������ ������� ������������:" << endl;
    A.Read();
    cout << "������ ������� ������������:" << endl;
    B.Read();
    cout << "������ ������� ������������:" << endl;
    C.Read();
    while (!correct) {
        try
        {
            cout << "�������� ���� ������:\n0 - ��� �����\n1 - �������\n2 - �����\n3 - �������\n4 - ������" << endl;
            cin >> strIndex;
            index = stoi(strIndex);
            if (index < 0 || index > 4) throw 0;
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

double Triangle::CalcSquare() { //����� ���������� �������
    int x1 = A.GetX(), y1 = A.GetY();
    int x2 = B.GetX(), y2 = B.GetY();
    int x3 = C.GetX(), y3 = C.GetY();
    double S;
    S = 0.5 * fabs((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1));
    return S;
}

void Triangle::CalcSquare(double* rez) { //����� ���������� ������� � ������������ ��������� ����� ���������
    if (rez == NULL) throw exception("������� ���������!");
    int x1 = A.GetX(), y1 = A.GetY();
    int x2 = B.GetX(), y2 = B.GetY();
    int x3 = C.GetX(), y3 = C.GetY();
    *rez = 0.5 * fabs((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1));
}

void Triangle::CalcSquare(double& rez) { //����� ���������� ������� � ������������ ��������� �� ������
    int x1 = A.GetX(), y1 = A.GetY();
    int x2 = B.GetX(), y2 = B.GetY();
    int x3 = C.GetX(), y3 = C.GetY();
    rez = 0.5 * fabs((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1));
}

double Triangle::CalcPerimeter() { //����� ���������� ���������
    int x1 = A.GetX(), y1 = A.GetY();
    int x2 = B.GetX(), y2 = B.GetY();
    int x3 = C.GetX(), y3 = C.GetY();
    double AB = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    double AC = sqrt((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1));
    double BC = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
    double P = AB + AC + BC;
    return P;
}

void Triangle::CalcPerimeter(double* rez) { //����� ���������� ��������� � ������������ ��������� ����� ���������
    if (rez == NULL) throw exception("������� ���������!");
    int x1 = A.GetX(), y1 = A.GetY();
    int x2 = B.GetX(), y2 = B.GetY();
    int x3 = C.GetX(), y3 = C.GetY();
    double AB = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    double AC = sqrt((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1));
    double BC = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
    *rez = AB + AC + BC;
}

void Triangle::CalcPerimeter(double& rez) { //����� ���������� ��������� � ������������ ��������� �� ������
    int x1 = A.GetX(), y1 = A.GetY();
    int x2 = B.GetX(), y2 = B.GetY();
    int x3 = C.GetX(), y3 = C.GetY();
    double AB = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    double AC = sqrt((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1));
    double BC = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
    rez = AB + AC + BC;
}

ostream& operator<< (ostream& out, Triangle tr) { //������������� �������� ������
    if (tr.colorIndex < 0 || tr.colorIndex > 4) throw exception("��������� ������ ����� ��� ���������!");
    out << "����������� � ��������� " << tr.A << ", " << tr.B << ", " << tr.C << ". ���� ������: " << Figure::colors[tr.colorIndex] << endl;
    return out;
}