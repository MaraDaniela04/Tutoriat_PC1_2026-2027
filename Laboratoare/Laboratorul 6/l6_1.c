#include <stdio.h>
#include <stdlib.h>

char c;
char a[1005], b[1005];

int main()
{
    FILE *file1 = fopen("text.in","a+");
    FILE *file2 = fopen("text.out","w");

    // Citim litera de pe prima linie
    fscanf(file1, "%c", &c);

    // Trecem peste caracterul 'Enter' (\n) cu fgetc
    fgetc(file1);
    
    // Acum putem citi linia de text
    fgets(a, 1005, file1);

    int i = 0, cnt = 0;

    while(a[i] != '\n' && a[i] != '\0') {
        if(a[i] != c) {
            b[cnt] = a[i];              // Salvam in vectorul b
            fprintf(file2, "%c", a[i]); 
            cnt++;
        }
        i++;
    }
    

    b[cnt] = '\0'; 

    fprintf(file1, "\n%s\n", b);

    fclose(file1);
    fclose(file2);

    return 0;
}
  