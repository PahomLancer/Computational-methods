// Coshi.cpp : Defines the entry point for the console application.
//1 variant
//y'=e^x*y^2 - 2*y; y(0)=1/2; x=[0,2];
//h=0.1; yт=e^-2x/(1+e^-x)
#include "stdafx.h"
#include <iostream>
#include "math.h"
#include <conio.h>
#include <iostream>

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
	setlocale(LC_ALL, "Rus");
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
	double *yt = new double[n + 1]; // Выделение памяти для массива
	//Расчет x
	x[0] = 0;
	for (int i = 1; i <= n + 1; i++){
		x[i] = x[0] + i*h;
	}
	for (int i = 0; i <= n + 1; i++){
		yt[i] = funct(x[i]);
	}
	//Расчет погрешности r
	//for (int i = 0; i <= n; i++){
	//	r[i] = 0.5*h*h*funct(x[i]);
	//}
	//Расчет y
	y[0] = 0.5;
	for (int i = 1; i <= n; i++){
		y[i] = y[i - 1] + h*funcd(x[i - 1], y[i - 1]);
	}
	printf("Метод Эйлера:\ndy = e^x*y^2 - 2*y\ny(0)=1/2; x=[0,2]; h = 0.1; n = 20;\n");
	for (int i = 0; i <= n; i++){
		printf("i=%d, x=%lf, yt=%lf, y=%lf, r=%lf\n", i, x[i], yt[i], y[i], abs(yt[i] - y[i]));
	}
	//delete[] x; //Удаление массива
	//delete[] r; //Удаление массива
	//delete[] y;	//Удаление массива
	//Рунге-Кутт
	//y(x+h)=y(x)+pi*ki i=(1,q)
	//k1 = h f(x,y)
	//k2 = h f(x+a2h, y+b21k1)
	//ki = h f(x+aih, y+bi1k1+...+bii-1ki-1) i = 1,...,q
	//q = 1           q = 2
	//yi+1=yi+k1		yi+1=yi+1/2(k1+k2)
	//k1=h f(xi,yi)		k1 = h f(xi,yi) k2 = h f(xi+h, yi+h)
	//y0=y(x0)			y0=y(x0)
	//xi=a+ih0 i=1,..,n h0=(b-a)/n x=xi
	float k1, k2, k3, k4;
	for (int i = 0; i<n; ++i)
	{
		k1 = h * funcd(x[i], y[i]);
		k2 = h * funcd(x[i] + h, y[i] + k1);
		y[i + 1] = y[i] + 0.5*(k1 + k2);
	}
	printf("Метод Рунге-Кутта 2-порядка:\ndy = e^x*y^2 - 2*y\ny(0)=1/2; x=[0,2]; h = 0.1; n = 20;\n");
	for (int i = 0; i <= n; i++){
		printf("i=%d, x=%lf, yt=%lf, y=%lf, r=%lf\n", i, x[i], yt[i], y[i], abs(yt[i] - y[i]));
	}
	for (int i = 0; i<=n; ++i)
	{
		k1 = h * funcd(x[i], y[i]);
		k2 = h * funcd(x[i] + h / 2, y[i] + k1 / 2);
		k3 = h * funcd(x[i] + h / 2, y[i] + k2 / 2);
		k4 = h * funcd(x[i] + h, y[i] + k3);
		y[i + 1] = y[i] + 0.16666*(k1 + 2 * k2 + 2 * k3 + k4);
	}
	printf("Метод Рунге-Кутта 4-порядка:\ndy = e^x*y^2 - 2*y\ny(0)=1/2; x=[0,2]; h = 0.1; n = 20;\n");
	for (int i = 0; i <= n; i++){
		printf("i=%d, x=%lf, yt=%lf, y=%lf, r=%lf\n", i, x[i], yt[i], y[i], abs(yt[i]-y[i]));
	}
	//delete[] x; //Удаление массива
	//delete[] r; //Удаление массива
	//delete[] y;	//Удаление массива
	//Метод Милна
	for (int i = 4; i <= n; i++){
		y[i] = y[i - 4] + 4 * h / 3 * (2 * funcd(x[i - 3], y[i - 3]) - funcd(x[i - 2], y[i - 2]) + 2 * funcd(x[i - 1], y[i - 1]));
		//y[i] = y[i - 2] + 4 * h / 3 * (funcd(x[i - 2], y[i - 2]) - 4 * funcd(x[i - 1], y[i - 1]) + funcd(x[i], y[i]));
	}
	printf("Метод Милна:\ndy = e^x*y^2 - 2*y\ny(0)=1/2; x=[0,2]; h = 0.1; n = 20;\n");
	for (int i = 0; i <= n; i++){
		printf("i=%d, x=%lf, yt=%lf, y=%lf, r=%lf\n", i, x[i], yt[i], y[i], abs(yt[i] - y[i]));
	}
	return 0;
}