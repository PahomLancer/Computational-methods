//3x-cos(x)-1=0 a, b, e
#include <stdafx.h>
#include <iostream>
#include "math.h"
int main()
{
    double fa, fb, fc;
    double a, b, c, e;
    int i = 0;
	printf("Function is 3x-cos(x)-1=0\n");
    printf("Input a (left): ");
    scanf("%lf", &a);
    printf("Input b (right): ");
    scanf("%lf", &b);
    printf("Input epsilon: ");
    scanf("%lf", &e);
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
	printf("Iterations = %d, c = %lf", i, c);
    return 0;
}