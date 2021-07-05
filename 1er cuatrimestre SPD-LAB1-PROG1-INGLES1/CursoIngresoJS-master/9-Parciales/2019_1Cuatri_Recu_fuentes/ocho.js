function mostrar()
{
/*
Realizar el algoritmo que permita iterar el ingreso de dos datos de un vehiculo, un color (rojo verde o amarillo) y 
un valor entre 0 y 10000 hasta que el usuario quiera e informar al terminar el ingreso por document.write: 
a) La cantida de rojos 
b) La cantidad de rojos con precio mayor a 5000 
c) La cantidad de vehiculos con precio inferior a 5000 
d) El promedio de todos los vehiculos ingresados. 
e) El mas caro y su color 
*/
var color;
var valor;
var respuesta;
var contadorRojo=0;
var contadorRojoMayor5000=0;
var contadorValorMenor5000=0;
var valorMayor;
var colorMayor;
var contador=0;
var acumuladorValor=0;
var promedio;
do{
    color=prompt("ingrese un color").toLowerCase();
    while(color!="rojo" && color!="amarillo" && color!="verde")
    {
        color=prompt("dato invalido. ingrese un color");

    }
    valor=parseInt(prompt("ingrese un valor"))
    while(isNaN(valor || valor<0 || valor>10000))
    {
        valor=parseInt(prompt("Dato invalido. ingrese un valor"))

    }

    if(color=="rojo")
    {
        contadorRojo++;
    }
    if(color=="rojo" && valor>5000)
    {
        contadorRojoMayor5000++;
    }
    if(valor<5000)
    {
        contadorValorMenor5000++;
    }
    if(contador==0 || valorMayor<valor)
    {
        valorMayor=valor;
        colorMayor=color;
    }
    contador++;
    acumuladorValor=acumuladorValor+valor;

    respuesta=prompt("si quiere ingresar mas datos escriba 's");
}while(respuesta=="s");
promedio=acumuladorValor/contador;

document.write("La cantidad de rojos es "+contadorRojo);
document.write("</br>La cantidad de rojos con precio mayor a 5000 es "+contadorRojoMayor5000);
document.write("</br>La cantidad de vehiculos con precio inferior a 5000 es "+contadorValorMenor5000);
document.write("</br> El promedio de todos los vehiculos ingresados es "+promedio);
document.write("</br>El mas caro y su color "+valorMayor+" y su color es "+colorMayor);
}
