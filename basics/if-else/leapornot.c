#include<stdio.h>
int main(){
    int a,f;
    printf("Enter a year so I will let you know wheter its leap or not\n");
    scanf("%d",&a);
    if((a%4==0 || a%400==0)&& (a%100!=0)){
        printf("Its leap year");
    }
    else
    {
        printf("Not");
    }
}