#include<stdio.h>
int main(){
    int a,b,c,d;
    printf("Enter a number whose factorial you want to know :: ");
    scanf("%d",&a);
    b=1;
    for(int i=1;i<=a;i++){
    b=b*i;
    printf("The factorial of %d is : %d\n",i,b);
        }
    }
    