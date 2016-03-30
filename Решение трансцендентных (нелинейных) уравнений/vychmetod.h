//f(x)=3x-cos(x)-1=0 a, b, e
//f(x) = 1 + cos(x)
//f(x)'=1/3 sin(x)
//f(x)''=1/3 cos(x)
#include "stdafx.h"
#include <iostream>
#include "math.h"
using namespace System;

int main()
{
    double fa, fb, fc, fad2, fcd1;
	double x0, x1, fx0, fx0d1, fx0d2;
    double a, b, c = 0, q, e;
    int i = 0;
	//Reading 
	printf("Function is 3x-cos(x)-1=0\n");
	//Left border
    printf("Input a (left): ");
    scanf("%lf", &a);
	//Right border
    printf("Input b (right): ");
    scanf("%lf", &b);
	//Tochnost
    printf("Input epsilon: ");
    scanf("%lf", &e);
	
	//Newton
	fa = 3*a - cos(a) - 1;
	fad2 = cos(a);
	if (fa*fad2>0)
            c = a;
        else
            c = b;
	fc = 3*c - cos(c) - 1;
    while (abs(fc) > e)
    {
        i++;
		fc = 3*c - cos(c) - 1;
		fcd1 = sin(c) + 3;
		c = c - fc/fcd1;
    }
    printf("Newton\n");
	printf("Iterations = %d, c = %lf\n", i, c);
	
	//Operators reset
	i = 0;
	c = 0;
	
	//Newton modify
	fa = 3*a - cos(a) - 1;
	fad2 = sin(a) + 3;
	if (fa*fad2>0)
            c = a;
        else
            c = b;
	fcd1 = sin(c) + 3;
	fc = 3*c - cos(c) - 1;
    while (abs(fc) > e)
    {
        i++;
		fc = 3*c - cos(c) - 1;
		c = c - fc/fcd1;
    }
    printf("Newton modify\n");
	printf("Iterations = %d, c = %lf\n", i, c);
	
	//Operators reset
	i = 0;
	c = 0;
	
	//Chebyhew
	x0 = a;
	fx0 = 3*x0 - cos(x0) - 1;
	fx0d1 = sin(x0) + 3;
	fx0d2 = cos(x0);
	x1 = x0 - fx0/fx0d1 - (fx0d2*fx0*fx0)/(2*fx0d1*fx0d1*fx0d1);
    while (abs(x0-x1) > e)
    {
        i++;
		x0 = x1;
		fx0 = 3*x0 - cos(x0) - 1;
		fx0d1 = sin(x0) + 3;
		fx0d2 = cos(x0);
		x1 = x0 - fx0/fx0d1 - (fx0d2*fx0*fx0)/(2*fx0d1*fx0d1*fx0d1);
    }
    printf("Chebyhew\n");
	printf("Iterations = %d, c = %lf\n", i, x1);
	
	//Operators reset
	i = 1;
	c = 0;
	
	//Prost_iter
	x0 = a;
	x1 = 0.333 + cos(x0)/3;
	x0 = x1;
	x1 = 0.333 + cos(x0)/3;
	q = 0.333;
	q = (1-q)/q;
    while (abs(x1 - x0) > q*e)
    {
        i++;
		x0 = x1;
		x1 = 0.333 + cos(x0)/3;
    }
    printf("Prost_iter\n");
	printf("Iterations = %d, c = %lf\n", i, x1);
	
	//Operators reset
	i = 0;
	c = 0;
	
	//Metod hord
	fa = 3*a - cos(a) - 1;
    fb = 3*b - cos(b) - 1;
    c = a - fa/(fb - fa)*(b - a); //center c = a - (f(a)/(f(b)-f(a))*(b-a))
    fc = 3*c - cos(c) - 1;
    while (abs(fc) > e)
    {
        i++;
        if (fa*fc>0)
            a = c;
        else
            b = c;
		fa = 3*a - cos(a) - 1;
		fb = 3*b - cos(b) - 1;
		c = a - fa/(fb - fa)*(b - a);
		fc = 3*c - cos(c) - 1;
    }
    printf("Hord\n");
	printf("Iterations = %d, c = %lf\n", i, c);
	
	//Operators reset
	i = 0;
	c = 0;
	
	//Dihot
	c = (b+a)/2; //center
    fa = 3*a-cos(a)-1;
    fb = 3*b-cos(b)-1;
    fc = 3*c-cos(c)-1;
    while (abs(fc) > e)
    {
        i++;
        if (fa*fc>0)
            a = c;
        else
            b = c;
		c = (b+a)/2;
        fa = 3*a-cos(a)-1;
		fb = 3*b-cos(b)-1;
		fc = 3*c-cos(c)-1;
    }
    printf("Dihotom\n");
	printf("Iterations = %d, c = %lf\n", i, c);
	return 0;
}