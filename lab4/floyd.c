#include <stdio.h>

#define MAX 20
#define INF 999

int main() {
    int i, j, n, v, k, min, u;
    int c[MAX][MAX], s[MAX], d[MAX];

    printf("\nEnter the number of vertices: ");
    scanf("%d", &n);

    printf("\nEnter the cost adjacency matrix (use 999 for no edge):\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &c[i][j]);
        }
    }

    printf("\nEnter the source vertex: ");
    scanf("%d", &v);

    // Initialize
    for (i = 1; i <= n; i++) {
        s[i] = 0;           // not visited
        d[i] = c[v][i];     // initial distances from source
    }

    d[v] = 0;
    s[v] = 1;

    // Start Dijkstra's algorithm
    for (k = 2; k <= n; k++) {
        min = INF;
        u = -1;

        // Find the minimum distance unvisited vertex
        for (i = 1; i <= n; i++) {
            if (s[i] == 0 && d[i] < min) {
                min = d[i];
                u = i;
            }
        }

        if (u == -1) break; // no more reachable nodes

        s[u] = 1;

        // Update distances
        for (i = 1; i <= n; i++) {
            if (s[i] == 0 && d[i] > d[u] + c[u][i]) {
                d[i] = d[u] + c[u][i];
            }
        }
    }

    // Output
    printf("\nShortest distances from vertex %d:\n", v);
    for (i = 1; i <= n; i++) {
        if (d[i] == INF)
            printf("%d -> %d = No Path\n", v, i);
        else
            printf("%d -> %d = %d\n", v, i, d[i]);
    }

    return 0;
}

