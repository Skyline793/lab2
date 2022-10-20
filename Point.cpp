#include "Point.h"
#include <iostream>
#define PI 3.14159265335
using namespace std;

Point::Point() { //конструктор без параметров
    X = Y = 0;
	counter++;
}

Point::Point(int X, int Y) { //конструктор с параметрами
	this->X = X;
	this->Y = Y;
	counter++;
}

Point::Point(int X, int Y, string metka) { //конструктор с параметрами
	this->X = X;
	this->Y = Y;
	this->metka = metka;
	counter++;
}


void Point::Init(int X, int Y) { //метод инициализации
    this->X = X;
    this->Y = Y;
}

void Point::Read() { //метод ввода
	int x, y;
	string metka;
	cout << "Введите координаты точки (x, y): ";
	cin >> x >> y;
	cout << "Введите идентификатор точки (Enter, чтобы не создавать идентификатор): ";
	cin.ignore();
	getline(cin, metka);
	*this = Point(x, y, metka);
}

int Point::GetX() { //метод получения координаты X
    return X;
}

int Point::GetY() { //метод получения координаты Y
    return Y;
}

void Point::Display() { //Метод вывода координат
	if(metka.empty())
		cout << "(" << X << "," << Y << ")";
	else
		cout << metka << "(" << X << "," << Y << ")";

}

void Point::PolarCoords() { //метод перевода в полярные координаты
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
	printf("Полярные координаты: r=%.3lf f=%.1lf град.\n", r, f);
}

double Point::PerevodToGradus(double rad) //статический метод перевода радиан в градусы
{
	double grad = rad * 180 / PI;
	return grad;
}

double Point::PerevodToRadian(double grad) //статический метод перевода градусов в радианы
{
	double rad = grad * PI / 180;
	return rad;
}

int Point::GetCount() //статический метод получения счетчика
{
	return counter;
}

Point& Point::operator++() //перегруженный оператор префиксного инкремента
{
	this->X++;
	this->Y++;
	return *this;
}

Point Point::operator++(int) //перегруженный оператор постфиксного инкремента
{
	Point tmp = *this;
	++(*this);
	return tmp;
}