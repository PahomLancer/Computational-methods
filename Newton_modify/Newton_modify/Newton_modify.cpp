//f(x)=3x-cos(x)-1=0 a, b, e
//f(x)'=sin(x)+3
//f(x)''=cos(x)
#include "stdafx.h"
#include <iostream>
#include "math.h"
using namespace System;

int main()
{
    double fa, fc, fad2, fcd1;
    double a, b, c, e;
    int i = 0;
	printf("Function is 3x-cos(x)-1=0\n");
    printf("Input a (left): ");
    scanf("%lf", &a);
    printf("Input b (right): ");
    scanf("%lf", &b);
    printf("Input epsilon: ");
    scanf("%lf", &e);
	fa = 3*a - cos(a) - 1;
	fad2 = sin(a) + 3;
	fcd1 = sin(c) + 3;
	if (fa*fad2>0)
            c = a;
        else
            c = b;
	fc = 3*c - cos(c) - 1;
    while (abs(fc) > e)
    {
        i++;
		fc = 3*c - cos(c) - 1;
		//fcd1 = sin(c) + 3;
		c = c - fc/fcd1;
    }
    printf("Newton modify\n");
	printf("Iterations = %d, c = %lf", i, c);
    return 0;
}
