typedef struct
{
    int idUsuario;
    char nick[50];
    int popularidad;

}Usuario;
Usuario* usuario_new();

Usuario* usuario_newParametros(char* idUsuario,char* nick,char* popularidad);
void usuario_delete(Usuario* this);



int usuario_setIdUsuario(Usuario* this,int idUsuario);
int usuario_getIdUsuario(Usuario* this,int* idUsuario);

int usuario_setNick(Usuario* this,char* nick);
int usuario_getNick(Usuario* this,char* nick);

int usuario_setPopularidad(Usuario* this,int popularidad);
int usuario_getPopularidad(Usuario* this,int* popularidad);

void mostrarUsuario(Usuario* usuario);
int buscarUsuarioId(LinkedList* listaUsuario,int id);
