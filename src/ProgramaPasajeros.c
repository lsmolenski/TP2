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

	int init;
	int *opcionElegida;
	int deseaSalir = 0;
	int opcionElegidaI;
	Passenger listPassenger[MAX_CANT_PSJ];
	init = Passenger_Inicializar(listPassenger, MAX_CANT_PSJ);

	int esVacio;



	strncpy(psjAux.name,"Monica",strlen("Monica"));
	strncpy(psjAux.lastName,"Gutierrez",strlen("Gutierrez"));
	psjAux.id = 4545;
	psjAux.typePassenger = 2;
	psjAux.price = 55434.322;
	strncpy(psjAux.flycode,"AB-001/2",strlen("AB-001/2"));
	psjAux.isEmpty=0;
	psjAux.statusFlight=1;

	Passenger psjAuxDos;
	strncpy(psjAuxDos.name,"Hernan",strlen("Hernan")-1);
	strncpy(psjAuxDos.lastName,"zultz",strlen("Zultz")-1);
	psjAuxDos.id = 4543;
	psjAuxDos.typePassenger = 3;
	psjAuxDos.price = 80559.432;
	strncpy(psjAuxDos.flycode,"AB-024/3",strlen("AB-024/3")-1);
	psjAuxDos.isEmpty=0;
	psjAuxDos.statusFlight=0;

	listPassenger[0]=psjAux;




	//COMIENZA MOSTRANDO EL MENU
	//TODO: POR AHORA ESTA PORCION DE CODIGO ANDA
	int ingresoOpcionOK;
	int idPsjBucado;
	int indexPsjBuscado;
	int buscaOK;
	int buscaBorrarOK;
	do {
		MenuPrincipal();

		ingresoOpcionOK = getPedirInt("Ingrese opcion deseada MP: ", 5, 0, 4, "Ingreso invalido, reintente: ", &opcionElegidaI);

//		&opcionElegidaI = opcionElegida;
		printf("\nOpcion elegida:%d \n", opcionElegidaI);
		switch(opcionElegidaI){
			case 1:
				printf("Opcion elegida 1\n");
				Passenger_Alta(listPassenger,MAX_CANT_PSJ);

				break;
			case 2:
				if (!estaVacio(listPassenger, MAX_CANT_PSJ)){
					printf("*** MODIFICACION PASAJERO ***\n");
					fflush(stdin);
					buscaOK = getInt("Ingrese ID de pasajero: ", &idPsjBucado,MAX_LEN_PSJ_ID);
					printf("** Buscando pasajero %d**", idPsjBucado);
					indexPsjBuscado = findPassengerById(listPassenger,MAX_CANT_PSJ,idPsjBucado);
					printf("\nIndex -> %d",indexPsjBuscado);
					if (indexPsjBuscado >= 0){
						printf("\n** PASAJERO A MODIFICAR **");
						printPassengerU(listPassenger[indexPsjBuscado]);
						modifyPassenger(listPassenger, indexPsjBuscado);
					}
					else{
						printf("El pasajero con ID ingresado (%d) no fue encontrado\n",idPsjBucado);
					}

				}else{
					printf("\nNo hay pasajeros aun.\n");
				}

				break;
			case 3:
				printf("*** BAJA DE PASAJERO ***\n");
				if (!estaVacio(listPassenger, MAX_CANT_PSJ)){
					fflush(stdin);
					buscaBorrarOK = getInt("Ingrese ID de pasajero a Borrar: ", &idPsjBucado,MAX_LEN_PSJ_ID);

					int indexBorrar = findPassengerById(listPassenger, MAX_CANT_PSJ, idPsjBucado);
					if (indexBorrar >= 0){
						int confirmaBorrado;
						printPsgById(listPassenger, MAX_CANT_PSJ, idPsjBucado);
						getPedirInt("Confirma baja de Pasajero\n\t1: CONFIRMA | 0: CANCELA\n\t\t", 1, 0, 1, "Error, reingrese", &confirmaBorrado);
						if (confirmaBorrado == 1){
							indexPsjBuscado = removePassenger(listPassenger, MAX_CANT_PSJ, idPsjBucado);
							if (indexPsjBuscado != -1){
								printf("\n\t** Pasajero %d borrado OK **\n",indexPsjBuscado);
							}
						}
					}
					else{
						printf("El pasajero con ID ingresado (%d) no fue encontrado\n",idPsjBucado);
					}

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


	int opcion;
	getPedirInt("\nOrdenar pasajeros \n\t1: ASCENDENTE | 0: DESCENDENTE\n\t\t", 1, 0, 1, "Error, reingrese", &opcion);


	//ASCENDENTE SI OPCION = 1
//		sortPassengersByPachaDos(listPassenger, MAX_CANT_PSJ, opcion);
		sortPassengersByCode(listPassenger, MAX_CANT_PSJ, opcion);
		printPsgByStatus(listPassenger,MAX_CANT_PSJ,0);






	printf("\t\ntermina\t\n");


	return EXIT_SUCCESS;
};



