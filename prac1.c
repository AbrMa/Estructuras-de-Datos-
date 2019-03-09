#include <stdio.h>
#include <stdlib.h>

int *****asignaMemoriaCincoDimensiones(int mM, int nN, int oO, int pP, int qQ);
int *****ingresaValoresCincoDimensiones(int *****a,int mM, int nN, int oO, int pP, int qQ);
void destruyeMemoriaCincoDimensiones(int ***** a,int mM, int nN, int oO, int pP);

int main()
{
	int *****fiveCube=NULL, m=0, n=0, o=0, p=0, q=0;
	printf("PRÁCTICA 1: Apuntadores\nIngresa las cinco dimensiones separadas por espacio:\nm n o p q\n");
	scanf("%d %d %d %d %d",&m,&n,&o,&p,&q);
	fiveCube=asignaMemoriaCincoDimensiones(m,n,o,p,q);
	fiveCube=ingresaValoresCincoDimensiones(fiveCube,m,n,o,p,q);
	destruyeMemoriaCincoDimensiones(fiveCube,m,n,o,p);

	return 0;
}

int *****asignaMemoriaCincoDimensiones(int mM, int nN, int oO, int pP, int qQ)
{
	int *****aux = NULL, i=0, j=0, k=0, l=0, eme=0;
	aux = (int *****)malloc(mM*sizeof(int ****));
	for(i=0; i<mM; i++)
	{
		aux[i] = (int ****)malloc(nN*sizeof(int ***));
		for(j=0; j<nN; j++)
		{
			aux[i][j] = (int ***)malloc(oO*sizeof(int **));
			for(k=0; k<oO ; k++)
			{
				aux[i][j][k] = (int **)malloc(pP*sizeof(int *));
				for(l=0; l<pP; l++)
				{
					aux[i][j][k][l] = (int *)malloc(qQ*sizeof(int));
				}
			}
		}
	}
	return aux;
}
int *****ingresaValoresCincoDimensiones(int *****a,int mM, int nN, int oO, int pP, int qQ)
{
	int i=0, j=0, k=0, l=0, m=0;
	for(i=0; i<mM; i++)
		for(j=0; j<nN; j++)
			for(k=0; k<oO; k++)
				for(l=0; l<pP; l++)
					for(m=0; m<qQ; m++)
						a[i][j][k][l][m]=0;
	return a;
}

void destruyeMemoriaCincoDimensiones(int ***** a,int mM, int nN, int oO, int pP)
{
	int i=0, j=0, k=0, l=0;
	for(i=0; i<mM; i++)
	{
		for(j=0; j<nN; j++)
		{

			for(k=0; k<oO ; k++)
			{
				for(l=0; l<pP; l++)
				{
					free(a[i][j][k][l]);
				}
				free(a[i][j][k]);
			}
			free(a[i][j]);
		}
		free(a[i]);
	}
	free(a);
}