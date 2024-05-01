#include<stdio.h>
int main()
{
    int a,c,v;
    int f=0;
    printf("Enter a number :");
    scanf("%d",&a);
    for (int i=1;i<=a;i++){
        if((a%1==0 && a%a==0) && a%i==0){
                f++;
        }
        else{

        }
    }
    if(f==2)
    printf("Its prime %d",a);
    else
    printf("Its not a prime %d",a);
}