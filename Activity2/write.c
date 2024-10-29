#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp = fopen("traffic.dat", "w");
    if (fp == NULL) {
        printf("Error opening file for writing.\n");
        return 1;
    }

    // Scenario 1
    fprintf(fp, "main_lane,10\n");
    fprintf(fp, "diversion_lane,10\n");
    fprintf(fp, "left_main,20\n");
    fprintf(fp, "left_diversion,50\n");
    fprintf(fp, "right_main,20\n");
    fprintf(fp, "right_diversion,30\n");
    fprintf(fp, "pedestrian_main,60\n");
    fprintf(fp, "pedestrian_diversion,70\n");
    fprintf(fp, "---\n");

    // Scenario 2
    fprintf(fp, "main_lane,15\n");
    fprintf(fp, "diversion_lane,25\n");
    fprintf(fp, "left_main,30\n");
    fprintf(fp, "pedestrian_main,50\n");
    fprintf(fp, "right_main,20\n");
    fprintf(fp, "pedestrian_diversion,60\n");
    fprintf(fp, "---\n"); 

    // Scenario 3
    fprintf(fp, "left_diversion,10\n");
    fprintf(fp, "main_lane,20\n");
    fprintf(fp, "right_main,25\n");
    fprintf(fp, "pedestrian_main,15\n");
    fprintf(fp, "main_lane,40\n");
    fprintf(fp, "---\n"); 

    fclose(fp);
    printf("Traffic scenarios written to traffic.dat successfully.\n");

    return 0;
}
