
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "libro.h"
#include "editorial.h"
#include "parser.h"
#include "validaciones.h"


// EL CONTROLLER SOLO ABRE Y CIERRA CON LO Q TIENE Q TRABAJAR PARSER
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_LibroLoadFromText(char* path , LinkedList* pArrayList)
{
	FILE* pArchivo;
	int retorno = -1;

	if(path != NULL && pArrayList != NULL)
	{
		pArchivo = fopen(path,"r");
		if(pArchivo != NULL)
		{
			parser_LibrofromText(pArchivo, pArrayList);
			fclose(pArchivo);
			retorno = 1;
			printf("el parser funciono \n");
		}
		printf("no es nulo \n");
	}
	printf("\nla lista mide: %d",ll_len(pArrayList));
    return retorno;
}

int controller_EditorialLoadFromText(char* path , LinkedList* pArrayList)
{
	FILE* pArchivo;
	int retorno = -1;

	if(path != NULL && pArrayList != NULL)
	{
		pArchivo = fopen(path,"r");
		if(pArchivo != NULL)
		{
			parser_EditorialfromText(pArchivo, pArrayList);
			fclose(pArchivo);
			retorno = 1;
			printf("el parser funciono \n");
		}
		printf("no es nulo \n");
	}
	printf("\n La lista mide: %d",ll_len(pArrayList));
    return retorno;
}



/// brief Listar empleados
///  \param path char*
/// \param pArrayListEmployee LinkedList*
/// \return int
/// */

int controller_ListLibro(LinkedList* thisLibro ,LinkedList* thisEditorial)
{
	int retorno = -1;
	eLibro* pLibro;
	int len;

	len= ll_len(thisLibro);
	if(thisLibro != NULL)
	{
		for(int i=0; i< len;i++)
		{
			pLibro = (eLibro*)ll_get(thisLibro,i);
			MostrarUnLibro(pLibro,thisEditorial);
			retorno = 1;
		}
	}
	return retorno;
}


int controller_ordenarLibrosPorAutor(LinkedList* pListaLibros)
{
    int len;
    int retornoSort;
    int retorno = 0;
    len = ll_len(pListaLibros);

    if(len > 1)
    {
        puts("\nSe esta ordenando la lista, esto puede tardar unos segundos...");
        retornoSort = ll_sort(pListaLibros, libro_compararPorAutor, 1);
        if(retornoSort == 0)
        {
            puts("\nLista ordenada con exito.");
            retorno = 1;
        }
        else
        {
            puts("\nHubo un error al tratar de ordenar la lista.");
        }
    }
    else
    {
        puts("\nNo hay libros suficientes en la lista para efectuar el ordenamiento.");
    }

    return retorno;
}

