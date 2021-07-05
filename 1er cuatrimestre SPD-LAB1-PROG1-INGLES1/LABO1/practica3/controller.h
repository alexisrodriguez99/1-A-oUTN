int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{

    FILE* pFile;
    int vacio;
    int retorno=0;
    pFile=fopen(path,"r");
    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {
        vacio=ll_isEmpty(pArrayListEmployee);
        if(vacio==1)
        {
            retorno=parser_EmployeeFromText(pFile,pArrayListEmployee);
        }

    }
    fclose(pFile);
    return retorno;
}
