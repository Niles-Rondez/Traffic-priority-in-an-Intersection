#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct {
    char movement[MAX];
    int time;
} Traffic;

Traffic createTraffic(char *movement, int time) {
    Traffic t;
    strcpy(t.movement, movement);
    t.time = time;
    return t;
}

int main() {
    FILE *fp = fopen("traffic.dat", "wb");
    if (fp == NULL) {
        printf("Error opening file for writing.\n");
        return 1;
    }

    Traffic list[8];

    list[0] = createTraffic("main_lane", 15);
    list[1] = createTraffic("diversion_lane", 20);
    list[2] = createTraffic("left_main", 25);
    list[3] = createTraffic("left_diversion", 35);
    list[4] = createTraffic("right_main", 10);
    list[5] = createTraffic("right_diversion", 15);
    list[6] = createTraffic("pedestrian_main", 45);
    list[7] = createTraffic("pedestrian_diversion", 50);

    fwrite(list, sizeof(Traffic), 8, fp);
    fclose(fp);

    printf("Test data written to traffic.dat successfully.\n");
    return 0;
}
