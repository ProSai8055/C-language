#include<stdio.h>
#include<math.h>
int main(){
double a,b,c;
printf("Enter the sides of right angled triangle : \n");
scanf("%lf %lf",&a,&b);
c=sqrt((a*a)+(b*b));
printf("The hypotenuse of triangle would be %lf",c);
}