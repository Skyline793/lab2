#pragma once
#include "Point.h"

//класс треугольник
class Triangle { 
    Point A, B, C; //вершины треугольника
public:
    Triangle(); //конструктор без параметров
    Triangle(int x1, int y1, int x2, int y2, int x3, int y3); //конструктор с параметрами 
    void Init(int x1, int y1, int x2, int y2, int x3, int y3); //метод инициализации
    void Read(); //метод ввода
    void Display(); //метод вывода
    double CalcSquare(); //метод вычисления площади
    double CalcPerimeter(); //метод вычисления периметра
};

