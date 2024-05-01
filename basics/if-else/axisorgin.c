#include<stdio.h>
int main(){
    int a,v,c,b,d,e,f,g;
    printf("Enter the value of x and y coordinate\n");
    scanf("%d %d",&a,&b);
    if(a==0 || b==0){
        if(a==0 && b==0){
        printf("The point lies on Origin");
            }
    else if(a==0){
        printf("The point lies on y axis");
    }
    else 
    printf("Its lies on x axis");
    }
    else
    printf("Its lies on some quardant");
}