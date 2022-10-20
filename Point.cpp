#include "Point.h"
#include <iostream>
#define PI 3.14159265335
using namespace std;

Point::Point() { //����������� ��� ����������
    X = Y = 0;
	counter++;
}

Point::Point(int X, int Y) { //����������� � �����������
	this->X = X;
	this->Y = Y;
	counter++;
}

Point::Point(int X, int Y, string metka) { //����������� � �����������
	this->X = X;
	this->Y = Y;
	this->metka = metka;
	counter++;
}


void Point::Init(int X, int Y) { //����� �������������
    this->X = X;
    this->Y = Y;
}

void Point::Read() { //����� �����
	int x, y;
	string metka;
	cout << "������� ���������� ����� (x, y): ";
	cin >> x >> y;
	cout << "������� ������������� ����� (Enter, ����� �� ��������� �������������): ";
	cin.ignore();
	getline(cin, metka);
	*this = Point(x, y, metka);
}

int Point::GetX() { //����� ��������� ���������� X
    return X;
}

int Point::GetY() { //����� ��������� ���������� Y
    return Y;
}

void Point::Display() { //����� ������ ���������
	if(metka.empty())
		cout << "(" << X << "," << Y << ")";
	else
		cout << metka << "(" << X << "," << Y << ")";

}

void Point::PolarCoords() { //����� �������� � �������� ����������
	double r, f;
	r = sqrt(X * X + Y * Y);
	if (X == 0) {
		if (Y > 0)
			f = PerevodToGradus(PI / 2);
		if (Y < 0)
			f = PerevodToGradus(3 * PI / 2);
		else f = 0;
	}
	else {
		f = atan((double)Y / X);
		if (X > 0 && Y < 0)
			f += 2 * PI;
		if (X < 0)
			f += PI;
		f = PerevodToGradus(f);
	}
	printf("�������� ����������: r=%.3lf f=%.1lf ����.\n", r, f);
}

double Point::PerevodToGradus(double rad) //����������� ����� �������� ������ � �������
{
	double grad = rad * 180 / PI;
	return grad;
}

double Point::PerevodToRadian(double grad) //����������� ����� �������� �������� � �������
{
	double rad = grad * PI / 180;
	return rad;
}

int Point::GetCount() //����������� ����� ��������� ��������
{
	return counter;
}

Point& Point::operator++() //������������� �������� ����������� ����������
{
	this->X++;
	this->Y++;
	return *this;
}

Point Point::operator++(int) //������������� �������� ������������ ����������
{
	Point tmp = *this;
	++(*this);
	return tmp;
}