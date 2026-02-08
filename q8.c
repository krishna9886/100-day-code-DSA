#include<stdio.h>
void power(int a, int b){
    if(b==0){
        printf("1\n");
    } else if(b>0){
        int result = 1;
        for(int i=0; i<b; i++){
            result *= a;
        }
        printf("%d\n", result);
    }
}
int main(){
    int a,b;
    printf("enter a and b:");
    scanf("%d  %d",&a,&b);
    if(b<0){
        printf("enter +ve integer for b.\n");
    } else {
        power(a,b);
    }
}