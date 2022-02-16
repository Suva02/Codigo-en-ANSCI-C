/*
 * ePost.h
 *
 *  Created on: 16 feb. 2022
 *      Author: Neri y Valen
 */

#ifndef EPOST_H_
#define EPOST_H_
#include "LinkedList.h"

typedef struct
{
	int id;
	char user[21];
	int likes;
	int disLikes;
	int followers;

}ePost;

ePost* ePost_constructor();
ePost* ePost_constructorParametrizado(char* id, char* user, char* likes, char* disLikes, char* followers);

int ePost_setId(ePost* this, int id);
int ePost_getId(ePost* this, int* id);

int ePost_setUser(ePost* this, char* user);
int ePost_getUser(ePost* this, char* user);

int ePost_setLikes(ePost* this, int likes);
int ePost_getLikes(ePost* this, int* likes);

int ePost_setDislikes(ePost* this, int disLikes);
int ePost_getDislikes(ePost* this, int* disLikes);

int ePost_setFollowers(ePost* this, int followers);
int ePost_getFollowers(ePost* this, int* followers);

void ePost_imprimirPosteo(ePost* this);
int ePost_imprimirTodo(LinkedList* listaPosteos);

void* ePost_mapear(void* this);

//FUNCIONES FILTRO
int ePost_filtrarMejoresPosteos(void* this);
int ePost_filtrarPorHaters(void* this);

int ePost_ordenarPorCantidadFollowers(void* followersUno, void* followerDos);
int ePosteo_efectuarOrdenamientoPorFollowers(LinkedList* listaDatos);
int ePosteo_informarElMasLikeado(LinkedList* listaDatos);
#endif /* EPOST_H_ */
