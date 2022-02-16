#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
   LinkedList* this= NULL;

	this = (LinkedList*)malloc(sizeof(LinkedList));

	if(this != NULL)
	{
		this->size = 0;
		this->pFirstNode = NULL;
	}

	return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
	int aux = -1;

	if(this != NULL)
	{

		aux = this->size;

	}
	return aux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* pNode = NULL;
	int i;

	if(this != NULL && ll_len(this)>0 && nodeIndex >= 0 && nodeIndex < ll_len(this))
	{

		pNode = this->pFirstNode;
		for(i = 0; i<nodeIndex; i++)
		{
			pNode = pNode->pNextNode;
		}
	}
	return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
	return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
	int aux = -1;
	Node* pNodoNuevo = (Node*)malloc(sizeof(Node));
	Node* auxNodeAnterior = NULL;
	Node* auxNodeSiguiente = NULL;

	if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this))
	{
		if(nodeIndex == 0)
		{
			pNodoNuevo->pNextNode = this->pFirstNode;
			this->pFirstNode = pNodoNuevo;
		}
		else
		{
			if(nodeIndex > 0 && nodeIndex <= ll_len(this))
			{
				   auxNodeAnterior = getNode(this, nodeIndex-1);
				   auxNodeSiguiente = auxNodeAnterior->pNextNode;
				   auxNodeAnterior->pNextNode = pNodoNuevo;
				   pNodoNuevo->pNextNode = auxNodeSiguiente;
			}
		}
		this->size += 1;
		pNodoNuevo->pElement = pElement;
		aux = 0;
	}
	return aux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
	int aux = -1;

	if(this != NULL)
	{
		addNode(this, ll_len(this), pElement);
		aux = 0;
	}

	return aux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
	void* aux = NULL;
	Node* auxNode = NULL;

	if(this != NULL && ll_len(this) > 0 && index >= 0 && index < ll_len(this))
	{
		auxNode = getNode(this, index);
		aux = auxNode->pElement;
	}

	return aux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
	  int aux = -1;
	  Node* auxNode = NULL;

	  if(this != NULL && ll_len(this) > 0 && index >= 0 && index < ll_len(this))
	  {
		auxNode = getNode(this, index);
		auxNode->pElement = pElement;
		aux = 0;
	  }

	  return aux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
	int returnAux = -1;
	Node* pNode = NULL;
	Node* pNodeAux = NULL;

	if(this != NULL && index >= 0 && index < ll_len(this) && ll_len(this) > 0)
	{
		if(index != 0 && index != (ll_len(this)))
		{
			pNodeAux = getNode(this, (index-1));
			pNode = getNode(this, index);
			pNodeAux->pNextNode = pNode->pNextNode;
			free(pNode);
		}
		else
		{
			if(index == 0)
			{
				pNode = getNode(this, index);
				this->pFirstNode = pNode->pNextNode;
				free(pNode);
			}
			else
			{
				if(index != 0 && index == (ll_len(this)))
				{
					free(pNode);
				}
			}
		}


		this->size--;
		returnAux = 0;
	}

	return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int aux = -1;
    int i;

    if(this != NULL)
    {
        for(i = (ll_len(this)); i >= 0; i--)
        {
            ll_remove(this, i);
        }
        aux = 0;
    }
    return aux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int aux = -1;

    if(this != NULL)
    {
        ll_clear(this);
        free(this);
        aux = 0;
    }
    return aux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
	int aux = -1;
	Node* auxPunteroNodo = NULL;
	int i;

	if(this != NULL)
	{
		for(i = 0; i < ll_len(this); i++)
		{
			auxPunteroNodo = getNode(this, i);
			if(auxPunteroNodo->pElement == pElement)
			{
				aux = i;
				break;
			}
		}
	}

	return aux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
	int aux = -1;

	if(this != NULL)
	{
		if(ll_len(this) > 0)
		{
			aux = 0;
		}
		else
		{
			aux = 1;
		}
	}

	return aux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int aux = -1;

    if(this != NULL && index >= 0 && index <= ll_len(this))
    {
    	aux = addNode(this, index, pElement);
    }

    return aux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
	void* aux = NULL;

	if(this != NULL && index >= 0 && index <= ll_len(this))
	{
		aux = ll_get(this, index);
		if(aux != NULL)
		{
			ll_remove(this, index);
		}
	}

	return aux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
	int aux = -1;
	Node* pNodo = NULL;
	int i;

	if(this != NULL)
	{
		aux = 0;
		for(i = 0; i < ll_len(this); i++)
		{
			pNodo = getNode(this, i);
			if(pNodo->pElement == pElement)
			{
				aux = 1;
				break;
			}
		}
	}

	return aux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
	int aux = -1;
	void* auxP = NULL;
	int ret;
	int i;

	if(this != NULL && this2 != NULL)
	{
		aux = 1;
		for(i = 0; i < ll_len(this2); i++)
		{
			auxP = ll_get(this, i);
			ret = ll_contains(this2, auxP);
			if(ret == 0)
			{
				aux = 0;
				break;
			}
		}
	}

	return aux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
	LinkedList* cloneArray = NULL;
	void* auxiliarP = NULL;
	int i;

	if(this != NULL && from >= 0 && from < ll_len(this) && to >= 0 && to <= ll_len(this))
	{
		cloneArray = ll_newLinkedList();

		for(i = from; i < to; i++)
		{
			auxiliarP = ll_get(this, i);
			ll_add(cloneArray, auxiliarP);
		}
	}

	return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;

    if(this != NULL)
    {
        cloneArray = ll_subList(this, 0, ll_len(this));
    }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
	int aux =-1;
	int i;
	void* pElementoUno;
	void* pElementoDos;
	int flagSwap;
	int largo;

	if(this!=NULL && order>=0 && pFunc != NULL)
	{
		largo = ll_len(this);
		do
		{
			flagSwap=0;
			for (i = 0; i < largo-1; i++)
			{
				pElementoUno = ll_get(this, i);
				pElementoDos = ll_get(this, i + 1);
				if( ((pFunc(pElementoUno, pElementoDos) < 0) && !order) ||
					((pFunc(pElementoUno, pElementoDos) > 0) && order) )
				{
					flagSwap=1;
					ll_set(this, i, pElementoDos);
					ll_set(this, i + 1, pElementoUno);
				}
			}
		}while(flagSwap);
		aux=0;
	}
	return aux;

}



