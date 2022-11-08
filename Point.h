#pragma once
#include "Angle.h"
#include <string>
using namespace std;

//класс точка
class Point
{
    static int counter; //счетчик количества точек
protected:
    int X ,Y; //координаты точки
    string metka; //метка для идентификации точки
public:
    Point(); //конструктор без параметров
    Point(int x, int y); //конструктор с параметрами
    Point(int x, int y, string metka); //конструктор с параметрами
    ~Point(); //деструктор
    void SetX(int X); //метод установки значения X
    void SetY(int Y); //метод установки значения Y
    void SetMetka(string metka); //метод установки значения идентификатора
    virtual void Read(); //виртуальный метод ввода
    int GetX(); //метод получения координаты X
    int GetY(); //метод получения координаты Y
    string GetMetka(); //метод получения идентификатора
    void PolarCoords(); //метод перевода в полярные координаты
    static int GetCount(); //статический метод получения счетчика
    Point& operator++(); //перегруженный оператор префиксного инкремента
    Point operator++(int); //перегруженный оператор постфиксного инкремента
    friend ostream& operator<< (ostream &out, Point p); //перегруженный оператор вывода
};

