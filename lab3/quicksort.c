#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 5000

// Function declarations
void quicksort(int[], int, int);
int partition(int[], int, int);

int main()
{
    int i, n, a[MAX], ch = 1;
    clock_t start, end;

    while(ch)
    {
        printf("\nEnter the number of elements: ");
        scanf("%d", &n);
        
        // Generate random array
        for(i = 0; i < n; i++)
            a[i] = rand() % 200;
        
        printf("The randomly generated array is:\n");
        for(i = 0; i < n; i++)
            printf(" %d ", a[i]);
        
        start = clock();  // Start timing
        quicksort(a, 0, n - 1);  // Call quicksort
        end = clock();  // End timing
        
        printf("\n\nThe sorted array elements are:\n");
        for(i = 0; i < n; i++)
            printf("%d\n", a[i]);
        
        printf("\nTime taken = %f seconds\n", ((double)(end - start)) / CLOCKS_PER_SEC);  // Print time taken
        
        // Ask if user wants to continue
        printf("\nDo you wish to continue (0/1)? ");
        scanf("%d", &ch);
    }

    return 0;
}

// Function to implement QuickSort
void quicksort(int a[], int low, int high)
{
    int mid;
    if(low < high)
    {
        mid = partition(a, low, high);  // Partition the array
        quicksort(a, low, mid - 1);     // Sort the left subarray
        quicksort(a, mid + 1, high);    // Sort the right subarray
    }
}

// Function to partition the array
int partition(int a[], int low, int high)
{
    int key, i, j, temp, k;
    key = a[low];  // Pivot element is the first element
    i = low + 1;   // Start from the next element
    j = high;      // Start from the last element
    
    // Loop until i <= j
    while(i <= j)
    {
        // Move i to the right as long as elements are smaller than or equal to pivot
        while(i <= high && a[i] <= key)
            i = i + 1;
        
        // Move j to the left as long as elements are larger than pivot
        while(a[j] > key)
            j = j - 1;
        
        // If i < j, swap elements
        if(i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
        else
        {
            break;  // i >= j, stop the loop
        }
    }
    
    // Swap the pivot element with the element at position j
    temp = a[low];
    a[low] = a[j];
    a[j] = temp;

    return j;  // Return the pivot index
}

