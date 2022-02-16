/*
 * Input.c
 *
 *  Created on: 2 nov. 2021
 *      Author: Neri y Valen
 */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <limits.h>
#include <values.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include "Input.h"



int systemPause(char* message)
{
	int ret=-1;
	if(message!=NULL)
	{
		fflush(stdin);
		printf("\n%s",message);
		getchar();
		ret=0;
	}
	return ret;
}

int pedirNumero(int* num,char* mensaje,char* mensajeError,int min, int max)
{
    int retorno=-1;
    char numAux[51];
    int numIntAux;


    if(num!=NULL && mensaje!=NULL && mensajeError!=NULL)
    {

        printf("%s",mensaje);
        fflush(stdin);
        scanf("%[^\n]",numAux);
        numIntAux=atoi(numAux);


        while((!pedirNumeroAcompanado(numAux) && !validarEspacios(mensaje)) || (numIntAux>max||numIntAux<min))
        {
            printf("%s",mensajeError);
            fflush(stdin);
            scanf("%[^\n]",numAux);
            numIntAux=atoi(numAux);
        }

        *num=atoi(numAux);

        retorno=0;
    }


    return retorno;
}
int pedirNumeroFlotante(float* num, char* mensaje, char* mensajeError, int min, int max)
{
	int retorno=-1;
	char numAux[51];
	int numFloatAux;


	if(num!=NULL && mensaje!=NULL && mensajeError!=NULL)
	{

		printf("%s",mensaje);
		fflush(stdin);
		scanf("%[^\n]",numAux);
		numFloatAux=atoi(numAux);


		while((!pedirNumeroAcompanado(numAux) && !validarEspacios(mensaje)) || (numFloatAux>max||numFloatAux<min))
		{
			printf("%s",mensajeError);
			fflush(stdin);
			scanf("%[^\n]",numAux);
			numFloatAux=atoi(numAux);
		}

		*num=atoi(numAux);

		retorno=0;
	}


	return retorno;
}
int pedirNombreCompleto(char* string,char* mensaje,char* mensajeError,int max)
{
    int retorno=-1;
    char Auxiliar[200];
    if(string!=NULL && max>0)
    {
        printf("%s",mensaje);
        fflush(stdin);
        scanf("%[^\n]",Auxiliar);

        while(strlen(Auxiliar)>max || pedirNumeroAcompanado(Auxiliar)==-1 || validarCadena(Auxiliar)==0)
        {
            printf("%s",mensajeError);
            fflush(stdin);
            scanf("%[^\n]",Auxiliar);
        }
        strcpy(string,Auxiliar);
        retorno=0;
    }
    return retorno;
}
int validarCadena(char* string)
{
    int i;
    int tam;
    int retorno=-1;
    if(string!=NULL)
    {
        tam=strlen(string);
        transformarMayus(string);
        for(i=0;i<tam;i++)
        {

            if(string[i] < 97 || string[i] > 122)
            {
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

int pedirNumeroAcompanado(char* string)
{
    int retorno=-1;
    int i;
    int tam;

    if(string!=NULL)
    {
        tam=strlen(string);

        for(i=0;i<tam;i++)
        {
            if(isdigit(string[i])==0 && string[i]!='.' && string[0]!='+' && string[0]!='-')
            {
                retorno=0;
                break;
            }

        }

    }
    return retorno;
}

int validarEspacios(char* string)
{
    int returno=-1;
    int i;
    int tam;
    tam=strlen(string);
    for(i=0;i<tam;i++)
    {
    	if(string[i] == ' ' || string[i] == '\t'  || string[i] == '\v')
        {
            returno=0;
            break;
        }

    }
    return returno;
}

int transformarMayus(char* string)
{
    int retorno=-1;
    int i;
    int tam;
    if(string!=NULL)
    {
        tam=strlen(string);
        for(i=0;i<tam;i++)
        {
            string[i]=tolower(string[i]);
        }

        retorno=0;
    }
    return retorno;
}

