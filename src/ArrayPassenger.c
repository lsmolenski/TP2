/*
 * ArrayPassenger.c
 *
 *  Created on: 21 abr. 2022
 *      Author: lucas
 */

#include "ArrayPassenger.h"
#include "PedirDatos.h"
#include <stdlib.h>
#include <stdio.h>
//#define OCUPADO 0
//#define LIBRE 1


static int idPassengerAuto = 1100;



int Passenger_Inicializar(Passenger *list, int tam){
	int retorno = 0;
	int i;
	if (list != NULL ){
//		printf("\nentra bien a inicializar el array de pasajeros");
		if (tam > 0 ){
			for ( i= 0;i < tam;i++){
				list[i].isEmpty = LIBRE;
			}
		retorno = 1;
		}
	}
	else{
		printf("Array de pasajeros null\n");
	}
	return retorno;
}


/*	IMPRIME PASAJEROS DE ACUERDO AL ESTADO RECIDIBOD:
 * 	1 - imprime pasajeros inactivos (OCUPADO = 0 | isEmpty)
 * 	2 - imprime pasajeros activos (OCUPADO = 1 | isEmpty)*/
void printPsgById(Passenger list[], int length, int id){
	Passenger psjrAux;
	int i;

	if (list != NULL && length > 0){
//		psjrAux = *psjrLista;

		for (i = 0; i<=length; i++){
			if (list[i].id == id){
				printPassengerU(list[i]);
			}
				fflush(stdout);
		}
	}
}

/*	IMPRIME PASAJEROS DE ACUERDO AL ESTADO RECIDIBOD:
 * 	1 - imprime pasajeros inactivos (OCUPADO = 0 | isEmpty)
 * 	2 - imprime pasajeros activos (OCUPADO = 1 | isEmpty)*/
void printPsgByStatus(Passenger list[], int length, int id){
	Passenger psjrAux;
	int i;

	if (list != NULL && length > 0){
//		psjrAux = *psjrLista;

		for (i = 0; i<=length; i++){
			if (list[i].isEmpty == id){
				printPassengerU(list[i]);
			}
				fflush(stdout);
		}
	}
}


void printPassengerU(Passenger pasajero){

	printf("\nPasajero n° %d\n", pasajero.id);
	printf("Nombre y apellido: %s %s \n",pasajero.lastName,pasajero.name);
//	fflush(stdout);
	printf("Código de vuelo: %s | Precio: $%.2f\n",pasajero.flycode,pasajero.price);


	switch (pasajero.typePassenger){
		case PSJ_TYPE_A:
			printf("Tipo pasajero: %s\n","VIP");
			break;
		case PSJ_TYPE_B:
			printf("Tipo pasajero: %s\n", "BUSSINESS");
			break;
		case PSJ_TYPE_C:
			printf("Tipo pasajero: %s\n", "LOW COST");
			break;
		case PSJ_TYPE_D:
			printf("Tipo pasajero: %s\n", "TRIPULACION");
			break;
	}

	switch (pasajero.statusFlight){
		case VUELO_STATUS_CREADO:
			printf("VUELO: %s\n","CREADO");
			break;
		case VUELO_STATUS_CANCELADO:
			printf("Tipo pasajero: %s\n", "CANCELADO");
			break;
		}


	printf("**********************************************\n");
	fflush(stdout);

}

