/*
 * ePost.c
 *
 *  Created on: 16 feb. 2022
 *      Author: Neri y Valen
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
#include "ePost.h"
#include "Input.h"

ePost* ePost_constructor()
{
	ePost* this;
	this = (ePost*) malloc(sizeof(ePost));
	return this;
}
ePost* ePost_constructorParametrizado(char* id, char* user, char* likes, char* disLikes, char* followers)
{
	ePost* this;
	this = ePost_constructor();

	if(this!= NULL && user!= NULL && likes!= NULL && disLikes!= NULL && followers)
	{
		if(ePost_setId(this, atoi(id)) == -1)
		{
			printf("\nError al settear id...\n");
		}
		if(ePost_setUser(this, user) == -1)
		{
			printf("\Error al settear user...\n");
		}
		if(ePost_setLikes(this, atoi(likes)) == -1)
		{
			printf("\nError al settear likes...\n");
		}
		if(ePost_setDislikes(this, atoi(disLikes)) == -1)
		{
			printf("\nError al settear dislikes...\n");
		}
		if(ePost_setFollowers(this, atoi(followers)) == -1)
		{
			printf("\nError al settear followers...\n");
		}
	}

	return this;
}

int ePost_setId(ePost* this, int id)
{
	int retorno = -1;

	if(this!= NULL && id>0)
	{
		this->id = id;
		retorno = 0;
	}

	return retorno;
}
int ePost_getId(ePost* this, int* id)
{
	int retorno = -1;
	if(this!= NULL && id!= NULL)
	{
		*id = this->id;
		retorno = 0;
	}

	return retorno;
}

int ePost_setUser(ePost* this, char* user)
{
	int retorno = -1;

	if(this!= NULL && user!= NULL)
	{
		strcpy(this->user, user);
		retorno = 0;
	}

	return retorno;
}
int ePost_getUser(ePost* this, char* user)
{
	int retorno = -1;
	if(this!= NULL && user!= NULL)
	{
		strcpy(user,this->user);
		retorno = 0;
	}

	return retorno;
}

int ePost_setLikes(ePost* this, int likes)
{
	int retorno = -1;

	if(this!= NULL && likes>=0)
	{
		this->likes = likes;
		retorno = 0;
	}

	return retorno;
}
int ePost_getLikes(ePost* this, int* likes)
{
	int retorno = -1;
	if(this!= NULL && likes!= NULL)
	{
		*likes = this->likes;
		retorno = 0;
	}

	return retorno;
}

int ePost_setDislikes(ePost* this, int disLikes)
{
	int retorno = -1;

	if(this!= NULL && disLikes>=0)
	{
		this->disLikes = disLikes;
		retorno = 0;
	}

	return retorno;
}
int ePost_getDislikes(ePost* this, int* disLikes)
{
	int retorno = -1;
	if(this!= NULL && disLikes!= NULL)
	{
		*disLikes = this->disLikes;
		retorno = 0;
	}

	return retorno;
}

int ePost_setFollowers(ePost* this, int followers)
{
	int retorno = -1;

	if(this!= NULL && followers>=0)
	{
		this->followers = followers;
		retorno = 0;
	}

	return retorno;
}
int ePost_getFollowers(ePost* this, int* followers)
{
	int retorno = -1;
	if(this!= NULL && followers!= NULL)
	{
		*followers = this->followers;
		retorno = 0;
	}

	return retorno;
}
void ePost_imprimirPosteo(ePost* this)
{
	int id;
	char user[21];
	int likes;
	int disLikes;
	int followers;

	ePost_getId(this, &id);
	ePost_getUser(this, user);
	ePost_getLikes(this, &likes);
	ePost_getDislikes(this, &disLikes);
	ePost_getFollowers(this, &followers);

	printf ( "%-5d %-20s %-20d %-20d %-20d\n " ,this->id, this->user, this->likes, this->disLikes, this->followers);
}

int ePost_imprimirTodo(LinkedList* listaPosteos)
{
	int retorno = -1;
	int tam;
	int i;
	ePost* this;

	if(listaPosteos!= NULL)
	{
		tam = ll_len(listaPosteos);
		printf("\nLista de posteos..\n\n  %-5s %-20s %-20s %-20s %-20s\n ","Id","User","Likes","Dislikes","followers");
		for(i = 0; i<tam;i++)
		{
			this = (ePost*) ll_get(listaPosteos, i);
			ePost_imprimirPosteo(this);
			retorno = 0;
		}
	}

	return retorno;
}


void* ePost_mapear(void* this)
{
	ePost* unPost;
	int likes;
	int dislikes;
	int followers;

	int likesAsignados;
	int disLikesAsignados;
	int followersAsignados;

	if(this!= NULL)
	{
		unPost = (ePost*) this;
		ePost_getLikes(unPost, &likes);
		ePost_getDislikes(unPost, &dislikes);
		ePost_getFollowers(unPost, &followers);

		likesAsignados = (rand() % (3000 - 500 + 1) + 500);
		disLikesAsignados = (rand() % (3500 - 300 + 1) + 300);
		followersAsignados = (rand() % (20000 - 10000 + 1) + 10000);

		ePost_setLikes(unPost, likesAsignados);
		ePost_setDislikes(unPost, disLikesAsignados);
		ePost_setFollowers(unPost, followersAsignados);
	}

	return unPost;
}

int ePost_filtrarMejoresPosteos(void* this)
{
	int retorno = 0;
	int likes;
	ePost* unPost;

	if(this!= NULL)
	{
		unPost = (ePost*) this;

		ePost_getLikes(unPost, &likes);
		if(likes>5000)
		{
			retorno = 1;
		}
	}

	return retorno;
}

int ePost_filtrarPorHaters(void* this)
{
	int retorno = 0;
	int likes;
	int disLikes;
	ePost* unPost;

	if(this!= NULL)
	{
		unPost = (ePost*) this;

		ePost_getLikes(unPost, &likes);
		ePost_getDislikes(unPost, &disLikes);
		if(disLikes>likes)
		{
			retorno = 1;
		}
	}

	return retorno;
}

int ePost_ordenarPorCantidadFollowers(void* followersUno, void* followerDos)
{
	int retorno = -1;
	ePost* follower1;
	ePost* follower2;

	if(followersUno!= NULL && followerDos!= NULL)
	{
		follower1 = (ePost*) followersUno;
		follower2 = (ePost*) followerDos;

		if(follower1->followers>follower2->followers)
		{
			retorno = 0;
		}
	}

	return retorno;
}

int ePosteo_efectuarOrdenamientoPorFollowers(LinkedList* listaDatos)
{
	int ordenLista = 0;
	int retorno = -1;


	if(listaDatos!= NULL)
	{
		   ll_sort(listaDatos, ePost_ordenarPorCantidadFollowers, ordenLista);
		   printf("\nSe ordeno la lista por Followers correctamente!\n\n");
		   ePost_imprimirTodo(listaDatos);
		   retorno = 0;
	}

	return retorno;
}

int ePosteo_informarElMasLikeado(LinkedList* listaDatos)
{
	ePost* this;
	int id;
	char user[21];
	int likes;
	int disLikes;
	int followers;
	int retorno = -1;

	//maximos
	char userMaximo[21];
	int likesMaximos;

	//flag
	int flagMaximo = 1;

	int i;
	int tam;

	if(listaDatos!= NULL)
	{
		tam = ll_len(listaDatos);
		for(i = 0; i<tam; i++)
		{
			this = (ePost*) ll_get(listaDatos, i);
			ePost_getId(this, &id);
			ePost_getUser(this, user);
			ePost_getLikes(this, &likes);
			ePost_getDislikes(this, &disLikes);
			ePost_getFollowers(this, &followers);

			if(flagMaximo == 1 || likes>likesMaximos)
			{
				strcpy(userMaximo, user);
				likesMaximos = likes;
				flagMaximo = 0;
			}
		}

		printf("\nEl user con el posteo mas likeado es: %s, con un numero de %d likes", userMaximo, likesMaximos);
		retorno = 0;
	}

	return retorno;
}
