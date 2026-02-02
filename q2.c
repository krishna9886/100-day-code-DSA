/*Delete an Element from an Array

Problem: Write a C program to delete the element at a given 1-based position pos from an array of n integers. Shift remaining elements to the left.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer pos (1-based position to delete)

Output:
- Print the updated array with (n-1) elements, space-separated
*/
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
    int pos;
    printf("enter the elements postion to be deleted:");
    scanf("%d",&pos);
    for(int i=pos-1;i<n-1;i++){
        arr1[i]=arr1[i+1];

    }
    n--;
    for(int i=0;i<n;i++){
        printf("%d ",arr1[i]);
    }



return 0;}