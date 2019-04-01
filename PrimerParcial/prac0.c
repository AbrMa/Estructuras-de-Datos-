#include <stdio.h>
#include <stdlib.h>

int muestraMenu();
void elijeOpcion(int n);

//funciones principales.
void sumaVectores();
void productoPunto();
void sumaMatrices();
void multipliacionMatrizVector(int operacion);

int *creaVector(int nN);
void destruirVector(int *u);
int *ingresaComponentesVectores(int nN, int *u);
void imprimeSumaVectores(int nN, int *u, int *v);
void imprimeProductoPuntoVectores(int nN, int *u, int*v);

int **creaMatriz(int mM, int nN);
void destruirMatriz(int **u, int mM);
int **ingresaComponentesMatriz(int mM, int nN, int **u);
void imprimeMatriz(int mM, int nN, int **u);
void imprimeSumaMatriz(int mM, int nN, int **u, int **v);
int **MultiplicacionMatrices(int mM, int nN, int lL,int **u, int **v);

int main()
{
	int opc = -1;
	opc = muestraMenu();
	elijeOpcion(opc);
	return 0;
}

int muestraMenu()
{
	int aux = -1;
	printf("PRÁCTICA 0 - Libreria de álgebra lineal.\n");
	printf("Este programa realiza operaciones básicas de álgebra lineal.\n");
	printf("(0)...Suma de vectores.\n");
	printf("(1)...Producto punto.\n");
	printf("(2)...Suma de matrices.\n");
	printf("(3)...Multiplicación de matriz por vector.\n");
	printf("(4)...Multiplicación de 2 matrices.\n");
	printf("Elija una opción.\n");
	scanf("%d",&aux);
	return aux;
}

void elijeOpcion(int n)
{
	switch(n)
	{
		case 0:
			sumaVectores();
		break;
		case 1:
			productoPunto();
		break;
		case 2:
			sumaMatrices();
		break;
		case 3:
			multipliacionMatrizVector(0);
		break;
		case 4:
			multipliacionMatrizVector(1);
		break;
		default:
			printf("Número no válido.\n");
			main();
	}
}

void sumaVectores()
{
	int n = 0, *a=NULL, *b=NULL;
	printf("Usted eligió:\n");
	printf("(0)...Suma de Vectores.\n");
	printf("Sean A & B vectores que pertenecen a V^n, ingrese n, número de componentes del vector.\n");
	scanf("%d", &n);
	a = creaVector(n);
	b = creaVector(n);
	printf("Vector A:\n");
	a = ingresaComponentesVectores(n,a);
	printf("Vector B\n");
	b = ingresaComponentesVectores(n,b);
	imprimeSumaVectores(n,a,b);
	destruirVector(a);
	destruirVector(b);
}

void productoPunto()
{
	int n = 0, *a=NULL, *b=NULL;
	printf("Usted eligió:\n");
	printf("(1)...Producto punto.\n");
	printf("Sean A & B vectores que pertenecen a V^n, ingrese n, número de componentes del vector.\n");
	scanf("%d", &n);
	a = creaVector(n);
	b = creaVector(n);
	a = ingresaComponentesVectores(n,a);
	b = ingresaComponentesVectores(n,b);
	imprimeProductoPuntoVectores(n,a,b);
	destruirVector(a);
	destruirVector(b);
}

void sumaMatrices()
{
	int m=0, n=0, **a=NULL, **b=NULL;
	printf("Usted eligió:\n");
	printf("(2)...Suma de matrices.\n");
	printf("Sean A & B matrices de mismo tamaño mxn, ingrese m = \n");
	scanf("%d",&m);
	printf("Ingrese n = \n");
	scanf("%d",&n);
	a = creaMatriz(m,n);
	b = creaMatriz(m,n);
	printf("Ahora ingrese los datos en las matrices\n");
	printf("Matriz A:\n");
	ingresaComponentesMatriz(m,n,a);
	printf("Matriz B:\n");
	ingresaComponentesMatriz(m,n,b);
	printf("La Matriz A es : \n");
	imprimeMatriz(m,n,a);
	printf("La Matriz B es : \n");
	imprimeMatriz(m,n,b);
	printf("La Matriz C=A+B es :\n");
	imprimeSumaMatriz(m,n,a,b);
	destruirMatriz(a,m);
	destruirMatriz(b,m);
}

