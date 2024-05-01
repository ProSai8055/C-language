#include <stdio.h>
#include <string.h>
int main()
{
    int a, b, c, d;
    // printf("Enter the sides of traingles ::\n ");
    // scanf("%d %d %d", &a, &b, &c);
    // if (((a + b) > c) && ((c + a) > b) &&((b + c) > a)) 
    // {
       
    //             printf("It can form a  triangle ::");
    //         }
         
    //  else // if ((a+b)<c ||(a+c)<b||(b+c)<a)
    // {
    //     printf("It can't be a triangle");
    // }
    printf("Enter the Age of Ram ::\n");
    scanf("%d",&a);
    printf("Enter the Age of Shyam::\n");
    scanf("%d",&b);
    printf("Enter the Age of Ajay ::\n");
    scanf("%d",&c);    
    if(a<b && a<c){
        printf("Ram is the youngest among all ");
    }
    else if(b<a && b<c){
        printf("Shyam is the youngest among all ");
    }
    else if(c<b && a>c){
        printf("Ajey  is the youngest old teacher among alll ");
    }
}
