#include<stdio.h>
int main(){
    int a,v,b;
    printf("Enter a positive number\n");
    scanf("%d",&a);
    if(a<0){
        printf("Please enter postive number!! ::");
        scanf("%d",&a);
    }
    if(a%2==0){
        printf("%d is a even number \n",a);
    }
    else{
        printf("%d is a odd number\n",a);
    }
    if(a%5==0){
        printf("%d is divisible by 5 :)\n ",a);

    }
    else{
        printf("%d is not divisible by 5 :( ",a);
    }}