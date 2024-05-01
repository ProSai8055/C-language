#include<stdio.h>
int main(){
    int c,s,p,l;
    printf("Enter the cost price\n");
    scanf("%d",&c);
    printf("Enter the selling price\n");
    scanf("%d",&s);
    if(c>s){
        printf("The stupid owner is in loss :((((\n");
        int a=c-s;
        printf("He has lost Rs %d",a);
    }
    else if(c<s){
        printf("The Goof owner is in Profit:))))\n");
        int a=s-c;
        printf("He has Gained Rs %d",a);
    }
    else{
        printf("He is nether in pro or loss");
    }

}