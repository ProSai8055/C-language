// for loop = repeats a section of code of limited amount of time

/*
#include<stdio.h>
int main(){
    for(int i=10;i>=1;i--){
        printf("%d \n",i);
    }
}
*/
//while = repeats a section of code possibly unlimited times while the condition remains true 
// a while loop might not excute at all 

#include<stdio.h>
#include<string.h>
int main(){
    char n[25];
 
    printf("enter your name");
    fgets(n,25,stdin);
    n[strlen(n)-1]='\0';

       while(strlen(n)==0){
        printf("You have not entered your name");
          printf("enter your name");
    fgets(n,25,stdin);
    n[strlen(n)-1]='\0';
       }
    printf("Hello %s",&n);
}

