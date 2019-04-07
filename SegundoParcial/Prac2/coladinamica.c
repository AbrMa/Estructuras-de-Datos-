typedef int TipoDato;
#include "coladinamica.h"

void crearCola( Cola* cola )
{
	cola -> frente = cola -> fin = NULL;
}

Nodo* crearNodo( TipoDato elemento )
{
	Nodo* t;
	t = ( Nodo* )malloc( sizeof( Nodo ) );
	t -> elemento = elemento;
	t -> siguiente = NULL;
	return t;
}

int colaVacia( Cola cola )
{
	return ( cola.frente == NULL );
}

void insertar( Cola* cola, TipoDato entrada)
{
	Nodo* a;
	a = crearNodo( entrada );
	if ( colaVacia( *cola ) )
		cola -> frente = a;
	else
		cola -> fin -> siguiente = a;
	cola -> fin = a;
}

TipoDato quitar( Cola* cola )
{
	TipoDato tmp;
	if ( !colaVacia( *cola ) )
	{
		Nodo* a;
		a = cola -> frente;
		tmp = cola -> frente -> elemento;
		cola -> frente = cola -> frente -> siguiente;
		free( a );
	}
	else
	{
		puts( "Error cometido al intentar eliminar de una cola vacía" );
		exit( -1 );
	}
		return tmp;
}

TipoDato frente( Cola cola )
{
	if ( colaVacia( cola ) )
	{
		puts( " Error: cola vacía " );
		exit( -1 );
	}
	return ( cola.frente -> elemento );
}

void borrarCola( Cola* cola )
{
	while ( cola -> frente )
	{
		Nodo* n;
		n = cola -> frente;
		cola -> frente = cola -> frente -> siguiente;
		free( n );
	}
}
