#include <stdio.h>
#include <stdlib.h>
#define TAM 100

typedef struct cola{
	int frente;
	int final;
	item ListaCola[TAM];
}COLA;

void InsertarCola(COLA *Q, item x);
void CrearCola(COLA *Q);
item FrenteCola(COLA Q);
item QuitarCola(COLA *Q);
item ColaLlena(COLA Q);
int ColaVacia(COLA Q);
