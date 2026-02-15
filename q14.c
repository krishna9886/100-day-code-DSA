#include <stdio.h>

int main() {
    int n,m;
    int sum=0;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d",&m,&n);
    if(m!=n){
        printf("not possible");
        return 0;
    }
    
    int arr[m][n];

  
    printf("enter your elements:");
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    for(int i=0;i<m;i++){
        sum=sum+arr[i][i];
    }
    printf("sum of digonal elements is :%d\n",sum);
    return 0;
    
}
