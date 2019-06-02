#include <stdio.h>
#include <time.h>
#include "pila.c"

ficha fichas[28];
ficha jugadorUno[21];
ficha jugadorDos[21];
void seleccionarFicha(int x, Nodo** Fichas, Nodo** Tablero);
int ultimo = 6;
void crearFichas();
void revolverFichas(Nodo** Fichas);
void repartirFaJuagadores(Nodo** Fichas);
void crearMenu();
void mostrarFichas(int x);
void insertarTablero(Nodo** Tablero, ficha ficha);
void mostrarTablero(Nodo* Tablero);
int verificaGanador(ficha x[21]);

int main()
{
	int cont = 1, jugador = 0, opc;
	time_t t;
	ficha aux;
	aux.numA = 6;
	aux.numB = 6;
	srand((unsigned) time(&t));
	crearFichas();
	Nodo* Fichas;
	Nodo* Tablero;
	crearPila(&Fichas);
	crearPila(&Tablero);
	insertar(&Tablero, aux);
	revolverFichas(&Fichas);
	repartirFaJuagadores(&Fichas);
	mostrarTablero(Tablero);
	while(cont)
	{
		if (jugador == 0)
		{
			printf("Jugador %d, elige una opción\n", jugador+1);
			printf("(1) Mostrar fichas\n"); 
			printf("(2) Tirar ficha\n"); 
			printf("(3) Mostrar tablero\n"); 
			scanf("%d", &opc);
			switch (opc) 
			{
				case 1:
					mostrarFichas(1);
					break;
				case 2:
					seleccionarFicha(1, &Fichas, &Tablero);
					jugador++;
					jugador%=2;
					mostrarTablero(Tablero);
					printf("Jugada exitosa");
					break;
				case 3:
					mostrarTablero(Tablero);
					break;
			}

		}
		else if (jugador == 1)
		{
			printf("Jugador %d, elige una opción\n", jugador+1);
			printf("(1) Mostrar fichas\n"); 
			printf("(2) Tirar ficha\n"); 
			printf("(3) Mostrar tablero\n"); 
			scanf("%d", &opc);
			switch (opc) 
			{
				case 1:
					mostrarFichas(2);
					break;
				case 2:
					seleccionarFicha(2, &Fichas, &Tablero);
					jugador++;
					jugador%=2;
					mostrarTablero(Tablero);
					printf("Jugada exitosa");
					break;
				case 3:
					mostrarTablero(Tablero);
					break;
			}

		}
		
		if (verificaGanador(jugadorUno))
		{
			printf("Ganó el jugador Uno\n");
			cont = 0;
		}
		if (verificaGanador(jugadorDos))
		{
			printf("Ganó el jugador Uno\n");
			cont = 0;
		}

	}
	return 0;
}

int verificaGanador(ficha x[21])
{
	int i, suma = 0;
	for (i = 0; i < 21; i++)
		suma += x[i].numA;	
	if (suma == -21)
		return 1;
	else
		return 0;
}

void seleccionarFicha(int x, Nodo** Fichas, Nodo** Tablero)
{
	int num, valido = 1, comer = 0, i;
	ficha aux;
	if(x == 1)
	{
		while(valido)
		{
			mostrarFichas(1);
			printf("La última ficha ingresada fue %d\n", ultimo);
			printf("Selecciona una ficha\n");
			scanf("%d", &num);
			printf("Usted escogió la ficha %d\n", num);
			printf("|%d|%d|\n", jugadorUno[num].numA, jugadorUno[num].numB);
			if (jugadorUno[num].numA == ultimo || jugadorUno[num].numB == ultimo)
			{
				if (jugadorUno[num].numA == ultimo)
				{
					ultimo = jugadorUno[num].numB;
				}	
				else if (jugadorUno[num].numB == ultimo)
				{
					ultimo = jugadorUno[num].numA;
				}
				printf("Ahora el último número es: %d\n", ultimo);
				insertar(Tablero, jugadorUno[num]);
				jugadorUno[num].numA = -1;
				jugadorUno[num].numB = -1;
				valido = 0;
			}
			else
			{
				printf("Ficha no válida, por favor escoja otra, si desea comer presione 1\n");
				scanf("%d", &comer);
				if (comer == 1)
				{
					i = 0;
					while (jugadorUno[i].numA != -1)
					{
						i++;
						i%=21;
					}
					jugadorUno[i] = quitar(Fichas);
				}
				
			}
			
		}
	}

	if(x == 2)
	{
		while(valido)
		{
			mostrarFichas(2);
			printf("La última ficha ingresada fue %d\n", ultimo);
			printf("Selecciona una ficha\n");
			scanf("%d", &num);
			printf("Usted escogió la ficha %d\n", num);
			printf("|%d|%d|\n", jugadorDos[num].numA, jugadorDos[num].numB);
			if (jugadorDos[num].numA == ultimo || jugadorDos[num].numB == ultimo)
			{
				if (jugadorDos[num].numA == ultimo)
				{
					ultimo = jugadorDos[num].numB;
				}	
				else if (jugadorDos[num].numB == ultimo)
				{
					ultimo = jugadorDos[num].numA;
				}
				printf("Ahora el último número es: %d\n", ultimo);
				insertar(Tablero, jugadorDos[num]);
				jugadorDos[num].numA = -1;
				jugadorDos[num].numB = -1;
				valido = 0;
			}
			else
			{
				printf("Ficha no válida, por favor escoja otra, si desea comer presione 1\n");
				scanf("%d", &comer);
				if (comer == 1)
				{
					i = 0;
					while (jugadorDos[i].numA != -1)
					{
						i++;
						i%=21;
					}
					jugadorDos[i] = quitar(Fichas);
				}
				
			}
			
		}
	}

}

