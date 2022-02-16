/*
 * Parser.c
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
#include "Parser.h"
#include "ePost.h"


int parser_Posts(FILE* pFile, LinkedList* listaDatos)
{
	ePost* this;
	int retorno = -1;

	char id[21];
	char user[21];
	char likes[21];
	char disLikes[21];
	char followers[21];

	if(pFile!= NULL && listaDatos!= NULL)
	{

		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]", id, user, likes, disLikes, followers);

		while(!feof(pFile))
		{

			fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]", id, user, likes, disLikes, followers);

			if(feof(pFile))
			{
				break;
			}
			this = ePost_constructorParametrizado(id, user, likes, disLikes, followers);

			ll_add(listaDatos, this);
		}
		printf("\nDatos cargados correctamente!\n");
		fclose(pFile);
		retorno = 0;
	}

	return retorno;
}
