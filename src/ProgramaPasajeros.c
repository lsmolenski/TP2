/*
 ============================================================================
 Name        : TP2.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "ArrayPassenger.h"
#include "ValidarDatos.h"
#include "PedirDatos.h"

#define MAX_CANT_PSJ 4
#define MAX_LEN_PSJ_ID 10


int ProgramaPasajeros(void) {
	setbuf(stdout, NULL);


	/* inicializacion de datos	*/
	Passenger psjAux;


	int *opcionElegida;
	int deseaSalir = 0;
	int opcionElegidaI;
	Passenger listPassenger[MAX_CANT_PSJ];

	int esVacio;


	int ingresoOpcionOK;
	int idPsjBucado;
	int indexPsjBuscado;
	int buscaOK;
	int buscaBorrarOK;

	Passenger_Inicializar(listPassenger, MAX_CANT_PSJ);
	//COMIENZA MOSTRANDO EL MENU
	do {
		MenuPrincipal();

		ingresoOpcionOK = getPedirInt("Ingrese opcion deseada: ", 5, 0, 4, "Ingreso invalido, reintente: ", &opcionElegidaI);

		switch(opcionElegidaI){
			case 1:
				printf("\n*** ALTA PASAJERO ***\n");
				Passenger_Alta(listPassenger,MAX_CANT_PSJ);

				break;
			case 2:
				if (!estaVacio(listPassenger, MAX_CANT_PSJ)){
					printf("*** MODIFICACION PASAJERO ***\n");
					fflush(stdin);
					Passenger_Modificacion(listPassenger,MAX_CANT_PSJ);
				}else{
					printf("\nNo hay pasajeros aun.\n");
				}
				break;
			case 3:
				if (!estaVacio(listPassenger, MAX_CANT_PSJ)){
					printf("*** BAJA DE PASAJERO ***\n");
					Passenger_Baja(listPassenger, MAX_CANT_PSJ);

				}else{
					printf("\nNo hay pasajeros aun.\n");
				}
				break;
			case 4:
				printf("Opcion elegida 4\n");

				if (!estaVacio(listPassenger, MAX_CANT_PSJ)){
					int ordenaOK;
					int opcionElegida;
					getPedirInt("Ingrese opcion deseada\n 1. Listado ordenado por Apellido y Tipo de pasajero\n 2. Total y promedios de viajes\n 3. Listado ordenado por codigo de vuelo y estado Activo ", 5, 1, 3, "Ingreso invalido, reintente: ", &opcionElegida);
					switch(opcionElegida){
						case 1:
							ordenaOK = sortPassengersByPachaDos(listPassenger, MAX_CANT_PSJ, 1);
							if (ordenaOK == 0){
								printPsgByStatus(listPassenger,MAX_CANT_PSJ,0);
							}
							break;
						case 2:
							calcularPromediosPasajeros(listPassenger,MAX_CANT_PSJ);
							break;
						case 3:
							ordenaOK = sortPassengersByCode(listPassenger, MAX_CANT_PSJ, 1);
							if (ordenaOK == 0){
								printPsgByStatus(listPassenger,MAX_CANT_PSJ,OCUPADO);
							}
							break;
					}
				}else {
					printf("\nNo hay pasajeros aun.\n");
				}


				break;
			case 0:
				deseaSalir = 1;
				break;
		}
		fflush(stdin);

	}while(ingresoOpcionOK ==0 || deseaSalir != 1);
/***********************************************************************/
	return EXIT_SUCCESS;
};



