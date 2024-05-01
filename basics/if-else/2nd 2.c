#include<stdio.h>
#include<string.h>
int main(){
    int a,b,c,d;
    printf("Enter the sides of traingles ::\n ");
    scanf("%d %d %d",&a,&b,&c);
    if((a+b)>c){
        if((b+c)>a){
            if((c+a)>b){
                printf("It can form a  triangle ::");
            }
        }
    }
    else printf("It can't be a triangle");
}
