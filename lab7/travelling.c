#include <stdio.h>
#include <limits.h>

#define V 4

int tsp(int graph[V][V], int v[], int pos, int n, int count, int cost, int start) {
    if (count == n && graph[pos][start]) return cost + graph[pos][start];

    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (!v[i] && graph[pos][i]) {
            v[i] = 1;
            int temp = tsp(graph, v, i, n, count + 1, cost + graph[pos][i], start);
            ans = (temp < ans) ? temp : ans;
            v[i] = 0;
        }
    }
    return ans;
}

int main() {
    int graph[V][V] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };
    int v[V] = {0};
    v[0] = 1;
    printf("Minimum cost: %d\n", tsp(graph, v, 0, V, 1, 0, 0));
    return 0;
}