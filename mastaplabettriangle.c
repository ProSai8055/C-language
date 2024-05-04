#include <stdio.h>
int main()
{
    int s, a, d, b;
    printf("Enter the size of pyramid :");
    scanf("%d", &a);
    int m = 1;

    for (int i = 0; i < a; i++)
    {
        int q = ((m + i) / 2) + 1;
        char c='A';
        for (int j = 1; j <= a - i - 1; j++)
        {
            printf(" ");
        }

        for (int k = 1; k <= m + i; k++)
        {
            printf("%c", c);

            if (k < q)
                c++;
            else
                c--;
        }
        m++;
        printf("\n");
    }
}
