	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>

	#include "..//inc//LinkedList.h"


	static Node* getNode(LinkedList* this, int nodeIndex);
	static int addNode(LinkedList* this, int nodeIndex,void* pElement);


	LinkedList* ll_newLinkedList(void)
	{
		LinkedList* this;

		this = (LinkedList*)malloc(sizeof(LinkedList));

		if (this != NULL)
		{
			//Inicializo el puntero al primer nodo con null y el size en 0
			this->pFirstNode = NULL;
			this->size = 0;
		}
		return this;
	}


	int ll_len(LinkedList* this)
	{
		int retorno = -1;

		if(this!=NULL)
		{
			//Retorno el campo size
			retorno = this->size;
		}
		return retorno;
	}



	static Node* getNode(LinkedList* this, int indiceNodo)
	{
		Node* nodo = NULL; //Inicializo en NULL

		if(this != NULL && indiceNodo >= 0 && indiceNodo < ll_len(this))
		{
			//Guardo en nodo el primer nodo
			nodo = this->pFirstNode;

			for(int i = 0 ; i < indiceNodo ; i++)
			{
				//Reemplazo a nodo con el valor de next node hasta que llegue al indiceNodo.
				nodo = nodo->pNextNode;
			}
		}
		return nodo;
	}



	Node* test_getNode(LinkedList* this, int nodeIndex)
	{
		return getNode(this, nodeIndex);
	}



	static int addNode(LinkedList* this, int indiceNodo, void* pElement)
	{
		int retorno = -1;

		Node* nuevoNodo;
		Node* nodoAnterior;

		if(this != NULL && indiceNodo >= 0 && indiceNodo <= ll_len(this))
		{
			//Pido nuevo nodo
			nuevoNodo = (Node*)malloc(sizeof(Node));

			if(nuevoNodo != NULL)
			{
				//Le asgino el puntero al elemento
				nuevoNodo->pElement = pElement;

				//Si es el primer nodo
				if(indiceNodo == 0)
				{
					//Simplemente intercambio valores
					nuevoNodo->pNextNode = this->pFirstNode;
					this->pFirstNode = nuevoNodo;
				}
				else
				{
					//Si no es el primero busco el nodo anterior al indice.
					nodoAnterior = getNode(this,indiceNodo-1);

					if(nodoAnterior != NULL)
					{
						//En el nuevo nodo.nextNode guardo el nextNode del nodo anterior
						nuevoNodo->pNextNode = nodoAnterior->pNextNode;

						//Y en el nodo anterior nexNode guardo el puntero que vale nuevoNodo
						nodoAnterior->pNextNode = nuevoNodo;
					}
				}

				//Incremento el size en uno.
				this->size++;

				retorno = 0;
			}
		}
		return retorno;
	}


	int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
	{
		return addNode(this,nodeIndex,pElement);
	}



	int ll_add(LinkedList* this, void* pElement)
	{
		int retorno = -1;

		if(this != NULL)
		{
			int resultadoAddNode;

			//Agrego un nodo con el indice igual al largo de la lista (y el elemento)
			resultadoAddNode = addNode(this,ll_len(this),pElement);

			if(resultadoAddNode == 0)
			{
				retorno = 0;
			}
		}
		return retorno;
	}


	void* ll_get(LinkedList* this, int index)
	{
		void* retorno = NULL;

		Node* nodoAux;

		if(this != NULL && index >= 0 && index < ll_len(this))
		{
			//En el pNodoAux guardo el nodo que me devolvio el getNode con el index
			nodoAux = getNode(this,index);

			//Si lo encontre
			if(nodoAux != NULL)
			{
				//Devuelvo el elemento
				retorno = nodoAux->pElement;
			}
		}
		return retorno;
	}



	int ll_set(LinkedList* this, int index,void* pElement)
	{
		int retorno = -1;
		Node *pNodeAux;

		if (this != NULL && index >= 0 && index < ll_len(this))
		{
			//Obtengo el puntero al Nodo con el indice ingresado en param
			pNodeAux = getNode(this, index);

			//Si existe el nodo en ese indice
			if (pNodeAux != NULL)
			{
				//Cambio el valor del puntero al Elemento del nodo encontrado por el nuevo.
				pNodeAux->pElement = pElement;
				retorno = 0;
			}
		}

		return retorno;
	}



	int ll_remove(LinkedList* this,int index)
	{
		int retorno = -1;

		Node* pNodoAux;
		Node* pNodeAnterior;

		if(this != NULL && index>= 0 && index < ll_len(this))
		{
			//Obtengo el nodo del cual pertenece al indice de parametros.
			pNodoAux = getNode(this,index);

			//Si existe
			if(pNodoAux != NULL)
			{

				//Si es el primero
				if(index == 0)
				{
					//En el pPrimerNodo guardo el 2do nodo (como primero).
					this->pFirstNode = pNodoAux->pNextNode;
				}
				else //Si no es el primero
				{
					//Guardo el nodo anterior (index-1)
					pNodeAnterior = getNode(this,index-1);
					if(pNodeAnterior != NULL)
					{
						pNodeAnterior->pNextNode = pNodoAux->pNextNode;
					}
				}

				//Libero la memoria del nodo que pertenecia al elemento.
				free(pNodoAux);

				//Decremento el size de la ll.
				this->size--;

				retorno = 0;
			}
		}
		return retorno;
	}



	int ll_clear(LinkedList* this)
	{
		int retorno = -1;

		if(this!=NULL)
		{
			int resultadoRemove;

			for(int i = 0 ; i < ll_len(this) ; i++)
			{
				//Remuevo el nodo y elemento del valor de I. (Hasta el largo de la ll)
				resultadoRemove = ll_remove(this,i);

				//Si el remove salio bien
				if(resultadoRemove == 0)
				{
					retorno = 0;
				}
				else
				{
					//Si en alguna ocasion sale mal, retorno error.
					retorno = -1;
					break;
				}
			}
		}
		return retorno;
	}



	int ll_deleteLinkedList(LinkedList* this)
	{
		int retorno = -1;

		if(this != NULL)
		{
			int resultadoClear;

			//Hago un clear de la linkedList.
			resultadoClear = ll_clear(this);

			//Si sale bien y ya libere la memoria de todos los nodos y elementos
			if(resultadoClear == 0)
			{
				//Libero finalmente la linkedlist.
				free(this);
				retorno = 0;
			}
		}
		return retorno;
	}


	int ll_indexOf(LinkedList* this, void* pElemento)
	{
		int retorno = -1;

		//Me creo un elemento auxiliar
		void* pElementAux;

		if(this != NULL)
		{
			for(int i = 0 ; i < ll_len(this) ; i++)
			{
				//En el elemento auxiliar guardo lo que obtenga del get en el indice I
				pElementAux = ll_get(this,i);

				//Si el pElemento del get coincide con el ingresado en param, corto el for y devuelvo el index.
				if(pElementAux == pElemento)
				{
					retorno = i;
					break;
				}
			}
		}
		return retorno;
	}


	int ll_isEmpty(LinkedList* this)
	{
		int retorno = -1;

		if(this != NULL)
		{
			//Simplemente obtengo el largo de la linkedlist.
			int longitudll;
			longitudll = ll_len(this);

			//Si su longitud es 0
			if(longitudll == 0)
			{
				//Lista vacia
				retorno = 1;
			}
			else if (longitudll > 0)
			{
				//Lista con 1 o mas elementos
				retorno = 0;
			}
		}
		return retorno;
	}


	int ll_push(LinkedList* this, int index, void* pElement)
	{
		int retorno = -1;

		if(this != NULL && index>=0 && index<=ll_len(this))
		{
			int resultadoAddNode;

			//LLamo a mi funcion add node y le ingreso el elemento y el indice
			resultadoAddNode = addNode(this,index,pElement);

			//Si sale bien el add
			if(resultadoAddNode == 0)
			{
				retorno = 0;
			}
		}
		return retorno;
	}



	void* ll_pop(LinkedList* this,int index)
	{
		void* retorno = NULL;
		void* pElementAux;

		if(this != NULL && index>=0 && index<ll_len(this))
		{
			//Primero verifico si existe el elemento de la posicion indicada y lo obtengo
			pElementAux = ll_get(this,index);

			if (pElementAux != NULL) //Si existe
			{
				//Lo remuevo
				int resultadoRemove;
				resultadoRemove = ll_remove(this,index);

				//Si el remove salio bien
				if(resultadoRemove == 0)
				{
					retorno = pElementAux;
				}
			}
		}
		return retorno;
	}


	int ll_contains(LinkedList* this, void* pElement)
	{
		int retorno = -1;

		if(this != NULL)
		{
			//Verifico el indice del elemento
			int indiceElemento;
			indiceElemento = ll_indexOf(this,pElement);

			//Si el valor que devuelve es mayor o igual a 0
			if(indiceElemento >= 0)
			{
				retorno = 1;
			}
			else
			{
				//Si no encontro ningun elemento retorna -1
				retorno = 0;
			}

		}
		return retorno;
	}


	int ll_containsAll(LinkedList* this, LinkedList* this2)
	{
		int retorno = -1;

		if(this != NULL && this2 != NULL)
		{
			void* pElemento;
			retorno = 1;

			//Recorro hasta el size de la ll-2
			for(int i = 0 ; i < ll_len(this2) ; i++)
			{
				//Obtengo cada elemento
				pElemento = ll_get(this2, i);

				//Pregunto si existe el elemento y pregunto si NO existe en la ll-1
				if(pElemento != NULL && ll_contains(this, pElemento) == 0)
				{
					retorno = 0;
					break;
				}

				//Hago lo mismo con el siguiente elemento de la lista.
			}
		}
		return retorno;
	}


	LinkedList* ll_subList(LinkedList* this,int from,int to)
	{
		//Creo el puntero donde guardo la nueva ll
		LinkedList* pNewll = NULL;

		if(this != NULL && from >= 0 && from <= ll_len(this) && to >= 0 && to <= ll_len(this) && from < to)
		{
			//Creo el un puntero a elemento que voy a usar para el traspaso.
			void* pElement;

			//Creo nueva ll
			pNewll = ll_newLinkedList();

			//Si se creo bien
			if (pNewll != NULL)
			{

				for(int i = from ; i < to ; i++)
				{
					//Obtengo el elemento de la primera ll
					pElement = ll_get(this, i);

					//Si existe
					if(pElement != NULL)
					{
						//Lo agrego a la nueva ll
						ll_add(pNewll,pElement);
					}

					//Hago ese "traspaso" con todos los elementos de la ll de param. (Desde from hasta to).
				}
			}
		}

		return pNewll;
	}



	LinkedList* ll_clone(LinkedList* this)
	{
		//Creo el puntero a la nueva ll clonada.
		LinkedList* pllClonada = NULL;

		if(this != NULL)
		{
			//Le otorgo el valor de sublist para que cree una linked list desde el indice 0 hasta el ultimo.
			pllClonada = ll_subList(this,0,ll_len(this));
		}

		return pllClonada;
	}


	int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
	{
		int retorno =-1;

		if (this != NULL && pFunc != NULL && (order == 0 || order == 1))
		{
			int flagEstadoDesordenado = 1;
			int criterio;

			void* pElement;
			void* pElement2;

			//Mientras que el flag de desorden este en 1
			while (flagEstadoDesordenado == 1)
			{
				//Flag desorden vale 0
				flagEstadoDesordenado = 0;

				//Recorro la ll hasta su ultimo elemento
				for (int i = 0; i < ll_len(this)- 1; i++)
				{
					//Obtengo el el elemento
					pElement = ll_get(this,i);

					//Obtengo el elemento siguiente
					pElement2 = ll_get(this,i+1);

					//Guardo mi resultado de la funcion criterio pasada
					criterio = pFunc(pElement,pElement2);

					//Si el orden es 1 (ascendente) y el criterio es 1 o El orden es 0 (descendente) y el criterio es -1
					if ( (order == 1 && criterio == 1) || (order == 0 && criterio == -1))
					{
						//Seteo el segundo elemento donde iba el primero y el primero donde iba el segundo, (los invierto).
						ll_set(this,i,pElement2);
						ll_set(this,i+1,pElement);

						//Pongo el flag en desordenado
						flagEstadoDesordenado = 1;
					}

					//Hago esto con cada elemento.
				}

				//Hago esto cada vez que se intercambie un elemento. Si ya no se intercambio ninguno, termina el sort.
			}
			retorno = 0;
		}
		return retorno;
	}

