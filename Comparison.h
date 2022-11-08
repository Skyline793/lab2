#pragma once
#include <iostream>
using namespace std;
template <typename T>
class Comparison
{
public:
	static T CompareSquare(T a, T b)
	{
		
		if (a.CalcSquare() > b.CalcSquare())
			return a;
		else
			return b;
	}
	static T ComparePerimeter(T a, T b)
	{
		if (a.CalcPerimeter() > b.CalcPerimeter())
			return a;
		else
			return b;
	}
};
