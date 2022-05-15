/*
 * PedirDatos.h
 *
 *  Created on: 5 abr. 2022
 *      Author: lucas
 */

#ifndef LIBRERIA1_H_
#define LIBRERIA1_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayPassenger.h"




void imprimir();
int getPedirInt(char mensaje[], int reintentos, int minimo, int maximo, char mensajeError[],int *pNumeroIngresado);
int getFloat(char mensaje[], int reintentos, int minimo, int maximo, char mensajeError[],float *pNumeroIngresado);
int getChars(char mensaje[], int reintentos, char mensajeError[],char *pOpcionIngresada);
int getPedirStringSoloLetras(char mensaje[], int reintentos, char mensajeError[],char *pmensajeIngresado, int largoIngreso);
int validarIngresoCaracter(char *);
int myGets(char *cadena, int longitud);
int pedirDatosPasajero(Passenger *psj, int idPasajero);
int myGetsD(char *cadena, int longitud);

// DEVUELVE EL NUMERO FLOTANTE REAL FINAL SIN DISTINGUIR ENTRE . O ,
int getFinalFloat(char arrayPosiblesNumeros[], float *floatFinal);
// DEVUELVE EL NUMERO INT
int getIntByString(char arrayPosiblesNumeros[], int *intFinal);
int getFloatFromS(char mensaje[], int reintentos, char mensajeError[], float *pNumeroIngresado, int largoIngreso);
int getInt(char mensaje[], int *pNumeroIngresado, int largoNum);
#endif /* LIBRERIA1_H_ */
