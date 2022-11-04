#include "Point.h"
#include <iostream>
#define PI 3.14159265335
using namespace std;

int Point::counter = 0; //инициализаци€ счетчика точек

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

Point::~Point() { //деструктор
	counter--;
}

void Point::SetX(int X) { //метод установки значени€ X
	this->X = X;
}

void Point::SetY(int Y) { //метод установки значени€ Y
	this->Y = Y;
}

void Point::SetMetka(string metka) { //метод установки значени€ идентификатора
	this->metka = metka;
}

void Point::Read() { //метод ввода
	bool correct = 0;
	int x, y;
	string strX, strY;
	string metka;
	while (!correct) {
		try {
			cout << "¬ведите координаты точки (x, y): ";
			cin >> strX >> strY;
			x = stoi(strX);
			y = stoi(strY);
			correct = 1;
		}
		catch (invalid_argument& e) {
			cout << "Ќекорректное значение! ѕовторите ввод:" << endl;
		}
		cin.ignore(1024, '\n');
	}
	cout << "¬ведите идентификатор точки (Enter, чтобы не создавать идентификатор): ";
	getline(cin, metka);
	*this = Point(x, y, metka);
}

int Point::GetX() { //метод получени€ координаты X
    return X;
}

int Point::GetY() { //метод получени€ координаты Y
    return Y;
}

string Point::GetMetka() { //метод получени€ идентификатора
	return metka;
}

void Point::PolarCoords() { //метод перевода в пол€рные координаты
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
	printf("ѕол€рные координаты: r=%.3lf f=%.1lf град.\n", r, f);
}

int Point::GetCount() //статический метод получени€ счетчика
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

ostream& operator<< (ostream& out, Point p) { //перегруженный оператор вывода
	out << p.metka << "(" << p.X << "," << p.Y << ")";
	return out;
}