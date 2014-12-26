#ifndef __VEC3D_H_INC
#define __VEC3D_H_INC

typedef struct vec3dtag *vec3d;

typedef double real_t;

struct vec3dtag {
        real_t x;
        real_t y;
        real_t z;
};

vec3d vec_new(real_t x, real_t y, real_t z);

void vec_free(vec3d v);

vec3d vec_sum(vec3d v1, vec3d v2);

vec3d vec_scalar_mul(vec3d v1, real_t x);

real_t vec_dot_product(vec3d v1, vec3d v2);

vec3d vec_cross_product(vec3d v1, vec3d v2);

#endif
