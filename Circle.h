#pragma once
#include "Point.h"
//����� ����������
class Circle {
    Point Center; //����� ����������
    int R; //������
public:
    Circle(); //����������� ��� ����������
    Circle(int x, int y, int r); //����������� � �����������
    void Init(int x, int y, int r); //����� �������������
    void Display(); //����� ������
    void Read(); //����� �����
    void PrintEquation(); //����� ������ ��������� ����������
    double CalcSquare(); //����� ���������� ������� �����
};

