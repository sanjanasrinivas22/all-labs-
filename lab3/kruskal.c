#include <stdio.h>

#define MAX 10
#define INF 999

int cost[MAX][MAX], n, t[MAX][2], sum;

void kruskal(int cost[MAX][MAX], int n);
int find(int parent[MAX], int i);

int main() {
    int i, j;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            // Set 0s or invalid edges to INF to avoid selecting them
            if (cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    kruskal(cost, n);

    printf("Edges of the minimal spanning tree:\n");
    for (i = 0; i < n - 1; i++) {
        printf("(%d, %d)\n", t[i][0], t[i][1]);
    }

    printf("Sum of minimal spanning tree: %d\n", sum);

    return 0;
}

void kruskal(int cost[MAX][MAX], int n) {
    int parent[MAX], count = 0, k = 0, min, u, v;

    for (int i = 0; i < n; i++)
        parent[i] = i;

    sum = 0;

    while (count < n - 1) {
        min = INF;
        u = -1;
        v = -1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (find(parent, i) != find(parent, j) && cost[i][j] < min) {
                    min = cost[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        if (u != -1 && v != -1) {
            int root_u = find(parent, u);
            int root_v = find(parent, v);

            if (root_u != root_v) {
                parent[root_u] = root_v;
                t[k][0] = u;
                t[k][1] = v;
                sum += min;
                k++;
                count++;
            }

            // Remove selected edge to avoid duplicate selection
            cost[u][v] = cost[v][u] = INF;
        } else {
            break; // No valid edge found
        }
    }
}

int find(int parent[MAX], int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}


