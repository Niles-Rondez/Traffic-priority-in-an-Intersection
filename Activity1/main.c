#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct {
    char movement[MAX];
    int time;
} Traffic;

int getPriority(char *movement) {
    if(strcmp(movement, "main_lane") == 0) return 1;
    if(strcmp(movement, "diversion_lane") == 0) return 2;
    if(strcmp(movement, "left_main") == 0) return 3;
    if(strcmp(movement, "left_diversion") == 0) return 4;
    if(strcmp(movement, "right_main") == 0) return 5;
    if(strcmp(movement, "right_diversion") == 0) return 6;
    if(strcmp(movement, "pedestrian_main") == 0) return 7;
    if(strcmp(movement, "pedestrian_diversion") == 0) return 8;
}

void insertInPriorityQueue(Traffic pq[], int *size, Traffic t);
void calculateTime(Traffic pq[], int size);

int main() {
    Traffic pq[MAX];
    int size = 0;
    FILE *fp = fopen("traffic.dat", "rb");
    if(fp != NULL) {
        Traffic t;
        while(fread(&t, sizeof(Traffic), 1, fp)) {
            insertInPriorityQueue(pq, &size, t);
        }
        fclose(fp);
        calculateTime(pq, size);
        return 0;
    }
    return 1;
}

void insertInPriorityQueue(Traffic pq[], int *size, Traffic t) {
    int priority = getPriority(t.movement);
    int i;
    for(i = *size - 1; i >= 0 && getPriority(pq[i].movement) > priority; i--) {
        pq[i + 1] = pq[i];
    }
    pq[i + 1] = t;
    *size += 1;
}

void calculateTime(Traffic pq[], int size) {
    int total_time = 0;
    for(int i = 0; i < size; i++) {
        if(strcmp(pq[i].movement, "pedestrian_main") == 0) {
            printf("Total time before main pedestrian can cross: %d seconds\n", total_time);
            return;
        }
        total_time += pq[i].time;
    }
    printf("Main pedestrian not found!\n");
}