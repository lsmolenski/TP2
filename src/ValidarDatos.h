/*
 * ValidarDatos.h
 *
 *  Created on: 21 abr. 2022
 *      Author: lucas
 */

#ifndef VALIDARDATOS_H_
#define VALIDARDATOS_H_





#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int esNumeroEntero(char arrayPosiblesNumeros[]);
int esNumericaB(char arrayPosiblesNumeros[]);

int esNumeroNegativo(char arrayPosiblesNumeros[]);



//REEMPLAZA EN EL STRING RECIBIDO, LAS COMAS POR PUNTOS PARA SER TRANSFORMADO A FLOAT
int replaceCommaDot(char arrayPosiblesNumeros[]);

//valida que el string pasado por parametro sea correcto para ser transformado a numero flotante
int esNumericaConSignos(char arrayPosiblesNumeros[]);



// DEVUELVE 0 SI EL NOMBRE INGRESADO ES CORRECTO
/*	valida que no puedan ingresarse caracteres especiales salvo que sean:
 * 	á,é,í,ó,ú,Á,É,Í,Ó,Ú,n,Ñ o espacios	*/
int getIsString(char cadena[]);
int compararCaracterValido(char caracValidos[], char caracter);



#endif /* VALIDARDATOS_H_ */
