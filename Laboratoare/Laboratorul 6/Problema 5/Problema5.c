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

    char text[100], cuvant[10];
    fgets(text, sizeof(text), f);
    scanf("%s", cuvant);
    
    char *p = strtok(text, " ");
    while(p != NULL){
        if (strstr(p, cuvant))
            printf("%s ", p);
        p = strtok(NULL, " ");
    }
    
    fclose(f);
    return 0;
}
