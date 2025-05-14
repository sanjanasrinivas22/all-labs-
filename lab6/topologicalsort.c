#include <stdio.h>

int a[10][10], n, t[10], indegree[10];
int stack[10], top = -1;

void computeIndegree(int, int[][10]);
void tps_SourceRemoval(int, int[][10]);

int main() {
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    int i, j;
    // Reading the adjacency matrix
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // Compute the indegree of each node
    computeIndegree(n, a);
    
    // Perform source removal-based topological sort
    tps_SourceRemoval(n, a);
    
    // Output the topological sort
    printf("Topological Sort: ");
    for (i = 0; i < n; i++) {
        printf("%d ", t[i]);
    }

    return 0;
}

// Function to compute the indegree of each node
void computeIndegree(int n, int a[][10]) {
    int i, j;
    for (i = 0; i < n; i++) {
        indegree[i] = 0; // Initialize indegree to 0
        for (j = 0; j < n; j++) {
            indegree[i] += a[j][i]; // Sum up all incoming edges
        }
    }
}

// Function to perform the source removal method for topological sorting
void tps_SourceRemoval(int n, int a[][10]) {
    int i, j, v, k = 0;
    
    // Find all nodes with indegree 0 (sources) and add them to the stack
    for (i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            stack[++top] = i;
        }
    }
    
    // Process nodes from the stack
    while (top != -1) {
        v = stack[top--];  // Pop node from stack
        t[k++] = v;        // Add node to topological order
        
        // Reduce indegree of all neighbors and if any becomes 0, add to stack
        for (i = 0; i < n; i++) {
            if (a[v][i] != 0) {
                indegree[i]--;
                if (indegree[i] == 0) {
                    stack[++top] = i;
                }
            }
        }
    }
}
