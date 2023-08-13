#include <stdio.h>
#include <stdbool.h>

#define MAX 100

void dfs(int graph[MAX][MAX], bool visited[MAX], int n, int vertex)
{
    printf("%d ", vertex);
    visited[vertex] = true;

    for (int i = 0; i < n; i++)
    {
        if (graph[vertex][i] && !visited[i])
        {
            dfs(graph, visited, n, i);
        }
    }
}

int main()
{
    int vertices;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &vertices);

    int graph[MAX][MAX];
    bool visited[MAX] = {false};

    printf("Enter the adjacency matrix for the graph:\n");
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    int startVertex;
    printf("Enter the starting vertex for DFS: ");
    scanf("%d", &startVertex);

    printf("DFS Traversal Order: ");
    dfs(graph, visited, vertices, startVertex);

    return 0;
}