#include<stdio.h>
int main(){
    int a,b,c,d;
    a=0;
    printf("Enter a digit :");
    scanf("%d",&b);
    if(b<0){
        d=4;
        b=b*(-1);
    }
    c=b;
    while(c>0){
        a++;
        c=c/10;
    }
    if(d==4) b=b*(-1);
    printf("The Number %d contains %d digits",b,a);
}