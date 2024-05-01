#include<stdio.h>
int main(){
    int a,b,c,d,r,g;
    g=0;
    printf("Enter A Number :: ");
    scanf("%d",&a);
    c=0;
    d=a;
    while(d>0){
        r=d%10;
         g=g*10;
        g=g+r;
        // if((d/10)!=0)
        // if((d/10)==0)
        // break;
       
        d=d/10;
    }
    c=a+g;
    printf("%d\n",c);
    printf("The Reverse Number is %d of number %d",g,a);
}