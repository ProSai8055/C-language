#include<stdio.h>
int main(){
    int a,b,c,d,e;
    printf("Enter the lenght of rectangle ");
    scanf("%d",&a);
    printf("Enter the breadth of rectangle ");
    scanf("%d",&b);
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            if(i==1 || j== 1 || i==a ||  j==b){
                printf("*");
            }
            else printf(" ");
        }
        printf("\n");
    }
}