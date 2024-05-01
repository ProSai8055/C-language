#include<stdio.h>
int main(){
    int a,b;
    scanf("%d",&a);
    // int x=4,y=3,z;
    // z=x-- -y;
    // printf("\n%d\n%d\n%d",x,y,z);
    // scanf("%d",&a);
    for (int i=1;i<=a;i++){
        if(i%2==0){
            continue;
        }
        printf("%d ",i);
    }
    // int x=4,y=0,z;
    // while(x>=0){
    //     if(x==y)
    //     break;
    // else{
    //     printf("\n%d %d",x,y);
    //     x--;
    //     y++;
    // }
    }
