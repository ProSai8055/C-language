#include<stdio.h>
int main(){
    int a,b,c,d;
    printf("Enter the length of traingle's base: ");
    scanf("%d",&a);
    int t=a;
    for (int i=1;i<=a;i++){
        int s=1;
        for(int j=1;j<=i;j++){
            printf("%d",s);
            s=s+2;
        }
        t--;
        printf("\n");
    }
}