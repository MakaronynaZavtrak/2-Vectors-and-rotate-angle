#include <iostream>
#include <math.h>
#define _USE_MATH_DEFINES
#include <tgmath.h>
#include "Header.h"
#include <string>

double findLength(int a[]) {//функция нахождения длины вектора
	double ln = (sqrt(pow(*a, 2) + pow(*(a + 1), 2) + pow(*(a + 2), 2)));
	return ln;
};
int scalMultiplication(int a[], int b[]) {
	int scal = 0;
	for (int i = 0; i < 3; i++) {
		scal += a[i] * b[i];
	};
	return scal;
};
double getAngle(int vector1[], int  vector2[]) {//функция нахождения угла между двумя векторами
	double module1 = findLength(vector1);
	double module2 = findLength(vector2);
	int scalMult = scalMultiplication(vector1, vector2);
	double Cosinus = scalMult / (module1 * module2);
	double angle = (acos(Cosinus))*(180/M_PI);
	return angle;
};
int* findNormalVector(int a[], int b[]) {//функция нахождения нормального вектора согласно правилу правой тройки
	int A = a[1] * b[2] - b[1] * a[2];
	int B = -1 * (a[0] * b[2] - b[0] * a[2]);
	int C = a[0] * b[1] - b[0] * a[1];
	int* resultArr = new int[3] { A, B, C };
	if (mixedMultiplication(a, b, resultArr) > 0) {
		return resultArr;
	}
	else {
		for (int i = 0; i < 3; i++) {
			resultArr[i] *= -1;
		};
		return resultArr;
	};
};
int mixedMultiplication(int a[], int b[], int c[]) {//функция нахождения смешанного произведения векторов
	int result = a[0] * (b[1] * c[2] - c[1] * b[2]) - a[1] * (b[0] * c[2] - c[0] * b[2]) + a[2] * (b[0] * c[1] - c[0] * b[1]);
	return result;
};
double* getRotatedVector(int arr[], double rotateAngle)//функция нахождения координат повёрнутого вектора
{
	double new_x = arr[0] * cos(rotateAngle) - arr[2] * sin(rotateAngle);
	double new_z = arr[0] * sin(rotateAngle) + arr[2] * cos(rotateAngle);
	double* new_Vector = new double[3];
	new_Vector[0] = new_x;
	new_Vector[1] = arr[1];
	new_Vector[2] = new_z;
	return new_Vector;
};

void printVector(double arr[]) {
	for (int i = 0; i < 3; i++) {
		std::cout << arr[i] << " ";
	};
};
