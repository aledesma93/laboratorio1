
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>

	#include "Employee.h"
	#include "utn.h"

	Employee* employee_new (void)
	{
		return (Employee*) malloc (sizeof(Employee));
	}



	Employee* employee_newParametros (char* nombre, int idEmpleado, int horasTrabajadas, int sueldo)
	{
		Employee* pEmpleado = NULL;

		if (nombre != NULL && idEmpleado > 0 && horasTrabajadas > 0 && sueldo > 0)
		{
			pEmpleado = employee_new();

			//Si se obtuvo la memoria requerida
			if (pEmpleado != NULL)
			{
				//Copiamos todos los valores recibidos en parametros a la direccion obtenida.
				strncpy (pEmpleado->nombre, nombre, CHARACTERS_LEN);
				pEmpleado->id = idEmpleado;
				pEmpleado->horasTrabajadas = horasTrabajadas;
				pEmpleado->sueldo = sueldo;
			}
			else
			{
				printf ("\nNo hay mas lugar para otro empleado.\n");
			}
		}

		return pEmpleado;
	}



	void employee_delete(Employee* this)
	{
		if (this != NULL)
		{
			free (this);
			this = NULL;
		}
	}


	//--------------------------------SETTER Y GETTERS-------------------------------


	int employee_setNombre(Employee* this, char* nombre)
	{
		int retorno = -1;

		if (this != NULL && nombre != NULL)
		{
			retorno = -2;
			int validacionNombre;
			validacionNombre = esNombreValido(nombre, CHARACTERS_LEN);

			if (validacionNombre == 0 )
			{
				strncpy (this->nombre, nombre, CHARACTERS_LEN);
				retorno = 0;
			}
		}
		return retorno;
	}



	int employee_setId(Employee* this, int id)
	{
		int retorno = -1;

		if (this != NULL && id > 0)
		{
			retorno = -2;
			int validacionId;

			validacionId = esIdValidoInt (id);

			if (validacionId == 0)
			{
				this->id = id;
				retorno = 0;
			}
		}
		return retorno;
	}


	int employee_setIdTxt(Employee* this, char* id)
	{
		int retorno = -1;

		if (this != NULL && id != NULL)
		{
			retorno = -2;
			int validacionId;

			validacionId = esIdValido (id, CHARACTERS_LEN);

			if (validacionId == 0)
			{
				int idNumerico;
				idNumerico = atoi (id);

				this->id = idNumerico;
				retorno = 0;
			}
		}
		return retorno;
	}



	int employee_getId (Employee* this, int* id)
	{
		int retorno = -1;

		if (this != NULL && id != NULL)
		{
			retorno = -2;

			int auxId;
			auxId = this->id;

			int resultadoValidacion;
			resultadoValidacion = esIdValidoInt (auxId);

			if (resultadoValidacion == 0)
			{
				*id = auxId;
				retorno = 0;
			}
		}

		return retorno;
	}


	int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas)
	{
		int retorno = -1;

		if (this != NULL && horasTrabajadas > 0)
		{
			retorno = -2;
			int validacionHorasTrabajadas;

			validacionHorasTrabajadas = esHoraTrabajadaValidaInt (horasTrabajadas);

			if (validacionHorasTrabajadas == 0)
			{
				this->horasTrabajadas = horasTrabajadas;
				retorno = 0;
			}
		}
		return retorno;
	}


	int employee_setHorasTrabajadasTxt(Employee* this, char* horasTrabajadas)
	{
		int retorno = -1;

		if (this != NULL && horasTrabajadas != NULL)
		{
			retorno = -2;
			int validacionHorasTrabajadas;

			validacionHorasTrabajadas = esHoraTrabajadaValida (horasTrabajadas, CHARACTERS_LEN);

			if (validacionHorasTrabajadas == 0)
			{
				int horasTrabajadasInt;
				horasTrabajadasInt = atoi (horasTrabajadas);

				this->horasTrabajadas = horasTrabajadasInt;
				retorno = 0;
			}
		}
		return retorno;
	}



	int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas)
	{
		int retorno = -1;

		if (this != NULL && horasTrabajadas != NULL)
		{
			retorno = -2;

			int auxHorasTrabajadas;
			auxHorasTrabajadas = this->horasTrabajadas;

			int resultadoValidacion;
			resultadoValidacion = esHoraTrabajadaValidaInt (auxHorasTrabajadas);

			if (resultadoValidacion == 0)
			{
				*horasTrabajadas = auxHorasTrabajadas;
				retorno = 0;
			}

		}

		return retorno;
	}


	int employee_setSueldo (Employee* this, int sueldo)
	{
		int retorno = -1;

		if (this != NULL && sueldo > 3)
		{
			retorno = -2;
			int validacionSueldo;

			validacionSueldo = esSueldoValidoInt (sueldo);

			if (validacionSueldo == 0)
			{
				this->sueldo = sueldo;
				retorno = 0;
			}
		}
		return retorno;
	}



	int employee_setSueldoTxt(Employee* this, char* sueldo)
	{
		int retorno = -1;

		if (this != NULL && sueldo != NULL)
		{
			retorno = -2;
			int validacionSueldo;

			validacionSueldo = esSueldoValido (sueldo, CHARACTERS_LEN);

			if (validacionSueldo == 0)
			{
				int sueldoInt;
				sueldoInt = atoi (sueldo);

				this->sueldo = sueldoInt;
				retorno = 0;
			}
		}
		return retorno;
	}



	int employee_getSueldo(Employee* this,int* sueldo)
	{
		int retorno = -1;

		if (this != NULL && sueldo != NULL)
		{
			retorno = -2;

			int auxSueldo;
			auxSueldo = this->sueldo;

			int validacionSueldo;
			validacionSueldo = esSueldoValidoInt (auxSueldo);

			if (validacionSueldo == 0)
			{
				*sueldo = auxSueldo;
				retorno = 0;
			}
		}

		return retorno;
	}



	int employee_getAll(Employee* this, int* id, char* nombre, int* horasTrabajadas, int* sueldo)
	{
		int retorno = -1;

		if (this != NULL && id != NULL && nombre != NULL && horasTrabajadas != NULL && sueldo != NULL)
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




	int employee_setAllTxt(Employee* this, char* id, char* nombre, char* horasTrabajadas, char* sueldo)
	{
		int retorno = -1;

		if (this != NULL && id != NULL && nombre != NULL && horasTrabajadas != NULL && sueldo != NULL)
		{
			retorno = -2;

			int resultadoSetterId;
			int resultadoSetterNombre;
			int resultadoSetterHorasTrabajadas;
			int resultadoSetterAuxSueldo;

			resultadoSetterId = employee_setIdTxt (this,id);
			resultadoSetterNombre = employee_setNombre (this,nombre);
			resultadoSetterHorasTrabajadas = employee_setHorasTrabajadasTxt (this,horasTrabajadas);
			resultadoSetterAuxSueldo = employee_setSueldoTxt(this, sueldo);

			if (resultadoSetterId == 0 && resultadoSetterNombre == 0 && resultadoSetterHorasTrabajadas == 0 && resultadoSetterAuxSueldo == 0)
			{
				//El seteo salio bien.
				retorno = 0;
			}
		}

		return retorno;
	}


	int employee_setAll(Employee* this, int id, char* nombre, int horasTrabajadas, int sueldo)
	{
		int retorno = -1;

		if (this != NULL && id > 0 && nombre != NULL && horasTrabajadas >= 0 && sueldo > 0)
		{
			retorno = -2;

			int resultadoSetterId;
			int resultadoSetterNombre;
			int resultadoSetterHorasTrabajadas;
			int resultadoSetterAuxSueldo;

			resultadoSetterId = employee_setId (this,id);
			resultadoSetterNombre = employee_setNombre (this,nombre);
			resultadoSetterHorasTrabajadas = employee_setHorasTrabajadas (this,horasTrabajadas);
			resultadoSetterAuxSueldo = employee_setSueldo (this, sueldo);

			if (resultadoSetterId == 0 && resultadoSetterNombre == 0 && resultadoSetterHorasTrabajadas == 0 && resultadoSetterAuxSueldo == 0)
			{
				//El seteo salio bien.
				retorno = 0;
			}
		}

		return retorno;
	}



	int employee_getNombre(Employee* this, char* nombre)
	{
		int retorno = -1;
		//int resultadoObtencionNombre;
		char auxNombre[CHARACTERS_LEN];

		if (this != NULL && nombre != NULL)
		{
			retorno = -2;

			//Lo obtengo y lo guardo en un auxiliar
			strncpy (auxNombre, this->nombre, CHARACTERS_LEN);

			//Lo valido
			if ( esNombreValido (auxNombre, CHARACTERS_LEN) == 0 )
			{
				// Si es nombre valido, lo devuelvo.
				retorno = 0;
				strncpy (nombre, auxNombre, CHARACTERS_LEN);
			}
		}

		return retorno;
	}



	int printEmployee (Employee* this)
	{
		int retorno = -1;

		if (this != NULL)
		{
			retorno = 0;
			printf ("(%d),(%s),(%d),(%d)\n", this->id, this->nombre, this->horasTrabajadas, this->sueldo);
		}

		return retorno;
	}



	int getAllFieldsFromConsoleValidated (char* pNombreValidado, int* pHorasTrabajadasValidadas, int* pSueldoValidado)
	{
		int retorno = -1;

		if (pNombreValidado != NULL && pHorasTrabajadasValidadas != NULL && pSueldoValidado != NULL)
		{
			retorno = -2;

			int resultadoObtencionNombre;
			int resultadoObtencionHorasTrabajadas;
			int resultadoObtencionSueldo;

			char auxNombre[CHARACTERS_LEN];
			char auxHorasTrabajadas[CHARACTERS_LEN];
			char auxSueldo[CHARACTERS_LEN];

			//Pido sueldo y horas en chars para no tener que hacer otro ISVALID de cada uno pero de INTS.
			resultadoObtencionNombre = utn_getNombre(auxNombre,CHARACTERS_LEN,"\nIngrese el nombre del empleado.\n","\nError en el ingreso del nombre.\n", 3);
			resultadoObtencionHorasTrabajadas = utn_getDni(auxHorasTrabajadas,CHARACTERS_LEN,"\nIngrese las horas trabajadas del empleado.\n","\nError en el ingreso de las horas trabajadas.\n", 3);
			resultadoObtencionSueldo = utn_getDni(auxSueldo,CHARACTERS_LEN,"\nIngrese el sueldo del empleado.\n","\nError en el ingreso del sueldo.\n", 3);

			//Si recibi algo medianamente coherente, puedo empezar la validacion.
			if (resultadoObtencionNombre == 0 && resultadoObtencionHorasTrabajadas == 0 && resultadoObtencionSueldo == 0)
			{
				retorno = -3;

				int resultadoValidacionNombre;
				int resultadoValidacionSueldo;
				int resultadoValidacionHorasTrabajadas;

				resultadoValidacionNombre = esNombreValido (auxNombre,CHARACTERS_LEN);
				resultadoValidacionSueldo = esSueldoValido (auxSueldo,CHARACTERS_LEN);
				resultadoValidacionHorasTrabajadas = esHoraTrabajadaValida (auxHorasTrabajadas, CHARACTERS_LEN);

				//Si todos los campos son validos. Los devuelvo a los punteros de parametros.
				if (resultadoValidacionNombre == 0 && resultadoValidacionSueldo == 0 && resultadoValidacionHorasTrabajadas == 0)
				{
					strncpy (pNombreValidado,auxNombre,CHARACTERS_LEN);

					int sueldoInt;
					sueldoInt = atoi (auxSueldo);
					*pSueldoValidado = sueldoInt;

					int horasTrabajadasInt;
					horasTrabajadasInt = atoi (auxHorasTrabajadas);
					*pHorasTrabajadasValidadas = horasTrabajadasInt;

					retorno = 0;
				}
			}

		}

		return retorno;
	}



	int employeeFuncionCriterio (void* item1 ,void* item2)
	{
		int retorno = 0;

		if (item1 != NULL && item2 != NULL)
		{
			//Convierto los punteros void a employee
			Employee* empleado1 = (Employee*) item1;
			Employee* empleado2 = (Employee*) item2;

			int employee1Id;
			int employee2Id;

			//Obtengo los valores Id de cada uno
			employee_getId (empleado1, &employee1Id);
			employee_getId (empleado2, &employee2Id);

			if (employee1Id > employee2Id)
			{
				retorno = 1;
			}
			else
			{
				retorno = -1;
			}
		}

		return retorno;
	}
