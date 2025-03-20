// Write a program in C to find the second largest element in an array.

#include <stdio.h>
#include <stdlib.h>

int main(){
    int n=6;
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    for(int i=0;i<n;i++){
        printf("%d \n",arr[i]);
    }
    int max= arr[0];
    int max2= arr[0];
    for(int i=1;i<5;i++){
        if (arr[i]>max){
            max=arr[i];
        }
        
    }
    
    for(int i=1;i<5;i++){
        if(arr[i]>max2 && arr[i]<max){
            max2=arr[i];
        }
    }
    printf("%d is the max element \n",max);
    printf("%d is the second max element \n",max2);
}

// Write a program in C to find the sum of the left diagonals of a matrix.





