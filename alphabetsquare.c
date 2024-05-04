#include<stdio.h>
int main(){
    int a,b,c,f;
  
    printf("Enter the side of square :");
    scanf("%d",&a);
    for(int i=1;i<=a;i++){
          char s='A';
        for(int j=1;j<=a;j++){
            printf("%c ",s);
           s++;
        }
        printf("\n");
    }
}