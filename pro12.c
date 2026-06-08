#include <stdio.h>
#include <stdlib.h>

int camera[20];
int solutionCount = 0;

int isSafe(int row, int col) {

    for(int i = 1; i < row; i++) {

        if(camera[i] == col ||
           abs(camera[i] - col) == abs(i - row)) {

            return 0;
        }
    }

    return 1;
}

void placeCameras(int row, int n) {

    for(int col = 1; col <= n; col++) {
        if(isSafe(row, col)) {
            camera[row] = col;
            if(row == n) {
                solutionCount++;
                printf("\nArrangement %d:\n", solutionCount);
                for(int i = 1; i <= n; i++) {
                    for(int j = 1; j <= n; j++) {
                        if(camera[i] == j)
                            printf("C ");
                        else
                            printf(". ");
                    }
                    printf("\n");
                }
            }
            else {
                placeCameras(row + 1, n);
            }
        }
    }
}

int main() {

    int n;

    printf("Enter grid size: ");
    scanf("%d", &n);

    placeCameras(1, n);

    printf("\nTotal arrangements = %d\n", solutionCount);

    return 0;
}