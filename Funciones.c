#include <stdio.h>
#include <stdlib.h>

#include "Persona.h"

void mostrarEnteros(void* d){
    printf("%d", *((int*)d));
}

void mostrarPersonasLista(void* d){
    printf("%s", personaToString((Persona*)d));
}
