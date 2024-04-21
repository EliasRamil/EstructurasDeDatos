#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Lista.h"

typedef struct Nodo {
    DATO dato;
    struct Nodo* siguiente;
} Nodo;

struct Lista {
    Nodo* inicio;
    int iTamanioLista;
};

//-----------------------------------------------------------Constructor-------------------------------------------------------
Lista* crearLista(){
    return (Lista*)calloc(1, sizeof(Lista));
}

//-------------------------------------------------------------Getter-----------------------------------------------------------
int getTamanioLista(Lista* l){
    return l->iTamanioLista;
}

//-----------------------------------------------------Funciones ocultas de la Lista-------------------------------------------
/*
    PRE: La lista debe haber sido creada.
    POST: Indica si la posicion indicada existe o no en la lista.
 */
bool existePosicion(Lista* l, int iPosicion) {
    return ((iPosicion >= 0) && (iPosicion < (l->iTamanioLista))) ? true : false;
}

//-----------------------------------------------------Funciones de la lista---------------------------------------------------
int posicionrDatoEnLaLista(Lista* l, DATO d){
    Nodo* actual = l->inicio;
    int iPos = DATO_NO_ENCONTRADO, i = 0;

    while(iPos == DATO_NO_ENCONTRADO && actual != NULL){

        if(actual->dato == d)
            iPos = i;

        i++;
        actual = actual->siguiente;
    }

    return iPos;
}

void mostrarLista(Lista* l, void mostrarDato(DATO)){
    DATO d;

    for(int i=0; i<l->iTamanioLista; i++){
        d = obtenerDatoDeLaLista(l, i);
        printf("%d) ", i);
        mostrarDato(d);
        puts("");
    }

}

void agregarAlInicio(Lista* l, DATO d){
    Nodo* n = (Nodo*)malloc(sizeof(Nodo));

    n->dato = d;
    n->siguiente = l->inicio;
    l->inicio = n;

    l->iTamanioLista++;
}

void agregarALaLista(Lista* l, int iPos, DATO d){

    if(iPos >= 0 && iPos <= l->iTamanioLista){

        if(iPos == 0 || iPos == l->iTamanioLista){

            if(iPos == 0){
                agregarAlInicio(l, d);
            } else
                agregarAlFinal(l, d);

        } else {

            Nodo* n = (Nodo*)malloc(sizeof(Nodo));
            Nodo* actual = l->inicio;

            n->dato = d;

            bool bInsertado = false;
            int i = 0;
            while(actual != NULL && !bInsertado){

                if(i == iPos-1){
                    n->siguiente = actual->siguiente;
                    actual->siguiente = n;
                    bInsertado = true;
                }

                i++;
                actual = actual->siguiente;
            }

            l->iTamanioLista++;
        }

    } else
        puts("No se pudo agregar elemento a la lista");

}

void agregarAlFinal(Lista* l, DATO d){
    Nodo* n = (Nodo*)malloc(sizeof(Nodo));
    n->dato = d;
    n->siguiente = NULL;

    if(l->iTamanioLista != 0){

        Nodo* actual = l->inicio;
        while (actual->siguiente != NULL) {
            actual = actual->siguiente;
        }

        actual->siguiente = n;

    } else
        l->inicio = n;

    l->iTamanioLista++;
}

DATO obtenerDatoInicial(Lista* l){
    return obtenerDatoDeLaLista(l, 0);
}

DATO obtenerDatoDeLaLista(Lista* l, int iPos){
    DATO d = NULL;

    if(l->iTamanioLista != 0 && existePosicion(l, iPos)){

        Nodo* n = l->inicio;
        bool bEncontrado = false;
        int iContador = 0;

        while(!bEncontrado && n != NULL){

            iContador++;
            if(iContador == iPos+1){
                d = n->dato;
                bEncontrado = true;
            }

            if (n != NULL) {
                n = n->siguiente;
            }
        }
    }

    return d;
}

DATO obtenerDatoFinal(Lista* l){
    return obtenerDatoDeLaLista(l, l->iTamanioLista-1);
}

DATO eliminarDatoInicial(Lista* l){
    DATO d = NULL;

    if(l->iTamanioLista > 0){
        Nodo* actual = l->inicio;

        d = actual->dato;
        l->inicio = l->inicio->siguiente;
        free(actual);

        l->iTamanioLista--;
    } else
        puts("La lista esta vacia...");


    return d;
}

DATO eliminarDatoDeLaLista(Lista* l, int iPos){
    DATO d = NULL;

    if(l->iTamanioLista > 0){

        if(iPos != 0){
            Nodo* anterior = NULL;
            Nodo* actual = l->inicio;
            int i = 0;
            bool bEliminado = false;

            while(actual != NULL && !bEliminado){

                if(i == iPos){
                    d = actual->dato;
                    bEliminado = true;
                }

                if(!bEliminado){
                    anterior = actual;
                    actual = actual->siguiente;
                } else {
                    anterior->siguiente = actual->siguiente;
                    free(actual);
                    actual = NULL;
                    l->iTamanioLista--;
                }

                i++;
            }

        } else
            d = eliminarDatoInicial(l);

    } else
        puts("La lista esta vacia...");

    return d;
}

DATO eliminarDatoFinal(Lista* l){
    return eliminarDatoDeLaLista(l, l->iTamanioLista-1);
}

//-----------------------------------------------------------Destructores-------------------------------------------------------
void destruirLista(Lista* l){
    DATO d = NULL;

    while(l->iTamanioLista > 0){
        d = eliminarDatoInicial(l);
        free(d);
    }

    free(l);
}
