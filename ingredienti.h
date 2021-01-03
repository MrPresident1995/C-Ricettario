#ifndef INGREDIENTI_H
#define INGREDIENTI_H

typedef struct node *nodo;
struct node
{
    char *nome;
    float costo;
    float calorie;
    nodo next;
};

nodo lettura_ingredienti(FILE* fp);
nodo instail(nodo h, char *nome, float costo, float calorie);
nodo newnode(char *nome, float costo, float calorie, nodo next);
int info_ingrediente(nodo h, char *str);
void stampa_ingredienti(nodo h);

#endif

