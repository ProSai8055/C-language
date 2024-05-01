//function protoype = ensures that calls to a function are made witht the correct agruments

#include<stdio.h>
void hell(char[], int, int); // function protoype
int main(){
    hell("RU",3,7) ;
}

void hell(char s[],int a,int r)
{
    printf("\nYou are name is %s",s);
    printf("\nYou are %d old",a);
    printf("\nYou in %d std",r);
}What are the features of pointers? Write a C program to print address of a
variable
