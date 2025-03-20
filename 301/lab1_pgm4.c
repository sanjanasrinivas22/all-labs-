// Write a program in C to count the total number of duplicate elements in an array.

#include <stdio.h>

int main(){
    int i,j;
    int n,total=0;
    printf("enter the number of the elememts in the array \n");
    scanf("%d",&n);
    int a[n];

    printf("enter the array elements are:");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    printf("the array elements are:");
    for(int i=0;i<n;i++){
        printf("%d \n",a[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if (a[i]==a[j])
                total=total+1;
            else
                total=total;
        }

    }

    printf("%d is the total number of duplicates",total);
}