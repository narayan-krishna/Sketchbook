#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct { float x; float y; } point;
float distance(point, point);
void closest_point (point, point*);

int less_than_1k() {
    int buf_size = 4;
    int num_count[1000];
    char buf[4];
    int count = 0;
    while((c = getchar()) != EOF) {
        buf[count] = c;
        count ++;
        if(count == 4) {
        }
    }
    return count;
}

int main() {
    return 0;
}

// void closest_point (point* points, int points_size) {
//     int distance_closest = -1;
//     for(int i = 0; i < points_size; i ++) {

//     }
// }