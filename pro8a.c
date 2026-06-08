#include <stdio.h>

#define MAX 20
#define INF 999

int main() {

    int n;
    int dist[MAX][MAX];

    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter distance matrix:\n");

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &dist[i][j]);
        }
    }

    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    printf("\nShortest Path Matrix:\n");

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {

            if(dist[i][j] == INF)
                printf("INF ");

            else
                printf("%d ", dist[i][j]);
        }

        printf("\n");
    }
    return 0;
}