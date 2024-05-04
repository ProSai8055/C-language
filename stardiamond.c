#include <stdio.h>
int main()
{
    int nsp, nst, ml, a;

    printf("Enter the odd number of pattern :: ");
    scanf("%d", &a);
    while (a % 2 == 0)
    {
        printf("Enter the odd number only your dumbo :: ");
        scanf("%d", &a);
    }
    nsp = a / 2;
    nst = 1;
    ml = a / 2 + 1;
    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= nsp; j++)
        {
            printf(" ");
        }
        for (int k = 1; k <= nst; k++)
        {
            printf("*");
        }
        if (i < ml)
        {
            nsp--;
            nst += 2;
        }
        else
        {
            nsp++;
            nst -= 2;
        }
        printf("\n");
    }
}