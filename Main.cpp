#include <iostream>
#include <string>
#include <math.h>
#include <tgmath.h>
#include "Header.h"
using namespace std;
int main()
{
	int a[3]{7,1,0};//инициализируем
	int b[3]{ 5,5,0};//два вектора
	double rotateDAngle = 45.3456;//угол, на который будем поворачивать
	double angleBetween = getAngle(a, b);//нахождения угла между двумя данными векторами
	cout << angleBetween << endl;
	int* norm = findNormalVector(a, b);//нахождение нормального вектора к плоскости, построенного векторами a и b, согласной правой тройке
	double* Rotate = getRotatedVector(a, rotateDAngle);//нахождение координат повернутого вектора
	printVector(Rotate);//вывод в консоль координат повернутого вектора
	return 0;
};
