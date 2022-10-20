#pragma once
class Point
{
    int X ,Y; //координаты точки
    static int counter;
public:
    Point(); //конструктор без параметров
    Point(int x, int y); //конструктор с параметрами
    ~Point();
    void Init(int x, int y); //метод инициализации
    int GetX(); //метод получения координаты X
    int GetY(); //метод получения координаты Y
    void Display(); //Метод вывода координат
    void PolarCoords(); //метод перевода в полярные координаты
    static double PerevodToGradus(double rad);
    static double PerevodToRadian(double grad);
    static int GetCount();
    Point& operator++();
    Point operator++(int); 
};

