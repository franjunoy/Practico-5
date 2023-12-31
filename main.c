#include <stdio.h>
#include <stdlib.h>
#include "listaDob.h"

lista *crearLista(int dato)
{
    lista *nuevo = NULL;
    nuevo = (lista *)malloc(sizeof(lista));
    if (nuevo != NULL)
    {
        nuevo->dato = dato;
        nuevo->sgte = NULL;
        nuevo->ante = NULL;
    }
    return nuevo;
}

int insertar(lista **i, int d)
{
    lista *nuevo = NULL;
    nuevo = crearLista(d);
    if (nuevo != NULL)
    {
        nuevo->sgte = *i;
        nuevo->ante = NULL;
        if (*i != NULL)
            (*i)->ante = nuevo;
        *i = nuevo;
        return 0;
    }
    return 1;
}
void listar(lista *i)
{
    lista *aux = i;
    while (aux != NULL)
    {
        printf("%d\n", aux->dato);
        aux = aux->sgte;
    }
}
int insertarFin(lista **i, int dato)
{
    lista *nuevo = NULL, *aux = *i;
    nuevo = crearLista(dato);
    if (nuevo != NULL)
    {
        while (aux->sgte != NULL)
            (aux = aux->sgte);
        nuevo->ante = aux;
        aux->sgte = nuevo;
        return 0;
    }
    return 1;
}
int eliminar(lista **i, int dato)
{
    lista *actual = *i, *ant = NULL, *sig = NULL;
    while (actual != NULL)
    {
        if (actual->dato == dato)
        {
            if (actual == *i)
            {
                *i = actual->sgte;
                if (actual->sgte != NULL)
                    actual->sgte->ante = NULL;
            }
            else if (actual->sgte == NULL)
            {
                ant = actual->ante;
                actual->ante = NULL;
                ant->sgte = NULL;
            }
            else
            {
                ant = actual->ante;
                actual->ante = NULL;
                sig = actual->sgte;
                actual->sgte = NULL;
                ant->sgte = sig;
                sig->ante = ant;
            }
            free(actual);
            return 0;
        }
        actual = actual->sgte;
    }
    return 1;
}
int main()
{
    lista *i;
    i = NULL;
    insertar(&i, 5);
    insertar(&i, 3);
    insertar(&i, 4);
    insertar(&i, 10);
    insertarFin(&i, 6);
    insertarFin(&i, 8);
    insertarFin(&i, 1);
    insertar(&i, 8);
    insertar(&i, 1);
    printf("Listo elementos%d\n");
    listar(i);
    printf("Fin del listado\n");
    eliminar(&i, 4);
    eliminar(&i, 1);
    eliminar(&i, 10);
    eliminar(&i, 14);
    printf("Listo elementos\n");
    listar(i);
    printf("Fin del listado\n");
    return 0;
}
