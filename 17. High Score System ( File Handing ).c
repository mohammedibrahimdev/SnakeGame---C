#include <stdio.h>
#include <stdlib.h>

int main() {
    int score = 50;      // Current game score
    int highscore = 0;   // Previous high score
    FILE *file;

    // 1?? Open the file in read mode to check previous high score
    file = fopen("D:\\highscore.txt", "r");  // Specify path in D: drive
    if (file != NULL) {
        fscanf(file, "%d", &highscore);  // Read previous high score
        fclose(file);
    }

    printf("Previous High Score: %d\n", highscore);

    // 2?? Compare and update if current score is higher
    if (score > highscore) {
        printf("New High Score! %d\n", score);
        file = fopen("D:\\highscore.txt", "w");  // Open file in write mode
        if (file != NULL) {
            fprintf(file, "%d", score);  // Save new high score
            fclose(file);
        } else {
            printf("Error: Cannot open file to save high score.\n");
        }
    } else {
        printf("High score remains: %d\n", highscore);
    }

    return 0;
}