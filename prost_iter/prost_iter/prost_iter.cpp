// prost_iter.cpp : main project file.
//3x-cos(x)-1=0 a, b, e
//3 + sin(x) = 0
#include "stdafx.h"
#include <iostream>
#include "math.h"
using namespace System;

int main()
{
    double a, b, x0, x1, e;
    int i = 1;
	printf("Function is 3x-cos(x)-1=0\n");
    printf("Input a (left): ");
    scanf("%lf", &a);
    printf("Input b (right): ");
    scanf("%lf", &b);
    printf("Input epsilon: ");
    scanf("%lf", &e);
	x0 = b;
	x1 = 3*x0 - cos(x0) - 1;
    while (abs(x0 - x1) > e)
    {
        i++;
        x0 = x1;
		x1 = 3*x0 - cos(x0) - 1;
    }
    printf("Prost_iter\n");
	printf("Iterations = %d, c = %lf", i, x1);
    return 0;
}