#include<stdio.h>
int main(){
    int a,b,c,d,e;
    float n;
        // printf("Enter the values of two integers \n");
        // scanf("%d%d",&a,&b);
        // c=a/b;
        // d=a-(c*b);
        // printf("The Remainder is %d",d);
    printf("Enter a floating number \n");
    scanf("%f",&n);
    a=n;
    long z=n-a;
    printf("The decimal part is :: %lf",z);
    return 0;
}