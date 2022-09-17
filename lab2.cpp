﻿// lab2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <Windows.h>
using namespace std;

typedef struct 
{
    int X, Y;
} TPoint;

typedef struct {
    TPoint coord;
} Vector;

void ReadVector(Vector* v) {
    printf("Введите координаты вектора (x, y): ");
    scanf("%d%d", &v->coord.X, &v->coord.Y);
    
}

void DisplayVector(Vector v) {
    printf("Вектор\nКоординаты: (%d,%d)\n", v.coord.X, v.coord.Y);
}

void InitVector(Vector* v, int x, int y) {
    v->coord.X = x;
    v->coord.Y = y;
}

double CalcVectLen(Vector v) {
    double len;
    len = sqrt(v.coord.X * v.coord.X + v.coord.Y * v.coord.Y);
    return len;
}

double CalcScalarProd(Vector v1, Vector v2) {
    double prod;
    prod = v1.coord.X * v2.coord.X + v1.coord.Y * v2.coord.Y;
    return prod;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251); 
  
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
