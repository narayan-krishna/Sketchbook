#include <stdio.h>
#define MAXLINE 1000

//hello

int get_line(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould";

int main() {
    printf("Hello world\n");
    char line[MAXLINE];                                                        
    int found = 0;

    /*program purpose: print lines with pattern*/

    /*outline what the program should do here,
      and outline with functions */
    while (get_line(line, MAXLINE) > 0) {
        if (strindex(line, pattern) >= 0) {
            printf("%s\n", line);
            found ++;
        }
    }

    return found;
}

/*getting a single line, and return its length*/
int get_line(char s[], int lim) {
    int c;
    int i = 0;
    /*while the line limit hasn't been reach*/
    /*while the gotten character is neither end of line or file*/
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n') {
        s[i++] = c;
    }
    if(c == '\n') {
        s[i++] = c;
    }
    /*append a null char to the end*/
    s[i] = '\0';
    return i;
}

/*return index of char[t] in char s*/
int strindex(char s[], char t[]){
    int i, j, k;

    /*run through every char of s*/
    for(i = 0; s[i] != '\0'; i++) {
        /*check every character of the string to see if
        following pattern is equal to word*/
        for(j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++); 
        if(k > 0 && t[k] == '\0') {
            return i;
        }
    }
    return -1;
}
