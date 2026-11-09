#include <stdio.h>
#include <string.h>

int main()
{
    FILE* f = fopen("intrare.in", "r+");        
    if (f == NULL) {
        printf("Eroare intrare.in");
        return 1;
    }

    char litera, text[100], text_nou[100];

    fscanf(f, "%c\n", &litera);
    
    fgets(text, sizeof(text), f);
    
    int j = 0, dim = strlen(text);
    for (int i = 0; i < dim; i++) {
        if (text[i] != litera) {
            text[j] = text[i];
            j++;
        }
    }
    text[j] = '\0';

    FILE* fnou = fopen("iesire.out", "w");
    if (fnou == NULL) {
        printf("Eroare iesire.out");
        return 1;
    }
    fputs(text, fnou);

    fputs(text, f);

    fclose(f);
    fclose(fnou);

    return 0;
}
