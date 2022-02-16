/*
 * Controller.h
 *
 *  Created on: 15 feb. 2022
 *      Author: Neri y Valen
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include "LinkedList.h"

int controller_cargarDatos(char* path, LinkedList* listaDatos);
int controller_guardarListaFiltro1(char* path, LinkedList* listaFiltro1);
int controller_guardarListaFiltro2(char* path, LinkedList* listaFiltro2);
#endif /* CONTROLLER_H_ */