void mostrarTablero(Nodo* Tablero)
{
	printf("******Tablero******\n");
	printf("La última pieza es: %d \n", ultimo); 
	while(Tablero)
	{
		printf("|%d|%d|\n\n", Tablero -> elemento.numA, Tablero -> elemento.numB);
		Tablero = Tablero -> siguiente;
	}
	printf("*******************\n");
}

void insertarTablero(Nodo** Tablero, ficha ficha)
{
	if (ficha.numA == ultimo)
	{
		insertar(Tablero, ficha);
		ultimo = ficha.numA;
	}
	else if (ficha.numB == ultimo)
	{
		insertar(Tablero, ficha);
		ultimo = ficha.numB;
	}
	else
		printf("Ficha invalida");
}

void mostrarFichas(int x)
{
	int i;
	if (x == 1)
	{
		printf("Jugador 1:\n\n");
		for (i = 0; i < 21; i++)
		{

			if (jugadorUno[i].numA != -1 && jugadorUno[i].numB != -1)
			{
				printf("Ficha %d\n", i);
				printf("|%d|%d|\n\n", jugadorUno[i].numA, jugadorUno[i].numB);
			}
		}	
	}
	if (x == 2)
	{
		printf("Jugador 2:\n\n");
		for (i = 0; i < 21; i++)
		{

			if (jugadorDos[i].numA != -1 && jugadorDos[i].numB != -1)
			{
				printf("Ficha %d\n", i);
				printf("|%d|%d|\n\n", jugadorDos[i].numA, jugadorDos[i].numB);
			}
		}	
	}	
	
}

void repartirFaJuagadores(Nodo** Fichas)
{
	int i;
	for (i = 0; i < 21; i++)
	{
		jugadorUno[i].numA = -1;
		jugadorUno[i].numB = -1;
		jugadorDos[i].numA = -1;
		jugadorDos[i].numB = -1;
	}

	for (i = 0; i < 7; i++)
	{
		jugadorUno[i] = quitar(Fichas);
		jugadorDos[i] = quitar(Fichas);
	}
}

void revolverFichas(Nodo** Fichas)
{
	int i, k = 0, hayFichas = 28;
	int fichaValida[28];
	for (i = 0; i < 28; i++)
		fichaValida[i] = 1;
	while (hayFichas)
	{
		i = rand() % 28;
		if (fichaValida[i])
		{
			insertar(Fichas, fichas[i]);
			fichaValida[i] = 0;
			hayFichas--;
		}
	}
}

void crearFichas()
{
	fichas[0].numA = 0;
	fichas[0].numB = 0;
	fichas[1].numA = 1;
	fichas[1].numB = 0;
	fichas[2].numA = 1;
	fichas[2].numB = 1;
	fichas[3].numA = 2;
	fichas[3].numB = 0;
	fichas[4].numA = 2;
	fichas[4].numB = 1;
	fichas[5].numA = 2;
	fichas[5].numB = 2;
	fichas[6].numA = 3;
	fichas[6].numB = 0;
	fichas[7].numA = 3;
	fichas[7].numB = 1;
	fichas[8].numA = 3;
	fichas[8].numB = 2;
	fichas[9].numA = 3;
	fichas[9].numB = 3;
	fichas[10].numA = 4;
	fichas[10].numB = 0;
	fichas[11].numA = 4;
	fichas[11].numB = 1;
	fichas[12].numA = 4;
	fichas[12].numB = 2;
	fichas[13].numA = 4;
	fichas[13].numB = 3;
	fichas[14].numA = 4;
	fichas[14].numB = 4;
	fichas[15].numA = 5;
	fichas[15].numB = 0;
	fichas[16].numA = 5;
	fichas[16].numB = 1;
	fichas[17].numA = 5;
	fichas[17].numB = 2;
	fichas[18].numA = 5;
	fichas[18].numB = 3;
	fichas[19].numA = 5;
	fichas[19].numB = 4;
	fichas[20].numA = 5;
	fichas[20].numB = 5;
	fichas[21].numA = 6;
	fichas[21].numB = 0;
	fichas[22].numA = 6;
	fichas[22].numB = 1;
	fichas[23].numA = 6;
	fichas[23].numB = 2;
	fichas[24].numA = 6;
	fichas[24].numB = 3;
	fichas[25].numA = 6;
	fichas[25].numB = 4;
	fichas[26].numA = 6;
	fichas[26].numB = 5;
	//fichas[27].numA = 6;
	//fichas[27].numB = 6;
}
