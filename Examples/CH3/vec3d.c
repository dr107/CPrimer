#include <stdio.h>
#include <stdlib.h>

typedef float real_t;

typedef struct vec3d {
        real_t x;
        real_t y;
        real_t z;
} vec3d;

vec3d *vec_new(real_t x, real_t y, real_t z)
{
        vec3d *ptr=malloc(sizeof(vec3d));
        ptr->x=x;
        ptr->y=y;
        ptr->z=z;
        return ptr;
}

void vec_free(vec3d *vec)
{
        free(vec);
}

vec3d *vec_sum(vec3d *v1, vec3d *v2)
{
        real_t x = v1->x + v2->x;
        real_t y = v1->y + v2->y;
        real_t z = v1->z + v2->z;
        return vec_new(x,y,z);
}

vec3d *vec_scalar_mul(vec3d *v1, real_t c)
{
        real_t x,y,z;
        x=c*v1->x;
        y=c*v1->y;
        z=c*v1->z;
        return vec_new(x,y,z);
}

real_t vec_dot_product(vec3d *v1, vec3d *v2)
{
        return (v1->x * v2->x) + (v1->y * v2->y) + (v1->z * v2->z);
}

/*
  Allocates a new vector that represents the cross
  product of v1 and v2
 */
vec3d *vec_cross_product(vec3d *v1, vec3d *v2)
{
        real_t x=v1->y*v2->z - v1->z*v2->y;
        real_t y=v1->z*v2->x - v1->x*v2->z;
        real_t z=v1->x*v2->y - v1->y*v2->x;
        return vec_new(x,y,z);
}

int main(void)
{
        vec3d *v1 = vec_new(3,-3,1);
        vec3d *v2 = vec_new(4,9,2);

        vec3d *sum=vec_sum(v1, v2);
        real_t dot=vec_dot_product(v1, v2);
        vec3d *cross=vec_cross_product(v1, v2);
        vec3d *times2=vec_scalar_mul(v1, 2);
        printf("{3 -3 1} + {4 9 2} = {%f %f %f}\n", sum->x, sum->y, sum->z);
        printf("{3 -3 1} . {4 9 2} = %f\n", dot);
        printf("{3 -3 1} X {4 9 2} = {%f %f %f}\n",
               cross->x, cross->y, cross->z);
        printf("2*{3 -3 1}  = {%f %f %f}\n", times2->x, times2->y, times2->z);

        vec_free(v1);
        vec_free(v2);
        /*
          When I first coded this, I forgot these next three lines.

          Run ./vec.o in valgrind and see what it says.

          As you can see, the output is exactly what is expected, but valgrind
          tells more of the story.

          Then uncomment them and do it again. Memory leaks are tricky.
        */
        /*
        vec_free(sum);
        vec_free(cross);
        vec_free(times2);
        */

}
