#pragma once
#include "Point.h"

//����� �����������
class Triangle { 
    Point A, B, C; //������� ������������
public:
    Triangle(); //����������� ��� ����������
    Triangle(int x1, int y1, int x2, int y2, int x3, int y3); //����������� � ����������� 
    void Read(); //����� �����
    double CalcSquare(); //����� ���������� �������
    void CalcSquare(double* rez); //����� ���������� ������� � ������������ ��������� ����� ���������
    void CalcSquare(double& rez); //����� ���������� ������� � ������������ ��������� �� ������
    double CalcPerimeter(); //����� ���������� ���������
    void CalcPerimeter(double* rez); //����� ���������� ��������� � ������������ ��������� ����� ���������
    void CalcPerimeter(double& rez); //����� ���������� ��������� � ������������ ��������� �� ������
    friend ostream& operator<< (ostream& out, Triangle tr); //������������� �������� ������
};

