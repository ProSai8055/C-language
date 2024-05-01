#include<stdio.h>
int main(){
    int a,b,c,d;
    b=1;
    c=1;
    printf("Enter the nth term of fibonacci :: \n");
    scanf("%d",&a);

    for(int i=1;i<=a-2;i++){
        
        d=b+c;
        b=c;
        c=d;
       
    }
if(a==1) printf("The fibonacci series term: 1\n");
else if(a==2) printf("The fibonacci series term :2\n");
else printf("The fibonacci series :%d\n",d);
}