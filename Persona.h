#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

#define CADENA 30

typedef struct Persona Persona;

Persona* crearPersona(char sDNI[11], char sNombre[CADENA], int iDiaDeNacimiento, int iMesDeNacimiento, int iAnioDeNacimiento);

const char* getDNI(Persona*);
const char* getNombre(Persona*);
const char* getFechaDeNacimiento(Persona*);
int getEdad(Persona*);

void setNombre(Persona*, char sNombre[CADENA]);

const char* personaToString(Persona*);

void destruirPersona(Persona*);

#endif // PERSONA_H_INCLUDED
