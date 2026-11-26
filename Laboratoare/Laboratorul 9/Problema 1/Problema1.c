#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *sterg(char *p, int poz, int cate)
{
    int n = strlen(p);
    for (int i = poz; i+cate <= n; i++)
        p[i] = p[i + cate];
    char *q = realloc(p, n - cate + 1);
    return q ? q : p;
}

char *inserez(char *p, char *s, int poz)
{
    int n = strlen(p);
    int m = strlen(s);
    char *q = realloc(p, n + m + 1);
    if (!q) return p;
    p = q;
    for (int i = n; i >= poz; i--)
        p[i + m] = p[i];
    for (int i = 0; i < m; i++)
        p[poz + i] = s[i];
    return p;
}

char *inlocuire(char *p, char *cuv1, char *cuv2)
{
    int ok = 0;
    int m = strlen(cuv1);
    int n = strlen(cuv2);
    int i = 0;
    while (p[i] != '\0')
    {
        ok = 1;
        for (int j = 0; j < m; j++)
        {
            if (p[i + j] != cuv1[j])
            {
                ok = 0;
                break;
            }
        }
        if (ok == 1)
        {
            p = sterg(p, i, m);
            p = inserez(p, cuv2, i);
            i += n;
        }
        else
            i++;
    }
    return p;
}


int main()
{
    char cuv1[10], cuv2[10];
    char *sir=malloc(100*sizeof(char));     // alocam dinamic sirul
    if (sir == NULL){
        printf("Eroare la alocare \n");
        return 1;
    }

    fgets(sir, 100, stdin);
    scanf("%s %s", cuv1, cuv2);
    printf("\n");

    sir = inlocuire(sir, cuv1, cuv2);       // inlocuim in sir cuv1 cu cuv2
    puts(sir);

    free(sir);                              // eliberam memoria
    return 0;
}
