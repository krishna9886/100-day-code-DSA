#include <stdio.h>

int main() {
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter elements: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int k;
    printf("Enter the k positions to rotate: ");
    scanf("%d", &k);

    k = k % n; 
   

    int temp[k]; 

    for(int i = 0; i < k; i++) {
        temp[i] = arr[n - k + i];
    }

    
    for(int i = n - 1; i >= k; i--) {
        arr[i] = arr[i - k];
    }

   
    for(int i = 0; i < k; i++) {
        arr[i] = temp[i];
    }

    printf("Arr after rotation: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}