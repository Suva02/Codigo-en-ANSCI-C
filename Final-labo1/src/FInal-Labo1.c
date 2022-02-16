/*
 ============================================================================
 Name        : FInal-Labo1.c
 Author      : Valentin
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <limits.h>
#include <values.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include "Input.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Parser.h"
#include "ePost.h"

int main(void)
{
	setbuf(stdout,NULL);
	srand(time(NULL));
	int controlDatos;
	int controlEstadisticas;

	controlDatos = 0;
	controlEstadisticas = 0;

	LinkedList* listaDatos = ll_newLinkedList();
	LinkedList* listaMapeada = ll_newLinkedList();
	LinkedList* listaFiltro1 = NULL;
	LinkedList* listaFiltro2 = NULL;


	int opcion;

			do{

				pedirNumero(&opcion, "\n\nIngrese alguna de las siguientes opciones: "
						"\n\n1.Cargar archivo "
						"\n2.Imprimir Lista "
						"\n3.Asignar estadisticas "
						"\n4.Filtrar por mejores posteos "
						"\n5.Filtrar por haters "
						"\n6.Ordenar por nivel de cantidad de followers "
						"\n7.Mostrar mas popular "
						"\n8.Salir ", "\n\nError! reingrese opcion: "
						"\n\n1.Cargar archivo "
						"\n2.Imprimir Lista "
						"\n3.Asignar estadisticas "
						"\n4.Filtrar por mejores posteos "
						"\n5.Filtrar por haters "
						"\n6.Ordenar por nivel de cantidad de followers "
						"\n7.Mostrar mas popular "
						"\n8.Salir ", 1, 8);

				switch(opcion)
				{
					case 1:
						if(controller_cargarDatos("posts.csv", listaDatos) == -1)
						{
							printf("\nError al cargar datos!\n");
						}
						else
						{
							controlDatos++;
						}
						systemPause("\nPresione una tecla para continuar...\n");
					break;
					case 2:
						if(controlDatos>0)
						{
							if(ePost_imprimirTodo(listaDatos) == -1)
							{
								printf("\nError al imprimir datos! Lista nula...\n");
							}
						}
						else
						{
							printf("\nNo hay datos cargados en el sistema...\n");
						}
						systemPause("\nPresione una tecla para continuar...\n");
					break;
					case 3:
						if(controlDatos>0)
						{
							listaMapeada = ll_map(listaDatos, ePost_mapear);
							ePost_imprimirTodo(listaMapeada);
							printf("\nEstadisticas asignadas correctamente!\n");
							controlEstadisticas = 1;
						}
						else
						{
							printf("\nNo hay datos en el sistema...\n");
						}
						systemPause("\nPresione una tecla para continuar...\n");
					break;
					case 4:
						if(controlDatos>0)
						{
							if(controlEstadisticas == 1)
							{
								listaFiltro1 = ll_filter(listaDatos, ePost_filtrarMejoresPosteos);
								if(listaFiltro1!= NULL)
								{
									controller_guardarListaFiltro1("mejoresPosteos.txt", listaFiltro1);
									ePost_imprimirTodo(listaFiltro1);
								}
								else
								{
									printf("\nError! La lista filtro es nula...n");
								}
							}
							else
							{
								printf("\nPrimero debe asignarle estadisticas a los posteos...(opcion 3)\n");
							}
						}
						else
						{
							printf("\nError! No hay datos cargados en el sistema...\n");
						}

						systemPause("\nIngrese una tecla para continuar...\n");
					break;
					case 5:
						if(controlDatos>0)
						{
							if(controlEstadisticas == 1)
							{
								listaFiltro2 = ll_filter(listaDatos, ePost_filtrarPorHaters);
								if(listaFiltro2!= NULL)
								{
									controller_guardarListaFiltro2("haters.txt", listaFiltro2);
									ePost_imprimirTodo(listaFiltro2);
								}
								else
								{
									printf("\nError! La lista filtro es nula...n");
								}
							}
							else
							{
								printf("\nPrimero debe asignarle estadisticas a los posteos...(opcion 3)\n");
							}
						}
						else
						{
							printf("\nError! No hay datos cargados en el sistema...\n");
						}
						systemPause("\nIngrese una tecla para continuar...\n");
					break;
					case 6:
						if(controlDatos>0)
						{
							if(controlEstadisticas == 1)
							{
								if(ePosteo_efectuarOrdenamientoPorFollowers(listaDatos) == -1)
								{
									printf("\nError al efectuar ordenamiento! Lista nula...n");
								}
							}
							else
							{
								printf("\nPrimero debe asignarle estadisticas a los posteos...(opcion 3)\n");
							}
						}
						else
						{
							printf("\nNo hay datos cargados en el sistema...\n");
						}

						systemPause("\nIngrese una tecla para continuar...\n");
					break;
					case 7:
						if(controlDatos>0)
						{
							if(controlEstadisticas == 1)
							{
								if(ePosteo_informarElMasLikeado(listaDatos) == -1)
								{
									printf("\nError al informar el nombre del user con el posteo mas likeado! Lista nula...\n");
								}
							}
							else
							{
								printf("\nPrimero debe asignarle estadisticas a los posteos...(opcion 3)\n");
							}
						}
						else
						{
							printf("\nError al mostrar! No hay datos en el sistema...\n");
						}
						systemPause("\nIngrese una tecla para continuar...\n");
					break;
					case 8:
						printf("\nPrograma finalizado...\n");
					break;
				}

			}while(opcion!= 8);
	return EXIT_SUCCESS;
}
