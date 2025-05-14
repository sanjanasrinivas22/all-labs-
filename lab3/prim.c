#include <stdio.h>

#define MAX 10
#define INF 999

int cost[MAX][MAX], n, t[MAX][2], sum;

void prims(int cost[MAX][MAX], int n);

int main() {
    int i, j;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix (use 999 for no edge):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    prims(cost, n);

    printf("Edges of the minimal spanning tree:\n");
    for (i = 0; i < n - 1; i++) {
        printf("(%d, %d)\n", t[i][0], t[i][1]);
    }

    printf("Sum of minimal spanning tree: %d\n", sum);

    return 0;
}

void prims(int cost[MAX][MAX], int n) {
    int i, j, u, v, min, source = 0;
    int d[MAX], p[MAX], s[MAX];

    // Initialization
    for (i = 0; i < n; i++) {
        d[i] = cost[source][i];
        s[i] = 0;
        p[i] = source;
    }

    s[source] = 1;
    sum = 0;
    int k = 0;

    for (i = 0; i < n - 1; i++) {
        min = INF;
        u = -1;

        // Find the unvisited node with minimum cost to MST
        for (j = 0; j < n; j++) {
            if (s[j] == 0 && d[j] < min) {
                min = d[j];
                u = j;
            }
        }

        if (u == -1) break;  // No more reachable vertices

        // Include edge in MST
        t[k][0] = p[u];  // from parent
        t[k][1] = u;     // to current node
        k++;
        sum += cost[u][p[u]];
        s[u] = 1;

        // Update distances from newly added vertex
        for (v = 0; v < n; v++) {
            if (s[v] == 0 && cost[u][v] < d[v]) {
                d[v] = cost[u][v];
                p[v] = u;
            }
        }
    }
}
