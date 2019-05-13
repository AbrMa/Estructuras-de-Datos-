#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
//Estructura de datos.
#include "pila.c"
#define TAM 100

int esOperando(char C);
int esOperador(char C);
int IsRightAssociative(char op);
int obtenerPrecedencia(char op);
int tieneMAyorPrecedencia(char op1, char op2);

void imprimePostfija(char *arr);

int main()
{
	char cadena[TAM];
	scanf("%s", cadena);
	imprimePostfija(&cadena[TAM]);
	return 0;
}


void imprimePostfija(char *arr)
{
	Nodo* pila;
	crearPila(&pila);
	char cadena[TAM] = "";
}

int esOperando(char C)
{
	if(C >= '0' && C <= '9') return 1;
	if(C >= 'a' && C <= 'z') return 1;
	if(C >= 'A' && C <= 'Z') return 1;
	return 0;
}

int esOperador(char C)
{
	if(C == '+' || C == '-' || C == '*' || C == '/' || C== '$')
		return 1;

	return 0;
}

int IsRightAssociative(char op)
{
	if(op == '$') return 1;
	return 0;
}

int obtenerPrecedencia(char op)
{
	int weight = -1;
	switch(op)
	{
	case '+':
	case '-':
		weight = 1;
	case '*':
	case '/':
		weight = 2;
	case '$':
		weight = 3;
	}
	return weight;
}

int tieneMAyorPrecedencia(char op1, char op2)
{
	int op1Weight = obtenerPrecedencia(op1);
	int op2Weight = obtenerPrecedencia(op2);

	if(op1Weight == op2Weight)
	{
		if(IsRightAssociative(op1)) return 0;
		else return 1;
	}
	return op1Weight > op2Weight ?  1: 0;
}
