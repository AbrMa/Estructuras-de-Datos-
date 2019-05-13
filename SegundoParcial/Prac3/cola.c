typedef int item;
#include "cola.h"

void CrearCola(COLA *Q){
	Q->frente = Q->final = 0;
}

int ColaLlena(COLA Q){
	if(Q.frente == (Q.final+1)%TAM)
		return 1;
	
	return 0;
}

int ColaVacia(COLA Q){
	if(Q.frente == Q.final)
		return 1;
	
	return 0;
}

void InsertarCola(COLA *Q, item x){
	if(ColaLlena(*Q)){
		printf("Error, cola llena");
		exit(-1);
	}
	Q->final = ((Q->final+1)%TAM);
	Q->ListaCola[Q->final] = x;
}

item QuitarCola(COLA *Q){
	if(ColaVacia(*Q)){
		printf("Error, cola vacia");
		exit(-1);
	}
	Q->frente = ((Q->frente+1)%TAM);
	return (Q->ListaCola[Q->frente]);
}

item FrenteCola(COLA Q){
	if(ColaVacia(Q)){
		printf("Error, cola vacia");
		exit(-1);
	}
	
	return (Q.ListaCola[(Q.frente+1)%TAM]);
}
