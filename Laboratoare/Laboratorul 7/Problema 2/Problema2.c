#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float radical(float x){
    return sqrt(x);
}

float invers(float x){
    return 1/x;
}

float sinus(float x){
    return sin(x);
}

int main()
{
    float (*operatii[3])(float) = {radical, invers, sinus};

    float x;
    scanf("%f", &x);

    printf("Radicalul din %.2f este %.2f \n", x, (*operatii)(x));       /// <=> operatii[0](x)
    printf("Inversul lui %.2f este %.2f \n", x, (*(operatii + 1))(x));  /// <=> operatii[1](x)
    printf("Sinusul lui %.2f este %.2f \n", x, (*(operatii + 2))(x));   /// <=> operatii[2](x)

    return 0;
}
