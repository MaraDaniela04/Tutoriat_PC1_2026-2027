//rezolvare fara fisiere

#include <stdio.h>

struct polinom {
    long long coef[102];
} a, b, r;

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    for (int i = 0; i <= n; i++) {
        char semn, x;
        int putere;
        long long coeficient;
        
        scanf(" %c%lld%c^%d", &semn, &coeficient, &x, &putere);
        
        if (semn == '+')
            a.coef[putere] += coeficient;
        else if (semn == '-')
            a.coef[putere] -= coeficient;
    }

    for (int i = 0; i <= m; i++) {
        char semn, x;
        int putere;
        long long coeficient;
        
        scanf(" %c%lld%c^%d", &semn, &coeficient, &x, &putere);
        
        if (semn == '+')
            b.coef[putere] += coeficient;
        else if (semn == '-')
            b.coef[putere] -= coeficient;
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            r.coef[i + j] += a.coef[i] * b.coef[j];
        }
    }

    for (int i = 0; i <= m + n; i++) {
        printf("%lld ", r.coef[i]);
    }
    printf("\n");

    return 0;
}

/* Exemplu date de intrare:
1 1
+2x^1 +3x^0
+1x^1 +1x^0
*/
