#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "libro.h"
#include "editorial.h"


static Node* getNode(LinkedList* this, int nodeIndex); // hace q la funcion no pueda ser cambiada fuera de este ambito, es para llamarlas dentro de otras funciones
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void) //la cabcera de este cienpiez mecanico
{
    LinkedList* this = NULL; //el this apunta a este elemento, es como señalarlo
    this = (LinkedList*)malloc(sizeof(LinkedList)); //asigno espacio en memoria dinamica
    if(this !=NULL) // si no existe la lista, la creo de 0, la cabecera apunta a null donde engancho el primer nodo, tamaño inicio en 0
    {
    	this->pFirstNode = NULL;
    	this->size = 0;

    }
    return this; // apunta lo que tiene en ese momento el linkedlist, si es igual a null retorna a null, retorna eso si no consiguo espacio en memoria
    			//con el this retorna lo q haya en el puntero a fx de linkedlist
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this) //me dice cuantos nodos hay
{
    int returnAux = -1;
    if(this != NULL)
    {
    	returnAux = this->size; //en el retorno tiene el valor del campo size
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex) //obtengo un nodo
{
	Node* pNode = NULL; //retorna null en caso de error
	if(this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this))
	{
		pNode = this->pFirstNode; //asigno la direccion de memoria que tenga en ese momento el nodo en posicion 0, ese dato esta en la cabecera del linkedlist
									//del nodo 0 el enganchado a la cabecera, lo encuentro con su dir de memoria q esta en pfirNode
		for(int i=0 ; i < nodeIndex ; i++) //recorro los indices del nodo, obtengo los nodos siguientes.
		{
			pNode = pNode->pNextNode; //se redefine a si misma, pNode me va a guardar la direccion del siguiente
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
static int addNode(LinkedList* this, int nodeIndex,void* pElement) // creo nodo nuevo y lo agrego a algun lugar de la lista
{
	Node* nuevoNodo;
	Node* anteriorNodo;

	int returnAux = -1;
	if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this)) //estoy creando nodo, el nodo como limite tiene el numero q coincide con el size
	{
		nuevoNodo = (Node*)malloc(sizeof(Node));
		if(nuevoNodo != NULL)
		{
			if(nodeIndex == 0) //si es el primer nodo
			{

				//nuevo apunta al ant
				//ll apunta al nuevo
				nuevoNodo->pNextNode = this->pFirstNode;
				this->pFirstNode = nuevoNodo;

			}
			else
			{
				anteriorNodo = getNode(this, nodeIndex-1); //obtengo el nodo anterior
				if(anteriorNodo != NULL)
				{
					//nuevo apunta al ant
					//viejo apunta al nuevo
					nuevoNodo->pNextNode = anteriorNodo->pNextNode;
					anteriorNodo->pNextNode = nuevoNodo;//pNextNode = ESTE NODO
				}
			}
			nuevoNodo->pElement = pElement;
			//pElement = no puede ser nulo porque puedo reservar espacio en memoria para un nodo simplemente
			this->size++; //Incremento el tamaño de la linkedlist
			returnAux = 0;
		}
	}
	return returnAux;

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


/** \brief  Agrega un elemento a la lista //los elementos de la lista lista son los nodos, los elementos de los nodos son las estrucuturas
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement) //agrega un nodo llamando a addnode enlazado a un elemento y lo carga al final de la lista
{
    int returnAux = -1;
    if(this != NULL  )
    {
    	addNode(this,ll_len(this),pElement); //ll_len me dice la cantidad de elementos, entonces lo agrega al final
    	returnAux = 0;
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)//devuelve lo q esta adentro de ese nodo, el pElement que esta detro de un nodo
{
    void* returnAux = NULL;
    Node* pNode;
    if(this != NULL && index >= 0 && index < ll_len(this))
    {
    	pNode = getNode(this,index);
    	if(pNode != NULL)
    	{
    		returnAux = pNode->pElement;
    	}
    }

    return returnAux;
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
int ll_set(LinkedList* this, int index,void* pElement) // decime un indice y remplazame un elemnto por otro, hago el get obtengo el nodo y remplazo el elemento en ese nodo
{
    int returnAux = -1;
    Node* pNode;
    //llamo a get node, a ese p element le asigno el nuevo elemento pasado por parametro
    if(this != NULL && index >=0 && index < ll_len(this))
    {
    	pNode = getNode(this, index);
    	//pNode validar != NULL
    	pNode->pElement = pElement;
    	returnAux = 0;
    }
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index) // eliminar un nodo determinado de la lista, el pElement queda en memoria dinamica
{
    int returnAux = -1;
    Node* pNode;
    Node* pNodeAnterior;
    if(this != NULL && index >= 0 && index < ll_len(this)) //this.pFirsNode es la cabecera de mi linkedlit lo que esta "antes" de mi nodo 0
    {
    	pNode = getNode(this, index);
    	if(index == 0)
    	{
     		this->pFirstNode = pNode->pNextNode; //pNode es el nodo que voy a eliminar, le digo a la cabecera que guarde la dir de memoria del siguiente nodo que guarda mi nodo
     	}
    	else
    	{
    		pNodeAnterior = getNode(this, index-1);
    		pNodeAnterior->pNextNode = pNode->pNextNode;
    	}
    	free(pNode);
    	this->size --;
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
int ll_clear(LinkedList* this) //elimina todos los nodos de la lista
{
    int returnAux = -1;
    int longitud;

    if(this != NULL)
    {
    	longitud = ll_len(this);
    	for(int i = 0; i< longitud;i++ )
    	{
    		ll_remove(this,0); //si borra siempre el nodo 0, va a borrar el nodo que va quedando "pegado" a la cabecera.
    	}
    	returnAux = 0;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this) //elimina la lista
{
    int returnAux = -1;

    if(this != NULL)
    {
    	ll_clear(this);
    	free(this); //elimino la cabecera
    	returnAux = 0;
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)//recorre la lista buscando que algun nodo obtenga determinado elemento y devuelve en q indice
{
    int returnAux = -1;
    int longitud;
    if(this != NULL)
    {
    	longitud = ll_len(this);

    	for(int i = 0; i< longitud; i++)
    	{
    		if(ll_get(this, i) == pElement)
    		{
    			returnAux = i;
    			break;
    		}
    	}
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL //la lista no se creo
                        ( 0) Si la lista NO esta vacia //tengo por lo menos 1 nodo
                        ( 1) Si la lista esta vacia //solo tengo la cabecera
 *
 */
int ll_isEmpty(LinkedList* this) //segun que valor tenga size
{
    int returnAux = -1;
    if(this != NULL)
    {
    	returnAux = 1;

    	if(ll_len(this) > 0)
    	{
    		returnAux = 0;
    	}
    }
    return returnAux;
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
int ll_push(LinkedList* this, int index, void* pElement) // tengo q tener la direccion del nodo anterior, tambien del q quiero ocupar , intercalar en esa posicion el elemento q quiro insertar
{														//push cuando la lista esta vacia transformar el push en un add
    int returnAux = -1;

    if(this != NULL && index >= 0 && index <= ll_len(this))
    {
    	returnAux = addNode(this, index, pElement);
    }
    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index) //elimina el nodo pero devuelve el puntero al elemento, conserva el pElement
{
    void* returnAux = NULL;

    if(this != NULL && index >= 0 && index < ll_len(this))
    {
    	returnAux = ll_get(this, index);
    	ll_remove(this, index);
    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement) //devuelve verdadero o falso en fx de si ese pELment forma o no parte de la lista
{
    int returnAux = -1;
    if(this != NULL)
    {
    	returnAux = 0;
    	if(ll_indexOf(this, pElement)!= -1)
    	{
    		returnAux = 1;
    	}
    }
    return returnAux;
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
int ll_containsAll(LinkedList* this,LinkedList* this2) //si todos los elementos de la lista 2 estas contenidos en la lista 1
{
   int returnAux = -1;
	void* pElement;

	if(this != NULL && this2 != NULL)
	{
		returnAux = 0; //todos los elementos de this2 no estan en this

		for(int i = 0; i < ll_len(this2); i++)
		{
			pElement = ll_get(this2, i); //obtiene un elemento en determinado indice
			if(ll_contains(this, pElement))//si el elemento esta
			{
				returnAux = 1; //los elem de this2 estan en this
				break;
			}
		}
	}
        return returnAux;
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
LinkedList* ll_subList(LinkedList* this,int from,int to) //crea en memoria una lista nueva, new_ll , a esa lista se le hace add desde un indice a otro
{
    LinkedList* cloneArray = NULL; //cloneArray es la nueva sublist
    int i;
    void* pElement;

   if(this != NULL && from >= 0 && from <= ll_len(this) && to >= 0 && to <= ll_len(this) && from < to)
   {
	   cloneArray = ll_newLinkedList();
	   if (cloneArray != NULL)
	   {
		   for(i=from;i<to;i++)
		   {
			   pElement = ll_get(this, i);
			   if(pElement != NULL)
			   {
				   ll_add(cloneArray,pElement);
			   }
		   }
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
LinkedList* ll_clone(LinkedList* this) //copiar la lista desde 0 hasta size
{
    LinkedList* cloneArray = NULL;

    if(this != NULL)
	{
	  cloneArray = ll_subList(this,0,ll_len(this));
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
	int returnAux =-1;
	int i;
	int estadoDeOrdenamiento = 1;
	int criterio; //retorno del int del puntero a funcion
	void* pElement;
	void* pElement2;

	if (this != NULL && pFunc != NULL && (order == 0 || order == 1))
	{
		while (estadoDeOrdenamiento)
		{
			estadoDeOrdenamiento = 0;
			for (i = 0; i < ll_len(this)- 1; i++)
			{
				pElement = ll_get(this,i);
				pElement2 = ll_get(this,i+1);
				criterio = pFunc(pElement,pElement2); //comparo los elementos

				if ((order == 1 && criterio == 1) ||(order == 0 && criterio == -1))
				{
					ll_set(this,i,pElement2); //cambio de lugar
					ll_set(this,i+1,pElement);
					estadoDeOrdenamiento = 1;
				}
			}
		}
		returnAux = 0;
	}
    return returnAux;
}



/// @brief La función “ll_filter” recibirá una lista y una función criterio “fn”. Se deberá iterar todos los elementos
//de la lista y pasarlos a la función “fn”. La función “fn” devolverá 1 si ese ítem se debe agregar a la
//lista resultado o 0 si no debe agregarse. La función “ll_filter” generará la nueva lista resultado,
//agregará a la misma los ítems correspondientes y la devolverá.
///
/// @param this
/// @param fn
/// @return
LinkedList* ll_filter(LinkedList *this, int (*pFunc)(void*)) {

	/** llama a pFunc y le pasa un elemento, si pFunc devuelve 1, lo carga*/

	int tam; //guardo el tamanho del array
	void *pElement;
	LinkedList *newLinkedList = NULL; //LL para devolver filtrado

	if (this != NULL && *pFunc != NULL) {

		newLinkedList = ll_newLinkedList();
		if (newLinkedList != NULL) {
			tam = ll_len(this); //guardo el tamanho de la lista original

			for (int i = 0; i < tam; i++) {
				pElement = ll_get(this, i); //recorro la lista original.
				if (pFunc(pElement)) { // si el callback devuelve 1, me copio el elemento.
					ll_add(newLinkedList, pElement); //me los copio a la lista filtrada.
				}
			}

		}
	}
	return newLinkedList;
}


/*int ll_map(LinkedList* this, LinkedList* this2, int (*pFunc)(LinkedList*, void*))
{
   int retorno = 0;
   int retornoFunc;
   void* aux;
   int precio;
   float descuento;
   int i ;
   int len;

   if(this != NULL && this2 != NULL && pFunc != NULL)
   {
       len = ll_len(this);
       for(i=0; i<len; i++)
       {
           aux = ll_get(this, i);
           retornoFunc = pFunc(this2, aux);
           if(retornoFunc == 1)
           {
               eLibro_getPrecio(aux, &precio);
               descuento = (precio * 20) / 100;
               precio = precio - descuento;
               eLibro_setPrecio(aux, precio);
               retorno = 1;
           }
           else
           {
               if(retornoFunc == -1)
               {
                 eLibro_getPrecio(aux, &precio);
                 descuento = (precio * 10) / 100;
                 precio = precio - descuento;
                 eLibro_setPrecio(aux, precio);
                 retorno = 1;
               }
           }
       }
   }

   return retorno;
}

int ll_map(LinkedList* this, float (*pFunc)(void*)){
	int lenght;
	void* pElement;
	char resp;
	int retorno=0;
	int precio;
	LinkedList* list = NULL;
	if(this!=NULL && *pFunc!=NULL){
		list = ll_newLinkedList();
		lenght = ll_len(this);

		for (int i = 0; i < lenght; i++) {
			pElement = ll_get(this, i);
			precio = pFunc(pElement);
			if(precio!=-1){
				eLibro_getPrecio(pElement, &precio);
				ll_add(list, pElement);
			}
		}
	}

	controller_ListKnightZodiac(list);
	printf("Desea Guardarla? y/n \n");
	scanf("%c",&resp);
	if(resp=='y'){
		controller_saveAsText("mapeado.csv", list);
		ll_deleteLinkedList(list);
		retorno=1;
	}
	//mostrar lista armada
	//preguntar si la quiero guardar s/n
	//s: controller_saveAsText ("mapeado.csv",newLinkedList);
	//delete_linkedList(newLinkedList);
return retorno;
}*/

//te devuelve una nueva lista con la misma cantidad de elementos con elementos que pueden ser modificados segun el criterio de la funcion puntero
//realiza copia de la lista que quizas sea modificada (si cumple con el criterio de pFunc)
LinkedList* ll_map(LinkedList* this, int (*pFunc)(void*))
{
	int len;
	void *pElement;
	LinkedList *newLinkedList = NULL;

	if (this != NULL && pFunc != NULL)
	{
		newLinkedList = ll_clone(this); //la diferencia con filter es que clona la lista original
		if (newLinkedList != NULL)
		{
			len = ll_len(newLinkedList);

			for (int i = 0; i < len; i++)
			{
				pElement = ll_get(newLinkedList, i);
				pFunc(pElement);
				if(pElement != NULL)
				{
				   ll_add(newLinkedList, pElement);
				}
			}
		}
	}
	return newLinkedList;
}

