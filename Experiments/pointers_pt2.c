#include <stdio.h>
#define ALLOCSIZE 50

/*create a buffer*/
char allocbuf[ALLOCSIZE];
/*set the free position pointer to the first position of allocbuf*/
char* allocp = allocbuf; //aka alloc pointer

int string_length(char *s);

char* alloc(int n);
void afree(char* p);
void print();

int main (){

    //char *str = "hello";
    int alloc_bits = 10;
    alloc(alloc_bits);
    print();
    char *x = allocbuf + 5;
    afree(x);
    print();

    //printf("%d\n", string_length(str));
    return 0;
}


char* alloc(int n) {
    /*if free position + n is greater than buff size */
    if (allocp + n > allocbuf + ALLOCSIZE) {
        /*it can't be done, return error*/
       return 0;
    } else {
        /*otherwise move the pointer along*/
        allocp += n;
        return allocp;
    }
}

void afree(char *p) {
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE) {
        /*if points to somewhere in the buffer*/
        allocp = p;
    }
}

void print() {
   for(int i = 0; i < ALLOCSIZE; i ++) {
       printf("|");
       if (i + allocbuf < allocp) {
           printf("x");
       } else {
           printf("_");
       }
   }
    printf("|\n");
}

int string_length(char *s) {
    int n;
    for(n = 0; *s != '\0'; s++) {
        n++;
    }

    return n;
}
