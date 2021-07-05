function mostrar()
{
var letra;
var numero;
var respuesta;
var contadorPar=0;
var contadorImpar=0;
var contadorCero=0
var promedio;
var acumuladorPositivo=0;
var contadorPositivo=0;
var acumuladorNegativos=0;
var contadorNegativos=0;
var flag=0;
var numeroMax;
var numeroMin; 
var letraMax;
var letraMin;
do{
letra=prompt("Ingrese una letra").toLowerCase();
while(!(letra>="a" && letra<="z"))
{
    letraMax=prompt("letra invalida. Ingrese una letra")
}
numero=parseInt(prompt("Ingrese un numero (-100 a 100)"));
while(isNaN(numero || numero<-100 || numero>100))
{
    numero=parseInt(prompt("numero invalido. Ingrese un numero"));
}
if(numero%2==0)
{
    contadorPar++;
}
else 
{
    contadorImpar++;
}
if(numero==0)
{
    contadorCero++;
}
if(numero>=0)
{
acumuladorPositivo=acumuladorPositivo+numero;
contadorPositivo++;
}
else
{
    acumuladorNegativos=acumuladorNegativos+numero;
    contadorNegativos++;
}
if(flag==0 || numero>numeroMax)
{
    numeroMax=numero;
    letraMax=letra;

}
if (flag==0 || numero<numeroMin)
{
    numeroMin=numero;
    letraMin=letra;
    flag=1;
}
respuesta=prompt("Si quiere seguir ingresando datos esciba 'si'")    
}while(respuesta=="si");
if(contadorPositivo==0)
{
    promedio=0;
}
else{
promedio=acumuladorPositivo/contadorPositivo;
}

document.write("a) la cantidad de numeros pares es "+contadorPar);
document.write("</br>b) la cantidad de numeros impares es"+contadorImpar);
document.write("</br>c) la cantidad de ceros es "+contadorCero);
document.write("</br>d) el promedio de todos los numeros positivos es "+promedio);
document.write("</br>e) la suma de todos los numero negativos es "+acumuladorNegativos);
document.write("</br>f) el numero y la letra maxima son "+numeroMax+" y "+letraMax+". Por otra parte el numero y letra minimo es "+numeroMin+" y "+letraMin);
}
/*
var numero;
var letra;
var respuesta;
var contadorPar=0;
var contadorImpar=0;
var contadorCeros=0;
var contador=0;
var sumaNeg=0;
var sumaPos=0;
var contadorPositivos=0;
var maximo;
var minimo;
var letraMax;
var letraMin;
var flag=0;
var promedio;

do{
numero=parseInt(prompt("Ingrese un numero"));
while(isNaN(numero) || numero<=-100 || numero>=100)
{
    numero=parseInt(prompt("Numero invalido. Ingrese un numero"));
}
letra=prompt("Ingrese una letra");
if(contador==0 || numero>maximo)
{
    maximo=numero;
    letraMax=letra;
}
if(contador==0 || numero<minimo)
{
    minimo=numero;
    letraMin=letra;
}
if(numero%2==0)
{
    contadorPar++;
}
else if(numero%2==1)
{
    contadorImpar++;
}
else if(numero==0)
{
    contadorCeros;
}
if(numero>=0)
{
    sumaPos=sumaPos+numero;
    contadorPositivos++;
    flag=1;
}
else 
{
    sumaNeg=sumaNeg+numero;
}

contador=contador+1;
respuesta=prompt("Si quiere seguir escriba 'si'");
if(flag=0)
{
    promedio=0;
}
else
{
    promedio=sumaPos/contadorPositivos
}
}while(respuesta=="si");
alert("el promedio de los numeros positivos es "+promedio);
alert("la suma de todos los numeros negativos es "+sumaNeg);
alert("la cantidad de numero pares es "+contadorPar);
alert("la cantidad de numeros impares "+contadorImpar);
alert("la cantidad de ceros es "+contadorCeros);
alert("el numero maximo es "+maximo+" y su letra es "+letraMax);
alert("el numero minimo es "+minimo+" y su letra es "+letraMin);
*/

/*
function mostrar() {
    var letra;
    var numero;
    var contadorPares = 0;
    var contadorImpares = 0;
    var contadorCeros = 0;
    var acumuladorPositivos = 0;
    var acumuladorNegativos = 0;
    var mayor;
    var menor;
    var letraMayor;
    var letraMenor;
    var flag = 0;
    var contador = 0;
    var seguir;
    var promedioPos;

    do {
        letra = prompt("Ingrese una letra: ");
        while (!((letra >= 'A' && letra <= 'Z') || (letra >= 'a' && letra <= 'z'))) {
            letra = prompt("Eso no es una letra. Ingrese una letra: ");
        }
        numero = parseInt(prompt("Ingrese un numero entre -100 y 100: "));
        while (numero < -100 || numero > 100 || isNaN(numero)) {
            numero = parseInt(prompt("Dato invalido. Ingrese un numero entre -100 y 100: "));
        }
        // me fijo por la paridad
        if (numero % 2 == 0) {
            contadorPares++;
        }
        else {
            contadorImpares++;
        }
        // me fijo por el signo
        if (numero > 0) {
            acumuladorPositivos = acumuladorPositivos + numero;
            contador++;
        }
        else if (numero < 0) {
            acumuladorNegativos = acumuladorNegativos + numero;
        }
        else {
            contadorCeros++;
        }
        // busco maximos y minimos
        if (numero > mayor || flag == 0) {
            mayor = numero;
            letraMayor = letra;
        }

        if (numero < menor || flag == 0) {
            menor = numero;
            letraMenor = letra;
            flag = 1;
        }


        seguir = prompt("Quiere continuar?: ");
    } while (seguir == 's');

    promedioPos = acumuladorPositivos / contador;

    // mostrar los datos

    document.write("a) La cantidad de números pares: " + contadorPares + "</br>");
    document.write("b) La cantidad de números impares: " + contadorImpares + "</br>");
    document.write("c) La cantidad de ceros: " + contadorCeros + "</br>");
    document.write("d) El promedio de todos los números positivos ingresados: " + promedioPos + "</br>");
    document.write("e) La suma de todos los números negativos: " + acumuladorNegativos + "</br>");
    document.write("f) Numero maximo: " + mayor + " Letra: " + letraMayor + "</br>");
    document.write("f) Numero minimo: " + menor + " Letra: " + letraMenor + "</br>");

}
*/