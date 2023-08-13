#include <stdio.h>
#include <stdlib.h>
void prims(int g[20][20], int n);
int main()
{
    int n;
    int g[20][20];
    printf("Enter no of V ");
    scanf("%d", &n);
    printf("Enter cost matrix :");
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &g[i][j]);
            if (g[i][j] == 0)
                g[i][j] = 999;
        }
    prims(g, n);
    return 0;
}
void prims(int g[20][20], int n)
{
    int i, j, u, v, min, mincost = 0, visited[10], ne = 1;
    for (i = 1; i <= n; i++)
    {
        visited[i] = 0;
    }
    printf("The edges of the MSt are : ");
    visited[1] = 1;
    while (ne < n)
    {
        for (i = 1, min = 999; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (g[i][j] < min)
                {
                    if (visited[i] == 0)
                        continue;
                    else
                    {
                        min = g[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }
        if (visited[u] == 0 || visited[v] == 0)
        {
            printf("%d Edge(%d,%d)=%d\n", ne++, u, v, min);
            mincost = mincost + min;
            visited[v] = 1;
            g[u][v] = g[v][u] = 999;
        }
    }
    printf("Cost of MST is %d\n", mincost);
}