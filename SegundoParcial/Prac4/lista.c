#include <stdio.h>
#include <stdlib.h>

#define VERDADERO 	1
#define FALSO		0

typedef struct elemento
{
	int dato;
}	t_elemento, *Elemento;


typedef struct nodo
{
	struct nodo *enlaceA;
	Elemento elem;
	struct nodo *enlaceB;
} t_nodo, *Nodo;

typedef struct lista
{
	Nodo primero;
	Nodo ultimo;
	int longitud;
}	t_lista, *Lista;


int crearElemento(Elemento *e)
{
	Elemento x= NULL;
	
	x= (Elemento) malloc(sizeof(t_elemento));
	
	if (x==NULL)
	  return(FALSO);
	  
	*e= x;  
	
	return(VERDADERO);
}

int destruirElemento(Elemento e)
{
	if (e==NULL)
	  return(FALSO);
	  
	free(e);
	return(VERDADERO);
}

int escribirDato(Elemento e, int dato)
{
	if (e==NULL)
	  return(FALSO);
	  
	e->dato= dato;
	
	return(VERDADERO);
}

int leerDato(Elemento e, int *dato)
{
	if (e==NULL)
	  return(FALSO);
	  
	*dato= e->dato;
	
	return(VERDADERO);
}


int crearNodo(Nodo *n)
{
	Nodo m= NULL;
	
	m= (Nodo) malloc(sizeof(t_nodo));
	
	if (m==NULL)
	  return(FALSO);
	
	m->enlaceA= NULL;
	m->elem= NULL;
	m->enlaceB= NULL;
	
	*n= m;
	
	return(VERDADERO);
}

int destruirNodo(Nodo n)
{
	if (n==NULL)
	  return(FALSO);
	  
	n->elem= NULL;	//la destrucción del elemento se realiza por separado

	n->enlaceA= NULL;	
	n->enlaceB= NULL;
		
	free(n);
	
	return(VERDADERO);
}

int escribirElemento(Nodo n, Elemento e)
{
	if (n==NULL)
	  return(FALSO);
	  
	n->elem= e;
	
	return(VERDADERO);
}

int leerElemento(Nodo n, Elemento *e)
{
	if (n==NULL)
	  return(FALSO);
	  
	*e= n->elem;
	
	return(VERDADERO);
}

int conectarEnlaceA(Nodo n, Nodo eA)
{
	if (n==NULL)
	  return(FALSO);
	  
	n->enlaceA= eA;
	
	return(VERDADERO);
}

int conectarEnlaceB(Nodo n, Nodo eB)
{
	if (n==NULL)
	  return(FALSO);
	  
	n->enlaceB= eB;
	
	return(VERDADERO) ;
}

int consultarEnlaceA(Nodo n, Nodo *eA)
{
	if (n==NULL)
	 {	 
	 	*eA= NULL;
	    return(FALSO);
	 }
	  
	*eA= n->enlaceA;
	
	return(VERDADERO) ;
}

int consultarEnlaceB(Nodo n, Nodo *eB)
{
	if (n==NULL)
	  {	 
	 	*eB= NULL;
	    return(FALSO);
	  }
	  
	*eB= n->enlaceB;
	
	return(VERDADERO) ;
}

int desconectarEnlaceA(Nodo n)
{
	if (n==NULL)
	  return(FALSO);
	  
	n->enlaceA= NULL;
	
	return(VERDADERO) ;
}

int desconectarEnlaceB(Nodo n)
{
	if (n==NULL)
	  return(FALSO);
	  
	n->enlaceB= NULL;
	
	return(VERDADERO) ;
}

int crearLista(Lista *l)
{
	Lista y= NULL;

	y= (Lista) malloc(sizeof(t_lista));

	if (y==NULL)
	  return(FALSO);

	y->primero= NULL;
	y->ultimo= NULL;
	y->longitud= 0;

	*l= y;

	return(VERDADERO);
}


int insertarElemento(Lista l, Elemento e)
{
	Nodo n= NULL;
	int sw= FALSO;
	
	if (l==NULL)
	  return(FALSO);
	
	sw= crearNodo(&n);
	
	if (sw==VERDADERO)
		{
			sw= escribirElemento(n, e);
			if (sw==VERDADERO)
				{
					if (l->longitud==0)
					  l->primero= n;
					else
					  conectarEnlaceA(l->ultimo, n);
					  
					l->ultimo= n;
					(l->longitud)++;
					return(VERDADERO);
				}
		}
		
	return(FALSO);
}

int quitarElemento(Lista l, Elemento *e)
{
	int sw= FALSO;
	Nodo siguiente= NULL;
	
	if (l==NULL)
	  return(FALSO);
	  
	if (l->longitud==0)
	  return(FALSO);
	  
	sw= leerElemento(l->primero, e);
	
	if (sw==VERDADERO)
		{
			sw= consultarEnlaceA(l->primero, &siguiente);			
			if (sw==VERDADERO)
				{				
					sw= desconectarEnlaceA(l->primero);
					if (sw==VERDADERO)
						{		
							sw= destruirNodo(l->primero);
							if (sw==VERDADERO)
								{	
									l->primero= siguiente;
									(l->longitud)--;
							
									if (l->longitud==0)
							  			{
							  				l->primero= NULL;
							  				l->ultimo= NULL;
							  			}
							  	}
							return(VERDADERO);
						}
				}
		}
		
	return(FALSO);
}

