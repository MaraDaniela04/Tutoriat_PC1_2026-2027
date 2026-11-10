#include <stdio.h>
#include <stdlib.h>

char text[10005];

int main()
{

    FILE *file = fopen("text.in", "r");
    if (file == NULL) {
        printf("Eroare");
        return 1;
    }

    int i = 0;
    int c;
    
    while ((c = fgetc(file)) != EOF) {
        if (c >= 'a' && c <= 'z') {
            text[i] = c - 32; 
        } 
        else if (c >= 'A' && c <= 'Z') {
            text[i] = c + 32; 
        } 
        else {
            text[i] = c; 
        }
        i++;
    }
    text[i] = '\0'; 

    fclose(file);


    file = fopen("text.in", "w");
    if (file == NULL) {
        printf("Eroare la redeschiderea fisierului pentru scriere.\n");
        return 2;
    }

    fprintf(file, "%s", text);

    fclose(file);

    return 0;
}