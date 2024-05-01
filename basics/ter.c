//ternary opeator == shorcut of if / else if when assignning / returingn a vlaue 
// (condition) ?  x : y   x will printfif condition is true or else y will printf

#include<stdio.h>
int main(){
int x,y;
    printf("Enter your two numbers ");
    scanf("%d%d",&x,&y);
    (x<y)?printf("%d is small",x):printf("%d is small",y);
    
}