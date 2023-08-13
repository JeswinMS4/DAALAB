#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

void bfs(int graph[MAX_VERTICES][MAX_VERTICES], int vertices, int start)
{
    int queue[MAX_VERTICES], front = 0, rear = -1;
    bool visited[MAX_VERTICES] = {false};

    queue[++rear] = start;
    visited[start] = true;

    printf("BFS Traversal: ");

    while (front <= rear)
    {
        int current = queue[front++];

        printf("%d ", current);

        for (int i = 0; i < vertices; i++)
        {
            if (graph[current][i] && !visited[i])
            {
                queue[++rear] = i;
                visited[i] = true;
            }
        }
    }
}

int main()
{
    int vertices, start;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    int graph[MAX_VERTICES][MAX_VERTICES];

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &start);

    bfs(graph, vertices, start);

    return 0;
}