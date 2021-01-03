#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ingredienti.h"
#include "ricette.h"

nodo lettura_ingredienti(FILE* fp)
{
    int num, i;
    float costo, calorie;
    char nome[256];
    nodo head;

    head= malloc(sizeof(*head)); //ALLOCAZIONE TESTA DELLA LISTA INGREDIENTI
    head-> next= NULL;

    fscanf(fp, "%d", &num); //ACQUISIZIONE INGREDIENTI
    for(i=0; i<num; i++)
    {
        fscanf(fp, "%s%f%f", nome, &costo, &calorie);
        head= instail(head, nome, costo, calorie);
    }

    return head;
}

nodo newnode(char *nome, float costo, float calorie, nodo next)
{
    nodo x= malloc(sizeof(*x));

    if(x==NULL)
        return NULL;
    else
    {
        x->nome= strdup(nome);
        x->costo= costo;
        x->calorie= calorie;
        x->next= next;
    }
    return x;
}

nodo instail(nodo h, char *nome, float costo, float calorie)
{
    nodo x;

    if(h==NULL) //CONTROLLA CHE NON SIA LA TESTA
        return newnode(nome, costo, calorie, NULL);

    for(x=h; x->next!=NULL; x=x->next); //SCORRE LA LISTA FINO ALLA CODA

    x->next = newnode(nome, costo, calorie, NULL); //AGGIUNGE IL NUOVO NODO

    return h;
}

int info_ingrediente(nodo h, char *str)
{
    nodo x;

    for(x=h->next; x!=NULL; x=x->next)
        if(strcmp(str, x->nome)==0)
        {
            printf("Costo ingrediente: %.2f\n", x->costo);
            printf("Apporto calorico ingrediente: %.2f\n", x->calorie);
            return 1;
        }

    return 0;
}

void stampa_ingredienti(nodo h)
{
    nodo x;

    for(x=h->next; x!=NULL; x=x->next)
        printf("%s\n", x->nome);
}
