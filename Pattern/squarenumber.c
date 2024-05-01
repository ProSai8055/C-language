#include<stdio.h>
int main(){
    int a,b,c,d;
    printf("Enter the length of square: ");
    scanf("%d",&a);
    for (int i=1;i<=a;i++){
        int k=1;
        for(int j=1;j<=a;j++){
            
            printf("%d",j);
            k++;
        }
        printf("\n");
    }
}