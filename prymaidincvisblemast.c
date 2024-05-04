#include<stdio.h>
int main(){
    int a,nsp,nst,d;

    printf("Enter an number for patter :: ");
    scanf("%d",&a);
    nsp=0;
    nst=a;
    d=a;
    for(int i=1;i<=a;i++){
        for(int j=1;j<=d;j++){
            printf("*");
        }
        for(int k=1;k<=nsp;k++){
            printf(" ");
        }
        for(int k=1;k<=nsp;k++){
            printf(" ");
        }
        for(int l=1;l<=nst;l++){
            printf("*");
        }
        d--;
        nsp++;
        printf("\n");
        nst--;
      

    }
}