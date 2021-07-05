typedef struct
{
    int idMensaje;
    char mensaje[99999];
    int popularidad;
    int idUsuario;

}Post;
Post* post_new();
Post* post_newParametros(char* idMensaje,char* mensaje,char* popularidad,char* idUsuario);
void post_delete(Post* this);


int post_setIdMensaje(Post* this,int idMensaje);
int post_getIdMensaje(Post* this,int* idMensaje);

int post_setMensaje(Post* this,char* mensaje);
int post_getMensaje(Post* this,char* mensaje);

int post_setPopularidad(Post* this,int popularidad);
int post_getPopularidad(Post* this,int* popularidad);

int post_setIdUsuario(Post* this,int idUsuario);
int post_getIdUsuario(Post* this,int* idUsuario);
void mostrarPost(Post* post);
