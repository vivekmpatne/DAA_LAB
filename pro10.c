#include <stdio.h>

#define MAX 10
#define INF 9999

int main()
{
    int n;
    int cost[MAX][MAX];
    int visited[MAX] = {0};

    int mincost = 0;
    int edges = 0;
    int x, y;

    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);

            if(cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    visited[0] = 1;

    printf("\nOptimal Power Grid Connections:\n");

    while(edges < n - 1)
    {
        int min = INF;

        for(int i = 0; i < n; i++)
        {
            if(visited[i])
            {
                for(int j = 0; j < n; j++)
                {
                    if(!visited[j] && cost[i][j] < min)
                    {
                        min = cost[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }
        printf("Connect City %d -> City %d : Cost = %d\n",
               x, y, min);

        mincost += min;
        visited[y] = 1;
        edges++;
    }
    printf("\nTotal Power Grid Cost = %d\n", mincost);

    return 0;
}