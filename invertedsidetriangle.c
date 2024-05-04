#include<stdio.h>
int main(){
    int a,nsp,nst,d;
    printf("Enter the number of lines in the pattern :");
    scanf("%d",&a);
    nsp=0;
    nst=a;
    for(int i=1;i<=a;i++){
        for(int j=1;j<=nsp;j++){
            printf(" ");
        }
        for(int k=1;k<=nst;k++){
            printf("*");
        }
        nsp++;
        nst--;
        printf("\n");
    }
}