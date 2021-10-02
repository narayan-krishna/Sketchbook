#include <stdio.h>

#define MAXLENGTH 80

int binsearch(int x, int v[], int n){
    int low, mid, high;
    low = 0, high = n - 1;

    //if x < mid --> search the lower half
    //other wise --> search the upper half
    int counter = 0;
    while((low <= high)){
        printf("low %d |high%d\n", low, high);
        mid = (high+low)/2;
        printf("mid %d |target %d\n", mid, x);
        printf("middle value: %d\n", v[mid]);
        if(x < v[mid]){
            high = mid - 1;
        }else if (x > v[mid]){
            low = mid + 1;
        }else{
            return mid;
        }
        ++counter;
        if(counter == 7)
            break;
    } 
    return 0;
}

int atoi(char s[]){
    int i, n;
    n = 0;
    for(i = 0; i >= '0' && s[i] < '9'; i++){
        n = 10* n + (s[i] - '0');
    }
    return n;
}

int atoi2(char c){
    if(c >= '0' && c <= '9')
        return c - '0';
    return -1;
}

char lower(int c){
    if(c >= 'A' && c <= 'Z'){
            return c - 'A' + 'a';
    }else{
        return (char)c;
    }
}

int getLine(char arr[]){
    int c, i;
    for(i = 0; i < MAXLENGTH-1 && (c = getchar()) != EOF && c != '\n'; ++i){
        arr[i] = c;
    }
    if (c == '\n'){
        arr[i] = c;
        ++i;
    }
    arr[i] = '\0';
    return i - 1;
}

void reverse(){
    int len, i, counter, state = 0;
    char curr[MAXLENGTH] = { '\0' };
    counter = 0;
    while((len = getLine(curr)) > 0){
        for(i = MAXLENGTH-1; i >= 0; --i){
            if(curr[i] == '\0'){
                state = 1;
            }else if(state == 1){
                putchar(curr[i]);
            }
        }
        putchar('\n');
    }
}

int main(){
    // reverse();
    // char c[MAXLENGTH];
    // printf("%d\n", getLine(c));
    char x = lower('A');
    printf("%s\n", x);
    // printf("%d\n", atoi2('8'));

    // char s[1] = {'9'}; 
    // printf("%d\n", atoi(s));
    // int target = 3, arrsize = 10;
    // int arr[10] = {0, 1, 2, 3, 4, 8, 9, 14, 20, 21};
    // printf("%d\n", binsearch(target, arr, arrsize));
    return 0;
}