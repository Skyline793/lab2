#pragma once
#include <string>
using std::string;

class Point
{
    string metka; //����� ��� ������������� �����
    int X ,Y; //���������� �����
    static int counter; //������� ���������� �����
public:
    Point(); //����������� ��� ����������
    Point(int x, int y); //����������� � �����������
    Point(int x, int y, string metka); //����������� � �����������
    ~Point(); //����������
    void Init(int x, int y); //����� �������������
    void Read(); //����� �����
    int GetX(); //����� ��������� ���������� X
    int GetY(); //����� ��������� ���������� Y
    void Display(); //����� ������ ���������
    void PolarCoords(); //����� �������� � �������� ����������
    static double PerevodToGradus(double rad); //����������� ����� �������� ������ � �������
    static double PerevodToRadian(double grad); //����������� ����� �������� �������� � �������
    static int GetCount(); //����������� ����� ��������� ��������
    Point& operator++(); //������������� �������� ����������� ����������
    Point operator++(int); //������������� �������� ������������ ����������
};

