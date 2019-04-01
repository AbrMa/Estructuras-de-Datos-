#include <stdio.h>
#include <stdlib.h>
//Estructura de datos.
#include "pila.c"
//función que llena la pila.
void llenaPila(Nodo** pila);
void imprimirPila(Nodo* pila);

int main()
{
	//Descripción del programa.
	printf("Práctica 1: Pilas dinámicas.\n\nEste programa prueba la estructura de datos de pila.\nSe llena con 100 elementos (enteros) y después se vacía la pila.\n");
	Nodo* pila;//Declaración de la pila	
	crearPila(&pila);
	llenaPila(&pila);
	imprimirPila(pila);
	return 0;
}

void llenaPila(Nodo** pila)
{
	int i;
	for ( int i = 1; i < 101; i++ )
		insertar( pila, i );
}

void imprimirPila(Nodo* pila)
{
	while ( pila )
	{
		printf( "%d \n", pila -> elemento);
		pila = pila -> siguiente;
	}
}
