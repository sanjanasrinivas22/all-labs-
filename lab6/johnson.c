#include <stdio.h>
#include <stdlib.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to generate permutations using recursion and backtracking
void generatePermutations(int arr[], int start, int end) {
    if (start == end) {
        for (int i = 0; i <= end; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    } else {
        for (int i = start; i <= end; i++) {
            swap(&arr[start], &arr[i]);  // Swap to create a new permutation
            generatePermutations(arr, start + 1, end);  // Recursively generate further
            swap(&arr[start], &arr[i]);  // Backtrack (swap back to original)
        }
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input for number of elements.\n");
        return 1;  // Exit if input is invalid
    }

    int* arr = (int*)malloc(n * sizeof(int));  // Dynamically allocate memory for array
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;  // Exit if memory allocation fails
    }

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input for element %d.\n", i + 1);
            free(arr);  // Free allocated memory before exiting
            return 1;
        }
    }

    printf("The permutations are:\n");
    generatePermutations(arr, 0, n - 1);

    free(arr);  // Deallocate memory
    return 0;
}

