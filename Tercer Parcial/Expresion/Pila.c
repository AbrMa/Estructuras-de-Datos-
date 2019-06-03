#include"Pila.h"

int PilaVacia(PILA *p)
{
	if(p==NULL)
		return 1;
	return 0;
}

Tipodato CimaPila(PILA *p)
{
	if(!PilaVacia(p))
		return p->dato;
	else
	{
		printf("ERROR, PILA VACIA");
		exit(-1);
	}
}

void InsertarPila(PILA **p, Tipodato x)
{
	PILA *aux=(PILA *)malloc(sizeof(PILA));
	aux->dato=x;
	aux->enlace=*p;
	*p=aux;
}

Tipodato QuitarPila(PILA **p)
{
	if(PilaVacia(*p))
	{
		printf("ERROR, PILA VACIA");
		exit(-1);
	}
	Tipodato aux=(*p)->dato;
	*p=(*p)->enlace;
	return aux;
}

void EliminarPila(PILA *p)
{
	if(p!=NULL)
	{
		EliminarPila(p->enlace);
		free(p);
	}
}
