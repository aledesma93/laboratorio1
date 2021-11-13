
	#ifndef employee_H_INCLUDED
	#define employee_H_INCLUDED

	#define CHARACTERS_LEN 128

	//----ESTRUCTURA EMPLOYEE---------

	typedef struct
	{
		int id;
		char nombre[128];
		int horasTrabajadas;
		int sueldo;
	}Employee;

	//--------------------------------


	Employee* employee_new();
	Employee* employee_newParametros (char* nombre, int idEmpleado, int horasTrabajadas, int sueldo);
	void employee_delete(Employee* this);

	//------------------------------SETTER Y GETTERS-----------------------------------------------//


	int employee_setAllTxt(Employee* this, char* id, char* nombre, char* horasTrabajadas, char* sueldo);
	int employee_setAll(Employee* this, int id, char* nombre, int horasTrabajadas, int sueldo);
	int employee_getAll(Employee* this, int* id, char* nombre, int* horasTrabajadas, int* sueldo);
	int employee_setId(Employee* this,int id);
	int employee_setIdTxt(Employee* this, char* id);
	int employee_getId(Employee* this,int* id);
	int employee_setNombre(Employee* this,char* nombre);
	int employee_getNombre(Employee* this,char* nombre);
	int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
	int employee_setHorasTrabajadasTxt(Employee* this, char* horasTrabajadas);
	int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);
	int employee_setSueldo(Employee* this,int sueldo);
	int employee_setSueldoTxt(Employee* this, char* sueldo);
	int employee_getSueldo(Employee* this,int* sueldo);
	int printEmployee (Employee* this);
	int getAllFieldsFromConsoleValidated (char* nombreValidado, int* horasTrabajadasValidadas, int* sueldo);
	int employeeFuncionCriterio (void* item1 ,void* item2);

	#endif // employee_H_INCLUDED