int consultarPrimero(Lista l, Elemento *e)
{
	int sw= FALSO;
	
	if (l==NULL)
	  return(FALSO);
	  
	if (l->longitud==0 || l->primero==NULL)
	  return(FALSO);
	  
	sw= leerElemento(l->primero, e);
	  
	return(sw);
}

int destruirLista(Lista l)
{
	Nodo aux= NULL;
	int sw= FALSO;
	
	if (l==NULL)
	  return(FALSO);
	  
	while(l->primero!=NULL)
	{
		sw= consultarEnlaceA(l->primero, &aux);
		if (sw==FALSO)
		  return(FALSO);
		  
		sw= desconectarEnlaceA(l->primero);
		if (sw==FALSO)
		  return(FALSO);
		  
		sw= destruirNodo(l->primero);
		if (sw==FALSO)
		  return(FALSO);
		
		l->primero= aux;
		l->longitud--;
	}
	
	l->primero= NULL;
	l->ultimo= NULL;
	free(l);
	
	return(VERDADERO);
}

int insertarElementoPosicion(Lista l, Elemento e, int posicion)
{
	Nodo nuevo= NULL, aux=NULL, contiguo=NULL, sig= NULL;
	int sw= FALSO;
	int k=0;
		
	if (l==NULL)
	  return(FALSO);	
	
	sw= crearNodo(&nuevo);
	
	if (sw==VERDADERO)
		{			
			sw= escribirElemento(nuevo, e);
			if (sw==VERDADERO)
				{					
					if (l->longitud==0)
						{									
					  		l->primero= nuevo;
					  		(l->longitud)++;
					  	}
					else
					{						
						aux= l->primero;
						
						for (k=0; k<l->longitud; k++)
							{
								if (aux==NULL)
								  break;								  
								
								if (k==posicion)
									{										
										consultarEnlaceA(aux, &contiguo);
										
										desconectarEnlaceA(aux);
										desconectarEnlaceB(contiguo);
										
										conectarEnlaceA(aux, nuevo);
										conectarEnlaceB(contiguo, nuevo);										
										
										conectarEnlaceB(nuevo, aux);
										conectarEnlaceA(nuevo, contiguo);
										
										(l->longitud)++;

										break;
									}
								consultarEnlaceA(aux, &sig);
								aux= sig;
							}		
					
					}
					
					if (posicion==l->longitud-1)
					  l->ultimo= nuevo;
					
					return(VERDADERO);					
				}
		}
		
	return(FALSO);
}

int quitarElementoPosicion(Lista l, Elemento *e, int posicion)
{
	Nodo nuevo= NULL, aux=NULL, anterior= NULL, contiguo=NULL, sig= NULL;
	int sw= VERDADERO;
	int k=0;
		
	if (l==NULL)
	  return(FALSO);
	
	if (l->longitud==0)
	  return(FALSO);
	

	if (l->longitud==1)
	  {			
		leerElemento(l->primero, e);
		destruirNodo(l->primero);
		l->primero= NULL;
		l->ultimo= NULL;
		l->longitud= 0;
		return(VERDADERO);
	  }
	else
	  {
		aux= l->primero;
		for (k=0; k<l->longitud; k++)
		   {
				if (aux==NULL)
				  break;
								  
				if (k==posicion)
				  {															
					leerElemento(aux, e);
										
					consultarEnlaceA(aux, &contiguo);
					consultarEnlaceB(aux, &anterior);
										
					desconectarEnlaceA(aux);
					desconectarEnlaceB(contiguo);
										
					desconectarEnlaceB(aux);
					desconectarEnlaceA(anterior);
										
					conectarEnlaceA(anterior, contiguo);
					conectarEnlaceB(contiguo, anterior);										
										
					destruirNodo(aux);
										
					if (posicion==0)
					  l->primero= contiguo;
										  
					if (posicion==l->longitud-1)
					  l->ultimo= anterior;

					(l->longitud)--;
										
					return(VERDADERO);
				  }
								
				consultarEnlaceA(aux, &sig);							
				aux= sig;
			}	
										
	  }
					
	return(FALSO);
}

int main(int argc, char *argv[])
{
	Lista l= NULL;
	Elemento e= NULL;
	int k=0, x=0;
	int N= 3;	
	
	crearLista(&l);
	
	for (k=0; k<N; k++)
	 	{
	 		crearElemento(&e);
	 		escribirDato(e, k);
			insertarElementoPosicion(l, e, k-1);
		}
	
	for (k=N-1; k>=0; k--)
	 	{
	 		quitarElementoPosicion(l, &e, k);
	 		leerDato(e, &x);
	 		printf("%d\n", x);
		}
	
	destruirLista(l);
	return 0;
}

