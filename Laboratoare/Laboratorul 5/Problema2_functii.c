#include <stdio.h>
#include "functii.h"

void sm(int a, int b) {
    printf("%d\n", a+b);
}
void d(int a, int b) {
    printf("%d\n", a-b);
}
void p(int a, int b) {
    printf("%d\n", a*b);
}
void q(int a, int b) {
    if (b != 0)
        printf("%d\n", a/b);
    else
        printf("Eroare");
}
void r(int a, int b) {
    printf("%d\n", a%b);
}
