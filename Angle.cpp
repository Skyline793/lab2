#include "Angle.h"

double Angle::PerevodToGradus(double rad) //����������� ����� �������� ������ � �������
{
	double grad = rad * 180 / PI;
	return grad;
}

double Angle::PerevodToRadian(double grad) //����������� ����� �������� �������� � �������
{
	double rad = grad * PI / 180;
	return rad;
}
