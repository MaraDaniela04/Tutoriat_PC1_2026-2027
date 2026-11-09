#include <stdio.h>
#include <string.h>

int main()
{
    FILE* f = fopen("citire.in", "r");        
    if (f == NULL) {
        printf("Eroare citire.in");
        return 1;
    }

    char l1, l2, text[100];
    fscanf(f, "%c %c\n", &l1, &l2);
    fgets(text, sizeof(text), f);
    
    fclose(f);
    
    for (int i = 0; i < strlen(text); i++)
        if (text[i] == l1)
            text[i] = l2;
            
    FILE* g = fopen("citire.in", "w");        
    if (f == NULL) {
        printf("Eroare citire.in");
        return 1;
    }
    fputs(text, g);
    
    fclose(g);
    
    return 0;
}
