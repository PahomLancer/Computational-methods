// metodSetok.cpp : Defines the entry point for the console application.
//10 variant
//y''+2x^2*y'+y=x
//2y(0,5)-y'(0,5)=1
//y(0,8)=3

#include "stdafx.h"
#include <iostream>
#include "math.h"
#include <conio.h>
#include <iostream>


int main()
{
	setlocale(LC_ALL, "Rus");
	//y''+p(x)y'-q(x)y=f(x), a<=x<=b, a0*y(a)+a1*y'(a)=A, b0*y(b)+b1*y'(b)=B
	//p(x) = 2x^2, q(x) = -1, f(x) = x, 0.5 <= x <= 0.8, A = 1, B = 3
	double a0 = 2, a1 = -1, b0 = 1, b1 = 0, a = 0.5, b = 0.8, A = 1, B = 3;
	double n = 30, h;
	h = (b - a) / n; //рассчет шага
	//y'(i) = (y(i+1)-y(i))/h;
	//y''(i) = (y(i+2)-2*y(i+1)+y(i))/h^2
	//y'(n) = (y(n-1)-y(n))/h; y(0)'=(y(1)-y(0))/h
	//(y(i+2)-2*y(i+1)+y(i))/h^2 + p(i)*(y(i+1)-y(i))/h + q(i)*y(i) = f(i); i = 0, 1, ..., n-2;
	//a0 y(0) + a1(y(1)-y(0))/h = A; b0*y(n) + b1(y(n)-y(n-1))/h = B
	//y(0,8)=3 -> b0 = 1, b1 = 0, y(30) = 3
	//metod progonki
	//y(i+2) + (-2+h*p(i))y(i+1) + (1-h*p(i)+h^2*q(i))*y(i) = f(i)*h^2
	//m(i) = -2 * h*p(i)
	//n(i) = 1 - h*p(i) + h^2*q(i)
	//y(i+1) = f(i)/m(i)*h^2 - n(i)/m(i)*y(i) - 1/m(i)*y(i+2)
	//y(i+1) = c(i)*(d(i) - y(i+2))
	//c0 = (a1 - a0*h)/(m0*(a1-a0*h) + n0*a1)
	//d0 = n0 * A *h/(a1-a0*h) + f0*h^2
	double *x = new double[n]; // Выделение памяти для массива x
	double *f = new double[n]; // Выделение памяти для массива функции f(x)
	double *q = new double[n]; // Выделение памяти для массива функции q(x)
	double *p = new double[n]; // Выделение памяти для массива функции p(x)
	double *ni = new double[n]; // Выделение памяти для массива функции ni(x)
	double *mi = new double[n]; // Выделение памяти для массива функции mi(x)
	double *c = new double[n]; // Выделение памяти для массива функции c(x)
	double *d = new double[n]; // Выделение памяти для массива функции d(x)
	double *y = new double[n]; // Выделение памяти для массива функции y(x)
	x[0] = a;
	f[0] = x[0];
	q[0] = -1;
	p[0] = 2 * x[0]*x[0];
	mi[0] = -2 * h*p[0];
	ni[0] = 1 - h*p[0] + h*h*q[0];
	c[0] = (a1 - a0*h)/(mi[0]*(a1 - a0*h) + ni[0]*a1);
	d[0] = ni[0]*A*h/(a1 - a0*h) + f[0]*h*h;
	for (int i = 1; i <= n; i++){
		x[i] = x[0] + i*h;
		f[i] = x[i];
		q[i] = -1;
		p[i] = 2*x[i]*x[i];
		mi[i] = -2 * h*p[i];
		ni[i] = 1 - h*p[i] + h*h*q[i];
		c[i] = 1 / (mi[i] - ni[i] * c[i - 1]);
		d[i] = f[i] * h*h - ni[i] * c[i - 1] * d[i - 1];
	}
	y[30] = (b1*c[28] * d[28] + B*h) / (b1*(1 + c[28]) + b0*h);
	for (int i = n-1; i >= 1; i--){
		y[i] = c[i - 1] * (d[i - 1] - y[i + 1]);
	}
	y[0] = (a1*y[1] - A*h) / (a1 - a0*h);
	printf("Метод сеток:\ny''+2x^2*y'+y=x\n{2y(0,5)-y'(0,5)=1\n{y(0,8)=3\n");
	for (int i = 1; i <= n; i++){
		printf("i=%d, x=%lf, y=%lf\n", i, x[i], y[i]);
	}
	return 0;
}

