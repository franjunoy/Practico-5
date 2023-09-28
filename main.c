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

