#pragma once
#include "Point.h"
//����� ����������
class Circle {
    Point Center; //����� ����������
    double R; //������
public:
    Circle(); //����������� ��� ����������
    Circle(int x, int y, double R); //����������� � �����������
    Circle(int x, int y, double R, string metka); //����������� � �����������
    void Init(int x, int y, double R); //����� �������������
    void Display(); //����� ������
    void Read(); //����� �����
    void PrintEquation(); //����� ������ ��������� ����������
    double CalcSquare(); //����� ���������� ������� �����
    void CalcSquare(double* rez); //����� ���������� ������� � ������������ ��������� ����� ���������
    void CalcSquare(double& rez); //����� ���������� ������� � ������������ ��������� �� ������
};

