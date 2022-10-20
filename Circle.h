#pragma once
#include "Point.h"
//����� ����������
class Circle {
    Point Center; //����� ����������
    int R; //������
public:
    Circle(); //����������� ��� ����������
    Circle(int x, int y, int R); //����������� � �����������
    void Init(int x, int y, int R); //����� �������������
    void Display(); //����� ������
    void Read(); //����� �����
    void PrintEquation(); //����� ������ ��������� ����������
    double CalcSquare(); //����� ���������� ������� �����
    void CalcSquare(double* rez);
    void CalcSquare(double& rez);
};

