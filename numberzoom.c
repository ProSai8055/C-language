#include<stdio.h>
int main(){
    int a,v,b,c;
    printf("Enter the size of square :: ");
    scanf("%d",&a);
    for(int i=1;i<=2*a-1;i++)
    {
        v=1;
        for(int j=1;j<=2*a-1;j++){
            b=i;
            c=j;
            if(i>a) b=(2*a)-i;
            if(j>a) c=(2*a)-j;
          
            if(b>c)  v=(a+1)-c;
            else  v=(a+1)-b;
             
            printf("%d",v);  
           
        }
        printf("\n");
    }
}