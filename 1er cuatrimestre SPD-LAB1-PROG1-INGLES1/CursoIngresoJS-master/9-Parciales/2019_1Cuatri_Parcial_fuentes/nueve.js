function mostrar()
{
    /*
    Enunciado:
Bienvenidos. 
Realizar el algoritmo que permita ingresar el nombre de un país, cantidad de habitantes en millones entre 1 y 7000 (validar) 
la temperaruta mínima que se registra en su territorio(entre -50 y 50) hasta que el usuario quiera e informar al terminar
 el ingreso por document.write: 
a) La cantidad de temperaturas pares. 
b) El nombre del pais con menos habitantes 
c) la cantidad de paises que superan los 40 grados. 
d) el promedio de habitantes entre los paises ingresados 
f) la temperatura mínima ingresada, y nombre del pais que registro esa temperatura.
    */
var pais;
var cantidadHabitantes;
var temperatura;
var respuesta;
var temperarutaPar=0;
var cantidadHabitantesMin;
var paisMenorHabitantes;
var contador=0;
var ContadorPaisMayor40=0;
var acumuladorHabitantes=0; 
var promedio;
var temperarutaMin;
var paisMenorTemperatura;
do{

    pais=prompt("ingrese un pais").toLowerCase();
    while(pais<"a" || pais>"z")
    {
        pais=prompt("Dato invalido. ingrese un pais");

    }
   
    cantidadHabitantes=parseInt(prompt("Ingrese la cantidad de habitantes"));
    while(isNaN(cantidadHabitantes) || cantidadHabitantes<1 || cantidadHabitantes>7000)
    {
        cantidadHabitantes=parseInt(prompt("Dato invalido. Ingrese la cantidad de habitantes"));

    }
    
    temperatura=parseInt(prompt("ingrese una temperatura"));
    while((isNaN(temperatura) || temperatura<-50 || temperatura>50))
    {
        temperatura=parseInt(prompt("Dato invalido. ingrese una temperatura"));

    }
   
    if(temperatura%2==0)
    {
        temperarutaPar++;
    }
    
    if(contador==0 || cantidadHabitantes<cantidadHabitantesMin)
    {
        cantidadHabitantesMin=cantidadHabitantes;
        paisMenorHabitantes=pais;
    }
   
    if(temperatura>40)
    {
        ContadorPaisMayor40++;
    }

    if(temperatura<temperarutaMin || contador==0)
    {
        temperarutaMin=temperatura;
        paisMenorTemperatura=pais;
    }

    contador++;
    acumuladorHabitantes=acumuladorHabitantes+cantidadHabitantes;
    respuesta=prompt("si quiere ingresar mas datos escriba 's'")
}while(respuesta=="s");

promedio=acumuladorHabitantes/contador;

document.write("L cantidad de temeperaturas pares es "+temperarutaPar);
document.write("</br>El nombre del pais con menos habitantes es "+paisMenorHabitantes+" y su cantidad de habitantes es "+cantidadHabitantesMin);
document.write("</br>La cantidad de paises que superan los 40 grados es "+ContadorPaisMayor40);
document.write("</br>El promedio de habitantes entre los paises ingresados es"+promedio);
document.write("</br>La temperatura mini ingresada es de "+temperarutaMin+" y el nombre del pais es "+paisMenorTemperatura);

}
