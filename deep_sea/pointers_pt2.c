#include <stdio.h>
#define ALLOCSIZE 50

/*hello my name jeff*/

/*create a buffer*/
char allocbuf[ALLOCSIZE];
/*set the free position pointer to the first position of allocbuf*/
char* allocp = allocbuf; //aka alloc pointer

int string_length(char *s);

// char* alloc(int n);
// void afree(char* p);
// void print();

int main (){

    int *bufp; 

    char *in_text = "provid input";
    printf("%s\n", in_text);
    int buf_size = getchar() - '0';
    printf("%d\n", buf_size);

    int buf[buf_size];
    buf[buf_size - 1] = '\0';
    bufp = buf; //set this pointer to the head of buf

    int count = 0;
    while(*bufp != '\0') {
        *bufp = count;        
        bufp ++;
        count++;
    }

    for(int i = 0; i < buf_size; i++) {
        printf("%d", buf[i]);
    }

    printf("\n");

    //char *str = "hello";
    // int alloc_bits = 20;
    // alloc(alloc_bits);
    // print();
    // char *x = allocbuf + 9;
    // afree(x);
    // print();

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
