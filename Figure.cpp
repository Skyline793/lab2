#include "Figure.h"
const int Figure::N = 5;
const string Figure::colors[N] = {"не задан", "красный", "синий", "зеленый", "желтый"}; //массив цветов

Figure::Figure()
{
	colorIndex = 0;
}

void Figure::SetColorIndex(int colorIndex)
{
	if (colorIndex < 0 || colorIndex >= N) throw invalid_argument("Индекс цвета вне диапазона");
	this->colorIndex = colorIndex;
}

void Figure::ShowColors() //статический метод вывода списка цветов
{
	for (int i = 0; i < N; i++)
		cout << i << " - " << colors[i] << endl;
}