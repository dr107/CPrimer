#include <math.h>
#include <stdio.h>
#include "quad.h"

/*
  Allocate storage for the in and out structs
 */
quad_in qin;
quad_out qout;

void quad_compute(void)
{
        double det=qin.b*qin.b-4*qin.a*qin.c;
        double denom=2*qin.a;
        /*
          determinant<0 means there is no solution.

          If a<0 then, 2a<0, and we'd get a divide by 0 error.

          Note that when working with floats and doubles, you have to
          reckon with roundoff error, so == is not a great idea. Instead,
          we check if the absolute value of the number is less than some
          threshhold. Since the precsion of a double is ~13 digits, we use
          10^-12. Note you can use e to put in integer literals.
         */
        if (det<0 || fabs(denom)<1e-12 ) {
                qout.nosoln=1;
                return;
        }
	//there is a solution
	qout.nosoln=0;
        det=sqrt(det);
        qout.x1=(-qin.b+det)/denom;
        qout.x2=(-qin.b-det)/denom;
}
