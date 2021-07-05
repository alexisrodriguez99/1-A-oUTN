function mostrar()
{
var marca;
var peso;
var temperatura;
var respuesta;
var contadorTemp=0;
var pesoMax;
var pesoMin;
var marcaMax;
var flag=0;
var contadorT0=0;
var promedio;
var acumuladorPeso=0;
var contador=0;
do{

marca=prompt("ingrese una marca");
peso=parseInt(prompt("ingrese un peso(1-100)"));
while(isNaN(peso) || peso>100 || peso<1)
{
    peso=parseInt(prompt("peso invalido. Ingrese un peso(1-100)"));
}
temperatura=parseInt(prompt("ingrese una temperatura (-30 y 30)"));
while(isNaN(temperatura || temperatura>30 || temperatura<-30))
{
    temperatura=parseInt(prompt("temperatura invalida. Ingrese una temperatura (-30 y 30)"));

}
if(temperatura%2==0)
{
    contadorTemp++;
}
if(flag==0 || peso<pesoMax)
{
    pesoMax=peso;
    marcaMax=marca;
}
if(flag==0 || pero<pesoMin)
{
    pesoMin=peso;
    flag=1;
}
if(temperatura>0)
{
    contadorT0++;
}
acumuladorPeso=acumuladorPeso+peso;
contador++;

respuesta=prompt("escriba 'si' para ingresar mas datos");    
}while(respuesta=="si");
promedio=acumuladorPeso/contador
document.write("la cantidad de temperaturas pares son "+contadorTemp);
document.write("la marca del producto mas peso es "+marcaMax+" y su peso es de "+pesoMax);
document.write("la cantidad de productos que se conservan a menos 0 son "+contadorT0);
document.write("el promedio del peso de todos los productos es de "+promedio);
document.write("peso maximo "+pesoMax+" peso minimo "+pesoMin);

}
/*
var marca;
var peso;
var temperatura;
var respuesta;
var contPar=0;
var pesoMayor;
var contador=0;
var marcaMayor;
var temperaturaNeg=0;
var sumaPeso=0;
var pesoMenor;

do
{
marca=prompt("ingrese una marca");
peso=parseInt(prompt("ingrese el peso de 1 a 100"));
while(isNaN(peso) || peso<1 || peso>100)
{
    peso=parseInt(prompt("Peso incorrecto. Ingrese el peso de 1 a 100"));
}

if(contador==0 || peso>pesoMayor)
{
    pesoMayor=peso;
    marcaMayor=marca;
}
if(contador==0 || peso<pesoMenor)
{
    pesoMenor=peso;
}

temperatura=parseInt(prompt("Ingrese una temperatura entre -30 y 30"));
while(isNaN(temperatura) || temperatura<-30 || temperatura>30)
{
    temperatura=parseInt(prompt("Esa temperatura no es valida. Ingrese una  temperatura entre -30 y 30"));
}
if(temperatura%2==0)
{
    contPar++
}
if(temperatura>0)
{
    temperaturaNeg++
}

contador=contador+1
sumaPeso=sumaPeso+peso;
respuesta=prompt("Si desea continuar escriba 'si'");
}while(respuesta=="si");


document.write("a) la cantidad de temperatura pares es de "+contPar)
document.write("</br>b) la marca del producto mas pesado es "+marcaMayor+" y su peso es "+pesoMayor);
document.write("</br>c) la cantidad de productos que se conservan a menos de 0 grados son "+temperaturaNeg);
document.write("</br>d) el promedio del peso de todos los productos es "+sumaPeso/contador);
document.write("</br>f) el peso maximo y minimo son "+pesoMayor+",   "+pesoMenor+" respectivamente")

*/

/*
function mostrar() {
    var marca;
    var peso;
    var temperatura;
    var contadorTPar = 0;
    var marcaPesada;
    var mayorPeso;
    var contadorMenor0 = 0;
    var acumuladorPeso = 0;
    var promedioPeso;
    var contador = 0;
    var menorPeso;
    var seguir;
    var flag = 0;

    do {
        marca = prompt("Ingrese marca: ");
        peso = parseInt(prompt("Ingrese peso (1-100): "));
        while (peso < 1 || peso > 100 || isNaN(peso)) {
            peso = parseInt(prompt("Dato invalido. Ingrese peso (1-100): "));
        }
        temperatura = parseInt(prompt("Ingrese una temperatura entre -30 y 30: "));
        while (temperatura < -30 || temperatura > 30 || isNaN(temperatura)) {
            temperatura = parseInt(prompt("Dato invalido. Ingrese una temperatura entre -30 y 30: "));
        }

        if (temperatura % 2 == 0) {
            contadorTPar++;
        }

        if (peso > mayorPeso || flag == 0) {
            mayorPeso = peso;
            marcaPesada = marca;
        }
        if (peso < menorPeso || flag == 0) {
            menorPeso = peso;
            flag = 1;
        }

        if (temperatura < 0) {
            contadorMenor0++;
        }

        acumuladorPeso = acumuladorPeso + peso;
        contador++;

        seguir = prompt("Quiere continuar?: ");
    } while (seguir == 's');

    promedioPeso = acumuladorPeso / contador;


    document.write("a) La cantidad de temperaturas pares: " + contadorTPar + "</br>");
    document.write("b) La marca del producto más pesado: " + marcaPesada + "</br>");
    document.write("c) La cantidad de productos que se conservan a menos de 0 grados: " + contadorMenor0 + "</br>");
    document.write("d) El promedio del peso de todos los productos: " + promedioPeso + "</br>");
    document.write("e) Peso máximo: " + mayorPeso + " Peso mínimo: " + menorPeso + "</br>");

}
*/