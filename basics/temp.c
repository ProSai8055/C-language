#include<stdio.h>
#include<ctype.h>
int main(){
    double a,b,d;
    char c;
    printf("Enter the operator you want to procced with :");
    scanf("%c",&c);
    printf("Enter the numbers for which you want to procced with :");
    scanf("%lf%lf",&a,&b);
    switch (c){
        case '+':
            d=a+b;
            printf("The sum of numbers is : %.2lf",d);
            break;
        case '-':
            d=a-b;
            printf("The Differnece of numbers is : %.1lf",d);
            break;
        case '*':
            d=a*b;
            printf("The Product of numbers is : %0.4lf",d);
            break;
        case '/':
            d=a/b;
            printf("The Quotinet of numbers is : %0.3lf",d);
            break;
        default :
         printf("You have eneter worng operator");

    }
}