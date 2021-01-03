#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ricette.h"

int i;

ricetta lettura_ricette(FILE* fp_ric, ricetta *lista, int num_ric)
{
    int o;
    char nome[256];

    for(i=0; i<num_ric; i++)
    {
        fscanf(fp_ric, "%s%d%d", nome, &lista[i].tempo, &lista[i].num_ingredienti);
        lista[i].nome= strdup(nome);

        lista[i].elenco= malloc(lista[i].num_ingredienti*sizeof(char *)); //ALLOCAZIONE DINAMICA MATRICE INGREDIENTI IN UNA RICETTA
        lista[i].grammi= malloc(lista[i].num_ingredienti*sizeof(int)); //ALLOCAZIONE DINAMICA VETTORE GRAMMI

        for(o=0; o<lista[i].num_ingredienti; o++)
        {
            fscanf(fp_ric, "%s%d", nome, &lista[i].grammi[i]);
            lista[i].elenco[o]= strdup(nome);
        }
    }

    return *lista;
}

int info_ricetta(ricetta *lista, int num_ric, char *str)
{
    for(i=0; i<num_ric; i++)
        if(strcmp(str, lista[i].nome)==0)
        {
            printf("Tempo di preparazione: %d\n", lista[i].tempo);
            printf("Numero di ingredienti necessari: %d\n", lista[i].num_ingredienti);
            return 1;
        }

    return 0;
}

float calcolo_costo(nodo h, ricetta *lista, char *str, int num_ric)
{
    int x=-1;
    float costo, calorie, costo_tot= 0;

    for(i=0; i<num_ric; i++) //RICERCA RICETTA
        if(strcmp(str, lista[i].nome)==0)
            x= i;

    if(x==-1) //FALLIMENTO RICERCA RICETTA
        return -1;

    for(i=0; i<lista[x].num_ingredienti; i++)
    {
        costo= ricerca_costo(h, lista[x].elenco[i]);
        calorie= ricerca_calorie(h, lista[x].elenco[i]);
        calorie= calorie/1000;
        if(calorie<1)
            calorie= 1;
        costo_tot= costo_tot + costo*calorie;
    }

    return costo_tot;
}

float calcolo_calorie(nodo h, ricetta *lista, char *str, int num_ric)
{
    int x= -1;
    float calorie, calorie_tot= 0;

    for(i=0; i<num_ric; i++) //RICERCA RICETTA
        if(strcmp(str, lista[i].nome)==0)
            x= i;

    if(x==-1) //FALLIMENTO RICERCA
        return -1;

    for(i=0; i<lista[x].num_ingredienti; i++)
    {
        calorie= ricerca_calorie(h, lista[x].elenco[i]);
        calorie_tot= calorie_tot + calorie*lista[x].grammi[i];
    }

    return calorie_tot;
}

float ricerca_costo(nodo h, char *str)
{
    nodo x;

    for(x=h->next; x!=NULL; x=x->next)
        if(strcmp(str, x->nome)==0)
            return x->costo;

    return 0;
}

float ricerca_calorie(nodo h, char *str)
{
    nodo x;

    for(x=h->next; x!=NULL; x=x->next)
        if(strcmp(str, x->nome)==0)
            return x->calorie;

    return 0;
}

void stampa_ricette(ricetta *lista, int num_ric)
{
    for(i=0; i<num_ric; i++)
        printf("%s\n", lista[i].nome);
}

void ricerca_ingrediente(nodo h, ricetta *lista, char *str, int num_ric)
{
    int o, presente= 0;
    nodo x;

    for(x=h->next; x!=NULL; x=x->next) //RICERCA PRESENZA INGREDIENTE
        if(strcmp(str, x->nome)==0)
        {
            presente= 1;
            printf("Ingrediente presente in memoria\n");
            for(i=0; i<num_ric; i++) //INGREDIENTE PRESENTE
                for(o=0; o<lista[i].num_ingredienti; o++)
                    if(strcmp(str, lista[i].elenco[o])==0)
                        printf("%s\n", lista[i].nome);

            return ;
        }

    if(presente==0)
        printf("Ingrediente non presente in memoria\n");
}

ricetta aggiunta_ricetta(ricetta *lista, int num_ric)
{
    int o;
    char nome[256];

    printf("Inserire il nome della ricetta: ");
    scanf("%s", nome);
    lista[num_ric-1].nome= strdup(nome);
    printf("Inserire il tempo necessario alla sua preparazione (minuti): ");
    scanf("%d", &lista[num_ric-1].tempo);
    printf("Inserire il numero di ingredienti necessari: ");
    scanf("%d", &lista[num_ric-1].num_ingredienti);
    lista[i].elenco= malloc(lista[num_ric-1].num_ingredienti*sizeof(char *)); //ALLOCAZIONE DINAMICA RIGA MATRICE INGREDIENTI PER LA RICETTA
    for(o=0; o<lista[num_ric-1].num_ingredienti; o++)
    {
        printf("%d: ", o+1);
        scanf("%s", nome);
        lista[num_ric-1].elenco[o]= strdup(nome);
    }

    return *lista;
}
