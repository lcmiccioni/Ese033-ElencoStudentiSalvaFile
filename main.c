#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definisci le costanti
#define N 3
#define MAX_STRLEN 30
// Definisci il tipo di dato struct s_studente
struct s_studente {
    char nome[MAX_STRLEN+1];
    char cognome[MAX_STRLEN+1];
    int eta;
    char classe[MAX_STRLEN+1];
};

// Definisci studente come struct s_studente
typedef struct s_studente studente;

int main(int argc, char** argv) {
    // Dichiara le variabili locali
    studente elenco[N];
    int i;
    FILE *puntaFile;
    
    // Codice per l'inserimento, da parte dell'utente, dei dati in un array
    printf("Inserisci i dati per %d studenti:", N);
    for(i=0; i<N; i++) {
        printf("\nInserisci il nome: ");
        scanf("%s", elenco[i].nome);
        printf("Inserisci il cognome: ");
        scanf("%s", elenco[i].cognome);
        printf("Inserisci l'eta': ");
        scanf("%d", &(elenco[i].eta));
        printf("Inserisci la classe: ");
        scanf("%s", elenco[i].classe);
    }
    
    // Codice per la scrittura dell'elenco su file
    puntaFile = fopen("elenco.dat", "wb");
    if(puntaFile) {
        fwrite(elenco, sizeof(studente), N, puntaFile);
        fclose(puntaFile);
    }else {
        printf("\nIl file non si puo' aprire!");
    }
    
    return (EXIT_SUCCESS);
}
