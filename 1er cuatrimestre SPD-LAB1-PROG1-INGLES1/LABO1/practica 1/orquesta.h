#define TOrquesta 5
typedef struct
{
   char nombre[20];
    char lugar[20];
    int tipo;
    int id;
    int estado;
} eOrquesta;
void hardcodearOrquestas(eOrquesta lista[]);
void mostrarOrquesta(eOrquesta lista[],int tam);
void mostrarUnaOrquesta(eOrquesta lista);
int buscarLibre(eOrquesta lista[],int tam);
/*eOrquesta crearOrquesta(void);*/
int cargarUnaOrquesta(eOrquesta lista[],int tam);
void inicializar(eOrquesta lista[],int tam);
void guardarOrquesta(eOrquesta lista[], char nombre[], char lugar[], int tipo, int id, int indice,int estado);
int dameMayorID (eOrquesta lista[],int tam);
