#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef float melon;
melon add_melons(melon, melon);

typedef struct { float x; float y; } point;
float distance(point, point);

typedef struct { point a; point b; point c; } triangle;
float area(triangle);

typedef struct { char c; char s; } suitable;

int sieve(int n);

int main (int argc, char **argv){
    
    if(argc < 2) {
        printf("Needs more args!...\n");
        exit(-1); 
        return 0;
    }
    // point a = {0, 0};
    // point b = {0, 2};
    // point c = {2, 0};
    // printf("%f\n", distance(a, b));

    // triangle t = {a, b, c};

    // printf("%f\n", area(t));
    sieve( atoi(argv[1]) );
    return 0;
}

int sieve(int n) {
    /*establish counters*/
    if(n < 2) {
        return 1;
    }
    int i, j;
    int *a = malloc(n*sizeof(int));
    /*set a values to 1 (first two are already 0*/
    for (i = 2; i < n; i++) { a[i] = 1; }
    /*two pointers*/
    for (i = 2; i < n; i++) {
        if (a[i] != 0) {
            /*any index that is the product of two numbers i j
             is not prime*/
            for(j = i; i*j < n; j++) { a[i*j] = 0; }
        }
    }
    for (i = 2; i < n; i++) {
        if (a[i]) {
            printf("%4d ", i); //only print primes, spaced by 4
        }
    }
    printf("\n");
    return 0;
}

float distance(point a, point b) {
    float dx = a.x - b.x;
    float dy = a.y - b.y;
    return sqrt(dx*dx + dy*dy);
    
}

melon add_melons(melon m1, melon m2) {
    return m1+m2;
}

float area(triangle t) {
    return fabs(t.a.x * t.b.y - t.b.x * t.a.y
              + t.b.x * t.c.y - t.c.x * t.b.y
              + t.c.x * t.a.y - t.a.x * t.c.y) / 2;
}


