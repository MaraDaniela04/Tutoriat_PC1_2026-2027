#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, a[100][100], i, j;
    int *p= &a[0][0];
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", p+i*n+j);
    printf("\n");

    //Afisarea elementelor matricei
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%d ", *(p+i*n+j));
        printf("\n");
    }
    printf("\n");

    //Afisarea elementului de la intersectia diagonalelor
    if (n%2!=0)
        printf("%d", *(p+n*(n/2)+n/2));
    printf("\n");

    //Elementele de pe diagonale
    for(i = 0; i < n; i++)
        printf("%d ", *(p+i*n+i));
    printf("\n");
    for(i = 0; i < n; i++)
        printf("%d ", *(p+i*n+(n-1-i)));

    return 0;
}
