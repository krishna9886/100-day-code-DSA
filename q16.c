#include <stdio.h>

int main() {
    int n;
    printf("enter the size of array:");
    scanf("%d",&n);
    int arr[n];
    printf("enter the elements :");
    for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
    }
    int max=arr[0];
    int min=arr[0];
    for (int i=1;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
        if(arr[i]<min){
            arr[i]=min;
        }

    }
    printf("min: %d\n",min);
    printf("max: %d\n",max);

    return 0;
}
