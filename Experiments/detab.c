#include <stdio.h>

#define MAXLINE 80

int getLine(char line[], int limit){
    int c, i;
    for(i = 0; (c = getchar()) != EOF && i < limit - 1 && c != '\n'; ++i){
        line[i] = c;
    }
    line[i] = '\0';
    return i;
}

void detab(int n){
    enum { IN, OUT };
    int len, i, j;
    char line[MAXLINE];    

    while(len = getLine(line, MAXLINE) > 0){
        for(i = 0; line[i] != '\0'; ++i){
            //if tab is first character
            if(line[i] == '\t'){
                for(j = 0; j < n; ++j){
                    putchar(' ');
                }
            }else{
                putchar(line[i]);
            }
        }
        putchar('\n');
    }
}

int main(){
    detab(5);
    return 0;
}