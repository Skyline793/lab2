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
    string metka; //����� ��� ������������� �����
public:
    Point(); //����������� ��� ����������
    Point(int x, int y); //����������� � �����������
    Point(int x, int y, string metka); //����������� � �����������
    ~Point(); //����������
    void SetX(int X); //����� ��������� �������� X
    void SetY(int Y); //����� ��������� �������� Y
    void SetMetka(string metka); //����� ��������� �������� ��������������
    virtual void Read(); //����������� ����� �����
    int GetX(); //����� ��������� ���������� X
    int GetY(); //����� ��������� ���������� Y
    string GetMetka(); //����� ��������� ��������������
    void PolarCoords(); //����� �������� � �������� ����������
    static int GetCount(); //����������� ����� ��������� ��������
    Point& operator++(); //������������� �������� ����������� ����������
    Point operator++(int); //������������� �������� ������������ ����������
    friend ostream& operator<< (ostream &out, Point p); //������������� �������� ������
};

