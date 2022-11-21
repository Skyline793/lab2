#pragma once
#include <vector>
#include <algorithm>
#include <iostream>
#include "Figure.h"
#include "Circle.h"
#include "Triangle.h"
#include "Parallelogram.h"

using namespace std;

class FigureArray
{
	vector<Figure*> vect;
public:
	void Add(Figure* f);
	void Read();
	void Display();
	void Insert(Figure* f, int ind);
	void Delete(int ind);
	void SortByMaxSquare();
	void SortByMinSquare();
	void SortByMaxPerimeter();
	void SortByMinPerimeter();
	void FindColor(int colorIndex);

};

