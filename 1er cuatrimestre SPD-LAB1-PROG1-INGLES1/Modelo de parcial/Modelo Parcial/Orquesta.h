typedef struct
{
    int IDorquesta;
    char nombreOrquesta[21];
    char lugarOrquesta[21];
    int tipoOrquesta;
    int estado;

}eOrquesta;

void hardcodearOrquestas(eOrquesta[]);

void mostrarOrquesta(eOrquesta);
void listarOrquesta(eOrquesta[], int tam);

int inicializarOrquesta(eOrquesta[], int tam);
int buscarOrquestaLibre(eOrquesta[], int tam);
int agregarOrquesta(eOrquesta[], int tam, int*);
int cargarOrquesta(eOrquesta*, int*);
