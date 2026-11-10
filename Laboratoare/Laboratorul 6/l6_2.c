#include <stdio.h>
#include <stdlib.h>
#include <string.h>

    int main() {
    FILE *f = fopen("text.txt", "a+");
    
    char a, b;
    fscanf(f, "%c %c", &a, &b);
    
    if(f==NULL)
    {
    printf("EROARE");
    return 1;
    }
    
    fgetc(f);
    char t[101];
    
    fgets(t, sizeof(t), f);

    for (int i = 0; i<strlen(t); i++) {
        if (t[i] == a)
            t[i] = b;
    }

    fprintf(f, "%s",t);
    fclose(f);

    return 0;
}
