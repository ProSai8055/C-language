#include<stdio.h>
int main(){
    int a,b,c,d;
    c=1;
    printf("Enter two numbers : ");
    scanf("%d %d",&a,&b);
    for(int i=1;i<=b;i++) c=c*a;
    printf("The number is %d",c);   
}