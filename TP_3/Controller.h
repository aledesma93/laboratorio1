

	int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
	int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
	int controller_addEmployee(LinkedList* pArrayListEmployee, int valorMaximoExistenteID);
	int controller_editEmployee(LinkedList* pArrayListEmployee);
	int controller_removeEmployee(LinkedList* pArrayListEmployee);
	int controller_ListEmployee(LinkedList* pArrayListEmployee);
	int controller_sortEmployee(LinkedList* pArrayListEmployee);
	int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
	int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);
	int controller_findReplaceMaxId (LinkedList* pArrayListEmployee, int* idValorMinimoRecibido); //Se usa antes de llamar a cada opcion del menu.
	int controller_finalActions (LinkedList* pArrayListEmployee); //Se usa en Opcion 10.
