#include <stdio.h>
#include <math.h>

int x[20], count = 1;

void queens(int k, int n); 
int place(int k, int j);

int main()
{
    int n, k = 1;

    printf("\nEnter the number of queens to be placed: ");
    scanf("%d", &n);

    queens(k, n);
    return 0;
}

void queens(int k, int n)
{
    int j;
    for (j = 1; j <= n; j++)
    {
        if (place(k, j)) // Check if it's safe to place queen at (k, j)
        {
            x[k] = j; // Place queen at row k, column j

            if (k == n) // If all queens are placed
            {
                printf("\nSolution %d:", count);
                count++;
                for (int i = 1; i <= n; i++)
                    printf("\n\tRow %d <---> Column %d", i, x[i]);
                printf("\nPress Enter to continue...\n");
                getchar();  // Wait for user input to show next solution
            }
            else
                queens(k + 1, n); // Recursively place queens in next rows
        }
    }
}

int place(int k, int j)
{
    int i;
    for (i = 1; i < k; i++) // Check all previous rows
    {
        // Check if column or diagonal is already occupied
        if ((x[i] == j) || (abs(x[i] - j) == abs(i - k)))
            return 0;  // Not safe to place queen at (k, j)
    }
    return 1;  // Safe to place queen at (k, j)
}

