#include <ctype.h>
#include <stdio.h>

#define LIMIT 1000

double atof(char line[]);
int get_line(char line[], int char_limit); 
int strindex(char string[], char pattern[]);
int right_most(char string[], char pattern[]);

char pattern[] = "pattern";

int main() {
    char line[LIMIT]; 
    int length;
    int pattern_index;

    while((length = get_line(line, LIMIT)) > 0) {
        if((pattern_index = right_most(line, pattern)) >= 0) {
            printf("%d\n", pattern_index);
        }
    }

    return 0;
}


int get_line(char line[], int char_limit) {
    char c;
    int i = 0;

    while(--char_limit > 0 && (c=getchar()) != EOF && c!='\n') {
        line[i++] = c;
    }

    if(c=='\n') {
        line[i++] = c;
    }

    /*add an end char*/
    line[i] = '\0';
    return i;
}

int right_most(char string[], char pattern[]) {
    /*iterate through chars of main string*/
    int i, j, k;
    int last_loc = -1;

    for(i = 0; string[i] != '\0'; i++) {
        //iterate from point in string till pattern completion OR
        //until mismatch. use j to match i iterator initially
        //j runs through string, k runs through pattern
        for(j = i, k = 0; pattern[k] != '\0' && string[j]==pattern[k]; j++, k++);
        if(k > 0 && pattern[k] == '\0') {
            if(i > last_loc) {
                last_loc = i;
            }
        }
    }
    return last_loc;
}

int strindex(char string[], char pattern[]) {
    /*iterate through chars of main string*/
    int i, j, k;
    for(i = 0; string[i] != '\0'; i++) {
        //iterate from point in string till pattern completion OR
        //until mismatch. use j to match i iterator initially
        //j runs through string, k runs through pattern
        for(j = i, k = 0; pattern[k] != '\0' && string[j]==pattern[k]; j++, k++);
        if(k > 0 && pattern[k] == '\0') {
            return i;
        }
        /*run through the string*/
        /*run through the pattern, while iterating from pos j until pattern finishes*/
        /*if the pattern is good, check it against max*/
    }
    return -1;
}
