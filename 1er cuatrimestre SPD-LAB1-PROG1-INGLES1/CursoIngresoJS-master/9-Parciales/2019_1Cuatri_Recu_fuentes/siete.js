function mostrar()
{
/*
Bienvenidos. 
Realizar el algoritmo que permita el ingreso de 10 bolsas de alimento por prompt,con los kilos (validar entre 0 y 500) ,
 sabor validar(carne vegetales pollo) e informar por alert: 
a) El promedio de los kilos totales. 
b) El mas liviano y su sabor 
c) La cantidad de sabor carne y el promedio de kilos de sabor carne 
*/

var primedio;
var sabor;
var kilos;
var kilosMenor;
var saborMenor;
var contadorCarne=0;
var acumuladorKilosCarne=0;
var acumuladorKilos=0;
var promedioKilos;
var promedioKilosCarne;
for(var i=0;i<10;i++)
{
sabor=prompt("ingrese un sabor").toLowerCase();
while(sabor<"a" || sabor>"z")
{
    sabor=prompt("Dato invalido.ingrese un sabor").toLowerCase();

}

kilos=parseInt(prompt("ingrese los kilos"));
while(isNaN(kilos) || kilos<0 || kilos>500)
{
    kilos=parseInt(prompt("Dato invalido. ingrese los kilos"));
}

sabor=prompt("ingres un sabor").toLowerCase();
while(sabor!="carne" && sabor!="vegetales" && sabor!="pollo")
{
    sabor=prompt("dato invalido. ingres un sabor").toLowerCase();

}
if (i==0 || kilos<kilosMenor)
{
    kilosMenor=kilos;
    saborMenor=sabor;
}
if(sabor=="carne")
{
    contadorCarne++;
    acumuladorKilosCarne++;
}

acumuladorKilos=acumuladorKilos+kilos;


}

promedioKilos=acumuladorKilos/i;
promedioKilosCarne=acumuladorKilosCarne/contadorCarne;

alert("El promedio de los kilos totales es "+promedioKilos);
alert("El mas liviano y su sabor es "+kilosMenor+" y "+saborMenor+" respectivamente");
alert("La cantidad de sabor carne y el promedio de kilos de sabor carne es "+contadorCarne+" y "+promedioKilosCarne);
}
