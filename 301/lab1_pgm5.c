// Write a program in C to find the second smallest element in an array.

#include <stdio.h>
#include <stdlib.h>

int main(){
    int arr[5]={1,2,3,4,5};
    int min= arr[0];
    int min2= arr[0];
    for(int i=1;i<5;i++){
        if (arr[i]<min){
            min=arr[i];
        }
    }
    
    for(int i=1;i<5;i++){
        if(arr[i]<min2 && arr[i]>min){
            min2=arr[i];
        }
    }
    printf("%d is the min element \n",min);
    printf("%d is the second min element \n",min2);
}