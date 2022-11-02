#pragma once
#include "Angle.h"
#include <string>
using std::string;

//класс точка
class Point
{
    string metka; //метка для идентификации точки
    int X ,Y; //координаты точки
    static int counter; //счетчик количества точек
public:
    Point(); //конструктор без параметров
    Point(int x, int y); //конструктор с параметрами
    Point(int x, int y, string metka); //конструктор с параметрами
    ~Point(); //деструктор
    void Init(int x, int y); //метод инициализации
    void Read(); //метод ввода
    int GetX(); //метод получения координаты X
    int GetY(); //метод получения координаты Y
    void Display(); //Метод вывода координат
    void PolarCoords(); //метод перевода в полярные координаты
    static int GetCount(); //статический метод получения счетчика
    Point& operator++(); //перегруженный оператор префиксного инкремента
    Point operator++(int); //перегруженный оператор постфиксного инкремента
};

