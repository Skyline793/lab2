#pragma once
class Point
{
    int X, Y; //координаты точки
public:
    Point(); //конструктор без параметров
    Point(int x, int y); //конструктор с параметрами
    void Init(int x, int y); //метод инициализации
    int GetX(); //метод получения координаты X
    int GetY(); //метод получения координаты Y
    void Display(); //Метод вывода координат
};

