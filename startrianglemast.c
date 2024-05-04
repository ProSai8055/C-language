#include<stdio.h>
int main(){
    int a,b,c;
    printf("Enter the number side triangle :: ");
    scanf("%d",&a);
    // for(int i=1;i<=a;i++){
    //     for(int j=1;j<=a;j++){
    //         if((i+j)>a) printf("*");
    //         else  printf(" ");
    //     }
    //     printf("\n");
    // }

    for(int i=1;i<=a;i++){
        for(int j=1;j<=a+1-i;j++){
            printf(" ");
        }
            char s='A';
        for(int k=1;k<=i;k++){
            printf("%c",s);
        s++;
        }
        printf("\n");
    }
}
