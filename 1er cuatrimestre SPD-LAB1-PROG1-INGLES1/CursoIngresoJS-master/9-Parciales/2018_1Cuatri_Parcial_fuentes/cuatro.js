function mostrar()
{
var numero1;
var numero2;
var suma;
numero1=parseInt(prompt("Ingrese un numero"));
numero2=parseInt(prompt("Ingrese un numero"));
if (numero1==numero2)
{
    alert("El resultado es "+numero1+numero2);
}
else if (numero1>numero2)
{
    alert("el resultado es "+(numero1-numero2));
}
else
{
    suma=numero1+numero2;
    alert("El resultado es "+(numero1+numero2));
    if (suma>10)
    {
        alert("la suma es "+suma+" y supero el 10")
    }
}
}
