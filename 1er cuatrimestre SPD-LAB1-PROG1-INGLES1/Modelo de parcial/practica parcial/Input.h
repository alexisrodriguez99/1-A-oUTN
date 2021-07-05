#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/** \brief Pregunta si se desea continuar con la operacion
 *
 * \return int 1 si se desea cancelar
                0 si se continua con la operacion
 *
 */
int cancelarOperacion(char mensaje[]);
int generarId(int);


int ingresarCaracter(char*,char mensaje[], char mensajeError[], int tam);
int esLetra(char*, char[]);

int ingresarNumero(int*, char[], char[], int, int);
int getInt(int*, char[]);
int esNumero(char[]);





int ingresarDecimal(float* ,char[], char[], int, int);
int getFloat(float*, char[]);
int esDecimal(char[]);





/** \brief Permite el ingreso de cadenas de letras o espacios solamente, llama a esLetra para validar
            Valida que la cadena tenga un largo determinado
            En caso de dato invalido, muestra error y pregunta si se desa seguir con la operacion (Funcion  CancelarOperacion)
 *
 * \param cadena[] char Puntero a cadena en la que se escribe el dato
 * \param mensaje[] char Mensaje que indica que dato se esta ingresando
 * \param mensajeError[] char Mensaje que se muestra en caso de error al ingresar el dato
 * \param tam int Tamaño maximo de caracteres que puede tener la cadena
 * \return int Si el ingreso fue valido, la cadena se carga con los datos y devuelve 0,
                Si se decidio cancelar la operacion devuelve 1, y la cadena no se carga con ningun dato
 *
 */
int getPalabra_Nombre(char cadena[],char mensaje[], char mensajeError[], int tam);
/** \brief Permite el ingreso de cadenas de letras o numeros solamente, llama a sonLetrasNumeros para validar
            Valida que la cadena tenga un largo determinado
            En caso de dato invalido, muestra error y pregunta si se desa seguir con la operacion (Funcion  CancelarOperacion)
 *
 * \param cadena[] char Puntero a cadena en la que se escribe el dato
 * \param mensaje[] char Mensaje que indica que dato se esta ingresando
 * \param mensajeError[] char Mensaje que se muestra en caso de error al ingresar el dato
 * \param tam int Tamaño maximo de caracteres que puede tener la cadena
 * \return int Si el ingreso fue valido, la cadena se carga con los datos y devuelve 0,
                Si se decidio cancelar la operacion devuelve 1, y la cadena no se carga con ningun dato
 *
 */
int getLetras_Numeros(char cadena[],char mensaje[], char mensajeError[], int tam);
/** \brief Permite el ingreso de cadenas de con formato de mail , llama a esMail para validar
            Valida que la cadena tenga un largo determinado
            En caso de dato invalido, muestra error y pregunta si se desa seguir con la operacion (Funcion  CancelarOperacion)
 *
 * \param cadena[] char Puntero a cadena en la que se escribe el dato
 * \param mensaje[] char Mensaje que indica que dato se esta ingresando
 * \param mensajeError[] char Mensaje que se muestra en caso de error al ingresar el dato
 * \param tam int Tamaño maximo de caracteres que puede tener la cadena
 * \return int Si el ingreso fue valido, la cadena se carga con los datos y devuelve 0,
                Si se decidio cancelar la operacion devuelve 1, y la cadena no se carga con ningun dato
 *
 */
int getMail(char cadena[],char mensaje[], char mensajeError[], int tam);
/** \brief Permite el ingreso de cadenas de numeros o simbolos como guiones, guiones bajos, llama a sonLetrasNumeros para validar
            Valida que la cadena tenga un largo determinado
            En caso de dato invalido, muestra error y pregunta si se desa seguir con la operacion (Funcion  CancelarOperacion)
 *
 * \param cadena[] char Puntero a cadena en la que se escribe el dato
 * \param mensaje[] char Mensaje que indica que dato se esta ingresando
 * \param mensajeError[] char Mensaje que se muestra en caso de error al ingresar el dato
 * \param tam int Tamaño maximo de caracteres que puede tener la cadena
 * \return int Si el ingreso fue valido, la cadena se carga con los datos y devuelve 0,
                Si se decidio cancelar la operacion devuelve 1, y la cadena no se carga con ningun dato
 *
 */
int getNumeros_Simbolos(char cadena[],char mensaje[], char mensajeError[], int tam);


/** \brief Ingresa una cadena en un auxiliar
 *
 * \param char[] auxiliar de carga
 * \param mensaje[] char mensaje con la info de la carga
 *
 */
void cargarString(char[], char mensaje[]);

/** \brief Funcion que es llamada por getString, valida que todos los caracteres sean letras o espacios
 *
 * \param char[] auxiliar de carga
     Mensaje que indica que dato se esta ingresando
 * \return int devuelve 1 si la carga fue valida, 0 si fue invalida
 *
 */
int sonLetras(char[], char[]);
/** \brief valida que todos los caracteres sean letras o numeros
 *
 * \param char[] auxiliar de carga
     Mensaje que indica que dato se esta ingresando
 * \return int devuelve 1 si la carga fue valida, 0 si fue invalida
 *
 */
int sonLetrasNumeros(char[], char[]);
/** \brief valida que la cadena respete el formato de mail
 *
 * \param char[] auxiliar de carga
     Mensaje que indica que dato se esta ingresando
 * \return int devuelve 1 si la carga fue valida, 0 si fue invalida
 *
 */
int esMail(char[], char[]);
/** \brief valida que todos los caracteres sean numeros o simbolos como guiones, guiones bajos, etc.
 *
 * \param char[] auxiliar de carga
    Mensaje que indica que dato se esta ingresando
 * \return int devuelve 1 si la carga fue valida, 0 si fue invalida
 *
 */
int esNumeroSigno(char[], char[]);
