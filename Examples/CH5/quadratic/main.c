#include <stdio.h>
#include "quad.h"

void solve_eqn(double a, double b, double c)
{
        qin.a=a;
        qin.b=b;
        qin.c=c;
        printf("Attempting to solve %f x^2 + %f x + %f = 0\n",
               qin.a, qin.b, qin.c);
        quad_compute();
        if (qout.nosoln) {
                printf("There was no solution\n");
        } else {
                printf("The solutions are %f and %f\n",
                       qout.x1, qout.x2);
        }
}

int main(void)
{
        solve_eqn(5,3,2);
        solve_eqn(5,3,-2);
	solve_eqn(0,0,0);
        return 0;
}