int ll_sortByDireccion(LinkedList* this,LinkedList* thisDos, int (*pFunc)(void* ,void*, LinkedList*), int order)
{

	int aux =-1;
	int i;
	void* pElementoUno;
	void* pElementoDos;
	int flagSwap;
	int largo;

	if(this!=NULL && order>=0 && pFunc != NULL)
	{
		largo = ll_len(this);
		do
		{
			flagSwap=0;
			for (i = 0; i < largo-1; i++)
			{
				pElementoUno = ll_get(this, i);
				pElementoDos = ll_get(this, i + 1);
				if( ((pFunc(pElementoUno, pElementoDos,thisDos) < 0) && !order) ||
					((pFunc(pElementoUno, pElementoDos,thisDos) > 0) && order) )
				{
					flagSwap=1;
					ll_set(this, i, pElementoDos);
					ll_set(this, i + 1, pElementoUno);
				}
			}
		}while(flagSwap);
		aux=0;
	}
	return aux;

}


///la función “ll_filter” recibirá una lista y una función “pFunc”. se deberá iterar todos los
///elementos de la lista y pasárselos a la función “pFunc”. la función “pFunc” devolverá 1 si ese
///ítem se debe agregar a la lista resultado o 0 si no debe agregarse. la función “ll_filter” generará
///la nueva lista resultado, agregará a la misma los ítems correspondientes y la devolverá


LinkedList* ll_filter(LinkedList* this, int(*pFunc)(void*))
{
    LinkedList* filterList = NULL; //Declaro un nuevo Linkedlist

    void* aux = NULL; //Declaro un AUXILIAR a puntero a void

    if(this != NULL && pFunc != NULL)
    {
    	int tam = ll_len(this); //Obtengo el tamanio de la lista que me pasan como parametro (la principal)
        filterList = ll_newLinkedList(); //Creo una nueva lista

        if(filterList != NULL)
        {
            for(int i = 0; i < tam; i++) //Recorro la lista principal para obtener los elementos.
            {
                aux = ll_get(this, i); //Obtengo los elementos

                if(pFunc(aux)) //retorna 1 si la carga a la filter list, 0 sino cumple los requisitos
                {
                    if(ll_add(filterList, aux)) //en caso de que no se pueda cargar
                    {
                        ll_deleteLinkedList(filterList); //Elimino la lista
                        filterList = NULL;
                        break;
                    }
                }
            }
        }
    }

    return filterList; //Retorno la nueva lista
}

///RETORNA UN LINKEDLIST
LinkedList* ll_map(LinkedList* lista, void* (*pFunc) (void*))
{
    LinkedList* newList = NULL;
    newList = ll_newLinkedList();
    int tam = ll_len(lista);


    for(int i=0; i < tam; i++)
    {
        ll_add(newList, pFunc(ll_get(lista, i)));
    }

    return newList;
}
