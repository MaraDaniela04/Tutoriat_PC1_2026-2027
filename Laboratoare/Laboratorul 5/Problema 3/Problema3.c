#include <stdio.h>
#include <string.h>

#define MEDIA_CALCULATA(mate, info, bac) (0.8 * (((mate) + (info)) / 2.0) + 0.2 * (bac))

const int PRAG = 5;

typedef struct {
    int nr_legitimatie;
    char nume[100];
    float medie;
    float nota_mate;
    float nota_info;
    float nota_bac;
    char admis, buget;
} Candidat;

Candidat citire() {
    Candidat c;
    scanf("%d %s %f %f %f", &c.nr_legitimatie, c.nume, &c.nota_mate, &c.nota_info, &c.nota_bac);
    c.medie = MEDIA_CALCULATA(c.nota_mate, c.nota_info, c.nota_bac);
    if (c.medie >= PRAG) {
        c.admis = 'Y';
    } else {
        c.admis = 'N';
    }

    return c;
}

void buget(Candidat v[], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++){
        if (v[i].medie > v[j].medie) {              // sortam descrescator dupa medie
            Candidat aux = v[i];
            v[i] = v[j];
            v[j] = aux;
        }
    }
    for (int i = 0; i < 0.75*n; i++) {
        if (v[i].admis == 'Y' && i < 0.75*n)
            v[i].buget = 'Y';
        else
            v[i].buget = 'N';
    }
}

void afisare(Candidat v[], int n) {
    char s;
    scanf("%c", &s);
    switch (s) {
        case 'T': {                                 // se afiseaza toti candidatii alfabetic
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++) {
                    if (strcmp(v[i].nume, v[j].nume) < 0) {     // sortam in ordine alfabetica
                        Candidat aux = v[i];
                        v[i] = v[j];
                        v[j] = aux;
                    }
                }

            for (int i = 0; i < n; i++)
                printf("%s\n", v[i].nume);

            break;
        }
        case 'B': {                                 // se afiseaza candidatii admisi la buget
            int ok = 0;
            for (int i = 0; i < n; i++)
                if (v[i].buget == 'Y')
                    printf("%s %f\n", v[i].nume, v[i].medie), ok = 1;
            if (ok == 0)
                printf("Nu exista candidati la buget.");
            break;
        }
        case 'X': {                                 // se afiseaza candidatii admisi la taxa
            int ok = 0;
            for (int i = 0; i < n; i++)
                if (v[i].buget == 'N')
                    printf("%s %f\n", v[i].nume, v[i].medie), ok = 1;
            if (ok == 0)
                printf("Nu exista candidati la taxa.");
            break;
        }
        case 'R': {                                 // se afiseaza candidatii respinsi
            int ok = 0;
            for (int i = 0; i < n; i++)
                if (v[i].admis == 'N')
                    printf("%s %f\n", v[i].nume, v[i].medie), ok = 1;
            if (ok == 0)
                printf("Nu exista candidati respinsi.");
            break;
        }
        default:printf("Nu exista aceasta optiune");
    }
}

int main() {
    Candidat v[100];

    int n;
    scanf("%d", &n);

    v[0] = citire();
    for (int i = 1; i < n; i++) {
        v[i] = citire();
    }

    buget(v, n);

    afisare(v, n);

    return 0;
}