// devuelve -1
//devuelve 0 si esta llena la lista y no pudo ser insertado el pasajero
//devuelve 1 si pudo darlo de alta e insertar en la lista de pasajeros
int Passenger_Alta(Passenger passengerList[], int tam){
	int indexLibre = -1;
	int rtn;
	int idPsj;

	char namePsj[LEN_NAME];
	char lNamePsj[LEN_LNAME];
	char flyCode[LEN_LNAME];
	float price;

	fflush(stdin);
	if (passengerList != NULL && tam > 0 ){
		indexLibre = Passenger_BuscarLibre(passengerList, tam);

		//hay lugar para meter en la Lista
		if (indexLibre > -1){
			idPsj = Passenger_ObtenerIdUnico();

			int pideNameOK = getPedirStringSoloLetras("Ingrese nombre(s) pasajero: ", 5, "Ingreso inválido, reintente", namePsj, LEN_LNAME);
			int pideApelOK = getPedirStringSoloLetras("Ingrese apellido(s) pasajero: ", 5, "Ingreso inválido, reintente", lNamePsj, LEN_LNAME);

			getPedirString("Ingrese codigo de vuelo: ", 5, "Ingreso inválido, reintente", flyCode, LEN_FLYCODE);

			int pidePriceOK = getFloatFromS("Ingrese precio de vuelo: $", 5, "Ingreso invalido, reintente: ",&price, LEN_PRICE);
			int tipoPasajero;
			int pideTipoPsj = getPedirInt("Ingrese tipo pasajero \n\t3: VIP | 2: BUSINESS | 1: LOW COST | 0: TRIPULACION\n",
							5, 0, 3, "Opcion Invalida, ingrese nuevamente: \n", &tipoPasajero);


			int psjAddOk = addPassenger( passengerList, tam, idPsj, namePsj, lNamePsj, price, tipoPasajero, flyCode);
		}else{
			//no hay lugar en el vector para meter mas pasajeros
			rtn = 0;
			printf("\n Error \n");
		}

//		}
	}
	return 0;
}



/* RETORNA 1 SI PUDO AGREGAR EL PASAJERO
		-1 SI ALGUN ELEMENTO ES NULO O ERRONEO
*/
int addPassenger(Passenger *list, int len, int id, char name[], char lastName[],float price, int typePassenger, char flycode[]){
	//10 - may : PARECE QUE ANDA PIOLA
	Passenger psjNuevo;

	int rtn;
	int indexLibre;

	if (list != NULL) {
		if (name != NULL && lastName != NULL && flycode != NULL) {
			if (len > 0 && price != 0) {
				indexLibre = Passenger_BuscarLibre(list, len);
				printf("\ncasillero libre: %d\n",indexLibre);

				psjNuevo.isEmpty = OCUPADO;
				psjNuevo.id = id;


				psjNuevo.price = price;
				strncpy(psjNuevo.name, name, strlen(name)+1);
				strncpy(psjNuevo.lastName, lastName, strlen(lastName)+1);
				strncpy(psjNuevo.flycode, flycode, strlen(flycode)+1);
				psjNuevo.typePassenger = typePassenger;
				psjNuevo.statusFlight = VUELO_STATUS_CREADO;

				list[indexLibre] = psjNuevo;

			}
		}
		 else{
			 printf("\nsigue 5bis else1");
			 rtn = -1;
		 }
	}
	 else{
		 printf("\nsigue 6bis else2");
		 rtn = -1;
	 }

	return 1;


}

int modifyPassenger(Passenger *list, int id) {
	fflush(stdin);
//	fflush(stdout);
	Passenger psjNuevo;

	int rtn = -1;
	int opcionIngresada;

	Passenger auxPsj;

	if (list != NULL) {

		getPedirInt("\n\t1.NOMBRE | 2.APELLIDO | 3.PRECIO | 4.TIPO PASAJERO | 5.CODIGO VUELO \n: ", 5, 1, 5, "Ingreso invalido, reintente: ", &opcionIngresada);

		switch(opcionIngresada){
			case 1:
				fflush(stdin);
				getPedirStringSoloLetras("Ingrese nombre(s) pasajero: ", 5, "Ingreso inválido, reintente", list[id].name, LEN_LNAME);
				break;
			case 2:
				fflush(stdin);
				getPedirStringSoloLetras("Ingrese apellido(s) pasajero: ", 5, "Ingreso inválido, reintente", list[id].lastName, LEN_LNAME);
				break;
			case 3:
				fflush(stdin);
				getFloatFromS("Ingrese precio de vuelo: $", 5, "Ingreso invalido, reintente: ",&(list[id].price), LEN_PRICE);
				break;
			case 4:
				fflush(stdin);
				getPedirInt("Ingrese tipo pasajero \n\t3: VIP | 2: BUSINESS | 1: LOW COST | 0: TRIPULACION\n",5, 0, 3, "Opcion Invalida, ingrese nuevamente: \n", &(list[id].typePassenger));
				break;
			case 5:
				fflush(stdin);
				getPedirString("Ingrese codigo de vuelo: ", 5, "Ingreso inválido, reintente", list[id].flycode, LEN_FLYCODE);
				break;
		}

	}

	return 1;

}



