#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct {
    char movement[MAX];
    int time;
} Traffic;

Traffic separateTraffic(char *line);
void processScenario(Traffic scenario[], int count, FILE *outputFile);

int main() {
    FILE *inputFile = fopen("traffic.dat", "r");
    FILE *outputFile = fopen("traffic_result.dat", "w");
    if (inputFile == NULL || outputFile == NULL) {
        printf("Error opening files.\n");
        return 1;
    }

    char line[256];
    Traffic scenario[MAX];
    int count = 0;

    while (fgets(line, sizeof(line), inputFile)) {
        if (strcmp(line, "---\n") == 0) {
            processScenario(scenario, count, outputFile);
            count = 0;
        } else {
            scenario[count++] = separateTraffic(line);
        }
    }

    if (count > 0) {
        processScenario(scenario, count, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);
    printf("Results written to traffic_result.dat.\n");
    return 0;
}

Traffic separateTraffic(char *line) {
    Traffic t;
    char *token = strtok(line, ",");
    strcpy(t.movement, token);
    t.time = atoi(strtok(NULL, ","));
    return t;
}

void processScenario(Traffic scenario[], int count, FILE *outputFile) {
    int total_time = 0;
    int main_pedestrian_time = -1;

    for (int i = 0; i < count; i++) {
        if (strcmp(scenario[i].movement, "pedestrian_main") == 0) {
            main_pedestrian_time = total_time;
            break;
        } else {
            total_time += scenario[i].time;
        }
    }

    if (main_pedestrian_time >= 0) {
        fprintf(outputFile, "Total time before main pedestrian can cross: %d seconds\n", main_pedestrian_time);
    } else {
        fprintf(outputFile, "Main pedestrian not found!\n");
    }
}
