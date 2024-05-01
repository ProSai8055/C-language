#include<stdio.h>
 int birth(char y[],int x) // data type + parameter
 {
    printf("\nYou are name is %s",y);
    printf("\n YOu are %d old",x);
 }
 double square(double x){
    return x*x;
 }
 int main(){
/*    char n[]="sai";
    int age = 18;*/
    birth("Om",23); // agruments == passing 
   double s= square(29);
   printf("\n%0.3lf",s);
    }
    

    // returns = returns a value back to calling function 