// Write a program in C to find the sum of the left diagonals of a matrix.
#include <stdio.h>
#include <stdlib.h>


int main(){
    int m,n;
    int i,j;
    printf("enter the number of rows and columns \n");
    scanf("%d",&m);
    scanf("%d",&n);
    int a[m][n];
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",a[i][j]);
        }
    }

    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("%d",a[i][j]);
        }
        printf("\n");
    }
}