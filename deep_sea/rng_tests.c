#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int average(int nums[], int size) {
    int sum = 0;
    for(int i = 0; i < size; i ++) {
        sum += nums[i];
    }
    return sum/size;
}

int std_deviation(int nums[], int size) {
    int avg = average(nums, size);
    int numer = 0;
    for(int i = 0; i < size; i ++) {
        numer += (nums[i] - avg) * (nums[i] - avg);
    }
    return sqrt(numer/(size - 1));
}

void generate_rands (int *nums, int size, int r) {
    for(int i = 0; i < size; i ++) {
        nums[i] = rand() % r;
    }
}

int main () { 

    int n = (int)pow(10, 3);
    int r = (int)pow(10, 1);

    int numbers[n];
    generate_rands(numbers, n, r);
    printf("%d\n", average(numbers, n));
    printf("%d\n", std_deviation(numbers, n));
    return 0;
}
