#include <stdio.h>
#include <stdlib.h>

int *creaArreglo(int nN);
void destruirArreglo(int *u);
int *ingresaComponentesArreglo(int nN, int *u);

void imprimeDireccionArreglo(int* arr);
void imprimeDireccionQueAlmacenaArreglo(int* arr);
void imprimeDireccionCeldasArreglo(int* arr, int n);

void imprimeOpciones();

int main()
{
	int* arreglo = NULL, n=0;
	printf("Práctica 2\nEste programa crea un arreglo mediante un apuntador sencillo.\nIngresa el tamaño 'n' del arreglo.\n");
	scanf("%d",&n);     
    arreglo = creaArreglo(n);
    arreglo = ingresaComponentesArreglo(n,arreglo);
    imprimeDireccionArreglo(arreglo);
    imprimeDireccionQueAlmacenaArreglo(arreglo);
	imprimeDireccionCeldasArreglo(arreglo,n);
    destruirArreglo(arreglo);
	return 0;
}
	

int *creaArreglo(int nN)
{
	int *arr=NULL;
	arr = (int*)malloc(nN*sizeof(int));
	return arr;
}

void destruirArreglo(int *u)
{
	if(u!=NULL)
		free(u);
}

int *ingresaComponentesArreglo(int nN, int *u)
{
	int i=0;
	for(i = 0 ; i < nN ; i++ )
	{
		u[i]=i;
	}
	return u;
}

void imprimeDireccionArreglo(int* arr)
{
	printf("\nLa dirección de alrreglo es: \n%p\n", &arr);
}

void imprimeDireccionQueAlmacenaArreglo(int* arr)
{
	printf("\nLa dirección a la que hace referencia el arreglo es:\n%p\n", arr);	
}

void imprimeDireccionCeldasArreglo(int* arr, int n)
{
	printf("\nLa dirección de cada una de las celas y su contenido es:\n");
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%p %d\n", &arr[i],arr[i]);
	}
}
