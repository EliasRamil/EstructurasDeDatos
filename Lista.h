#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <stdbool.h>

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

//--------------------------------------------------Funciones Basicas de la lista------------------------------------------------
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

//--------------------------------------------------Funciones Extras de la lista-------------------------------------------------
/*
    PRE: La lista debe haber sido creada.
    POST: Busca un DATO en la lista y me indica en que posicion se encuetra y -1 en caso de no existir el dato en la lista.
*/
int posicionrDatoEnLaLista(Lista*, DATO);


/*
    PRE: La lista debe haber sido creada, debe existir el dato que deseo buscar y, además, debe existir una funcion que se encargue de comparar si 2 elementos son o no iguales
 *  preferentemente se lo utiliza para comparar TDA si deseo comparar en base a 1 TD que lo forma (atributo), en caso de buscar elementos en una lista de TD o TDA utilizar mejor la funcion posicionElementoEnLaLista.
    POST: Indico la posicion de donde se encuentra el elemento en la lista o ELEMENTO_NO_ENCONTRADO(-1) si es que en la lista no existe.
 */
int buscarDatoEnLaLista(Lista*, DATO dato_Buscado, bool buscarPor(DATO dato_Buscado, DATO dato));

/*
    PRE: La lista donde se va a almacenar no debe haber sido creada. La Lista en la que voy a buscar tiene que exisitir.
    POST: Retorno una lista con las posiciones donde estan los elementos que coinciden con el criterio de busqueda.
*/
Lista* buscarTodosLosDatosQueCumplanUnCriterioEnLaLista(Lista* l, DATO dato_Buscado, bool buscarPor(DATO dato_Buscado, DATO dato));

/*
    PRE: La lista debe haber sido creada y debe existir una funcion que muestre 1 tipo de dato en particular.
    POST: Se muestra por consola los datos de todos los elementos que hay en la lista.
*/
void mostrarLista(Lista*, void mostrarDato(DATO));

/*
    PRE: La lista debe haber sido creada.
    POST: Invierto los DATOs de la lista si es que ambas posiciones existen en la lista.
*/
void invertirDatos(Lista*, int iPosicion1, int iPosicion2);

/*
    PRE: Debe existir el enum COMPARACION.
    POST: Indica si los datos deben ser invertidos o no de posiciones en base al criterio.
*/
bool ascendente(int);

/*
    PRE: Debe existir el enum COMPARACION.
    POST: Indica si los datos deben ser invertidos o no de posiciones en base al criterio.
*/
bool descendente(int);

/*
    PRE: La lista debe haber sido creada y debe exister la funcion que se encargue de comparar los datos.
    POST: Ordeno la lista en forma ascendente o descendente segun se indique en el tercer parametro.
*/
void ordenarLista(Lista*, int comparar(DATO d1, DATO d2), bool criterio(int));

/*
    PRE: La lista donde se va a duplicar NO debe haber sido creada, debe existir la lista que se desea copiar.
    POST: Crea una lista en la cual se retornan los datos duplicados de la lista original.
*/
Lista* duplicarLista(Lista*);

/*
    PRE: La lista debe haber sido creada.
    POST: Agrega 1 dato a la lista de forma ordenada segun lo que se le indique en el 3er parametro (funcion que debe ser creada)
          Y se le indica en el 4to parametro si el orden es ascente o descende.
*/
void agregarDatoEnOrden(Lista*, DATO, int comparar(DATO d1, DATO d2), bool criterio(int));

//-----------------------------------------------------------Destructores-------------------------------------------------------
/*
    PRE: La lista debe haber sido creada.
    POST: La lista es eliminada y los datos que la formaban tambien son destruidos.
*/
void destruirLista(Lista*);

/*
    PRE: La lista debe haber sido creada y debe existir la funcion que elimine un tipo de dato en particular.
    POST: La lista es eliminada y los datos que la formaban tambien son destruidos.
*/
void destruirListaYDatos(Lista*, void eliminarDatos(DATO));

#endif // LISTA_H_INCLUDED
