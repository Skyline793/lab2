#pragma once
#include "Point.h"
//����� ������
class Vector {
    Point coord; //���������� ������
public:
    Vector(); //����������� ��� ����������
    Vector(int x, int y); //����������� � �����������
    void Init(int x, int y); //����� �������������
    void Display(); //����� ������ 
    void Read(); //����� �����
    double CalcVectLen(); //����� ���������� ����� �������
    void CalcVectLen(double* rez);
    void CalcVectLen(double& rez);
    double CalcScalarProd(Vector v2); //����� ���������� ���������� ������������ ��������
    Vector operator* (int k);
    friend Vector operator* (int k, Vector v);
    friend Vector operator+ (Vector v1, Vector v2);
 
};