int Passenger_BuscarLibre(Passenger passengerList[], int tam){
	int existeLibre = 0;
	int rtn = 0;
	int indexLibre;


	if (passengerList != NULL && tam > 0 ){
		for (int i = 0; i  < tam ; i++){
			if (passengerList[i].isEmpty == LIBRE ){
					rtn = i;
					existeLibre = 1;
					break;
			}
		}
		//devuelve -1 si no se encontró un lugar libre
		if (existeLibre == 0) {
				rtn = -1;
			}
	}
	return rtn;
}


int Passenger_ObtenerIdUnico(){
	return idPassengerAuto++;
}



int removePassenger(Passenger *list, int len, int idABorrar) {
	int indexPsjABorrar = -1;
	if (list != NULL && len > 0 && idABorrar != 0) {
		indexPsjABorrar = findPassengerById(list, len, idABorrar);
		if (indexPsjABorrar != -1) {
			list[indexPsjABorrar].isEmpty = LIBRE;
		}

	}
	return indexPsjABorrar;
}

int estaVacio(Passenger* list, int len){
	int estaVacio = 1; //NO ESTA VACIO
	if (list != NULL && len > 0){
		for (int i = 0; i < len;i++){
			if ( list[i].isEmpty == OCUPADO){
				//SI AL MENOS ENCUENTRO UN ELEMENTO COMO OCUPADO, NO ESTA VACIO
				estaVacio = 0;
				break;
			}
		}
	}
	return estaVacio;
}


/*	RECIBE UNA LISTA DE PASAJEROS, SU LARGO Y UN ID DE PASAJERO,
 * 		DEVUELVE -1 SI EL PASAJERO NO EXISTE EN LA LISTA O SINO EL INDICE DEL PASAJERO EN LA LISTA 	*/
int findPassengerById(Passenger* list, int len, int idBuscado){
	int passengerIndex = -1;
	if (list != NULL && len > 0 && idBuscado != 0){
			for (int i = 0; i < len; i++ ){
				if (list[i].id == idBuscado){
//					printf("Pasajero ID: %d , posicion: %d\n",list[i].id, i );
					passengerIndex = i;
					break;
				}
				
			}
		}
		return passengerIndex;

}

//int sortPassengers(Passenger* list, int len, int order);
int sortPassengersByCode(Passenger *list, int len, int order) {
	int rtn=-1;
	Passenger auxPasajero;

	if(list!=NULL)
	{
		for(int i=0;i<len;i++)
		{
			for(int i=0;i<len-1;i++)
			{
//				for(int j=i+1;j<len;j++)
//				//ASCENDENTE
				if(order ==1){
					if(strcmpi(list[i].flycode, list[i+1].flycode)>0)
					{
						auxPasajero=list[i];
						list[i]=list[i+1];
						list[i+1]=auxPasajero;
					}
					else if(strcmpi(list[i].flycode, list[i+1].flycode)==0 && list[i].statusFlight > list[i+1].statusFlight )
					{
						auxPasajero=list[i];
						list[i]=list[i+1];
						list[i+1]=auxPasajero;
					}

				}//DESCENDENTE
				else{

					if(strcmpi(list[i].flycode, list[i+1].flycode) < 0 )
					{
						auxPasajero=list[i];
						list[i]=list[i+1];
						list[i+1]=auxPasajero;
					}
					else if(strcmpi(list[i].flycode, list[i+1].flycode)==0 && list[i].statusFlight < list[i+1].statusFlight)
					{
						auxPasajero=list[i];
						list[i]=list[i+1];
						list[i+1]=auxPasajero;
					}
				}
//				}
			}
		}
		rtn = 0;
	}
	else{
		printf("\nOrdenamiento interrumpido\n");
	}


	return rtn;
}


