#include<stdio.h>
int main(){
    int a,b,c,d;
    printf("Enter the length of ulta traingle's base: ");
    scanf("%d",&a);
    int t=a;
    for (int i=1;i<=a;i++){
        for(int j=1;j+i<=a+1;j++){
            printf("%d",j);
        }
        t--;
        printf("\n");
    }
}