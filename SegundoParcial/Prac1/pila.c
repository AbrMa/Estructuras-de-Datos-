typedef int TipoDato;
#include "pila.h"

void crearPila(Nodo** pila)
{
	*pila = NULL;
}	

int pilaVacia(Nodo* pila)
{
	return pila == NULL;
}

void insertar(Nodo** pila, TipoDato elemento)
{
	Nodo* nuevo;

	nuevo = (Nodo*)malloc(sizeof(Nodo));
	nuevo -> elemento = elemento;
	nuevo -> siguiente = *pila;
	(*pila) = nuevo;
}

void suprimir(Nodo** pila)
{
	if (!pilaVacia(*pila))
	{
		Nodo *f;
		f = *pila;
		(*pila) = (*pila) -> siguiente;
			free(f);
	}
}

TipoDato cima(Nodo* pila)
{
	if(pilaVacia(pila))
	{
		puts(" Error de ejecución, pila vacía ");
		exit(1);
	}
	return pila -> elemento;
}

TipoDato quitar(Nodo** pila)
{
	TipoDato tem = cima(*pila);
	suprimir(pila);
	return tem;
}

void limpiarPila(Nodo** pila)
{
	while(!pilaVacia(*pila))
	{
		suprimir(pila);
	}
}
