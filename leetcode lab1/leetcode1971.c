#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 1000

// Helper function to perform DFS to check path
bool dfs(int node, int target, bool* visited, int** graph, int graphSize, int* graphColSize) {
    if (node == target) return true;
    visited[node] = true;

    for (int i = 0; i < graphColSize[node]; i++) {
        int neighbor = graph[node][i];
        if (!visited[neighbor]) {
            if (dfs(neighbor, target, visited, graph, graphSize, graphColSize)) {
                return true;
            }
        }
    }

    return false;
}

// Function to check if path exists
bool validPath(int n, int** edges, int edgesSize, int* edgesColSize, int source, int destination) {
    bool visited[n];
    for (int i = 0; i < n; i++) visited[i] = false;

    // Build adjacency list
    int* graph[n];
    int graphColSize[n];
    for (int i = 0; i < n; i++) {
        graph[i] = (int*)malloc(n * sizeof(int));
        graphColSize[i] = 0;
    }

    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0], v = edges[i][1];
        graph[u][graphColSize[u]++] = v;
        graph[v][graphColSize[v]++] = u;
    }

    return dfs(source, destination, visited, graph, n, graphColSize);
}

int main() {
    // Example usage with custom graph edges
    int n = 6;
    int edges[5][2] = {{0, 1}, {0, 2}, {3, 4}, {2, 3}, {5, 0}};
    int* edgesPtrs[5];
    for (int i = 0; i < 5; i++) {
        edgesPtrs[i] = edges[i];
    }

    if (validPath(n, edgesPtrs, 5, NULL, 0, 4)) {
        printf("Path exists\n");
    } else {
        printf("No path\n");
    }

    return 0;
}
