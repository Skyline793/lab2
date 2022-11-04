#pragma once
#include "Angle.h"
#include <string>
using std::string;

//����� �����
class Point
{
protected:
    string metka; //����� ��� ������������� �����
    int X ,Y; //���������� �����
private:
    static int counter; //������� ���������� �����
public:
    Point(); //����������� ��� ����������
    Point(int x, int y); //����������� � �����������
    Point(int x, int y, string metka); //����������� � �����������
    ~Point(); //����������
    void SetX(int X); //����� ��������� �������� X
    void SetY(int Y); //����� ��������� �������� Y
    void SetMetka(string metka); //����� ��������� �������� ��������������
    void Read(); //����� �����
    int GetX(); //����� ��������� ���������� X
    int GetY(); //����� ��������� ���������� Y
    string GetMetka(); //����� ��������� ��������������
    void Display(); //����� ������ ���������
    void PolarCoords(); //����� �������� � �������� ����������
    static int GetCount(); //����������� ����� ��������� ��������
    Point& operator++(); //������������� �������� ����������� ����������
    Point operator++(int); //������������� �������� ������������ ����������
};

