#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdbool.h>

#include "Lista.h"

void limpiarPantalla();

void mostrarEnteros(DATO);
int compararEnteros(DATO, DATO);

void mostrarPersonasLista(DATO);
void eliminarPersonasEnLista(DATO);
bool buscarPorEdad(DATO, DATO);

#endif // FUNCIONES_H_INCLUDED
