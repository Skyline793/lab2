#pragma once
class Point
{
    int X ,Y; //���������� �����
    static int counter;
public:
    Point(); //����������� ��� ����������
    Point(int x, int y); //����������� � �����������
    ~Point();
    void Init(int x, int y); //����� �������������
    int GetX(); //����� ��������� ���������� X
    int GetY(); //����� ��������� ���������� Y
    void Display(); //����� ������ ���������
    void PolarCoords(); //����� �������� � �������� ����������
    static double PerevodToGradus(double rad);
    static double PerevodToRadian(double grad);
    static int GetCount();
    Point& operator++();
    Point operator++(int); 
};

