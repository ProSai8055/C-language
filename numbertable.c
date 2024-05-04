#include<stdio.h>
int main(){
    int a,nsp,nst,d;

    printf("Enter an number for patter :: ");
    scanf("%d",&a);
    nst=a-1;
    nsp=1;
    d=a;
       for(int j=1;j<=2*d-1;j++){
            printf("%d",j);
        }
        printf("\n");
    for(int i=1;i<=a;i++){
        int s=1;
        for(int k=1;k<=nst;k++){
            printf("%d",s);
            s++;
        }
        for(int l=1;l<=nsp;l++){
            printf(" ");
            s++;
        }
        for(int m=1;m<=nst;m++){
            printf("%d",s);
            s++;
        }
     
       nsp+=2;
       nst--;
        
    
        printf("\n");
    }
}