//SI ORDER == 1 -> UP
//SI ORDER == 0 -> DOWN
int sortPassengersByPacha(Passenger* list, int len, int order){
	int rtn=-1;
	Passenger auxPasajero;

	if(list!=NULL)
	{
		for(int i=0;i<len;i++)
		{
			for(int i=0;i<len-1;i++)
			{
//				for(int j=i+1;j<len;j++)
//				{
					if(strcmp(list[i].lastName, list[i+1].lastName)>0 && order==1)
					{
						auxPasajero=list[i];
						list[i]=list[i+1];
						list[i+1]=auxPasajero;
					}
					else if(strcmp(list[i].lastName, list[i+1].lastName)==0 && list[i].typePassenger > list[i+1].typePassenger && order==1)
					{
						auxPasajero=list[i];
						list[i]=list[i+1];
						list[i+1]=auxPasajero;
					}
					if(strcmp(list[i].lastName, list[i+1].lastName)<0 && order==0)
					{
						auxPasajero=list[i];
						list[i]=list[i+1];
						list[i+1]=auxPasajero;
					}
					else if(strcmp(list[i].lastName, list[i+1].lastName)==0 && list[i].typePassenger < list[i+1].typePassenger && order==0)
					{
						auxPasajero=list[i];
						list[i]=list[i+1];
						list[i+1]=auxPasajero;
					}
//				}
			}
		}
		rtn = 0;
	}
	else{
		printf("\nOrdenamiento interrumpido\n");
	}


	return rtn;
}


int sortPassengersByPachaDos(Passenger* list, int len, int order){
	int rtn=-1;
	Passenger auxPasajero;

	if(list!=NULL)
	{
		for(int i=0;i<len;i++)
		{
			for(int i=0;i<len-1;i++)
			{
//				for(int j=i+1;j<len;j++)
//				//ASCENDENTE
				if(order ==1){
					if(strcmpi(list[i].lastName, list[i+1].lastName)>0 )
					{
						auxPasajero=list[i];
						list[i]=list[i+1];
						list[i+1]=auxPasajero;
					}
					else if(strcmpi(list[i].lastName, list[i+1].lastName)==0 && list[i].typePassenger > list[i+1].typePassenger )
					{
						auxPasajero=list[i];
						list[i]=list[i+1];
						list[i+1]=auxPasajero;
					}

				}//DESCENDENTE
				else{

					if(strcmpi(list[i].lastName, list[i+1].lastName) < 0 )
					{
						auxPasajero=list[i];
						list[i]=list[i+1];
						list[i+1]=auxPasajero;
					}
					else if(strcmpi(list[i].lastName, list[i+1].lastName)==0 && list[i].typePassenger < list[i+1].typePassenger)
					{
						auxPasajero=list[i];
						list[i]=list[i+1];
						list[i+1]=auxPasajero;
					}
				}
//				}
			}
		}
		rtn = 0;
	}
	else{
		printf("\nOrdenamiento interrumpido\n");
	}


	return rtn;
}
void calcularPromediosPasajeros(Passenger listPassenger[],int len){
	float precioPromedio;
	float totalVentas = 0;
	int cantidadTotalVuelosActivos = 0;
	int cantidadPorEncimaDelPromedio = 0;


	if (listPassenger != NULL && len > 0){
		for (int i =0; i < len; i++){
			if(listPassenger[i].isEmpty == OCUPADO){
				cantidadTotalVuelosActivos++;
				totalVentas = totalVentas + listPassenger[i].price;
			}
		}
		precioPromedio = totalVentas/cantidadTotalVuelosActivos;
		printf("\nTotal precio vuelos $%.2f\n",totalVentas);
		printf("Promedio precio de vuelos: $%.2f\n",precioPromedio);
		for (int i = 0; i < len; i++) {
			if (listPassenger[i].isEmpty == OCUPADO && listPassenger[i].price > precioPromedio) {
				cantidadPorEncimaDelPromedio++;

			}
		}
		printf("\nVuelos que superan el precio promedio ($%.2f): %d\n",precioPromedio,cantidadPorEncimaDelPromedio);


	}

}

