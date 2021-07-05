function mostrar()
{
/*
Bienvenidos. 
Realizar el algoritmo que permita ingresar el nombre de un estudiante, la edad (validar) , el sexo (validar) y
 la nota del final (validar) 
hasta que el usuario quiera e informar al terminar el ingreso por document.write: 
a) La cantidad de varones aprobados 
b) El promedio de notas de los menores de edad 
c) El promedio de notas de los adolescentes. 
d) El promedio de notas de los mayores 
f) El promedio de notas por sexo masculino y femenino 
*/
var nombre;
var edad;
var sexo;
var nota;
var respuesta;
var contadorAprobado=0;
var contadorMenorEdad=0;
var acumuladorNotaMenorEdad=0;
var acumuladorNotaAdolescente=0;
var contadorAdolescente=0;
var acumuladorNotaMayorEdad=0;
var contadorMayorEdad=0;
var acumuladorM=0;
var contadorM=0;
var acumuladorF=0;
var contadorF=0;
var promedioMenorEdad;
var promedioAdolescente;
var promedioMayoredad;
var promedioM;
var promedioF;
do{

    nombre=prompt("ingrese un nombre").toLowerCase();
    while(nombre<"a" || nombre>"z")
    {
        nombre=prompt("Dato invalido. ingrese un nombre");
    }

    edad=parseInt(prompt("ingrese una edad"))
    while(isNaN(edad || edad<1))
    {
        edad=parseInt(prompt("Dato invalido. ingrese una edad"))

    }
    sexo=prompt("ingrese un sexo").toLowerCase();
    while(sexo!="f" && sexo!="m")
    {
        sexo=prompt("Dato invalido. ingrese un sexo").toLowerCase();

    }
    nota=parseInt(prompt("ingrese una nota"))
    while(isNaN(nota) || nota<1)
    {
        nota=parseInt(prompt("ingrese una nota"))

    }
    if(sexo=="m" && nota>=4)
    {
        contadorAprobado++;
    }
    if(edad>18 )
    {
        acumuladorNotaMenorEdad+acumuladorNotaMenorEdad+nota;
        contadorMenorEdad++;
    }
    if(edad>15)
    {
        contadorAdolescente++;
        acumuladorNotaAdolescente=acumuladorNotaAdolescente+nota;
    }
    if(edad>=18)
    {
        acumuladorNotaMayorEdad=acumuladorNotaMayorEdad+nota;
        contadorMayorEdad++;
    }
    respuesta=prompt("si quiere seguir ingresando escriba 's'")
    if(sexo=="f")
    {
        acumuladorF=acumuladorF+nota
        contadorF++;
    }
    else
    {
        acumuladorM=acumuladorM+nota;
        contadorM++;
    }
}while(respuesta=="s");
if(contadorF==0)
{
    promedioF=0;
}
else
{
    promedioF=acumuladorF/contadorF;
}
if(contadorM==0)
{
    promedioM=0;
}
else
{
    promedioM=acumuladorM/contadorM;
}
if(contadorMenorEdad==0)
{
    promedioMenorEdad=0;
}
else
{
    promedioMenorEdad=acumuladorNotaMenorEdad/contadorMenorEdad;
}
if(contadorAdolescente==0)
{
    promedioAdolescente=0;
}
else
{
    promedioAdolescente=acumuladorNotaAdolescente/contadorAdolescente;
}
if(contadorMayorEdad==0)
{
    promedioMayoredad=0;
}
else
{
    promedioMayoredad=acumuladorNotaMayorEdad/contadorMayorEdad);
}


document.write("La cantidad de varones aprobados es"+contadorAprobado);
document.write("</br>El promedio de notas de los menores de edad es"+promedioMenorEdad);
document.write("</br>El promedio de notas de los adolescentes es"+promedioAdolescente);
document.write("</br>El promedio de notas de los mayores es "+promedioMayoredad);
document.write("</br>El promedio de notas por sexo masculino es "+promedioM+" y femenino es "+promedioF);

}
