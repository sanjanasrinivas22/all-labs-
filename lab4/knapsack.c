#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

void knapsack(int n, int w[], int p[], int c) {
    int v[10][10]; // DP table for storing results
    int i, j;

    // Initialize the DP table
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= c; j++) {
            if (i == 0 || j == 0) {
                v[i][j] = 0; // Base case: no items or no capacity
            } else if (w[i - 1] > j) {
                v[i][j] = v[i - 1][j]; // Item cannot be included
            } else {
                v[i][j] = max(v[i - 1][j], v[i - 1][j - w[i - 1]] + p[i - 1]); // Max profit
            }
        }
    }

    // Output the maximum profit
    printf("\n\n Maximum Profit is: %d\n", v[n][c]);

    // Print the DP table
    printf("\n\n Table:\n\n");
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= c; j++) {
            printf("%d\t", v[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n, c, i;

    // Input the number of objects
    printf("Enter the number of objects: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input for number of objects.\n");
        return 1;
    }

    int w[n], p[n];

    // Input the weights of the objects
    printf("Enter the weights of the objects: ");
    for (i = 0; i < n; i++) {
        if (scanf("%d", &w[i]) != 1 || w[i] <= 0) {
            printf("Invalid input for weight of object %d.\n", i + 1);
            return 1;
        }
    }

    // Input the profits of the objects
    printf("Enter the profits of the objects: ");
    for (i = 0; i < n; i++) {
        if (scanf("%d", &p[i]) != 1 || p[i] < 0) {
            printf("Invalid input for profit of object %d.\n", i + 1);
            return 1;
        }
    }

    // Input the capacity of the knapsack
    printf("Enter the capacity of the knapsack: ");
    if (scanf("%d", &c) != 1 || c <= 0) {
        printf("Invalid input for knapsack capacity.\n");
        return 1;
    }

    // Call the knapsack function
    knapsack(n, w, p, c);

    return 0;
}
