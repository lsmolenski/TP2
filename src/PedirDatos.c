/*
 * PedirDatos.c
 *
 *  Created on: 5 abr. 2022
 *      Author: lucas
 */

#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "PedirDatos.h"
#include "ValidarDatos.h"

#define LEN_OPCION 2
#define LEN_PRECIO 15

/*	07-05 NUEVA VERSION	*/
int myGetsD(char *cadena, int longitud) {
	fflush(stdin);
	int retorno = -1;
	char cadenaAux[longitud];

	if (cadena != NULL && longitud > 0) {
		if (fgets(cadenaAux, longitud, stdin) != NULL) {
			cadenaAux[strlen(cadenaAux) - 1] = '\0';
			strncpy(cadena, cadenaAux, longitud);
			retorno = 0;
		} else {
			retorno = -1;
		}
	}
	return retorno;
}
;

/*	26-04 NUEVA VERSION	*/
int myGets(char *cadena, int longitud) {
	int retorno = -1;
//	char cadenaAux[longitud];
	if (cadena != NULL && longitud > 0) {
		if (fgets(cadena, longitud, stdin) != NULL) {
			cadena[strlen(cadena) - 1] = '\0';
			retorno = 0;
		}
	}
	return retorno;
}
;

int getPedirString(char mensaje[], int reintentos, char mensajeError[], char *pmensajeIngresado, int largoIngreso) {
	//10 -MAY PARECE QUE ANDA BIEN
	int retorno = -1;

	int getStrOK;
	int esDigito = 0;

	//validar que todos los parametros recibidos sean algo razonable
	if (mensaje != NULL
			&& reintentos
					> 0&& mensajeError != NULL && pmensajeIngresado != NULL) {

		do {
			printf("%s", mensaje);

			getStrOK = myGetsD(pmensajeIngresado, largoIngreso);
			if (getStrOK != 0) {
				printf("%s\n", mensajeError);
				reintentos--;
			} else {
				reintentos = 0;
				retorno = 0;
			}
		} while (reintentos > 0);
	}
	return retorno;
}

/* DEVUELVE 0 SI LO INGRESADO ES SÓLO UNA CADENA DE CARACTERES */

int getPedirStringSoloLetras(char mensaje[], int reintentos, char mensajeError[], char *pmensajeIngresado, int largoIngreso) {
	int retorno = -1;
	int getStrOK;

	//validar que todos los parametros recibidos sean algo razonable
	if (mensaje != NULL && reintentos> 0&& mensajeError != NULL && pmensajeIngresado != NULL) {

		do {
			printf("%s", mensaje);
			fflush(stdin);
			getStrOK = myGetsD(pmensajeIngresado, largoIngreso);
			//evaluo si el caracter ingresado es Digito o es Letra
			if (getStrOK != 0 || getIsString(pmensajeIngresado) != 0) {
				printf("%s\n", mensajeError);
				reintentos--;
			} else {
				reintentos = 0;
				retorno = 0;
			}

		} while (reintentos > 0);
	}
	return retorno;
}

/*	Pregunta Ingreso al usuario y completa la opcion ingresada en pNumeroIngresado (FLOAT) */
int getFloatFromS(char mensaje[], int reintentos, char mensajeError[],
		float *pNumeroIngresado, int largoIngreso) {
	int retorno = 0;
	int ingresoOk = -1;

	float nroIngresoAux;
	char ingreso[largoIngreso];

	if (mensaje != NULL && reintentos > 0&& mensajeError != NULL && pNumeroIngresado != NULL) {
		printf("%s", mensaje);
//		fflush(stdout);

		do {
			if (ingresoOk == -1) {
				myGets(ingreso, largoIngreso);
				int n = getFinalFloat(ingreso, &nroIngresoAux);

				if (n != 0) {
					reintentos--;
//					printf("%s", mensajeError);
				}

				else {
					reintentos = 0;

					*pNumeroIngresado = nroIngresoAux;
					ingresoOk = 0;
					retorno = 1;
				}
			}
		} while (reintentos > 0);
	}

	return retorno;
}

int getFinalFloat(char arrayPosiblesNumeros[], float *floatFinal) {
	int retorno = -1;
	float auxFloat;
	int replace;

	if (arrayPosiblesNumeros != NULL && floatFinal != NULL) {

		if (esNumericaConSignos(arrayPosiblesNumeros) == 0) {

			//reemplazo si es que hay , por . para poder transformar
			replace = replaceCommaDot(arrayPosiblesNumeros);

			if (replace == 0) {
				//transformo a float y asigno la variable
				auxFloat = strtof(arrayPosiblesNumeros, NULL);

				retorno = 0;
				*floatFinal = auxFloat;
				fflush(stdout);
			}

		}
		return retorno;
	}
}

	/*	Pregunta Ingreso al usuario y completa la opcion ingresada en pNumeroIngresado (int) */
//TODO: OK 14-may ANDA
	int getPedirInt(char mensaje[], int reintentos, int minimo, int maximo,
			char mensajeError[], int *pNumeroIngresado) {
		fflush(stdin);
		int retorno = 0;
		int ingresoOk = -1;
		int nroIngresadoInt;
		char ingreso[LEN_OPCION];

		if (mensaje != NULL
				&& reintentos
						> 0&& minimo < maximo && mensajeError != NULL && pNumeroIngresado != NULL) {
			printf("%s", mensaje);

			do {
				fgets(ingreso, LEN_OPCION, stdin);
				if (esNumeroEntero(ingreso) == 0) {
					nroIngresadoInt = (int) strtol(ingreso, NULL, 10);
					if ((nroIngresadoInt > maximo || nroIngresadoInt < minimo)) {
						printf("%s", mensajeError);
						fflush(stdin);
						reintentos--;
					} else {
						reintentos = 0;
//					pNumeroIngresado = &nroIngresadoInt;
						*pNumeroIngresado = nroIngresadoInt;
						retorno = 1;
					}
				} else {
					reintentos--;
					printf("%s", mensajeError);
				}
			} while (reintentos > 0);
		}

		return retorno;
	}

	/*	Pregunta Ingreso al usuario y completa la opcion ingresada en pNumeroIngresado (int)
	 *
	 *
	 * 		*/
//TODO: NUEVA: SOLO PIDE NUMERO
	int getInt(char mensaje[], int *pNumeroIngresado, int largoNum) {
		int retorno = 0;
		int ingresoOk = -1;
		int nroIngresadoInt;
		char ingreso[largoNum];
		if (mensaje != NULL && pNumeroIngresado != NULL) {
			printf("%s", mensaje);

			fflush(stdin);
			do {
				myGets(ingreso, largoNum);
//			fgets(ingreso, largoNum, stdin);
				ingresoOk = esNumeroEntero(ingreso);
				if (ingresoOk == 0) {
					nroIngresadoInt = (int) strtol(ingreso, NULL, 10);
					*pNumeroIngresado = nroIngresadoInt;
				} else {
					printf("%s",
							"Algun caracter ingresado es inválido, reintente\n");
				}
			} while (ingresoOk != 0);
		}

		return retorno;
	}
	;

