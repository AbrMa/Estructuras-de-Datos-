#include<stdlib.h>
#include<stdio.h>

typedef char itemA;
typedef struct nodoA
{
	itemA dato;
	struct nodoA *izq,*der;
}ElemAB;
typedef ElemAB *ArbolBinario;

ArbolBinario CrearNodo(itemA x);
void NuevoArbol(ArbolBinario *r, itemA x, ArbolBinario , ArbolBinario);
void Liberar(ArbolBinario raiz);
void imprimirA(ArbolBinario raiz);
int profundidad(ArbolBinario raiz);
void ContarHojas(ArbolBinario raiz, int *nh);
void preorden(ArbolBinario raiz);
void enorden(ArbolBinario raiz);
void postorden(ArbolBinario raiz);
