/*
 * Controller.c
 *
 *  Created on: 15 feb. 2022
 *      Author: Neri y Valen
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <limits.h>
#include <values.h>
#include <ctype.h>
#include <string.h>
#include "Controller.h"
#include "Parser.h"
#include "ePost.h"

int controller_cargarDatos(char* path, LinkedList* listaDatos)
{
	int retorno=-1;
	char pathIngresado[21];

	printf("\nIngrese el nombre del archivos(recuerde que para poder identificar el archivo, debe agregar la ruta y su formato): ");
	fflush(stdin);
	scanf("%s", pathIngresado);

	if(strcmp(path, pathIngresado)!= 0)
	{
		printf("\nError! no se encontró un archivo con ese nombre...\n");
	}
	else
	{
		printf("\n\nArchivo encontrado!\n");

		FILE* pFile=fopen(path, "r");

		if(listaDatos!=NULL && path!=NULL)
		{
			if(parser_Posts(pFile, listaDatos) == -1)
			{
				printf("\nError al parsear el archivo...\n");
			}
			retorno=0;
		}
	}

	return retorno;
}

int controller_guardarListaFiltro1(char* path, LinkedList* listaFiltro1)
{
	ePost* this;
	FILE* pFile = NULL;

	int id;
	char user[21];
	int likes;
	int disLikes;
	int followers;

	int retorno = -1;
	int tam;
	int i;

	//CREO UN ARCHIVO
	pFile = fopen(path, "w");

	if(pFile!= NULL && listaFiltro1!= NULL)
	{

		tam = ll_len(listaFiltro1);


		fprintf(pFile, "%s\n", "id,user,likes,dislikes,followers");


		for(i = 0; i<tam; i++)
		{

			this = (ePost*)ll_get(listaFiltro1, i);


			if(ePost_getId(this, &id) == -1)
			{
				printf("\nError al gettear Id...\n");
			}
			if(ePost_getUser(this, user) == -1)
			{
				printf("\nError al gettear el user...\n");
			}
			if(ePost_getLikes(this, &likes) == -1)
			{
				printf("\nError al gettear los likes...\n");
			}
			if(ePost_getDislikes(this, &disLikes) == -1)
			{
				printf("\nError al gettear los dislikes...\n");
			}
			if(ePost_getFollowers(this, &followers) == -1)
			{
				printf("\nError al gettear los followers...\n");
			}

			fprintf(pFile, "%d,%s,%d,%d,%d\n", id, user, likes,disLikes,followers);
		}

		printf("\n\nLista filtro 1 guardada exitosamente!\n\n");
		retorno = 0;
	}
	fclose(pFile);
	return retorno;
}

int controller_guardarListaFiltro2(char* path, LinkedList* listaFiltro2)
{
	ePost* this;
	FILE* pFile = NULL;

	int id;
	char user[21];
	int likes;
	int disLikes;
	int followers;

	int retorno = -1;
	int tam;
	int i;

	//CREO UN ARCHIVO
	pFile = fopen(path, "w");

	if(pFile!= NULL && listaFiltro2!= NULL)
	{

		tam = ll_len(listaFiltro2);


		fprintf(pFile, "%s\n", "id,user,likes,dislikes,followers");


		for(i = 0; i<tam; i++)
		{

			this = (ePost*)ll_get(listaFiltro2, i);



			if(ePost_getId(this, &id) == -1)
			{
				printf("\nError al gettear Id...\n");
			}
			if(ePost_getUser(this, user) == -1)
			{
				printf("\nError al gettear el user...\n");
			}
			if(ePost_getLikes(this, &likes) == -1)
			{
				printf("\nError al gettear los likes...\n");
			}
			if(ePost_getDislikes(this, &disLikes) == -1)
			{
				printf("\nError al gettear los dislikes...\n");
			}
			if(ePost_getFollowers(this, &followers) == -1)
			{
				printf("\nError al gettear los followers...\n");
			}


			fprintf(pFile, "%d,%s,%d,%d,%d\n", id, user, likes,disLikes,followers);
		}

		printf("\n\nLista filtro 2 guardada exitosamente!\n\n");
		retorno = 0;
	}
	fclose(pFile);
	return retorno;
}
