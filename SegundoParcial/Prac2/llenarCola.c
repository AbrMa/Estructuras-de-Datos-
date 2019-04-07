#include <stdio.h>
#include <time.h>
#include "coladinamica.c"

int volado();
void milVecesMeterQuitar( Cola* cola );
void prueba( Cola *cola );

int main( )
{
	Cola cola;
	crearCola( &cola );
	milVecesMeterQuitar( &cola ); 
	return 0;
}

void prueba( Cola *cola )
{
	insertar( cola, 1 );
	quitar( cola );	
}

int volado( )
{
	return rand() % 2;
}

void milVecesMeterQuitar( Cola* cola )
{
	int meter = 1000, eliminar = 1000, temp, i = 0, j = 0;	

	while ( meter && quitar )
	{
		if ( volado() )
		{
			temp = rand() % 101; 
			insertar( cola, temp);
			printf( "PUSH\t%d\t%d\tIngresado a la cola\n", i+1, temp );
			i++;
			meter--;
		}
		{
			if ( !colaVacia( *cola ) )
			{
				temp = quitar( cola ); 
				printf( "POP\t%d\t%d\tEliminado de la cola\n", j+1, temp );
				j++;
				eliminar--;
			}
			else
			{
				printf( "\nCOLA VACÍA, SE VUELVE A TIRAR MONEDA\n\n" );
			}
		}
	
	}
}
