#include <stdio.h>
#include <string.h>
#include "pila.c" 

#define TAM 100

int elije_opcion();
void ejecuta_opcion();

int main()
{
	char cadena[TAM];	

	printf("\nCONVERSIÓN DE OPERACIONES INFIJA, POSTFIJA, PREFIJA\n");
	printf("\nIngrese la cadena a convertir: ");
	scanf("%s", &cadena);
	ejecuta_opcion();
	return 0;
}

int elije_opcion()
{
	int n;
	printf("\nElije una opción:\n");
	printf("(1) Convertir a infija. \n");
	printf("(2) Convertir a prefija. \n");
	printf("(3) Convertir a postfija. \n");
	scanf("%d", &n);
	return n;
}

void ejecuta_opcion()
{
	switch(elije_opcion())
	{
		case 1:
			printf("UNO\n");
			break;

		case 2:
			printf("DOS\n");
			break;

		case 3:
			printf("TRES\n");
			break;
		default:
			printf("Opción no valida, ingrese valor entre 1 y 3\n");
			ejecuta_opcion();
	}
}

