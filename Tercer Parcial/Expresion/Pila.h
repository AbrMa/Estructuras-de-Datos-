//#include<stdio.h>
//#include<stdlib.h>
#include "ArbolB.c"

typedef ArbolBinario Tipodato;
typedef struct pila
{
	Tipodato dato;
	struct pila *enlace;
}PILA;

int PilaVacia(PILA *p);
Tipodato CimaPila(PILA *p);
void InsertarPila(PILA **p,Tipodato x);
Tipodato QuitarPila(PILA **P);
void EliminarPila(PILA *p);
