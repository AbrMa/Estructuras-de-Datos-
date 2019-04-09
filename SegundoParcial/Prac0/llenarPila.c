#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Estructura de datos.
#include "pila.c"
//función que llena la pila.
void llenaPila(Nodo** pila);
void imprimirPila(Nodo* pila);
int volado( );
void milVecesMeterQuitar( Nodo** pila );

int main()
{
	time_t t;
	srand((unsigned) time(&t));
	//Descripción del programa.
	printf("Práctica 1: Pilas dinámicas.\n\nEste programa prueba la estructura de datos de pila.\nSe llena con 100 elementos (enteros) y después se vacía la pila.\n");
	Nodo* pila;//Declaración de la pila	
	crearPila(&pila);
	//llenaPila(&pila);
	//imprimirPila(pila);
	//limpiarPila(&pila);
	milVecesMeterQuitar( &pila );
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

int volado( )
{
	return rand() % 2;
}

void milVecesMeterQuitar( Nodo** pila )
{
	int meter = 1000, eliminar = 1000, temp, i = 0, j = 0;	

	while ( meter && eliminar )
	{
		if ( volado() )
		{
			temp = rand() % 101; 
			insertar( pila, temp );
			printf( "PUSH\t%d\t%d\tIngresado a la pila\n", i+1, temp );
			i++;
			meter--;
		}
		else
		{
			if ( !pilaVacia( *pila ) )
			{
				temp = quitar( pila ); 
				printf( "POP\t%d\t%d\tEliminado de la pila\n", j+1, temp );
				j++;
				eliminar--;
			}
			else
			{
				printf( "\nPILA VACÍA, SE VUELVE A TIRAR MONEDA\n\n" );
			}
		}
	
	}
}
