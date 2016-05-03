// Coshi.cpp : Defines the entry point for the console application.
//1 variant
//y'=e^x*y^2 - 2*y; y(0)=1/2; x=[0,2];
//h=0.1; yт=e^-2x/(1+e^-x)
#include "stdafx.h"
#include <iostream>
#include "math.h"

//Функция f(x,y)
double funcd(double x, double y)
{
	double e = 2.7182;
	e = pow(e, x)*pow(y, 2) - 2 * y;
	return (e);
}
//Функция для расчета погрешости
double funct(double x)
{
	double e = 2.7182;
	e = pow(e, -2 * x) / (1 + pow(e, -x));
	return (e);
}

int main()
{
	//Эйлер
	//y'=f(x,y); y(a)=y0; x=[a,b];
	//h=(b-a)/n; xk=x0+kh (k=0,1,...,n); yk=y(xk); x0=a;
	//yk+1=yk+hf(xk,yk) k = 0,1,...,n-1 y(x0)=y0
	double a = 0, b = 2, h = 0.1;
	int n = (b - a) / h;
	//n = 20
	double *x = new double[n + 1]; // Выделение памяти для массива
	double *r = new double[n + 1]; // Выделение памяти для массива
	double *y = new double[n + 1]; // Выделение памяти для массива
	//Расчет x
	x[0] = 0;
	for (int i = 1; i < n + 1; i++){
		x[i] = x[0] + i*h;
	}
	//Расчет погрешности r
	for (int i = 0; i < n; i++){
		r[i] = 0.5*h*h*funct(x[i]);
	}
	//Расчет y
	y[0] = 0.5;
	for (int i = 1; i < n; i++){
		y[i] = y[i - 1] + h*funcd(x[i - 1], y[i - 1]);
	}
	for (int i = 0; i < n; i++){
		printf("i=%d, x=%lf, r=%lf, y=%lf\n", i, x[i], r[i], y[i]);
	}
	delete[] x; //Удаление массива
	delete[] r; //Удаление массива
	delete[] y;	//Удаление массива
	return 0;
}