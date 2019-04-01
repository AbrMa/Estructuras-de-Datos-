#include <stdio.h>
#define N 8 
#define n (N+1)

void colocaReina(int i, int* solucion, int* contador);
int valido(int j);
void escribirUbicacion();
int reinas[n];
int main()
{
	int tieneSolucion, contador = 0;
	colocaReina(1, &tieneSolucion, &contador);
	return 0;
}

void colocaReina(int i, int* solucion, int* contador)
{
	int k;
	*solucion = 0;
	//do{
	for(k = 1; k<= N; k++)
	{
		reinas[i] = k;

		if(valido(i))
		{
			if (i<N)
			{
				colocaReina(i+1,solucion,contador);
				if(!(*solucion))
					reinas[i] = 0;
			}
			else
			{
				*solucion = 1;
				*contador += 1;
				printf("Tablero %d\n\n", *contador);
				escribirUbicacion();
				printf("___________________________\n\n");
			}

		}
	}
	//}while(!(*solucion) && (k < N));
}

int valido(int j)
{
	int v, r;
	v = 1;
	for(r = 1; r <= j-1; r++)
	{
		v = v && (reinas[r] != reinas[j]);
		v = v && ((reinas[j] + j) != (reinas[r] + r));
	        v = v && ((reinas[j] - j) != (reinas[r] - r));
	}
	return v;	
}

void escribirUbicacion()
{
	int i,j,a,b;
	char arr[N][N]; 
	for(i=0; i<N; i++)
		for(j=0; j<N; j++)
			arr[i][j] = 0;

	
//	for(i = 1; i <= N; i++)
//		printf("Reina %d en fila %d \n",i,reinas[i]);
	

 	for (i = 0; i<=N ; i++)
	{
		a = reinas[i]-1;
		b = i-1;
		arr[a][b] = 1;
	}

	for(i = 0; i<N; i++)
	{
		for (j=0; j<N; j++)
			printf("  %d  ", arr[i][j]);
		printf("\n\n");
	}
}

