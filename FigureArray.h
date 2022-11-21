#pragma once
#include <vector>
#include <algorithm>
#include <iostream>
#include "Figure.h"
#include "Circle.h"
#include "Triangle.h"
#include "Parallelogram.h"

using namespace std;

class FigureArray //класс массив фигур
{
	vector<Figure*> vect; //вектор фигур
public:
	void Add(Figure* f); //метод добавления фигуры
	void Read(); //метод добавления фигуры с вводом через консоль
	void Display(); //метод вывода объектов вектора
	void Insert(Figure* f, int ind); //метод вставки объекта на определнное место
	void Delete(int ind); //метод удаления объекта из вектора
	void SortByMaxSquare(); //метод сортировки по возрастанию площади фигур
	void SortByMinSquare(); //метод сортировки по убыванию площади фигур
	void SortByMaxPerimeter(); //метод сортировки по возрастанию периметра фигур
	void SortByMinPerimeter(); //метод сортировки по убыванию периметра фигур
	void DisplayColorFigures(int colorIndex); //метод поиска фигур определенного цвета
	FigureArray GetColorFigures(int colorIndex); //метод создания массива фигур определенного цвета

};

