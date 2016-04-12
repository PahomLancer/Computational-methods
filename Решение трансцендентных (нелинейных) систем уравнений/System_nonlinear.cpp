// System_nonlinear.cpp : Defines the entry point for the console application.
//10 variant
//f1 (sin y + 2x - 2 = 0} 
//f2 {cos(x-1) + y - 0.7 = 0} 

#include "stdafx.h"
#include <iostream>
#include "math.h"

int main()
{
	double x0, y0, x1, y1, q1, q2;
	double a, b, c, d, e, q;
	double fc, fcd2, fqd1, fq;
	int i = 0, i2;
	//Reading 
	printf("Function is f1 {sin y + 2x - 2 = 0} f2 {cos(x-1) + y - 0.7 = 0}\n");
	//Left border f1
	printf("Input a (left f1): ");
	scanf_s("%lf", &a);
	//Right border f1
	printf("Input b (right f1): ");
	scanf_s("%lf", &b);
	//Left border f2
	printf("Input c (left f2): ");
	scanf_s("%lf", &c);
	//Right border f2
	printf("Input d (right f2): ");
	scanf_s("%lf", &d);
	//Tochnost
	printf("Input epsilon: ");
	scanf_s("%lf", &e);

	//prost iter
	//x = -1/2 sin y + 0.5 f1
	//y = -cos(x-1) + 0.7 f2
	//f1'(x) = (x*y*sec(x*y)*sec(x*y)-tan(x*y))/(x*x)
	//f1'(y) = sec(x*y)*sec(x*y)
	//f2'(x) = 0.8*x/y
	//f2'(y) = (0.5 - 0.4*x*x)/(y*y)
	//|(x*y*sec(x*y)*sec(x*y)-tan(x*y))/(x*x)| + |0.8*x/y| <= q1 < 1
	//|sec(x*y)*sec(x*y)| + |(0.5 - 0.4*x*x)/(y*y)| <= q2 < 1
	x0 = a;
	y0 = c;
	y1 = -cos(x0 - 1) + 0.7;
	x1 = -0.5 * sin(y0) + 0.5;
	while ((abs(x1 - x0) > e) && (abs(y1 - y0) > e))
	{
		i++;
		x0 = x1;
		y0 = y1;
		y1 = -cos(x0 - 1) + 0.7;
		x1 = -0.5 * sin(y0) + 0.5;
	}
	printf("Prost_iter\n");
	printf("Iterations = %d, x = %lf, y = %lf\n", i, x1, y1);
	//metod Newtona
	//f1 (sin y + 2x - 2 = 0} 
	//f2 {cos(x-1) + y - 0.7 = 0} 
	//f1(teylor) = 2*x0 - 2 + (x-x0)*2 = 2x - 2
	//f2(teylor) = y0 - 0.7 + (y-y0) = y - 0.7
	//f1(x0, y0) = sin y0 + 2x0 - 2 + (x-x0)*2 + (y-y0)*cos(y0) = sin y0 + 2x - 2 + ycos y0 - y0 cos y0
	//f2(x0, y0) = cos(x0 - 1) + y0 - 0.7
	//f x = 1 - 1/2 sin y; cos(-1/2 sin y) + y - 0.7 = 0
	//f' 1 - 1/2 * sin(sin(y)/2)*cos(y)
	//f'' 1/2*sin(y)*sin(sin(y)/2)-1/4*cos(y)*cos(y)*cos(sin y/2)
	i2 = i;
	i = 0;
	fc = cos (-0.5*sin(c)) + c - 0.7;
	fcd2 = 0.5*sin(c)*sin(sin(c)/2) - 0.25*cos(c)*cos(c)*cos(sin(c)/2);
	if (fc*fcd2>0)
		q = c;
	else
		q = d;
	fq = cos(-0.5*sin(q)) + q - 0.7;
	while (abs(fq) > e)
	{
		i++;
		fq = cos(-0.5*sin(q)) + q - 0.7;
		fqd1 = 1 - 0.5*sin(sin(q)/2)*cos(q);
		q = q - fq/fqd1;
	}
	while (abs(fq) > e)
	{
		i++;
		fc = cos(-0.5*sin(q)) + c - 0.7;
		fcd2 = 1 - 0.5*sin(sin(q) / 2)*cos(q);
		q = q - fq / fqd1;
	}
	printf("Newton\n");
	printf("Iterations = %d, x = %lf, y = %lf\n", i2 - i, x1, y1);
	printf("Proverka\n");
	//f1 (sin y + 2x - 2 = 0} 
	//f2 {cos(x-1) + y - 0.7 = 0} 
	printf("f1 = %lf, f2 = %lf\n", sin(y1) + 2*x1 - 2, cos(x1-1) + y1 - 0.7);
	return 0;
}

