// lab2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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
#include "FigureArray.h"
#include <vector>
#include <algorithm>
#define PI 3.14159265335

using namespace std;

bool cond(Figure* f1, Figure* f2)
{
    if (f1->CalcSquare() < f2->CalcSquare())
        return 1;
    else return 0;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    FigureArray arr, newArr;
    //добавление фигур
    arr.Add(new Circle(0,0,1,0));
    arr.Add(new Circle(2,1,2.3,3));
    arr.Add(new Triangle(-4,3, 0, -2, 3,5, 1));
    arr.Add(new Parallelogram(5, 4, 1, -6, 1));
    arr.Add(new Parallelogram(-3, 5, 1, -4, 2));
    //ввод фигуры
    arr.Read();
    //вывод фигуры
    arr.Display();
    cout << endl;
    //сортировка по возрастанию площади
    cout << "сортировка по возрастанию площади" << endl;
    arr.SortByMaxSquare();
    arr.Display();
    cout << endl;
    //сортировка по убыванию площади
    cout << "сортировка по убыванию площади" << endl;
    arr.SortByMinSquare();
    arr.Display();
    cout << endl;
    //сортировка по возрастанию периметра
    cout << "сортировка по возрастанию периметра" << endl;
    arr.SortByMaxPerimeter();
    arr.Display();
    cout << endl;
    //сортировка по убыванию периметра
    cout << "сортировка по убыванию периметра" << endl;
    arr.SortByMinPerimeter();
    arr.Display();
    cout << endl;
    //вывод фигур красного цвета
    cout << "вывод фигур красного цвета" << endl;
    arr.DisplayColorFigures(1);
    cout << endl;
    //получение массива фигур без цвета
    cout << "получение массива фигур без цвета" << endl;
    newArr = arr.GetColorFigures(0);
    newArr.Display();
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
