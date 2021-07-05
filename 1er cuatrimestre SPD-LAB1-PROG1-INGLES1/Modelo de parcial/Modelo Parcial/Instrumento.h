typedef struct
{
    int IDinstrumento;
    char nombreInstrumento[21];
    int tipoInstrumento;
    int estado;
}eInstrumento;

void hardcodearInstrumentos(eInstrumento lista[]);

void listarInstrumentos(eInstrumento lista[], int tam);
void mostrarInstrumentos(eInstrumento Instrumentos);

int inicializarInstrumento(eInstrumento[], int tam);
int buscarInstrumentoLibre(eInstrumento[], int tam);
int agregarInstrumento(eInstrumento[], int tam, int*);
int cargarInstrumento(eInstrumento*, int*);
