/*3.	Para el departamento de Pinturas:
A.	Al ingresar una temperatura en Fahrenheit debemos mostrar la temperatura en Centígrados con un mensaje concatenado (ej.: " 32 Fahrenheit son 0 centígrados").
B.	Al ingresar una temperatura en Centígrados debemos mostrar la temperatura en Fahrenheit (ej.: "0  centígrados son 32 Fahrenheit ").
*/
function FahrenheitCentigrados () 
{
    var grado;
    var gradoCentigrados;
    grado=document.getElementById("Temperatura").value;
    grado=parseInt(grado);
    gradoCentigrados=(grado-32)*5/9
    alert(grado+"° Fahrenheit son "+gradoCentigrados+"° Cetigrados");
}

function CentigradosFahrenheit () 
{
    var grado;
    
    grado=document.getElementById("Temperatura").value;
    grado=parseInt(grado);
    
    alert(grado+"° Centigrados son "+((grado*9/5)+32)+"° Fahrenheit");
}
