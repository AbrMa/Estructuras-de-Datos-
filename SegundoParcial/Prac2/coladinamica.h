#include <stdlib.h>

typedef struct nodo
{
	TipoDato elemento;
	struct nodo* siguiente;
}Nodo;

typedef struct
{
	Nodo* frente;
	Nodo* fin;
}Cola;

void crearCola( Cola* cola );
void insertar( Cola* cola, TipoDato entrada );
TipoDato quitar( Cola* cola );
void borrarCola( Cola* cola );

TipoDato frente( Cola cola );

int colaVacia( Cola cola );
