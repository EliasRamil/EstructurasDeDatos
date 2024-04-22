#include <stdio.h>
#include <stdlib.h>

#include "Persona.h"
#include "Lista.h"

void limpiarPantalla(){
    #ifdef _WIN32
        system("cls");  // En Windows
    #else
        system("clear");  // En sistemas basados en Unix (Linux, macOS, etc.)
    #endif
}

void mostrarEnteros(void* d){
    printf("%d", *((int*)d));
}

int compararEnteros(void* d1, void* d2){
    int iRetorno = IGUAL;

    int* valor1 = (int*)d1;
    int* valor2 = (int*)d2;

    if (*valor1 < *valor2) {
        iRetorno = MENOR;
    } else if (*valor1 > *valor2) {
        iRetorno = MAYOR;
    }

    return iRetorno;
}

void mostrarPersonasLista(void* d){
    printf("%s", personaToString((Persona*)d));
}

void eliminarPersonasEnLista(void* p){
    destruirPersona((Persona*)p);
}

bool compararEdad(void* a, void* b){
    return (*((int*)a) == getEdad((Persona*)b)) ? true : false;
}
