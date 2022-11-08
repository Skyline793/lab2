#pragma once
#include <iostream>
using namespace std;

//Шаблон класса для сравнения параметров фигур
template <typename T> 
class Comparison
{
public:
	static T CompareSquare(T a, T b) //сравнение площадей
	{
		
		if (a.CalcSquare() > b.CalcSquare())
			return a;
		else
			return b;
	}
	static T ComparePerimeter(T a, T b) //сравнение периметров
	{
		if (a.CalcPerimeter() > b.CalcPerimeter())
			return a;
		else
			return b;
	}
};
