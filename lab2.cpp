// lab2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <Windows.h>
#define PI 3.14159265335
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

typedef struct {
    TPoint center;
    int R;
} Circle;

void InitCircle(Circle* c, int x, int y, int r) {
    c->center.X = x;
    c->center.Y = y;
    c->R = r;
}

void ReadCircle(Circle* c) {
    printf("Введите координаты центра окружности (x, y): ");
    scanf("%d%d", &c->center.X, &c->center.Y);
    printf("Введите радиус окружности (R>0): ");
    scanf("%d", &c->R);
}

void DisplayCircle(Circle c) {
    printf("Окружность\nКоординаты центра: (%d,%d)\nРадиус R=%d\n", c.center.X, c.center.Y, c.R);
}

void PrintCircleEquation(Circle c) {
    puts("Уравнение окружности:");
    if (c.center.X > 0) {
        if (c.center.Y > 0)
            printf("(x-%d)^2+(y-%d)^2=%d\n", c.center.X, c.center.Y, c.R * c.R);
        if (c.center.Y < 0)
            printf("(x-%d)^2+(y+%d)^2=%d\n", c.center.X, -c.center.Y, c.R * c.R);
        if (c.center.Y == 0)
            printf("(x-%d)^2+y^2=%d\n", c.center.X, c.R * c.R);
    }
    if (c.center.X < 0) {
        if (c.center.Y > 0)
            printf("(x+%d)^2+(y-%d)^2=%d\n", -c.center.X, c.center.Y, c.R * c.R);
        if (c.center.Y < 0)
            printf("(x+%d)^2+(y+%d)^2=%d\n", -c.center.X, -c.center.Y, c.R * c.R);
        if (c.center.Y == 0)
            printf("(x+%d)^2+y^2=%d\n", -c.center.X, c.R * c.R);
    }
    if (c.center.X == 0) {
        if (c.center.Y > 0)
            printf("x^2+(y-%d)^2=%d\n", c.center.Y, c.R * c.R);
        if (c.center.Y < 0)
            printf("x^2+(y+%d)^2=%d\n", -c.center.Y, c.R * c.R);
        if (c.center.Y == 0)
            printf("x^2+y^2=%d\n", c.R * c.R);
    }
}

double CalcCircleSquare(Circle c) {
    double S;
    S = PI * c.R * c.R;
    return S;
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
