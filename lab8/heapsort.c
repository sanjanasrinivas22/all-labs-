#include <stdio.h>
#include <time.h>

void heapify(int a[], int n, int i) {
    int largest = i;  // Initialize largest as root
    int left = 2 * i + 1;  // Left child index
    int right = 2 * i + 2;  // Right child index
    int temp;

    // If left child is larger than root
    if (left < n && a[left] > a[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && a[right] > a[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;

        // Recursively heapify the affected sub-tree
        heapify(a, n, largest);
    }
}

void heapsort(int a[], int n) {
    int i, temp;

    // Build a maxheap
    for (i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);

    // One by one extract elements from heap
    for (i = n - 1; i >= 1; i--) {
        // Move current root to end
        temp = a[0];
        a[0] = a[i];
        a[i] = temp;

        // Call heapify on the reduced heap
        heapify(a, i, 0);
    }
}

int main() {
    int i, n, ch = 1;
    int a[20];
    clock_t start, end;

    while (ch) {
        printf("\nEnter the number of elements to sort: ");
        scanf("%d", &n);

        printf("\nEnter the elements to sort: ");
        for (i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }

        start = clock();  // Start the timer
        heapsort(a, n);  // Call heapsort
        end = clock();  // End the timer

        printf("\nThe sorted list of elements is:\n");
        for (i = 0; i < n; i++) {
            printf("%d\n", a[i]);
        }

        // Calculate and print the time taken
        printf("\nTime taken is %lf CPU cycles\n", (double)(end - start) / CLOCKS_PER_SEC);

        printf("\nDo you wish to run again (0/1)? ");
        scanf("%d", &ch);
    }

    return 0;
}

