﻿// lab2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>
#include <cmath>
#include "Point.h"
#include "Vector.h"
#include "Circle.h"
#include "Triangle.h"
#include "Parallelogram.h"
#include "Figure.h"
#include "Comparison.h"
#define PI 3.14159265335

using namespace std;



int main()
{
	
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Triangle t1(3, 1, 0, 3, -3, 6), t2(4, 1, 6, 1, -3, -4);
    Circle c1(3, 2, 3.5), c2(4, 1, 4.4);
    Parallelogram p1(3, 1, 5, 2), p2(1, -2, 3, -6);
    Vector v1(1, 3), v2(4, 5);
    t1.SetColorIndex(4);
    cout << t1;

    cout << Comparison<Triangle>::CompareSquare(t1, t2);
    cout << Comparison<Triangle>::ComparePerimeter(t1, t2);
    cout << Comparison<Circle>::CompareSquare(c1, c2);
    cout << Comparison<Circle>::ComparePerimeter(c1, c2);
    cout << Comparison<Parallelogram>::CompareSquare(p1, p2);
    cout << Comparison<Parallelogram>::ComparePerimeter(p1, p2);



   
    cin.get(); cin.get();
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
