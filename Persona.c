#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#include "Persona.h"

typedef struct {
    int iDia;
    int iMes;
    int iAnio;
} Fecha;

struct Persona{
    char sDNI[9];
    char sNombre[CADENA];
    Fecha FechaDeNacimiento;
};

// Funciones declaradas de forma adelantada para usar en el constructor. Sirve para tener modularizados los valores
// que no quiero que se accedan, y en caso de necesitar pulir los criterios de los datos hacerlo en dichas funciones.
void setDNI(Persona*, char sDNI[11]);
void setFechaDeNacimiento(Persona*, int iDiaDeNacimiento, int iMesDeNacimiento, int iAnioDeNacimiento);

Persona* crearPersona(char sDNI[11], char sNombre[CADENA], int iDiaDeNacimiento, int iMesDeNacimiento, int iAnioDeNacimiento){
    Persona* p = (Persona*)malloc(sizeof(Persona));

    setDNI(p, sDNI);
    setNombre(p, sNombre);
    setFechaDeNacimiento(p, iDiaDeNacimiento, iMesDeNacimiento, iAnioDeNacimiento);

    return p;
}

const char* getDNI(Persona* p){
    return p->sDNI;
}

const char* getNombre(Persona* p){
    return p->sNombre;
}

const char* getFechaDeNacimiento(Persona* p){
    char str[11];

    sprintf(str, "%02d-%02d-%04d", p->FechaDeNacimiento.iDia, p->FechaDeNacimiento.iMes, p->FechaDeNacimiento.iAnio);

    return strdup(str); // Duplicar y devolver una copia de la cadena
}

int getEdad(Persona* p){
    time_t tiempoActual = time(NULL);
    struct tm* fechaActual = localtime(&tiempoActual);

    int iEdad = fechaActual->tm_year + 1900 - p->FechaDeNacimiento.iAnio;

    // Verificar si aún no ha cumplido años
    if (fechaActual->tm_mon + 1 < p->FechaDeNacimiento.iMes) {
        iEdad--;
    } else if (fechaActual->tm_mon + 1 == p->FechaDeNacimiento.iMes) {
        if (fechaActual->tm_mday < p->FechaDeNacimiento.iDia) {
            iEdad--;
        }
    }

    return iEdad;
}

void setDNI(Persona* p, char sDNI[11]){
    char aux[9];
    int k = 0;

    for(int i = 0; i < strlen(sDNI); i++){
        if(isdigit(sDNI[i])){
            aux[k] = sDNI[i];
            k++;
        }
    }

    aux[k] = '\0'; // Agregar el carácter nulo al final

    strcpy(p->sDNI, aux);
}

void setNombre(Persona* p, char sNombre[CADENA]){
    strcpy(p->sNombre, sNombre);
}

void setFechaDeNacimiento(Persona* p, int iDiaDeNacimiento, int iMesDeNacimiento, int iAnioDeNacimiento){
    p->FechaDeNacimiento.iDia = iDiaDeNacimiento;
    p->FechaDeNacimiento.iMes = iMesDeNacimiento;
    p->FechaDeNacimiento.iAnio = iAnioDeNacimiento;
}

const char* personaToString(Persona* p){
    char str[CADENA * 2];

    sprintf(str, "Nombre: %s\nDNI: %s\nNacimiento: %s\nEdad: %d", getNombre(p), getDNI(p), getFechaDeNacimiento(p), getEdad(p));

    return strdup(str); // Duplicar y devolver una copia de la cadena
}

void destruirPersona(Persona* p){
    free(p);
}
