#include "ingredienti.h"

#ifndef RICETTE_H
#define RICETTE_H

typedef struct
{
    char *nome;
    int tempo;
    int num_ingredienti;
    char **elenco;
    int *grammi;
}ricetta;

ricetta lettura_ricette(FILE* fp_ric, ricetta *lista, int num_ric);
int info_ricetta(ricetta *lista, int num_ric, char *str);
float calcolo_costo(nodo h, ricetta *lista, char *str, int num_ric);
float calcolo_calorie(nodo h, ricetta *lista, char *str, int num_ric);
float ricerca_costo(nodo h, char *str);
float ricerca_calorie(nodo h, char *str);
void stampa_ricette(ricetta *lista, int num_ric);
void ricerca_ingrediente(nodo h, ricetta *lista, char *str, int num_ric);
ricetta aggiunta_ricetta(ricetta *lista, int num_ric);

#endif
