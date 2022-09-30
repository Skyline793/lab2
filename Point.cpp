#include "Point.h"
#include <iostream>
using std::cout;

Point::Point() { //����������� ��� ����������
    X = Y = 0;
}

Point::Point(int x, int y) { //����������� � �����������
    this->X = x;
    this->Y = y;
}

void Point::Init(int x, int y) { //����� �������������
    this->X = x;
    this->Y = y;
}

int Point::GetX() { //����� ��������� ���������� X
    return this->X;
}

int Point::GetY() { //����� ��������� ���������� Y
    return this->Y;
}

void Point::Display() { //����� ������ ���������
    cout << "(" << X << "," << Y << ")";
}
