#include "Figure.h"
const string Figure::colors[5] = {"�� �����", "�������", "�����", "�������", "������"}; //������ ������

Figure::Figure()
{
	colorIndex = 0;
}

void Figure::SetColorIndex(int colorIndex)
{
	if (colorIndex < 0 || colorIndex >= Figure::colors->length()) throw invalid_argument("������ ����� ��� ���������");
	this->colorIndex = colorIndex;
}