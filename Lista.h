#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#define DATO_NO_ENCONTRADO -1

enum COMPARACION {
    MENOR = -1,
    IGUAL,
    MAYOR
};

typedef void* DATO;
typedef struct Lista Lista;

//-----------------------------------------------------------Constructor-------------------------------------------------------
/*
    PRE: La lista no debe haber sido creada.
    POST: La lista queda creada y el tamanio de la lista queda seteado en 0.
*/
Lista* crearLista();

//-------------------------------------------------------------Getter-----------------------------------------------------------
/*
    PRE: La lista debe haber sido creada.
    POST: Devuelve el dato contenido en el iTamanio_Lista de la lista.
*/
int getTamanioLista(Lista*);

//-----------------------------------------------------Funciones de la lista---------------------------------------------------
/*
    PRE: La lista debe haber sido creada.
    POST: Busca un DATO en la lista y me indica en que posicion se encuetra y -1 en caso de no existir el dato en la lista.
*/
int posicionrDatoEnLaLista(Lista*, DATO);

/*
    PRE: La lista debe haber sido creada y debe existir una funcion que muestre 1 tipo de dato en particular.
    POST: Se muestra por consola los datos de todos los elementos que hay en la lista.
*/
void mostrarLista(Lista*, void mostrarDato(DATO));

/*
    PRE: La lista debe haber sido creada.
    POST: Agrego al inicio de la lista 1 elemento.
 */
void agregarAlInicio(Lista*, DATO);

/*
    PRE: La lista debe haber sido creada.
    POST: Agrego 1 elemento a la lista en la posicion indicada si es que existe.
*/
void agregarALaLista(Lista*, int, DATO);

/*
    PRE: La lista debe haber sido creada.
    POST: Agrego al final de la lista 1 elemento.
 */
void agregarAlFinal(Lista*, DATO);

/*
    PRE: La lista debe haber sido creada.
    POST: Retorno el DATO de la lista en la posicion 0, si el dato no existe retorno NULL.
*/
DATO obtenerDatoInicial(Lista*);

/*
    PRE: La lista debe haber sido creada.
    POST: Retorno el DATO de la lista en la posicion solicitada, si el dato no existe retorno NULL.
*/
DATO obtenerDatoDeLaLista(Lista*, int);

/*
    PRE: La lista debe haber sido creada.
    POST: Retorno el DATO de la lista en la posicion final, si el dato no existe retorno NULL.
*/
DATO obtenerDatoFinal(Lista*);

/*
    PRE: La lista debe haber sido creada.
    POST: Remuevo el DATO inicial y lo retorno.
*/
DATO eliminarDatoInicial(Lista*);

/*
    PRE: La lista debe haber sido creada.
    POST: Remuevo y retorno el DATO que poseo en una posicion indicada de la lista si es que existe.
*/
DATO eliminarDatoDeLaLista(Lista*, int);

/*
    PRE: La lista debe haber sido creada.
    POST: Remuevo el DATO final y lo retorno.
*/
DATO eliminarDatoFinal(Lista*);

//-----------------------------------------------------------Destructores-------------------------------------------------------
/*
    PRE: La lista debe haber sido creada.
    POST: La lista es eliminada y los datos que la formaban tambien son destruidos.
*/
void destruirLista(Lista*);

#endif // LISTA_H_INCLUDED
