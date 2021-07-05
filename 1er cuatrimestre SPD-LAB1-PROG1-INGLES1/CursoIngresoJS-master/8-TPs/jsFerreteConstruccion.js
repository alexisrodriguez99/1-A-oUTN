/*2.	Para el departamento de Construcción:
A.	 mostrar la cantidad de alambre a comprar  si se ingresara el largo y el ancho de un terreno rectangular y se debe alambra con tres hilos de alambre.
B.	mostrar la cantidad de alambre a comprar  si se ingresara el radio  de un terreno circular y se debe alambra con tres hilos de alambre.
C.	Para hacer un contrapiso de 1m x 1m se necesitan 2 bolsas de cemento y 3 de cal, debemos mostrar cuantas bolsas se necesitan de cada uno para las medidas que nos ingresen.
*/

function Rectangulo () 
{
var largo;
var ancho;
var perimetro;
largo=document.getElementById("Largo").value;
ancho=document.getElementById("Ancho").value;
largo=parseInt(largo);
ancho=parseInt(ancho);
perimetro=ancho*2+largo*2;
alert("la cantidad necesaria para alambrar con 3 alambres es: "+perimetro*3);    
}
function Circulo () 
{
var radio;
var perimetro;
radio=document.getElementById("Radio").value;
radio=parseInt(radio);
perimetro=2*Math.PI*radio;
alert("La cantidad necesaria para alambrar el perimetro del circulo, con tres alambres es: "+perimetro*3);
}
function Materiales () 
{
var largo;
var ancho;
var area;
largo=document.getElementById("Largo").value;
ancho=document.getElementById("Ancho").value;
largo=parseInt(largo);
ancho=parseInt(ancho);
area=(largo+ancho)*2;
alert("La cantidad de bolsas para hacer un contrapiso de "+ancho+"m x "+largo+"m es de "+area*2+" bolsas de cemento y "+area*3+" bolsas cal.")
}