#include<stdio.h>
int main(){
    for(int i=1;i<=200;i++){
        if(i%19==0) printf("%d ",i);
    }
    int a;
    printf("\n");
    printf("Enter a number so I can write a table of it\n");
    scanf("%d",&a);
    for(int i=a;i<=(a*10);i=i+a){
        printf("%d ",i);
    }
}