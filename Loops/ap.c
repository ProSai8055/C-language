#include<stdio.h>
int main(){
    int a,b,c;
    printf("Enter a last number till where you want the ap\n");
    scanf("%d",&a);
    for(int i=1;i<=((2*a)-1);i=i+2)
    printf("%d ",i);



    // 4,7,10,13,16   d=3  a=4  4+(n-1)3  4+3n-3   3n+1
    printf("\nEnter the last nth term :: ");
    scanf("%d",&b);
    for(int i=4;i<=(3*b)+1;i=i+3)
        printf("%d ",i);

}