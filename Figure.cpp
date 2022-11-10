#include "Figure.h"
const int Figure::N = 5;
const string Figure::colors[N] = {"�� �����", "�������", "�����", "�������", "������"}; //������ ������

Figure::Figure()
{
	colorIndex = 0;
}

void Figure::SetColorIndex(int colorIndex)
{
	if (colorIndex < 0 || colorIndex >= N) throw invalid_argument("������ ����� ��� ���������");
	this->colorIndex = colorIndex;
}

void Figure::ShowColors() //����������� ����� ������ ������ ������
{
	for (int i = 0; i < N; i++)
		cout << i << " - " << colors[i] << endl;
}