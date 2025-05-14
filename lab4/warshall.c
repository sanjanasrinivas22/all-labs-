#include <stdio.h>

int n;
int a[10][10];  // Adjacency matrix
int p[10][10];  // Path matrix

// Function to print the path matrix
void write_data() {
    int i, j;
    printf("The path matrix is shown below\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", p[i][j]);
        }
        printf("\n");
    }
}

// Function to read the graph data (adjacency matrix)
void read_data() {
    int i, j;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix (0 or 1 values):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
}

// Function to compute the path matrix using Warshall's algorithm
void path_matrix() {
    int i, j, k;
    // Initialize the path matrix as the adjacency matrix
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            p[i][j] = a[i][j];
        }
    }

    // Apply Warshall's algorithm to compute the transitive closure
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                // If there is a path from i to k and from k to j, then there is a path from i to j
                if (p[i][k] == 1 && p[k][j] == 1) {
                    p[i][j] = 1;
                }
            }
        }
    }
}

int main() {
    read_data();      // Read the adjacency matrix
    path_matrix();    // Compute the path matrix
    write_data();     // Print the resulting path matrix
    return 0;
}
