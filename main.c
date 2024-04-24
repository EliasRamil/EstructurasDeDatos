#include <stdio.h>
#include <stdlib.h>

#include "Lista.h"
#include "Persona.h"
#include "Funciones.h"

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

    puts("");
    ordenarLista(listEnteros, compararEnteros,descendente);
    mostrarLista(listEnteros, mostrarEnteros);

    puts("");
    int* iNum5 = (int*)malloc(sizeof(int));
    *iNum5 = 11;
    agregarDatoEnOrden(listEnteros, iNum5, compararEnteros, descendente);
    int a = 7;
    agregarDatoEnOrden(listEnteros, (DATO)&a, compararEnteros, descendente);
    mostrarLista(listEnteros, mostrarEnteros);

    destruirLista(listEnteros);

    printf("\n\nPresionar Enter para continuar...\n");
    getchar();
    limpiarPantalla();
   //------------------------------------------------------------------------------------------------

    Lista* listPersona = crearLista();

    agregarAlInicio(listPersona, crearPersona("485", "Juan", 2, 3, 2005));
    agregarAlFinal(listPersona, crearPersona("544", "Nicol", 1, 4, 2005));
    agregarALaLista(listPersona, 2, crearPersona("985", "Fernando", 9, 8, 2015));
    agregarAlInicio(listPersona, crearPersona("375", "Luis", 22, 7, 1995));

    mostrarLista(listPersona, mostrarPersonasLista);

    puts("");
    DATO temp = eliminarDatoDeLaLista(listPersona, 3);

    mostrarLista(listPersona, mostrarPersonasLista);
    printf("\n---------------------------\n");
    Persona* aux = (Persona*)obtenerDatoInicial(listPersona);
    setNombre(aux, "Pedro");
    mostrarPersonasLista(temp);

    printf("\n---------------------------\n");
    int edad = 28;
    int resultado;

    // Llamar a la función buscarDatoEnLaLista y mostrar el resultado
    resultado = buscarDatoEnLaLista(listPersona, &edad, buscarPorEdad);
    mostrarPersonasLista(obtenerDatoDeLaLista(listPersona, resultado));

    printf("\n---------------------------\n");
    Lista* copiaListaPersona = duplicarLista(listPersona);
    mostrarLista(copiaListaPersona, mostrarPersonasLista);

    printf("\n---------------------------\n");
    edad = 19;
    Lista* personasDeLaEdadBuscada = buscarTodosLosDatosQueCumplanUnCriterioEnLaLista(listPersona, &edad, buscarPorEdad);
    mostrarLista(personasDeLaEdadBuscada, mostrarEnteros);

    destruirListaYDatos(listPersona, eliminarPersonasEnLista);
    destruirLista(personasDeLaEdadBuscada);

    puts("");
    return 0;
}
