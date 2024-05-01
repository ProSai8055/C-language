#include<stdio.h>
#include<math.h>
int main(){
    int r;
    double c,a;
    const double PI = 3.142857142857143;
    printf("Enter The Radius for which you want to find circumfernce of circle :\n");
    scanf("%d",&r);
    c=2*PI*r;
    a=PI*r*r;
    printf("The Circumfernce of circle would be %lf\n", c);
    printf("The Area of circle would be %lf\n", a);
}