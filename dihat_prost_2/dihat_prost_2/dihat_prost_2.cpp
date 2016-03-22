//3x-cos(x)-1=0 a, b, e
#include <stdafx.h>
#include <iostream>
#include "math.h"
int main()
{
    double fa, fb, fc;
    double a, b, c, e;
    int i = 0;
	printf("Function is x^3-x-3=0\n");
    printf("Input a (left): ");
    scanf("%lf", &a);
    printf("Input b (right): ");
    scanf("%lf", &b);
    printf("Input epsilon: ");
    scanf("%lf", &e);
    c = (b + a) / 2;//center
    fa = a*a*a - a - 3;
    fb = b*b*b - b - 3;
    fc = c*c*c - c - 3;
    while (abs(fc) > e)
    {
        i++;
        if (fa*fc<0)
        {
            a = a;
            b = c;
            c = (b + a) / 2;
            fa = a*a*a - a - 3;
            fb = b*b*b - b - 3;
            fc = c*c*c - c - 3;
        }
        else
        {
            a = c;
            b = b;
            c = (b + a) / 2;
            fa = a*a*a - a - 3;
            fb = b*b*b - b - 3;
            fc = c*c*c - c - 3;
        }
    }
    printf("Iterations = %d, c = %lf", i, c);
    return 0;
}