int filtrarMinotauro(void* unLibro)
{
    int retorno = 0;
    eLibro* auxLibro;
    int auxId;

    auxLibro= (eLibro*) unLibro;

    eLibro_getIdEditorial(auxLibro, &auxId);

    if (auxId == 3)
    {
    	retorno = 1;
    }

    return retorno;
}
int controller_saveAsTextMinotauro(char* path , LinkedList* listaLibros)
{
	FILE* pArchivo;
	eLibro* pLibro;
	int retorno;
	int len;
	int idAux;
	char tituloAux[50];
	char autorAux[50];
	int precioAux;
	LinkedList* listaMinotauro;
	retorno = 0;

	if(path != NULL && listaLibros != NULL &&  !ll_isEmpty(listaLibros))
	{
		listaMinotauro = ll_filter(listaLibros, filtrarMinotauro);

		len = ll_len(listaMinotauro);
		if(listaMinotauro != NULL)
		{
			pArchivo = fopen(path,"w");
			fprintf(pArchivo,"Id Libro,Titulo,Autor,Precio\n");
			if(pArchivo != NULL)
			{
				for(int i = 0; i<len; i++)
				{
					pLibro = (eLibro*)ll_get(listaMinotauro,i);


					if(!eLibro_getId(pLibro, &idAux) && !eLibro_getTitulo(pLibro, tituloAux)
						&& !eLibro_getAutor(pLibro, autorAux) && !eLibro_getPrecio(pLibro, &precioAux))
					{
						fprintf(pArchivo, "%d, %s, %s, %d\n", idAux, tituloAux, autorAux, precioAux);
						retorno = 1;
					}
				}
				fclose(pArchivo);
			}

		}
	}

	return retorno;
}
/*
int controller_aplicarDescuentos(LinkedList* listaLibros, LinkedList* listaEditorial)
{
    int retorno;
    int lenL;
    int lenE;

    lenL = ll_len(listaLibros);
    lenE = ll_len(listaEditorial);

    if(lenL > 0 && lenE > 0)
    {
        puts("\nAplicando descuentos, esto puede tardar unos minutos...");

        retorno = ll_map(listaLibros, listaEditorial, controller_validarDescuento);

        if(retorno == 1)
        {
            puts("\nLos descuentos fueron aplicados con exito.");
        }
        else
        {
            puts("\nNo se pudo aplicar ningun descuento.");
        }
    }
    else
    {
        puts("\nError, no hay libros cargados en la lista para aplicar descuentos.");
    }



    return retorno;
}

int controller_validarDescuento(LinkedList* listaEditorial, void* l1)
{
    int retorno = 0;
    int retornoCmp;
    eLibro* aux;
    char descEdit[125];
    float precio;

    aux = (eLibro*) l1;

    controller_obtenerEditorial(l1, listaEditorial, descEdit);
    eLibro_getPrecio(aux, &precio);

    retornoCmp = strcmp(descEdit, "Planeta");

    if(retornoCmp == 0)
    {
        if(precio >= 300)
        {
            retorno = 1;
        }
    }

    retornoCmp = strcmp(descEdit, "SIGLO XXI EDITORES");

    if(retornoCmp == 0)
    {

        if(precio <= 200)
        {
            retorno = -1;
        }
    }

    return retorno;
}

int controller_guardarMapeado(char* path, LinkedList* listaLibros, LinkedList* listaEditorial)
{
    FILE* pFile;
    int retorno = 0;
    int lenL;
    int lenE;
    int i;
    int id;
    char titulo[125];
    char autor[125];
    float precio;
    char descEdit[125];
    eLibro* aux;

    pFile = fopen(path, "w");

    lenL = ll_len(listaLibros);
    lenE = ll_len(listaEditorial);

    if(lenL > 0 && lenE > 0)
    {
        if(pFile != NULL)
        {
            for(i=0; i<lenL; i++)
            {
                aux = (eLibro*) ll_get(listaLibros, i);
                if(aux != NULL)
                {
                    eLibro_getId(aux, &id);
                    eLibro_getTitulo(aux, titulo);
                    eLibro_getAutor(aux, autor);
                    eLibro_getPrecio(aux, &precio);
                    controller_obtenerEditorial(aux, listaEditorial, descEdit);
                    fprintf(pFile, "%d,%s,%s,%.2f,%s\n",id, titulo, autor, precio, descEdit);
                    retorno = 1;
                }
            }

            puts("\nDatos guardados correctamente en el archivo 'mapeado.csv'");
        }
        else
        {
            puts("\nNo se encontro el archivo 'mapeado.csv'.");
        }
    }
    else
    {
        puts("\nNo hay libros cargados para guardar.");
    }

    return retorno;
}
int controller_obtenerEditorial(eLibro* miLibro, LinkedList* listaEditorial, char* descEdit)
{
    int retorno = 0;
    int i;
    int lenE;
    int idEL; //ID DE EDITORIAL DEL LIBRO
    int idE; // ID DE EDITORIAL PARA LA LISTA DE EDITORIALES
    eEditorial* auxE;

    lenE = ll_len(listaEditorial);

    if(miLibro != NULL && listaEditorial != NULL)
    {

    	eLibro_getIdEditorial(miLibro, &idEL);
        for(i=0; i<lenE; i++)
        {
            auxE = ll_get(listaEditorial, i);
            editorial_getIdEditorial(auxE, &idE);
            if(idEL == idE)
            {
            	editorial_getNombre(auxE, descEdit);
                retorno = 1;
            }
        }
    }

    return retorno;
}
int controller_saveAsText(char* path, LinkedList* librosList)
	{
		int retorno = -1;

		if (path != NULL && librosList)
		{
			retorno = -3;
			FILE* filePuntero;

			filePuntero = fopen (path,"w");

			if (filePuntero != NULL)
			{
				int librosguardados = 0;
				printf("\nArchivo abierto correctamente.\n");

				//ACA EMPIEZA P
				eLibro* pLibro;

				int auxId;
				char auxNombre[20];
				int auxHorasTrabajadas;
				int auxSueldo;

				int resultadoObtencionValidacion;

				for (int i = 0 ; i < ll_len(librosList) ; i++)
				{

					pLibro = ll_get(librosList, i);

					if (pLibro != NULL)
					{

						resultadoObtencionValidacion = employee_getAll(pLibro,&auxId,auxNombre,&auxHorasTrabajadas,&auxSueldo);

						if (resultadoObtencionValidacion == 0)
						{
							fprintf (filePuntero,"%d,%s,%d,%d\n",auxId,auxNombre,auxHorasTrabajadas,auxSueldo);
							librosguardados++;
						}
					}
				}
				//ACA TERMINA P

				//Salga como salga el save en el parser, cierro el archivo.
				fclose(filePuntero);


				if (librosguardados > 0)
				{
					printf ("\nSe guardaron %d empleados.\n",librosguardados);
					retorno = 0;
				}
				else
				{
					printf ("\nNo se pudo escribir ningun empleado.\n");
					retorno = -4;
				}

			}
			else
			{
				retorno = -2;
				printf ("\nError en la apertura del archivo.\n");
			}
		}

		return retorno;
	}
int libros_getAll(eLibro* this, int* id, char* titulo, char* autor,int* precio, int* idEditorial)
{
	int retorno = -1;

	if (this != NULL && id != NULL && titulo != NULL && autor != NULL && precio != NULL)
	{
		retorno = -2;

		int resultadoGetId;
		int resultadoGetNombre;
		int resultadoGetHoras;
		int resultadoGetSueldo;

		resultadoGetId = employee_getId(this,id);
		resultadoGetNombre = employee_getNombre(this,nombre);
		resultadoGetHoras = employee_getHorasTrabajadas(this,horasTrabajadas);
		resultadoGetSueldo = employee_getSueldo(this,sueldo);

		if (resultadoGetId == 0 && resultadoGetNombre == 0 && resultadoGetHoras == 0 && resultadoGetSueldo == 0)
		{
			retorno = 0;
		}
}

	return retorno;
}


int filtrarListaMinotauro(LinkedList* lista)
{
    int retorno=0;
    LinkedList* listaFiltrada = ll_newLinkedList();

    listaFiltrada=ll_filter(lista,filtrarMinotauro);
            if(listaFiltrada!=NULL)
            {
                guardarArchivo(listaFiltrada,"listaMinotauro.csv");
                retorno=1;
            }

            puts("\nSe hagenerado un nuevo archivo con la lista filtrada.");
    return retorno;
}

int filtrarPlaneta(LinkedList* lista)
{
	int retorno=0;
	    LinkedList* listaFiltrada = ll_newLinkedList();

	    listaFiltrada=ll_filter(lista,filtrarMinotauro);
	            if(listaFiltrada!=NULL)
	            {
	                guardarArchivo(listaFiltrada,"listaMinotauro.csv");
	                retorno=1;
	            }

	            puts("\nSe ha generado un nuevo archivo con la lista filtrada.");
	    return retorno;
}
int filtrarEditorial(LinkedList* lista)
{
    int retorno=0;
    LinkedList* listaFiltrada = ll_newLinkedList();
    int tipo;

    if(lista!=NULL)
    {
        printf("1. Planeta\n");
        printf("2. Siglo xxi editores\n");
        printf("3. Pearson\n");
        printf("4. Minotauro\n");
        printf("4. Salamandra\n");
        printf("4. Penguin Books\n");

        utn_getEntero(&tipo,20,"por que editorial desea filtrar? ","Error. Esa editorial no existe: ",1,4);

        switch(tipo)
        {
        case 1:
            listaFiltrada=ll_filter(lista,filtrarMinotauro);
            if(listaFiltrada!=NULL)
            {
                guardarArchivo(listaFiltrada,"filtradaPlaneta.csv");
                retorno=1;
            }
            break;
        case 2:
            listaFiltrada=ll_filter(lista,filtrarMinotauro);
            if(listaFiltrada!=NULL)
            {
                guardarArchivo(listaFiltrada,"filtradaPlaneta.csv");
                retorno=1;
            }
            break;
        case 3:
            listaFiltrada=ll_filter(lista,filtrarMinotauro);
            if(listaFiltrada!=NULL)
            {
                guardarArchivo(listaFiltrada,"filtradaPlaneta.csv");
                retorno=1;
            }
            break;
        case 4:
            listaFiltrada=ll_filter(lista,filtrarMinotauro);
            if(listaFiltrada!=NULL)
            {
                guardarArchivo(listaFiltrada,"filtradaPlaneta.csv");
                retorno=1;
            }
            break;
        }
    }

    return retorno;
}
*/
