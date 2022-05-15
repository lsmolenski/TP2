/*
 * ValidarDatos.c
 *
 *  Created on: 21 abr. 2022
 *      Author: lucas
 */

#include "ValidarDatos.h"


static char caracEspeciales[] = "áéíóúÁÉÍÓÚÑñ \0";






int esNumeroEntero(char arrayPosiblesNumeros[]) {
	int retorno = 0; //optimista
	int i = 0;

	if (arrayPosiblesNumeros != NULL) {
		while (arrayPosiblesNumeros[i] != '\0'){
			if (arrayPosiblesNumeros[i] > '9' || arrayPosiblesNumeros[i] < '0') {
				retorno = -1;
				break;
			}
			i++;
		}
	}
	return retorno;
};

/*	Reemplaza las comas por puntos en arrayNumeros para admitir ambos formatos de decimal*/
int replaceCommaDot(char arrayNumeros[]){
	int retorno = -1;
	int i = 0;
	if (arrayNumeros != NULL){
		while (arrayNumeros[i] != '\0'){
			if (arrayNumeros[i]== ','){
				arrayNumeros[i] = '.';
			}
			i++;
		}
		retorno = 0;
	}
	return retorno;
}

int esNumeroNegativo(char arrayPosiblesNumeros[]){
	int retorno = -1;

	if (arrayPosiblesNumeros != NULL && esNumericaConSignos(arrayPosiblesNumeros)==0 ){
		if (arrayPosiblesNumeros[0] == '-'){
			retorno = 0;
		}
	}
	return retorno;
}

/*	Valida si un vector de strings ingresado tiene:
 * 	- el caracter ingresado debe ser numerico
	 * 	- no puede tener mas de 1 coma
	 * 	- no puede tener mas de 1 punto
	 * 	- no puede tener ambos (coma y punto) a la vez
	 * 	- no puede tener espacios
 * 		*/
int esNumericaConSignos(char arrayPosiblesNumeros[]) {
//	printf("entra en numerica con signos %s* ", arrayPosiblesNumeros);
	int retorno = 0; //optimista
	int cantComas = 0;
	int cantPuntos = 0;
	int cantSignoMenos = 0;

	//Variables para identificar si hay una coma y un punto ingresados al mismo tiempo
	int usaComa=0;
	int usaPunto=0;
	int i = 0;

	if (arrayPosiblesNumeros != NULL) {
//		cantCaracteres = strlen(arrayPosiblesNumeros);

		while (arrayPosiblesNumeros[i] != '\0'  ){
			if ( (arrayPosiblesNumeros[i] > '9' || arrayPosiblesNumeros[i] < '0')) {
				//Chequeo que ademas no sea un valor valido: coma, guion o punto
				if ( arrayPosiblesNumeros[i] != '-' && arrayPosiblesNumeros[i] != ',' && arrayPosiblesNumeros[i] != '.'){
					retorno = -1;
					break;
				}
				else {
					switch (arrayPosiblesNumeros[i]) {
						case '-':
							cantSignoMenos++;
							break;
						case ',':
							usaComa = 1;
							cantComas++;
							break;
						case '.':
							usaPunto = 1;
							cantPuntos++;
							break;
					}
				}
			}
			//Pregunto si tiene mas de un signo coma o punto y ademas que no tenga ambos
				if ( (cantSignoMenos > 1 || cantComas > 1 || cantPuntos > 1)  || (usaPunto && usaComa) ) {
					retorno = -1;
					break;
				}
				i++;
			}
	}

	return retorno;
};






/* VERIICA SI LA CADENA INGRESADA TIENE SOLO CARACTERES O CARACTERES VALIDOS CONFIGURADOS */
int getIsString(char cadena[]) {
	int retorno = 0;
	int i = 0;
	//DEFINICION CARACTERES ESPECIALES VALIDOS
	char caracValidos[] = "áéíóúÁÉÍÓÚÑñ \0";

	if (cadena != NULL) {
		while (cadena[i]!= '\0' ){
			if (!(cadena[i] >= 65 && cadena[i] <= 90)
					&& !(cadena[i] >= 97 && cadena[i] <= 122)
					&& !(compararCaracterValido(caracEspeciales, cadena[i])==0) ){
				retorno = -1;
				break;
			}
			i++;
		};

		}
	return retorno;
};


/*	Recibe un vector de caracteresValidos, y evalua si el caracter recibido esta contenido en dicho vector de elementos	*/
/*	COMPARA caracter CON TODOS LOS ELEMENTOS DE LA CADENA caracValidos Y DEVUELVE UN 0 SI EXISTE DENTRO DE LA MISMA	*/
int compararCaracterValido(char caracValidos[], char caracter){
	int i= 0;
	int retorno = -1;

	if (caracValidos != NULL){
		while (caracValidos[i] != '\0'){
			if (caracValidos[i] == caracter){
				retorno = 0;
			}
			i++;
		}
	}
	return retorno;
}







