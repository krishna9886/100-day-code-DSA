// Implement linear search to find key k in an array. Count and display the number of comparisons performed.
#include<stdio.h>
int main(){
int n;
printf("Enter the number of elements: ");
scanf("%d", &n);
int arr1[n];
printf("enter elements:");
for(int i=0;i<n;i++){
    scanf("%d",&arr1[i]);
}
int k,comparisons=0;
printf("enter the key to be searched:");
scanf("%d",&k);
for(int i=0;i<n;i++){
    comparisons++;
    if(arr1[i]==k){
        printf("Element found at position %d\n",i+1);
        printf("Number of comparisons: %d\n",comparisons);
        return 0;
    }
    }

    printf("Element not found\n");
    printf("Number of comparisons: %d\n",comparisons);
    return 0;


}