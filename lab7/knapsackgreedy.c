#include <stdio.h>

int n = 5;
int p[10] = {3, 3, 2, 5, 1};  // Profits
int w[10] = {10, 15, 10, 12, 8};  // Weights
int W = 10;  // Capacity of the knapsack

int main() {
    int cur_w;        // Current weight in the knapsack
    float tot_v = 0;  // Total value of items in the knapsack
    int i, maxi;      // Variables for iteration and tracking the best item
    int used[10];     // Array to track if an item has been used

    // Initialize the used array to 0 (none used initially)
    for (i = 0; i < n; ++i) {
        used[i] = 0;
    }

    cur_w = W;  // Set the current weight to the total capacity of the knapsack

    // Greedy algorithm to fill the knapsack
    while (cur_w > 0) {
        maxi = -1;

        // Find the item with the highest value/weight ratio that hasn't been used
        for (i = 0; i < n; ++i) {
            if (used[i] == 0 && (maxi == -1 || ((float)p[i] / w[i]) > ((float)p[maxi] / w[maxi]))) {
                maxi = i;
            }
        }

        // Mark this item as used
        used[maxi] = 1;

        // If the current weight of the item fits in the remaining capacity
        if (w[maxi] <= cur_w) {
            cur_w -= w[maxi];
            tot_v += p[maxi];
            printf("Added object %d (%d, %d) completely in the bag. Space left: %d.\n", maxi + 1, w[maxi], p[maxi], cur_w);
        } else {
            // Otherwise, add the fractional part of the item
            float fraction = (float)cur_w / w[maxi];
            tot_v += p[maxi] * fraction;
            printf("Added %d%% (%d, %d) of object %d in the bag.\n", (int)(fraction * 100), w[maxi], p[maxi], maxi + 1);
            cur_w = 0;  // The knapsack is full
        }

        // If the knapsack is full, break the loop
        if (cur_w == 0) {
            break;
        }
    }

    // Print the total value of the knapsack
    printf("Filled the bag with objects worth %.2f.\n", tot_v);

    return 0;
}

