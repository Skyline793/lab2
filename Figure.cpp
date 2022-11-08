#include "Figure.h"
const string Figure::colors[5] = {"не задан", "красный", "синий", "зеленый", "желтый"}; //массив цветов

Figure::Figure()
{
	colorIndex = 0;
}

void Figure::SetColorIndex(int colorIndex)
{
	if (colorIndex < 0 || colorIndex >= Figure::colors->length()) throw invalid_argument("Индекс цвета вне диапазона");
	this->colorIndex = colorIndex;
}