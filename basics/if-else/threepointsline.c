#include <stdio.h>
int main()
{
    int a, b, v, c, f, d, e, g, h;
    printf("Enter the x1 and y1 points :: ");
    scanf("%d %d", &a, &b);
    printf("Enter the x2 and y2 points :: ");
    scanf("%d %d", &c, &d);
    printf("Enter the x3 and y3 points :: ");
    scanf("%d %d", &e, &f);
    double m, n;
    m = (d - b) / (c - a);
    n = (f - d) / (e - c);
    if (m == n)
        printf("Its lies on same line");
    else
        printf("Its doesn't lie on same line");
}
