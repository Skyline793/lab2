#pragma once
#include "Angle.h"
#include <string>
using namespace std;

//����� �����
class Point
{
    static int counter; //������� ���������� �����
protected:
    int X ,Y; //���������� �����
public:
    Point(); //����������� ��� ����������
    Point(int x, int y); //����������� � �����������
    ~Point(); //����������
    void SetX(int X); //����� ��������� �������� X
    void SetY(int Y); //����� ��������� �������� Y
    virtual void Read(); //����������� ����� �����
    int GetX(); //����� ��������� ���������� X
    int GetY(); //����� ��������� ���������� Y
    void PolarCoords(); //����� �������� � �������� ����������
    static int GetCount(); //����������� ����� ��������� ��������
    Point& operator++(); //������������� �������� ����������� ����������
    Point operator++(int); //������������� �������� ������������ ����������
    friend ostream& operator<< (ostream &out, Point p); //������������� �������� ������
};

