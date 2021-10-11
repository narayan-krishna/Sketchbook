#include <stdio.h>
#include <math.h>

void edit(int *x) {
    *x = 4;
}

int gcd(int u, int v) {  
    printf("%d | %d\n", u, v);
    if (v == 0) {
        return u;
    } else {
        return gcd(v, u % v);
    }
}

struct fraction { int numerator; int denominator; };

int normalize(struct fraction *f) {
    int gcdi = gcd(f->numerator, f->denominator);
    f->numerator /= gcdi;
    f->denominator /= gcdi;
    return 0;
}

float compute_per_hour (float per_year) {
    return per_year/(48*9*5);
}

int convert_stoi() {
    int val = 0;
    char c; 
    while((c = getchar()) != EOF && c != '\n') { 
        val += (c - '0');
        // printf("%d\n", val);
        val *= 10;
    }
    return val/10;
}

// 1 -> 1
// 2 -> 1*10 + 2
// 3 -> 12 * 100 + 3

int binary (int x) {
    int count = 0;
    while (x - ((int)pow(2,count)) >= 0) {
        // printf("%d\n", (int)pow(2, count));
        count ++;
    }

    for (int i = count - 1; i >= 0; i --) {
        int melon = (int)pow(2,i);
        if (x - melon >= 0) {
            putc('1', stdout);
            x -= melon;
        } else {
            putc('0', stdout);
        }
    }

    putc('\n', stdout);
    return count;
}



int main () {
    // struct fraction frac;
    // frac.numerator = 2;
    // frac.denominator = 4;
    // normalize(&frac);
    // printf("%d, %d\n", frac.numerator, frac.denominator);
    // int i;
    // printf("%d\n", i = convert_stoi());
    // printf("%d\n", i - 4);
    // printf("%d\n", gcd(12345, 56789));
    printf("%f\n", compute_per_hour(85000));

    // binary(convert_stoi());
    return 0;
}