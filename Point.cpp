#include "Point.h"
#include <iostream>
#define PI 3.14159265335
using namespace std;

int Point::counter = 0; //������������� �������� �����

Point::Point() { //����������� ��� ����������
    X = Y = 0;
	counter++;
}

Point::Point(int X, int Y) { //����������� � �����������
	this->X = X;
	this->Y = Y;
	counter++;
}

Point::~Point() { //����������
	counter--;
}

void Point::SetX(int X) { //����� ��������� �������� X
	this->X = X;
}

void Point::SetY(int Y) { //����� ��������� �������� Y
	this->Y = Y;
}

void Point::Read() { //����� �����
	bool correct = 0;
	int x, y;
	string strX, strY;
	string metka;
	while (!correct) {
		try {
			cout << "������� ���������� ����� (x, y): ";
			cin >> strX >> strY;
			x = stoi(strX);
			y = stoi(strY);
			correct = 1;
		}
		catch (invalid_argument& e) {
			cout << "������������ ��������! ��������� ����:" << endl;
		}
		cin.ignore(1024, '\n');
	}
	*this = Point(x, y);
}

int Point::GetX() { //����� ��������� ���������� X
    return X;
}

int Point::GetY() { //����� ��������� ���������� Y
	return Y;
}

void Point::PolarCoords() { //����� �������� � �������� ����������
	double r, f;
	r = sqrt(X * X + Y * Y);
	try {
		if (X == 0) throw 0;
		f = atan(Y / X);
		if (X > 0 && Y < 0)
			f += 2 * PI;
		if (X < 0)
			f += PI;
		f = Angle::PerevodToGradus(f);
	}
	catch (int) {
		if (Y > 0)
			f = Angle::PerevodToGradus(PI / 2);
		if (Y < 0)
			f = Angle::PerevodToGradus(3 * PI / 2);
		if (Y == 0)
			f = 0;
	}
	printf("�������� ����������: r=%.3lf f=%.1lf ����.\n", r, f);
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

ostream& operator<< (ostream& out, Point p) { //������������� �������� ������
	out << "(" << p.X << "," << p.Y << ")";
	return out;
}