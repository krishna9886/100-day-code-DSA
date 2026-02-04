//Problem: Given an array of n integers, reverse the array in-place using two-pointer approach.
#include<stdio.h>
int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr1[n];
    printf("enter elements:");
    for(int i=0;i<n;i++){
        scanf("%d",&arr1[i]);
    }
    for(int i=0;i<n/2;i++){
        int temp=arr1[i];
        arr1[i]=arr1[n-i-1];
        arr1[n-i-1]=temp;
    }
    printf("Reversed array: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr1[i]);
    }
    return 0;
}