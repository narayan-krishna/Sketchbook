#include <stdio.h>
#include <stdlib.h>

int *stack;
int *sp;
int N;

typedef int BYTES;

void stalloc(BYTES b) {
    if(sp + b > stack + N) {
        printf("overflow...\n");
    } else {
        sp += b;
    }
}

void stfree(BYTES b) {
    if(sp - b < stack) {
        printf("underflow...\n");
    } else {
        sp -= b;
    }
}

void print_stack() {
    for(int i = 0; i < N; i ++) {
        if(i < (sp - stack)) {
            putc('x', stdout);
        }
        else { putc('_', stdout); }
    }
    printf("\n");
}

int main (int argc, char **argv) {
    N = atoi(argv[1]);
    stack = malloc(N*sizeof(int));
    sp = stack;
    print_stack(); 
    stalloc(5);
    print_stack();
    stfree(4);
    print_stack();
    stalloc(60);
    free(stack);
}
