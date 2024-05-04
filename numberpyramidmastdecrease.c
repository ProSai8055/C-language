#include<stdio.h>
int main(){
    int a,nsp,nst,d;

    printf("Enter an number for patter :: ");
    scanf("%d",&a);
    nst=a-1;
    nsp=1;
    d=a;
    int v=1;
    int s=2*d-1;
    int ml=s/2+1;
int c=1;
       for(int j=1;j<=2*d-1;j++){
        
            printf("%d",v);
            if(c<ml) v++;
           else v--;
           c++;
        }
        printf("\n");
    for(int i=1;i<=a;i++){
        int s=1;
        int b=1;
        for(int k=1;k<=nst;k++){
            printf("%d",s);
           
           if(b<ml) s++;
           else s--;
            b++;
        }
        for(int l=1;l<=nsp;l++){
            printf(" ");
       
           if(b<ml) s++;
           else s--;
                b++;
        }
        for(int m=1;m<=nst;m++){
            printf("%d",s);
       
            if(b<ml) s++;
           else s--;
                b++;
        }
     
       nsp+=2;
       nst--;
        
    
        printf("\n");
    }
}