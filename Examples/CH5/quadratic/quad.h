#ifndef __QUAD_H_INC
#define __QUAD_H_INC

typedef struct quad_in {
        /*
          These fields represent the quadratic eqn
          ax^2+bx+c=0
        */
        double a;
        double b;
        double c;
} quad_in;

typedef struct quad_out {
        /* 
	  if this is nonzero, there was no solution. The rest of
	  the struct is not specified in that case.
	*/
        int nosoln;
        /*
          These represent the two solutions of that equation,
          if they exist.
         */
        double x1;
        double x2;
} quad_out;

extern quad_out qout;
extern quad_in qin;

/*
  Compute the solution to the quadratic equation represented by
  qin.
 */
void quad_compute(void);

#endif
