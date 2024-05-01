#include<stdio.h>
int main(){
    int a,b,c,d;
    printf("Enter the length of traingle's base: ");
    scanf("%d",&a);

    for (int i=1;i<=a;i++){
    int t=0;
    int s=1;

        for(int j=1;j<=i;j++){
        //     if(i%2==0){
        //     printf("%d ",t);
        //     t++;
        //     }
    
        //     else{
        //         printf("%d ",s);
        //         s++;
        //     }
        //     if(s==2 || t==2) {
        //         s=0;
        //         t=0;
        // }
        if((i+j)%2==0) printf("1");
        else printf("0");
        }
  
        printf("\n");
    }
}