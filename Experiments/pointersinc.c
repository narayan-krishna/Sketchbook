#include <stdio.h>

void functiondealswithnumbers(int *x){
    *x = 10;
}

void swap(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y; 
    *y = temp;
}

// void swap2(int &x, int &y){
//     int temp;
//     x = y;
//     y = temp;
// }

int main(){
    int x = 1, y = 2;
    int *px, *py;

    px = &x, py = &y;
    swap(px, py);
    // swap2(x, y);
    printf("%d|%d\n", x, y);

    // int x =1, y = 2, z[10];
    // int *ip; //ip is a pointer to an int. *ip (dereferenced ip) is an int
    // ip = &y;
    // printf("%d\n", *ip);
    // *ip = 0;
    // printf("%d\n", y);
    // int *np = &x;
    // *np = 11;
    // printf("%d\n", *np);
    // *np = *np + 10;
    // printf("%d\n", *np);
    // functiondealswithnumbers(np);
    // printf("%d\n", *np);

    // int *ip, x = 0, y;
    // ip = &x;
    // *ip = *ip+10;
    // y = *ip + 1;
    // *ip += 1;
    // printf("%d|%d|%d\n", *ip, x, y);
    // printf("%x\n", ip); //address ip points to
    // printf("%x\n", &ip); //address of address ip points to
    return 0;
}