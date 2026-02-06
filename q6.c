//roblem: Given a sorted array of n integers, remove duplicates in-place. Print only unique elements in order.
#include<stdio.h>
int main() {
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements of array in sorted order:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int count = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[i-1]) {
            arr[count++] = arr[i];
        }
    }

    printf("elements in order: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", arr[i]);
    }
    

    return 0;
}