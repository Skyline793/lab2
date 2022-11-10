#pragma once
#include <string>
#include <iostream>
using namespace std;

class Figure { //абстрактный класс фигура
protected:
	static const int N; //число цветов
	int colorIndex; //индекс массива цветов 
public:
	static const string colors[]; //массив цветов фигуры
	Figure(); //конструктор 
	void SetColorIndex(int colorIndex); //метод установки индекса цвета
	static void ShowColors(); //статический метод вывода списка цветов
	virtual double CalcSquare() = 0; //чисто виртуальный метод вычисления площади
	virtual double CalcPerimeter() = 0; //чисто виртуальный метод вычисления периметра
};

