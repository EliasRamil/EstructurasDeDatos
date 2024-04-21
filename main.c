#include <stdio.h>
#include <stdlib.h>

#include "Funciones.h"
#include "Lista.h"
#include "Persona.h"

/* Preguntas:
1. Si el destruirLista libera bien la memoria.
2. Si al eliminar es correcto que haga el free(actual) o si afecta al dato.
*/

/* Falta implementar:
1. Ordenar lista.
2. Buscar en una Lista de un TDA 1 dato en base al por ej DNI
*/

int main(void)
{
    Lista* listEnteros = crearLista();

    int* iNum1 = (int*)malloc(sizeof(int)), *iNum2 = (int*)malloc(sizeof(int)), *iNum3 = (int*)malloc(sizeof(int)), *iNum4 = (int*)malloc(sizeof(int));
    *iNum1 = 18;
    *iNum2 = 12;
    *iNum3 = 9;
    *iNum4 = 31;

    agregarAlFinal(listEnteros, iNum1);
    agregarAlInicio(listEnteros, iNum2);
    agregarAlInicio(listEnteros, iNum3);
    agregarAlFinal(listEnteros, iNum4);

    mostrarLista(listEnteros, mostrarEnteros);

    puts("");
    mostrarEnteros(obtenerDatoDeLaLista(listEnteros, posicionrDatoEnLaLista(listEnteros, iNum3)));

    destruirLista(listEnteros);

    printf("\n-----------------------------------------------------------------------------------------\n");

    Lista* listPersona = crearLista();

    agregarAlInicio(listPersona, crearPersona("485", "Juan", 2, 3, 2005));
    agregarAlFinal(listPersona, crearPersona("544", "Nicol", 1, 4, 2005));
    agregarALaLista(listPersona, 2, crearPersona("985", "Fernando", 9, 8, 2015));
    agregarAlInicio(listPersona, crearPersona("375", "Luis", 22, 7, 1995));

    puts("");
    mostrarLista(listPersona, mostrarPersonasLista);

    puts("");
    DATO temp = eliminarDatoDeLaLista(listPersona, 3);

    mostrarLista(listPersona, mostrarPersonasLista);
    printf("\n---------------------------\n");
    mostrarPersonasLista(temp);

    destruirLista(listPersona);

    puts("");
    return 0;
}
