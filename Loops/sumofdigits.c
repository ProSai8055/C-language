#include<stdio.h>
int main(){
    int a,b,c,d,e,f,g;
      int t=0;
    printf("Enter a number :");
    scanf("%d",&a);
    if(a<0){
        a=a*(-1);
        g=5;
    }
    c=a;
    b=0;
    while(c>0){
        t=c%10;
        // if(t%2==0){
        b=b+t;
      
        // }
          c=c/10;
    }
    if(g==5){
        a=a*(-1);
    }
    printf("The sum of digits of %d is = %d",a,b);
}