#include <stdio.h>
int main()
{
    int l, b, a, p;
    printf("Enter the A three diigit of rectangle\n");
    scanf("%d", &l);
    // if(l>=100 && l<=999){
    //     printf("%d lies is three digit ",l);
    // }
    // else{
    //     printf("Its not three digit");
    // }
    printf("Enter the Breath of rectangle\n");
    scanf("%d", &b);
    a = l * b;
    p = 2 * (l + b);
    if (a > p)
    {
        printf("%d Area of recangle is greater then %d perimeter\n", a, p);
    }
    // else if(c<s){
    //     printf("The Goof owner is in Profit:))))\n");
    //     int a=s-c;
    //     printf("He has Gained Rs %d",a);
    // }
    else
    {
        printf("Area is smaller");
    }
}
// #include<stdio.h>
// int main(){
//     int l,b,a,p;
//     printf("Enter the A three diigit of rectangle\n");
//     scanf("%d",&l);
//     if(l%3==0 && l%5==0){
//         printf("its div by 3 and 5");
//     }
//     // if(l>=100 && l<=999){
//     //     printf("%d lies is three digit ",l);
//     // }
//     // else{
//     //     printf("Its not three digit");
//     // }
//     // printf("Enter the Breath of rectangle\n");
//     // scanf("%d",&b);
//     // a=l*b;
//     // p=2*(l+b);
// // if(a>p){
// //     printf("%d Area of recangle is greater then %d perimeter\n",a,p);
// // }
// // // else if(c<s){
// // //     printf("The Goof owner is in Profit:))))\n");
// // //     int a=s-c;
// // //     printf("He has Gained Rs %d",a);
// // // }
// else{
//     printf("not");
//     }

// }


