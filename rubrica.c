#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTATTI 100
#define MAX_LUNG 50
#define MAX_TEL 20
#define NOME_FILE "rubrica.txt"

typedef struct {
    char nome[MAX_LUNG];
    char cognome[MAX_LUNG];
    char telefono[MAX_TEL];
} Contatto;

void caricaRubrica(Contatto rubrica[], int *n);
void salvaRubrica(Contatto rubrica[], int n);
void aggiungiContatto(Contatto rubrica[], int *n);
void mostraContatti(Contatto rubrica[], int n);
void cercaContatto(Contatto rubrica[], int n);


int main() {
    Contatto rubrica[MAX_CONTATTI];
    int numeroContatti = 0;
    int scelta;

    caricaRubrica(rubrica, &numeroContatti);

    do {
        printf("\n=== RUBRICA CONTATTI ===\n");
        printf("1. Mostra contatti\n");
        printf("2. Aggiungi contatto\n");
        printf("3. Cerca contatto\n");
        printf("0. Esci\n");
        printf("Scelta: ");
        
        if (scanf("%d", &scelta) != 1) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}
            scelta = -1;
        }
        getchar(); // consuma il \n

        switch (scelta) {
            case 1:
                mostraContatti(rubrica, numeroContatti);
                break;
            case 2:
                aggiungiContatto(rubrica, &numeroContatti);
                break;
            case 3:
                cercaContatto(rubrica, numeroContatti);
                break;
            case 0:
                printf("Uscita...\n");
                break;
            default:
                printf("Scelta non valida.\n");
        }

    } while (scelta != 0);

    salvaRubrica(rubrica, numeroContatti);

    return 0;
}

void caricaRubrica(Contatto rubrica[], int *n) {
    FILE *fp = fopen(NOME_FILE, "r");
    if (fp == NULL) {
        *n = 0;
        return;
    }

    *n = 0;
    while (*n < MAX_CONTATTI &&
           fscanf(fp, "%49[^;];%49[^;];%19[^\n]\n",
                  rubrica[*n].nome,
                  rubrica[*n].cognome,
                  rubrica[*n].telefono) == 3) {
        (*n)++;
    }

    fclose(fp);
}

void salvaRubrica(Contatto rubrica[], int n) {
    FILE *fp = fopen(NOME_FILE, "w");
    if (fp == NULL) {
        printf("Errore nell'apertura del file per scrittura.\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        fprintf(fp, "%s;%s;%s\n",
                rubrica[i].nome,
                rubrica[i].cognome,
                rubrica[i].telefono);
    }

    fclose(fp);
}

void aggiungiContatto(Contatto rubrica[], int *n) {
    if (*n >= MAX_CONTATTI) {
        printf("Rubrica piena, impossibile aggiungere altri contatti.\n");
        return;
    }

    Contatto c;

    printf("Nome: ");
    fgets(c.nome, MAX_LUNG, stdin);
    c.nome[strcspn(c.nome, "\n")] = '\0';

    printf("Cognome: ");
    fgets(c.cognome, MAX_LUNG, stdin);
    c.cognome[strcspn(c.cognome, "\n")] = '\0';

    printf("Telefono: ");
    fgets(c.telefono, MAX_TEL, stdin);
    c.telefono[strcspn(c.telefono, "\n")] = '\0';

    rubrica[*n] = c;
    (*n)++;

    printf("Contatto aggiunto con successo.\n");
}

void mostraContatti(Contatto rubrica[], int n) {
    if (n == 0) {
        printf("La rubrica è vuota.\n");
        return;
    }

    printf("\n--- Elenco contatti ---\n");
    for (int i = 0; i < n; i++) {
        printf("%d) %s %s - %s\n",
               i + 1,
               rubrica[i].nome,
               rubrica[i].cognome,
               rubrica[i].telefono);
    }
}
void cercaContatto(Contatto rubrica[], int n) {
    if (n == 0) {
        printf("La rubrica è vuota.\n");
        return;
    }

    char ricerca[MAX_LUNG];
    printf("Inserisci il nome o cognome da cercare: ");
    fgets(ricerca, MAX_LUNG, stdin);
    ricerca[strcspn(ricerca, "\n")] = '\0';

    int trovati = 0;
    printf("\n--- Risultati ricerca per \"%s\" ---\n", ricerca);
    for (int i = 0; i < n; i++) {
        if (strstr(rubrica[i].nome, ricerca) != NULL ||
            strstr(rubrica[i].cognome, ricerca) != NULL) {
            printf("%d) %s %s - %s\n",
                   i + 1,
                   rubrica[i].nome,
                   rubrica[i].cognome,
                   rubrica[i].telefono);
            trovati++;
        }
    }

    if (trovati == 0) {
        printf("Nessun contatto trovato.\n");
    }
}
