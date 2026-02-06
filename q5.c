#include <stdio.h>

int main() {
    
    ;
    int size1, size2;
    printf("Enter size of first log: ");
    scanf("%d", &size1);
    int log1[size1];

    printf("Enter elements of first log:\n");
    for (int i = 0; i < size1; i++){
         scanf("%d", &log1[i]);
    }

    printf("Enter size of second log: ");
    scanf("%d", &size2);
    int log2[size2];
    printf("Enter elements of second log:\n");
    for (int i = 0; i < size2; i++){
         scanf("%d", &log2[i]);
    }

    int total = size1 + size2;
    int merged[total];

    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2) {
        if (log1[i] <= log2[j]) merged[k++] = log1[i++];
        else merged[k++] = log2[j++];
    }

    while (i < size1){ 
    merged[k++] = log1[i++];
    }
    while (j < size2){
         merged[k++] = log2[j++];
    }

    printf("Merged array:");
    for (int t = 0; t < total; t++) {
        printf(" %d", merged[t]);
    }
    printf("\n");

    return 0;
}