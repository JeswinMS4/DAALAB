#include <stdio.h>

#define MAX_CITIES 10
#define INF 999

int costMatrix[MAX_CITIES][MAX_CITIES];
int visited[MAX_CITIES];
int n, minCost = INF;
int optimalPath[MAX_CITIES];

void getInput()
{
    int i, j;
    printf("Enter the number of cities: ");
    scanf("%d", &n);
    printf("Enter the cost matrix (Enter %d for no connection):\n", INF);
    for (i = 0; i < n; i++)
    {
        printf("Enter elements of row #%d (use %d for no connection):\n", i + 1, INF);
        for (j = 0; j < n; j++)
        {
            scanf("%d", &costMatrix[i][j]);
        }
        visited[i] = 0;
    }
}

void tsp(int currentCity, int depth, int currentCost, int path[])
{
    if (depth == n - 1)
    {
        int finalCost = currentCost + costMatrix[currentCity][0];
        if (finalCost < minCost)
        {
            minCost = finalCost;
            for (int i = 0; i < n; i++)
            {
                optimalPath[i] = path[i];
            }
        }
        return;
    }

    visited[currentCity] = 1;
    path[depth] = currentCity;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            tsp(i, depth + 1, currentCost + costMatrix[currentCity][i], path);
        }
    }
    visited[currentCity] = 0;
}

void printPath(int path[], int size)
{
    printf("Path: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d", path[i] + 1);
        if (i < size - 1)
        {
            printf(" -> ");
        }
    }
    printf("\n");
}

int main()
{
    getInput();
    int path[MAX_CITIES];
    printf("\n\nCalculating optimal path...\n");
    tsp(0, 0, 0, path);
    printf("Optimal ");
    printPath(optimalPath, n);
    printf("Minimum cost: %d\n", minCost);
    return 0;
}