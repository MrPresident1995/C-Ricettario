#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ingredienti.h"
#include "ricette.h"

int main()
{
    FILE* fp_ing;
    FILE* fp_ric;
    int op, fine, num_ric;
    char nome[256];
    nodo head;
    ricetta *lista;

    fp_ing= fopen("ingredienti.txt", "r"); //APERTURA + CONTROLLO FILE INGREDIENTI
    if(fp_ing==NULL)
    {
        printf("Errore");
        return -1;
    }

    fp_ric= fopen("ricette.txt", "r"); //APERTURA + CONTROLLO FILE RICETTE
    if(fp_ric==NULL)
    {
        printf("Errore");
        return -2;
    }

    head= lettura_ingredienti(fp_ing);

    fscanf(fp_ric, "%d", &num_ric);
    lista= malloc(num_ric*sizeof(ricetta)); //ALLOCAZIONE DINAMICA STRUTTURA RICETTA

    *lista= lettura_ricette(fp_ric, lista, num_ric);

    fine= 0;
    printf("Opzioni disponibili\n");
    printf("1- Informazioni su una ricetta\n");
    printf("2- Informazioni su un ingrediente\n");
    printf("3- Calcolo costo di una ricetta\n");
    printf("4- Calcolo apporto calorico di una ricetta\n");
    printf("5- Stampa dell'elenco delle ricette presenti in memoria\n");
    printf("6- Stampa dell'elenco degli ingredienti presenti in memoria\n");
    printf("7- Stampa dell'elenco delle ricette contenenti un dato ingrediente\n");
    printf("8- Aggiunta di una nuova ricetta\n");
    printf("9- Fine\n");
    while(fine!=1)
    {
        printf("\nOpzione: ");
        scanf("%d", &op);
        switch(op)
        {
            case 1:     printf("Inserire il nome della ricetta da cercare: ");
                        scanf("%s", nome);
                        if(info_ricetta(lista, num_ric, nome)!=1)
                            printf("Ricetta non trovata\n");
                        break;

            case 2:     printf("Inserire il nome dell'ingrediente da cercare: ");
                        scanf("%s", nome);
                        if(info_ingrediente(head, nome)!=1)
                            printf("Ingrediente non trovato\n");
                        break;

            case 3:     printf("Inserire il nome della ricetta da calcolare: ");
                        scanf("%s", nome);
                        printf("Il costo della ricetta e' pari a: %.2f\n", calcolo_costo(head, lista, nome, num_ric));
                        break;

            case 4:     printf("Inserire il nome della ricetta da calcolare: ");
                        scanf("%s", nome);
                        printf("L'apporto calorico della ricetta e' pari a: %.2f\n", calcolo_calorie(head, lista, nome, num_ric));
                        break;

            case 5:     stampa_ricette(lista, num_ric);
                        break;

            case 6:     stampa_ingredienti(head);
                        break;

            case 7:     printf("Inserire il nome dell'ingrediente da cercare: ");
                        scanf("%s", nome);
                        ricerca_ingrediente(head, lista, nome, num_ric);
                        break;

            case 8:     num_ric++;
                        lista= realloc(lista, num_ric*sizeof(ricetta));
                        *lista= aggiunta_ricetta(lista, num_ric);
                        break;

            case 9:     fine= 1;
                        break;

            default:    printf("Opzione non disponibile\n");
        }
    }

    fclose(fp_ing);
    fclose(fp_ric);
    return 0;
}
