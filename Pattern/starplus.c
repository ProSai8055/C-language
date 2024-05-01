#include<stdio.h>
int main(){
    int a,b,c,d,f;
    printf("Enter the odd number of pattern :: ");
    scanf("%d",&a);
    for(int k=1;a%2==0;k++){
        printf("Enter the odd number only your dumbo :: ");
        scanf("%d",&a);
    }
    d=(a/2)+1;
    for(int i=1;i<=a;i++){
        for(int j=1;j<=a;j++){
            if(d==i || d==j){
                
                printf("*");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }
}