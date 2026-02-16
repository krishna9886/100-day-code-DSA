#include <stdio.h>

int main() {
    int n;
    
    printf("enter the size of array:");
    if (scanf("%d", &n) != 1) return 0;

    int arr[n];
    int visited[n]; 
    printf("enter elements of array:");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        visited[i] = 0; 
    }

    for(int i = 0; i < n; i++) {
        
        if(visited[i] == 1) {
            continue;
        }
        
        int count = 1;
        
        for(int j = i + 1; j < n; j++) {
            if(arr[i] == arr[j]) {
                count++;
                visited[j] = 1; // Mark duplicate as visited so we don't count it again
            }
        }
        
        printf("%d:%d ", arr[i], count);
    }
    
    return 0;
}