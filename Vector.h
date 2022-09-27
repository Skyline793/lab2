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
    double CalcScalarProd(Vector* v2); //����� ���������� ���������� ������������ ��������
};

