#include <stdio.h>

int main() {
    int n,m;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d",&m,&n);
    int identity=1;

    int arr[m][n];
  
    printf("enter your elements:");
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&arr[i][j]);

        }
    }
      for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==j&&arr[i][j]!=1){
                identity=0;
                break;
            }
            if (i != j && arr[i][j] != 0) {
                identity= 0;
                break;

        }
    }
}
        if(identity==1){
        printf("matrix is identity matrix");
        }
        else{
            printf("matrix is non identity matrix");
        }
        return 0;
        }
    

