#include <stdio.h>

void hanoi( char varInicial, char varFinal, char varCentral, int n);
void imprimeMenu();

int main()
{
	int n = 0;
	imprimeMenu();
	scanf("%d",&n);
	hanoi('A','C','B',n);
	return 0;
}

void hanoi( char varInicial, char varFinal, char varCentral, int n)
{
	if(n==1)
		printf("Mueve disco %d de barra %c a %c \n", n, varInicial, varFinal);
	else
	{
		hanoi(varInicial, varCentral, varFinal, n-1);
		printf("Mueve disco %d de barra %c a %c \n", n, varInicial, varFinal);
		hanoi(varCentral, varFinal, varInicial, n-1); 
	}
}

void imprimeMenu()
{
	printf("Práctica 5: Torres de Hanoi\n");
	printf("La siguiente práctica da las instrucciones para resolver el puzzle de las torres de hanoi para n discos, ingrese el número de discos:\n");
}
