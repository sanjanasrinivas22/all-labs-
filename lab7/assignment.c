#include <stdio.h>
#define N 3
int costMatrix[N][N] = {
    {9, 2, 7},
    {6, 4, 3},
    {5, 8, 1}
};

int minCost = 999999;

void findMinCost(int row, int assigned[], int cost) {
    if (row == N) {
        if (cost < minCost) minCost = cost;
        return;
    }
    for (int col = 0; col < N; col++) {
        if (!assigned[col]) {
            assigned[col] = 1;
            findMinCost(row + 1, assigned, cost + costMatrix[row][col]);
            assigned[col] = 0;
        }
    }
}

int main() {
    int assigned[N] = {0};
    findMinCost(0, assigned, 0);
    printf("Minimum cost: %d\n", minCost);
    return 0;
}