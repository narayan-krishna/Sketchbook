#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <pthread.h>

//parallelize matrix multiplication

void mult(int *x, int *y, int *z){
    int r, c;
    for(r = 0; r < 3; ++r){
        for(c = 0; c < 3; ++c){
            z[r] += x[c]*y[c + r];
        }
    }
}



int main(int argc, char *argv[]){
    int p;
    if(argc != 2){
        printf("incorrect num args\n");
    }
    p = atoi(argv[1]);

    int a[3] = {1, 0, 2}; //3x1
    int b[9] = {1, 0, 0, 0, 1, 0, 0, 0, 1}; //3x3
    int c[3] = {0, 0, 0}; //1x3
    mult(a,b,c);
}