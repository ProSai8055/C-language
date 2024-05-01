#include<stdio.h>
int main(){
    int a,b,c,f;
  
    printf("Enter the number of lines of traingle :");
    scanf("%d",&a);
    for(int i=1;i<=a;i++){
          char s='A';
        for(int j=1;j<=i;j++){
            if(i%2==0){
            printf("%c ",s);
           s++;
            }
            else{
                printf("%d ",j);
            }
        }
        printf("\n");
    }
}