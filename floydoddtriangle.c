#include<stdio.h>
int main(){
    int a,b,c,d;
    printf("Enter the length of traingle's base: ");
    scanf("%d",&a);
    int t=1;
    for (int i=1;i<=a;i++){
        for(int j=1;j<=i;j++){
            printf("%d ",t);
            t=t+2;
        }
  
        printf("\n");
    }
}