void multipliacionMatrizVector(int operacion)
{
	int **a=NULL, **b=NULL, **c=NULL, m=0, n=0, k=0;
	printf("Usted eligió:\n");
	printf("(3)...Multiplicación de matriz por vector.\n");
	printf("Sea A una matriz de tamaño mxn, ingrese m = \n");
	scanf("%d",&m);
	printf("Ingrese n = \n");
	scanf("%d",&n);
	if(operacion == 0 )
	{
		printf("Sean B un vector que pertenece a V^n, el vector B tiene %d componentes.\n",n);
		k=1;
	}
	else
	{
		printf("Sean B una matriz de tamaño nxk ingrese k\n");
		scanf("%d",&k);
	}
	b = creaMatriz(m,n);
	a = creaMatriz(n,k);
	c = creaMatriz(m,k);
	printf("Ingrese valores para Matriz A:\n");
	b = ingresaComponentesMatriz(m,n,b);
	printf("Ingrese valores para Matriz B:\n");
	a = ingresaComponentesMatriz(n,k,a);;
	c = MultiplicacionMatrices(m, n, k, b, a);
	printf("Matriz B\n");
	imprimeMatriz(m,n,b);
	printf("Matriz A\n");
	imprimeMatriz(n,k,a);
	printf("C=AB :\n");
	imprimeMatriz(m,k,c);
}

int *creaVector(int nN)
{
	int *arr=NULL;
	arr = (int*)malloc(nN*sizeof(int));
	return arr;
}

void destruirVector(int *u)
{
	if(u!=NULL)
		free(u);
}

int *ingresaComponentesVectores(int nN, int *u)
{
	int i=0;
	for(i = 0 ; i < nN ; i++ )
	{
		printf("Ingrese la componente %d del vector A\n", (i+1));
		scanf("%d",&u[i]);
	}
	return u;
}

void imprimeSumaVectores(int nN, int *u, int *v)
{
	int i = 0;
	printf("A=<");
	for(i = 0 ; i < nN ; i++ )
	{
		 printf("%d", u[i]);
		 if(i < nN-1)
		 	printf(",");
	}
	printf("> & B=<");
	for(i = 0 ; i < nN ; i++ )
	{
		 printf("%d", v[i]);
		 if(i < nN-1)
		 	printf(",");
	}
	printf("> , A+B=<");
		for(i = 0 ; i < nN ; i++ )
	{
		 printf("%d", u[i]+v[i]);
		 if(i < nN-1)
		 	printf(",");
	}
	printf(">\n");	
}

void imprimeProductoPuntoVectores(int nN, int *u, int*v)
{
	int i, escalar=0;
	printf("A=<");
	for(i = 0 ; i < nN ; i++ )
	{
		 printf("%d", u[i]);
		 if(i < nN-1)
		 	printf(",");
	}
	printf("> & B=<");
	for(i = 0 ; i < nN ; i++ )
	{
		 printf("%d", v[i]);
		 if(i < nN-1)
		 	printf(",");
	}
	printf("> , A.B = ");
	for(i = 0 ; i < nN ; i++ )
	{
		escalar += u[i]*v[i];
		printf("(%d)(%d)", u[i],v[i]);
		if(i < nN-1)
			printf("+");
	}
	printf(" = %d\n",escalar);
}

int **creaMatriz(int mM, int nN)
{
	int i=0, j=0, **mat = NULL;
	mat = (int**)malloc(mM*sizeof(int*));
	for(i=0; i<mM; i++)
		mat[i]=(int*)malloc(nN*sizeof(int));
	return mat;
}

int **ingresaComponentesMatriz(int mM, int nN, int **u)
{
	int i=0, j=0;
	for(i=0; i<mM; i++)
	{
		for (j=0; j<nN; j++)
		{
			printf("Ingrese en Matriz en la columna %d en la fila %d\n", i+1 , j+1);
			scanf("%d",&u[i][j]);
		}
	}
	return u;
}

void imprimeMatriz(int mM, int nN, int **u)
{
	int i=0, j=0;
	for(i=0; i<mM; i++)
	{
		for (j=0; j<nN; j++)
		{
			printf("%d\t",u[i][j]);
		}
		printf("\n");
	}
}

void imprimeSumaMatriz(int mM, int nN, int **u, int **v)
{
	int i=0, j=0;
	for(i=0; i<mM; i++)
	{
		for (j=0; j<nN; j++)
		{
			printf("%d\t",u[i][j]+v[i][j]);
		}
		printf("\n");
	}
}

void destruirMatriz(int **u, int mM)
{
	int i=0;
	for(i=0; i<mM; i++)
	{
		free(u[i]);
	}
	free(u);
}

int **MultiplicacionMatrices(int mM, int nN, int lL, int **u, int **v)
{	
	int i=0, j=0, k=0;
	int **resultado = NULL, aux=0;
	resultado = creaMatriz(mM,lL);
	for(k=0; k<lL; k++)
	{
		for(i=0; i<mM; i++)
		{
			for(j=0; j<nN; j++)
			{
				aux += u[i][j]*v[j][k];
			}
			resultado[i][k] = aux ;
			aux=0;
		}
	}
	return resultado;
}
