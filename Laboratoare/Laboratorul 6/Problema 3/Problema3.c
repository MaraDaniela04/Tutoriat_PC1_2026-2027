#include <stdio.h>
#include <string.h>

int main()
{
    FILE* f = fopen("citire.in", "a+");        
    if (f == NULL) {
        printf("Eroare citire.in");
        return 1;
    }

    char text[100];
    fgets(text, sizeof(text), f);
    
    for (int i = 0; i < strlen(text); i++)
        if (text[i] >= 'A' && text[i] <= 'Z')
            text[i] += 32;
        else
            text[i] -= 32;
    
    fprintf(f, "\n");
    fputs(text, f);
    
    fclose(f);
    
    return 0;
}
