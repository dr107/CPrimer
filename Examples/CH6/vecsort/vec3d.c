#include <stdio.h>
#include <stdlib.h>
#include "vec3d.h"

vec3d vec_new(real_t x, real_t y, real_t z)
{
        vec3d ptr=malloc(sizeof(vec3d));
        ptr->x=x;
        ptr->y=y;
        ptr->z=z;
        return ptr;
}

void vec_free(vec3d vec)
{
        free(vec);
}

vec3d vec_sum(vec3d v1, vec3d v2)
{
        real_t x = v1->x + v2->x;
        real_t y = v1->y + v2->y;
        real_t z = v1->z + v2->z;
        return vec_new(x,y,z);
}

vec3d vec_scalar_mul(vec3d v1, real_t c)
{
        real_t x,y,z;
        x=c*v1->x;
        y=c*v1->y;
        z=c*v1->z;
        return vec_new(x,y,z);
}

real_t vec_dot_product(vec3d v1, vec3d v2)
{
        return (v1->x * v2->x) + (v1->y * v2->y) + (v1->z * v2->z);
}

/*
  Allocates a new vector that represents the cross
  product of v1 and v2
 */
vec3d vec_cross_product(vec3d v1, vec3d v2)
{
        real_t x=v1->y*v2->z - v1->z*v2->y;
        real_t y=v1->z*v2->x - v1->x*v2->z;
        real_t z=v1->x*v2->y - v1->y*v2->x;
        return vec_new(x,y,z);
}
