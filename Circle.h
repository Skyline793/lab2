#pragma once
#include "Point.h"
#include "Figure.h"

//����� ����������
class Circle : public Figure {
    Point Center; //����� ����������
    double R; //������
public:
    Circle(); //����������� ��� ����������
    Circle(int x, int y, double R); //����������� � �����������
    Circle(int x, int y, double R, int colorIndex); //����������� � �����������
    Circle(int x, int y, double R, string metka, int colorIndex); //����������� � �����������
    void Read(); //����� �����
    void PrintEquation(); //����� ������ ��������� ����������
    double CalcSquare(); //����� ���������� ������� �����
    void CalcSquare(double* rez); //����� ���������� ������� � ������������ ��������� ����� ���������
    void CalcSquare(double& rez); //����� ���������� ������� � ������������ ��������� �� ������
    double CalcPerimeter(); //����� ���������� ����� ����������
    void CalcPerimeter(double* rez); //����� ���������� ����� ���������� � ������������ ��������� ����� ���������
    void CalcPerimeter(double& rez); //����� ���������� ����� ���������� � ������������ ��������� �� ������
    friend ostream& operator<< (ostream& out, Circle c); //������������� �������� ������
};

