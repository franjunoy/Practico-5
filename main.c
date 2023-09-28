#include <stdio.h>
#include <stdlib.h>
#include "listaDob.h"

lista *crearLista(int dato){
    lista* nuevo= NULL;
    nuevo = (lista*)malloc(sizeof(lista));
    if(nuevo!=NULL){
        nuevo->dato=dato;
        nuevo->sgte=NULL;
        nuevo->ante=NULL;
    }
    return nuevo;
}

int insertar (lista **i, int d){
    lista *nuevo = NULL;
    nuevo = crearLista(d);
    if(nuevo != NULL){
        nuevo->sgte = *i;
        nuevo->ante = NULL;
        if(*i != NULL)
            (*i)->ante = nuevo;
            *i = nuevo;
        return 0;
        }
    return 1;
}
