#include <stdio.h>
#include <stdlib.h>

int main(){
    int n=4;
    int arr[n];
    printf("enter the elements");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf(" the elements are");

    for(int i=0;i<n;i++){
        printf("%d \n",arr[i]);
    }
    int min= arr[0];
    int min2= arr[0];
    for(int i=1;i<n;i++){
        if (arr[i]<min){
            min=arr[i];
        }
        
    }
    
    for(int i=1;i<n;i++){
        if(arr[i]<min2 && arr[i]>min){
            min2=arr[i];
        }
    }
    printf("%d is the min element \n",min);
    printf("%d is the second min element \n",min2);
}