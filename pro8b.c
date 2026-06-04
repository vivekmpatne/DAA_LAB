#include <stdio.h>

#define MAX 20

int main() {

    int n;
    int graph[MAX][MAX];

    printf("Enter number of webpages: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {

                graph[i][j] = graph[i][j] || ( graph[i][k] && graph[k][j] ) ;
            
            }
        }
    }

    printf("\nReachability Matrix:\n");

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    return 0;
}