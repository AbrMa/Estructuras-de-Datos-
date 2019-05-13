#include "cola.c"
#include <stdio.h>
#include<stdlib.h>
#include <time.h> 
//Inicia el programa
void init();
//Ingresa datos a la tabla de procesos en cola
void ingresarProcesos(COLA* P, COLA* L, COLA* R, int procesos);
//Imprime los procesos que estan en cola
void mostrarProcesos(COLA P, COLA L, COLA R, int procesos);
//Emula los procesos (quantum son los ms que "requiere cada proceso") y tipo es el tipo de emulacion (por pasos(3) o por tiempo(4))
int emular(COLA* P, COLA* L, COLA* R, int quantum, int procesos, int tipo);
//Realiza el tipo de emulacion (por pasos (1) y por tiempo (2)
void instruccion(int tipo);
//Hace el retardo para la emulacion por tiempo
void delay(int number_of_seconds);

int main(){
	//Segundo main xd
	init();
}

void init(){
	//Crea 3 colas porque cuando dijo que era con estructuras ya llevaba media practica xdxd
	COLA P, L, R;
	CrearCola(&P); //Nombre de proceso
	CrearCola(&L); //Tiempo de llegada
	CrearCola(&R); //Tiempo requerido
	//Para el quantum random
	srand(time(NULL));
	//Quantum entre 3 y 5 ms
	int quantum = rand() % 3 + 3;
	//Opcion y # de procesos
	int op, procesos=0;
	//Bucle de menu
	char continuar = 'n';
	while(continuar == 'n'){
		system("clear");
		printf("1.Cantidad de procesos\n2.Mostrar tabla de procesos\n3.Emular paso a paso\n4.Emular completo\n");
		fflush(stdin);
		scanf("%d", &op);
		
		switch(op){
			case 1: //Ingresar cantidad de procesos a realizar
				fflush(stdin);
				system("clear");
				printf("Ingrese la cantidad de procesos:\n");
				scanf("%d",&procesos);
				ingresarProcesos(&P, &L, &R, procesos);
				break;
			
			case 2: //Mostrar todos los procesos (sin emular)
				system("clear");
				if(procesos == 0)
					printf("No hay procesos en cola\n");
				else
					mostrarProcesos(P, L, R, procesos);
					
				printf("Desea salir del programa?(s/n)\n");
				fflush(stdin);
				scanf(" %c", &continuar);
				break;
			
			case 3: //Emula por pasos (emulacion tipo 1)
				if(procesos == 0)
					printf("No hay procesos en cola\n");
				
				else
					procesos = emular(&P, &L, &R, quantum, procesos, 1);
				
				printf("Desea salir del programa?(s/n)\n");
				fflush(stdin);
				scanf(" %c", &continuar);
				break;
			
			case 4: //Emula por tiempos (emulacion tipo 2)
				if(procesos == 0)
					printf("No hay procesos en cola\n");
				
				else
					procesos = emular(&P, &L, &R, quantum, procesos, 2);
				
				printf("Desea salir del programa?(s/n)\n");
				fflush(stdin);
				scanf(" %c", &continuar);
				break;
		}		
	}
}

void ingresarProcesos(COLA* P, COLA* L, COLA* R, int procesos){
	int i;
	int id = 65;
	int ms;
	srand(time(NULL));
	for(i=0; i<procesos; i++){
		//Los ms que requiere cada proceso son random entre 1 y 20
		ms = rand () % 20 + 1;
		
		InsertarCola(P, id);
		id++;
		
		InsertarCola(L, i);
		
		InsertarCola(R, ms);
	}
}

void mostrarProcesos(COLA P, COLA L, COLA R, int procesos){
	int i;
		printf("PROCESO		TIEMPO DE LLEGADA		REQUERIMIENTO CPU\n");
	for(i=0; i<procesos; i++){
		printf("%c		|%d				|%d\n", (char)QuitarCola(&P), QuitarCola(&L), QuitarCola(&R));
	}
}

int emular(COLA* P, COLA* L, COLA* R, int quantum, int procesos, int tipo){
	int nombre, proceso, ms;
	while(!ColaVacia(*P)){
		system("clear");
		printf("\n--------------------------------\n");
		mostrarProcesos(*P,*L,*R, procesos);
		
		nombre = QuitarCola(P);
		proceso = QuitarCola(L);
		ms = QuitarCola(R);		
		ms = ms - quantum;
		
		if(ms<=0){
			ms = 0;
			procesos --;
			printf("--------------------------------\nFin proceso %c\n\n", (char)nombre);
		}else{
			InsertarCola(P, nombre);
			InsertarCola(L, proceso);
			InsertarCola(R, ms);
		}
		
		instruccion(tipo);
	}
	//Retorna los procesos para que se "destruyan"
	return procesos;
}

void instruccion(int tipo){
	switch(tipo){
		case 1: //Simulacion por pasos: Espera a que el usuario presione una tecla para continuar
			system("pause");
			break;
		
		case 2: //Simulacion por tiempo: Emula cada 3 segundos
			delay(30);
			break;
	}
}

void delay(int segs){ 
    int ms = 1000 * segs; 
  	//momento de inicio
    clock_t inicio = clock(); 
	//bucle de retardo
    while (clock() < inicio + ms); 
} 
