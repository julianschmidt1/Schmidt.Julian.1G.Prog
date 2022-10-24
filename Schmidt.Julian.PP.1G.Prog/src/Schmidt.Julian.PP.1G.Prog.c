/*
 ============================================================================
 Name        : Prog.c
 Author      : Julian Schmidt
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX_VACUNAS 4
typedef struct {
	int id;
	char nombre[20];
	char tipo;
	float efectividad;
} eVacuna;

float aplicarAumento(float precioProducto);
int reemplazarCaracteres(char *cadena, char primerChar, char segundoChar);
int ordenarPorTipoEfectividad(eVacuna *vacunas, int tamVacunas);

int main(void) {
	setbuf(stdout, NULL);
	char testString[20] = "anana";
	eVacuna vacunas[MAX_VACUNAS] = { { 1, "Pfizer", 'a', 6.4 }, { 2,
			"Chinopharm", 'a', 5.2 }, { 3, "Astrazeneca", 'y', 6.5 }, { 4,
			"Sputnik", 'h', 7.7 } };

	puts("Punto 1");
	printf("valor: %f", aplicarAumento(100));

	puts("\n\nPunto 2");
	printf("%d %s", reemplazarCaracteres(testString, 'a', 'x'), testString);

	puts("\n\nPunto 3");
	ordenarPorTipoEfectividad(vacunas, MAX_VACUNAS);
	for(int i = 0;i<MAX_VACUNAS;i++){
		printf("---\n%d %s %c %f \n---", vacunas[i].id, vacunas[i].nombre, vacunas[i].tipo, vacunas[i].efectividad);
	}

	return EXIT_SUCCESS;
}

int ordenarPorTipoEfectividad(eVacuna *vacunas, int tamVacunas) {
	int rtn = 0;
	eVacuna auxVacuna;

	if (vacunas != NULL && tamVacunas > 0) {
		for (int i = 0; i < tamVacunas - 1; i++) {
			for (int j = i + 1; j < tamVacunas; j++) {

				if((vacunas[i].tipo > vacunas[j].tipo) || (vacunas[i].tipo == vacunas[j].tipo && vacunas[i].efectividad > vacunas[j].efectividad)){
					auxVacuna = vacunas[i];
					vacunas[i] = vacunas[j];
					vacunas[j] = auxVacuna;
				}

			}
		}

		rtn = 1;
	}
	return rtn;
}

float aplicarAumento(float precioProducto) {
	float valorAumentado;

	valorAumentado = (precioProducto * 5) / 100;

	return precioProducto + valorAumentado;
}

int reemplazarCaracteres(char *cadena, char primerChar, char segundoChar) {
	int contador = 0;

	if (cadena != NULL && sizeof(cadena) > 0) {

		for (int i = 0; cadena[i] != '\0'; i++) {
			if (cadena[i] == primerChar) {
				cadena[i] = segundoChar;
				contador++;
			}
		}
	}

	return contador;
}
