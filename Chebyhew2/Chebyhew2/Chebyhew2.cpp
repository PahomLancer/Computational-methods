// Chebyhew.cpp : main project file.
//f(x)=3x-cos(x)-1=0 a, b, e
//f(x)'=sin(x)+3
//f(x)''=cos(x)
#include "stdafx.h"
#include <iostream>
#include "math.h"
using namespace System;

int main()
{
    double a, b, e;
	double x0, x1, fx0, fx0d1, fx0d2;
    int i = 0;
	printf("Function is 3x-cos(x)-1=0\n");
    printf("Input a (left): ");
    scanf("%lf", &a);
    printf("Input b (right): ");
    scanf("%lf", &b);
    printf("Input epsilon: ");
    scanf("%lf", &e);
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
	printf("Iterations = %d, c = %lf", i, x1);
    return 0;
}
