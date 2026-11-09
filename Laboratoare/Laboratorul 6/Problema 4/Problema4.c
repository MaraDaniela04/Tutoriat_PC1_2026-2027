#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    FILE* f = fopen("citire.in", "r");        
    if (f == NULL) {
        printf("Eroare citire.in");
        return 1;
    }

    char text[100];
    fgets(text, sizeof(text), f);
    
    for (int i = 0; i < strlen(text); i++)
        if (islower(text[i]) != 0)
            text[i] = toupper(text[i]);
    
    int fr[33];
    for (int i = 0; i < 33; i++)
        fr[i] = 0;
    
    for (int i = 0; i<strlen(text); i++)
        for (char l = 'A'; l <= 'Z'; l++)
            if (text[i] == l){
                fr[l - 'A']++;
            }
    
    int max = 0;
    for (int i = 0; i < 32; i++)
        if (fr[i] > max)
            max = fr[i];
    
    if (max == 0)
        printf("Nu exista litere in fisier");
    else
        for (int i = 0; i < 32; i++)
            if (fr[i] == max)
                printf("%c ", 'A' + i);
    
    fclose(f);
    return 0;
}
