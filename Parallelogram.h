#pragma once
#include "Vector.h"

//����� ��������������
class Parallelogram {
    Vector a, b; //�������, �� ������� �������� ��������������
public:
    Parallelogram(); //����������� ��� ����������
    Parallelogram(int x1, int y1, int x2, int y2); //����������� � �����������
    void Init(int x1, int y1, int x2, int y2); //����� �������������
    void Read(); //����� �����
    void Display(); //����� ������
    double CalcSquare(); //����� ���������� ������� 
    void CalcSquare(double* rez); //����� ���������� ������� � ������������ ��������� ����� ���������
    void CalcSquare(double& rez); //����� ���������� ������� � ������������ ��������� �� ������
};

