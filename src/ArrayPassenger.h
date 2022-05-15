/*
 * ArrayPassenger.h
 *
 *  Created on: 21 abr. 2022
 *      Author: lucas
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OCUPADO 0
#define LIBRE 1

#define LEN_NAME 51
#define LEN_LNAME 51
#define LEN_FLYCODE 15
#define LEN_PRICE 15

#define PSJ_TYPE_A 3	//PASAJERO VIP
#define PSJ_TYPE_B 2	//PASAJERO BUSINESS
#define PSJ_TYPE_C 1	//PASAJERO LOW COST
#define PSJ_TYPE_D 0	//PASAJERO TRIPULACION

#define VUELO_STATUS_CREADO 1
#define VUELO_STATUS_CANCELADO 0



typedef struct {
	int id;
	char name[LEN_NAME];
	char lastName[LEN_LNAME];
	float price;
	char flycode[LEN_FLYCODE];


	int typePassenger;
	int statusFlight;
	int isEmpty;
}Passenger;


//HACER ABM DE PASAJERO
/*
 * alta
 * baja
 * modificacion
 *
 *
 *
 * */


int Passenger_Inicializar(Passenger *list, int len);
int addPassenger(Passenger *list, int len, int id, char name[], char lastName[],float price, int typePassenger, char flycode[]);
int modifyPassenger(Passenger *list, int id);
void printPassenger(Passenger *list, int length);
int findPassengerById(Passenger* list,int len, int id);
int removePassenger(Passenger *list, int len, int id);
int sortPassengers(Passenger *list, int len, int order);
int sortPassengersByPacha(Passenger* list, int len, int order);
int sortPassengersByPachaDos(Passenger* list, int len, int order);
void printPassengerU(Passenger pasajero);
void calcularPromediosPasajeros(Passenger listPassenger[],int len);

///***\brief Sort the elements in the array of passengers, the argument order
//indicate UP or DOWN order
//**
//* \param list Passenger*
//* \param len int
//* \param order int [1] indicate UP - [0] indicate DOW */
int sortPassengersByCode(Passenger *list, int len, int order);

int Passenger_ObtenerIdUnico();


void printPsgById(Passenger list[], int length, int id);

int Passenger_BuscarLibre(Passenger passengerList[],int tam);

int Passenger_Alta(Passenger passengerList[], int tam);
void printPsgByStatus(Passenger list[], int length, int libre);
int estaVacio(Passenger* list, int len);


#endif /* ARRAYPASSENGER_H_ */
