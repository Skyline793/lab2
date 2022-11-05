#pragma once
#include "Vector.h"
#include "Figure.h"

//����� ��������������
class Parallelogram : public Figure {
    Vector a, b; //�������, �� ������� �������� ��������������
public:
    Parallelogram(); //����������� ��� ����������
    Parallelogram(int x1, int y1, int x2, int y2); //����������� � �����������
    Parallelogram(int x1, int y1, int x2, int y2, int colorIndex); //����������� � �����������
    void Read(); //����� �����
    double CalcSquare(); //����� ���������� ������� 
    void CalcSquare(double* rez); //����� ���������� ������� � ������������ ��������� ����� ���������
    void CalcSquare(double& rez); //����� ���������� ������� � ������������ ��������� �� ������
    double CalcPerimeter(); //����� ���������� ���������
    void CalcPerimeter(double* rez); //����� ���������� ��������� � ������������ ��������� ����� ���������
    void CalcPerimeter(double& rez); //����� ���������� ��������� � ������������ ��������� �� ������
    friend ostream& operator<< (ostream& out, Parallelogram pr); //������������� �������� ������
};

