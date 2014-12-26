#include <stdio.h>
#include <stdlib.h>
#include "vec3d.h"

/*
  Compare two vec3ds according to their norm
 */
int compare(const void *vv1, const void *vv2)
{
        vec3d v1=*((vec3d*)vv1);
        vec3d v2=*((vec3d*)vv2);

        //compute the norms of the vectors
        real_t n1=vec_dot_product(v1, v1);
        real_t n2=vec_dot_product(v2, v2);

        double ret=n1-n2;

        if(ret<0) {
                return -1;
        } else if (ret>0) {
                return 1;
        } else {
                return 0;
        }
}

int main(void)
{
        vec3d v1=vec_new(1,2,3);
        vec3d v2=vec_new(4,5,6);
        vec3d v3=vec_new(7,8,9);

        vec3d vecs[3]={v2, v3, v1};

        printf("Before:\n[");
        for(int i=0; i<3; i++) {
                printf("{%f, %f, %f} ",
                       vecs[i]->x, vecs[i]->y, vecs[i]->z);
        }
        printf("]\n");


        qsort(vecs, 3, sizeof(vec3d), compare);

        printf("After:\n[");
        for(int i=0; i<3; i++) {
                printf("{%f, %f, %f} ",
                       vecs[i]->x, vecs[i]->y, vecs[i]->z);
        }
        printf("]\n");

        vec_free(v1);
        vec_free(v2);
        vec_free(v3);
        return 0;
}
