#include <stdio.h>
#define MAX 100
#define INFINITY 999
void dijkstra(int graph[MAX][MAX], int n, int start)
{
    int dist[MAX], prev[MAX], visited[MAX] = {0};
    for (int i = 0; i < n; i++)
    {
        dist[i] = INFINITY;
    }
    dist[start] = 0;
    for (int count = 0, u; count < n - 1; count++)
    {
        u = -1;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && (u == -1 || dist[i] < dist[u]))
            {
                u = i;
            }
        }
        visited[u] = 1;
        for (int v = 0; v < n; v++)
        {
            if (graph[u][v] && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
                prev[v] = u;
            }
        }
    }
    printf("Shortest distances from vertex %d:\n", start);
    for (int i = 0; i < n; i++)
    {
        printf("Vertex %d: Distance = %d, Path: %d", i, dist[i], i);
        for (int p = i; p != start; p = prev[p])
        {
            printf(" <- %d", prev[p]);
        }
        printf("\n");
    }
}
int main()
{
    int n, graph[MAX][MAX];
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix (use %d for no direct connection):\n", INFINITY);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    int start;
    printf("Enter the source vertex: ");
    scanf("%d", &start);
    dijkstra(graph, n, start);
    return 0;
}