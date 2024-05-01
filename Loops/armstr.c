#include<stdio.h>
int main(){
    int a,b,c,d,e;
    a=1;
 
    for(int i=1;i<=500;i++){
        //printf("%d \n",i);
         e=i;
            d=0;
        while(e>0){
           
            c=e%10;
            d=d+(c*c*c);
            e=e/10;
           
        }
         if(d==i) 
            {
                printf(" %d number is armstrong\n",i);
               
                }
    }
}