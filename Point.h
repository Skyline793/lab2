#pragma once
class Point
{
    int X, Y; //���������� �����
public:
    Point(); //����������� ��� ����������
    Point(int x, int y); //����������� � �����������
    void Init(int x, int y); //����� �������������
    int GetX(); //����� ��������� ���������� X
    int GetY(); //����� ��������� ���������� Y
    void Display(); //����� ������ ���������
};

