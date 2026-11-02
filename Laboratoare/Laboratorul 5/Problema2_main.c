#include <stdio.h>
#include <stdlib.h>
#include "functii.h"

int main() {
    int a, b;
    char s;
    scanf("%d%c%d", &a, &s, &b);
    switch (s) {
        case '+': {
            sm(a, b);
            break;
        }
        case '-': {
            d(a, b);
            break;
        }
        case '*': {
            p(a, b);
            break;
        }
        case '/': {
            q(a, b);
            break;
        }
        case '%': {
            r(a, b);
            break;
        }
        default: printf("Operatorul nu exista");
    }
    return 0;
}
