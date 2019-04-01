#include <stdio.h>
#include <stdlib.h>

typedef struct memoria{
    
    int *arreglo;
    int N;
}t_memoria,*Memoria;

Memoria crearMemoria(int longitud);
void destruirMemoria(Memoria m);
void escribirDato(Memoria m, int dato, int loc);
int leerDato(Memoria m, int loc);

void main()
{
    Memoria recuerdo = NULL;
    recuerdo = crearMemoria(1000);
    escribirDato(recuerdo,50,2);
    printf("El dato ingresado en la localizacion 2 es: %d",leerDato(recuerdo,2));
    destruirMemoria(recuerdo);
}

int leerDato(Memoria m, int loc)
{
    if(m==NULL)
        return 0;
    if(m->arreglo!=NULL)
        if(loc >= 0 && loc < m->N)
            return (m->arreglo[loc]);
    return 0;
}

void escribirDato(Memoria m, int dato, int loc)
{
    if(m==NULL)
        return;
    if(m->arreglo!=NULL && loc>=0 && loc < m->N)
        m->arreglo[loc] = dato;
}

void destruirMemoria(Memoria m)
{
    if(m==NULL)
        return;
    if(m->arreglo!=NULL)
        free(m->arreglo);
    free(m);
}

Memoria crearMemoria(int longitud)
{
    Memoria m = NULL;
    m = (Memoria)malloc(sizeof(t_memoria));
    if(m==NULL)
        return NULL;
    if(longitud>0)
    {
        m->arreglo=(int*)malloc(longitud*sizeof(int));
        if(m->arreglo==NULL)
        {
            free(m);
            m=NULL;
        }
        m->N = longitud;
    }
    return m;
}
