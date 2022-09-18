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

void VectorInit(Vector* v, int x, int y) {
    v->coord.X = x;
    v->coord.Y = y;
}

void VectorRead(Vector* v) {
    printf("Введите координаты вектора (x, y): ");
    scanf("%d%d", &v->coord.X, &v->coord.Y);
    
}

void VectorDisplay(Vector v) {
    printf("Вектор с координатами: (%d,%d)\n", v.coord.X, v.coord.Y);
}


double VectCalcLen(Vector v) {
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

void CircleInit(Circle* c, int x, int y, int r) {
    c->center.X = x;
    c->center.Y = y;
    c->R = r;
}

void CircleRead(Circle* c) {
    printf("Введите координаты центра окружности (x, y): ");
    scanf("%d%d", &c->center.X, &c->center.Y);
    printf("Введите радиус окружности (R>0): ");
    scanf("%d", &c->R);
}

void CircleDisplay(Circle c) {
    printf("Окружность c центром: О(%d,%d) и радиусом R=%d\n", c.center.X, c.center.Y, c.R);
}

void CirclePrintEquation(Circle c) {
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

double CircleCalcSquare(Circle c) {
    double S;
    S = PI * c.R * c.R;
    return S;
}

typedef struct {
    TPoint A, B, C;
} Triangle;

void TriangleInit(Triangle* t, int x1, int y1, int x2, int y2, int x3, int y3 ) {
    t->A.X = x1;
    t->A.Y = y1;
    t->B.X = x2;
    t->B.Y = y2;
    t->C.X = x3;
    t->C.Y = y3;
}

void TriangleRead(Triangle* t) {
    printf("Введите координаты точки А треугольника (x1, y1): ");
    scanf("%d%d", &t->A.X, &t->A.Y);
    printf("Введите координаты точки B треугольника (x2, y2): ");
    scanf("%d%d", &t->B.X, &t->B.Y);
    printf("Введите координаты точки C треугольника (x3, y3): ");
    scanf("%d%d", &t->C.X, &t->C.Y);
}

void TriangleDisplay(Triangle t) {
    printf("Треугольник с вершинами А(%d,%d), B(%d,%d), C(%d,%d)\n", t.A.X, t.A.Y, t.B.X, t.B.Y, t.C.X, t.C.Y);

}

double TriangleCalcSquare(Triangle t) {
    int x1 = t.A.X, y1 = t.A.Y, x2 = t.B.X, y2 = t.B.Y, x3 = t.C.X, y3 = t.C.Y;
    double S;
    S = 0.5 * fabs((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1));
    return S;
}

double TriangleCalcPerimeter(Triangle t) {
    int x1 = t.A.X, y1 = t.A.Y, x2 = t.B.X, y2 = t.B.Y, x3 = t.C.X, y3 = t.C.Y;
    double AB = sqrt((x2 - x1) ^ (x2 - x1) + (y2 - y1) ^ (y2 - y1));
    double AC = sqrt((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1));
    double BC = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
    double P = AB + AC + BC;
    return P;
}

typedef struct {
    Vector a, b;
} Parallelogram;

void ParallelogramInit(Parallelogram* pr, int x1, int y1, int x2, int y2) {
    VectorInit(&pr->a, x1, y1);
    VectorInit(&pr->b, x2, y2);
}

void ParallelogramRead(Parallelogram* pr) {
    int x1, y1, x2, y2;
    printf("Введите координаты первого из векторов, на которых построен параллелограм (x1, y1): ");
    scanf("%d%d", &x1, &y1);
    printf("Введите координаты второго из векторов, на которых построен параллелограм (x1, y1): ");
    scanf("%d%d", &x2, &y2);
    ParallelogramInit(pr, x1, y1, x2, y2);
}

void ParallelogramDisplay(Parallelogram pr) {
    puts("Параллелограм, построенный на векторах a и b:");
    VectorDisplay(pr.a);
    VectorDisplay(pr.b);
}

double ParallelogramCalcSquare(Parallelogram pr) {
    double S, len_a, len_b, prod, cosinus, sinus;
    len_a = VectCalcLen(pr.a);
    len_b = VectCalcLen(pr.b);
    prod = CalcScalarProd(pr.a, pr.b);
    cosinus = prod / (len_a * len_b);
    sinus = sqrt(1 - cosinus * cosinus);
    S = len_a * len_b * sinus;
    return S;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    puts("Тест структуры вектор:");
    Vector* V1, * V2;
    V1 = (Vector*)calloc(1, sizeof(Vector));
    V2 = (Vector*)calloc(1, sizeof(Vector));
    puts("Ввод координат векторов:");
    VectorRead(V1);
    VectorRead(V2);
    puts("\nВывод координат векторов:");
    VectorDisplay(*V1);
    VectorDisplay(*V2);
    printf("\nМодуль вектора |V1|=%g\nМодуль вектора |V2|=%g\n", VectCalcLen(*V1), VectCalcLen(*V2));
    printf("Скалярное произведение (V1, V2)=%g\n", CalcScalarProd(*V1, *V2));
    free(V1);
    free(V2);

    puts("\n\nТест структуры окружность:");
    Circle krug;
    puts("\nИнициализация окружности:");
    CircleInit(&krug, 0, 0, 2);
    CircleDisplay(krug);
    puts("\nВвод данных окружности:");
    CircleRead(&krug);
    CircleDisplay(krug);
    puts("\nВывод уравнения окружности:");
    CirclePrintEquation(krug);
    printf("\nПлощадь круга S=%g\n", CircleCalcSquare(krug));

    puts("\n\nТест структуры треугольник:");
    Triangle* tr;
    tr = (Triangle*)calloc(1, sizeof(Triangle));
    puts("\nИнициализация треугольника:");
    TriangleInit(tr, 3, 4, 0, -2, -1, 6);
    TriangleDisplay(*tr);
    puts("\nВвод координат вершин треугольника:");
    TriangleRead(tr);
    TriangleDisplay(*tr);
    printf("\nПлощадь треугольника S=%g\nПериметр треугольникаP=%g", TriangleCalcSquare(*tr), TriangleCalcPerimeter(*tr));
    free(tr);
  
    puts("\n\nТест структуры параллелограм:");
    Parallelogram pr;
    puts("\nИнициализация параллелограма:");
    ParallelogramInit(&pr, 1, 4, 5, -3);
    ParallelogramDisplay(pr);
    puts("\nВвод координат векторов, на которых построен параллелограм:");
    ParallelogramRead(&pr);
    ParallelogramDisplay(pr);
    printf("\nПлощадь параллелограма S=%g", ParallelogramCalcSquare(pr));

    cin.get();

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
