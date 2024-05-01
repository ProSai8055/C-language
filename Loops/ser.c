#include<stdio.h>
int main(){
    int a,b,d,c,e;
    b=0;
    printf("Enter nth term :");
    scanf("%d",&a);
    for(int i=1;i<=a;i++){
        if(i%2==0) b=b-i;
        else  b=b+i;
    }
    printf("The Sum of series is :: %d",b);
}