#pragma once
#include "Point.h"
//����� ������
class Vector : public Point {
public:
    Vector(); //����������� ��� ����������
    Vector(int x, int y); //����������� � �����������
    Vector(int x, int y, string metka); //����������� � �����������
    void Read(); //����� �����
    double CalcVectLen(); //����� ���������� ����� �������
    void CalcVectLen(double* rez); //����� ���������� ����� ������� � ������������ ��������� ����� ���������
    void CalcVectLen(double& rez); //����� ���������� ����� ������� � ������������ ��������� �� ������
    double CalcScalarProd(Vector v2); //����� ���������� ���������� ������������ ��������
    Vector operator* (int k); //������������� �������� ��������� ������� �� ����� ������
    void operator= (Point p); //������������� �������� ������������
    friend Vector operator* (int k, Vector v); //������������� ������������� �������� ��������� ������� �� ����� �����
    friend Vector operator+ (Vector v1, Vector v2); //������������� ������������� �������� �������� ��������
    friend ostream& operator<< (ostream& out, Vector v); //������������� �������� ������
 
};

