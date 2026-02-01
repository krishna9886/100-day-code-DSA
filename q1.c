#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr1[n]; 
    printf("enter elements:");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr1[i]);
    }
    int pos, x;
    printf("position of elem to be inserted:");
    scanf("%d", &pos);
    printf("enter element to be inserted:");
    scanf("%d", &x);
    
    for(int i = n-1; i >= pos-1; i--) {
        arr1[i+1] = arr1[i];
    }
    arr1[pos-1] = x;
    n++; 
    for(int i = 0; i < n; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");
    return 0;
}
