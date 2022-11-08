#pragma once
#include <string>
#include <iostream>
using namespace std;

class Figure { //абстрактный класс фигура
protected:
	static const string colors[]; //массив цветов фигуры
	int colorIndex; //индекс массива цветов 
public:
	Figure(); //конструктор 
	void SetColorIndex(int colorIndex); //метод установки индекса цвета
	virtual double CalcSquare() = 0; //чисто виртуальный метод вычисления площади
	virtual double CalcPerimeter() = 0; //чисто виртуальный метод вычисления периметра
};

