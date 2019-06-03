
#include "Pila.c"

void ArbolExp(char c, ArbolBinario *raiz, ArbolBinario *act, int *count, PILA **p);
void Recorridos(ArbolBinario raiz);

int main()
{
	char c;
	int count=0;
	ArbolBinario raiz;
	ArbolBinario actual;
	PILA *P=NULL;
	printf("Ingresa la Expresion valida, incluyendo parentesis: \n");
	while(c!='\n')
	{
		c=getchar();
		ArbolExp(c,&raiz,&actual,&count,&P);
	}
	Recorridos(raiz);
}

void ArbolExp(char c, ArbolBinario *raiz, ArbolBinario *act, int *count, PILA **p)
{
	if(c=='(' && *count==0)
	{
		*raiz=CrearNodo(' ');
		*act=*raiz;
		InsertarPila(p,*act);
		(*count)++;
	}
	else if(c=='(' && *count!=0)
	{
		if((*act)->izq==NULL)
		{
			(*act)->izq=CrearNodo(' ');
			*act=(*act)->izq;
			InsertarPila(p,*act);
		}
		else if((*act)->der==NULL)
		{
			(*act)->der=CrearNodo(' ');
			*act=(*act)->der;
			InsertarPila(p,*act);
		}
	}
	else if(c>65 && c<122)
	{
		if((*act)->izq==NULL)
		{
			(*act)->izq=CrearNodo(c);
		}
		else if((*act)->der==NULL)
		{
			(*act)->der=CrearNodo(c);
		}
	}
	else if(c=='+'||c=='-'||c=='/'||c=='*'||c=='^')
	{
		*act=QuitarPila(p);
		(*act)->dato=c;
	}
}

void Recorridos(ArbolBinario raiz)
{
	printf("\nEXPRESION PREFIJA\n");
	preorden(raiz);
	printf("\nEXPRESION INFIJA\n");
	enorden(raiz);
	printf("\nEXPRESION PREFIJA\n");
	postorden(raiz);
}
