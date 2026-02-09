//Problem: A secret system stores code names in forward order. To display them in mirror format, you must transform the given code name so that its characters appear in the opposite order.
#include<stdio.h>
#include<string.h>
int main(){
   int  n=100;
    char str[n];
    printf("enter the code name:");
    if(scanf("%99s",str)!=1) return 0;
    int len = strlen(str);
    printf("mirror format: ");
    for(int i=0;i<len/2;i++){
            char temp = str[i];
            str[i] = str[len-1-i];
        str[len-1-i] = temp;
    }
    printf("%s\n",str);
    return 0;
}
 