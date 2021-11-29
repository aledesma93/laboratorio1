#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "libro.h"
#include "editorial.h"
#include "parser.h"


/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_LibrofromText(FILE* pFile , LinkedList* pListLibro)
{
	eLibro* pLibro;

	int retorno = -1;
	char auxId[11];
	char auxTitulo[50];
	char auxAutor[50];
	char auxPrecio[20];
	char editorialId[20]; //ID DE EDITORIAL DEL ESTA EN ESTRUCT LIBRO

	if(pFile != NULL && pListLibro != NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxTitulo,auxAutor,auxPrecio,editorialId);
		while(!feof(pFile)) //leer varias lineas de un archivo
		{
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxTitulo,auxAutor,auxPrecio,editorialId);

			pLibro = eLibro_newParametros(auxId,auxTitulo,auxAutor,auxPrecio,editorialId);

			if(pLibro != NULL)
			{
				ll_add(pListLibro, pLibro);
				retorno = 0;
			}
		}
	}
    return retorno;
}

int parser_EditorialfromText(FILE* pFile , LinkedList* pListEditorial)
{
	eEditorial* pEditorial;

	int retorno = -1;
	char auxIdEditorial[11];
	char nombreEditorial[50];


	if(pFile != NULL && pListEditorial != NULL)
	{
		fscanf(pFile,"%[^,],%[^\n]\n",auxIdEditorial,nombreEditorial);
		while(!feof(pFile)) //leer varias lineas de un archivo
		{
			fscanf(pFile,"%[^,],%[^\n]\n",auxIdEditorial,nombreEditorial);

			pEditorial = editorial_newParametros(auxIdEditorial,nombreEditorial);

			if(pEditorial != NULL)
			{
				ll_add(pListEditorial, pEditorial);
				retorno = 0;
			}
		}
	}
    return retorno;
}

void guardarArchivo(LinkedList* lista, char* archivo)
{
    FILE* f = fopen(archivo,"w");
    eEditorial* aux;
    int tam = ll_len(lista);

    fprintf(f,"idEditorial,nombre\n\n");

    if(lista!=NULL)
    {
        for(int i=0; i<tam; i++)
        {
            aux=ll_get(lista,i);
            if(aux!=NULL)
            {
                fprintf(f,"%d,%s\n",aux->idEditorial,aux->nombre);
            }
        }

        fclose(f);
    }
}


/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

/*int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	Employee* pEmpleado;
	int retorno;
	retorno = -1;

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		while(!feof(pFile)) //leer varias lineas de un archivo
		{
			pEmpleado = employee_new();
			if(pEmpleado != NULL)
			{
				if(fread(pEmpleado,sizeof(Employee),1,pFile) ==1)
				{
					ll_add(pArrayListEmployee, pEmpleado);
					retorno = 0;
				}

			}
		}
	}
    return retorno;
}*/



