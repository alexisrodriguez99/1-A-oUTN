/*1.	Para el departamento de facturación:
A.	Ingresar tres precios de productos y mostrar la suma de los mismos.
B.	Ingresar tres precios de productos y mostrar el promedio de los mismos.
C.	ingresar tres precios de productos  y mostrar precio final (más IVA 21%).
*/
function Sumar () 
{
    var precioUno;
    var precioDos;
    var precioTres;
    var suma;
    precioUno=document.getElementById("PrecioUno").value;
    precioDos=document.getElementById("PrecioDos").value;
    precioTres=document.getElementById("PrecioTres").value;
    precioUno=parseInt(precioUno);
    precioDos=parseInt(precioDos);
    precioTres=parseInt(precioTres);
    suma=precioTres+precioDos+precioUno;
    alert("La suma de los precios es: "+suma);


}
function Promedio () 
{
	var precioUno;
    var precioDos;
    var precioTres;
    var suma;
    precioUno=document.getElementById("PrecioUno").value;
    precioDos=document.getElementById("PrecioDos").value;
    precioTres=document.getElementById("PrecioTres").value;
    precioUno=parseInt(precioUno);
    precioDos=parseInt(precioDos);
    precioTres=parseInt(precioTres);
    suma=precioTres+precioDos+precioUno;
    alert("El promedio de los tres precios es: "+parseInt(suma/3));

}
function PrecioFinal () 
{
	var precioUno;
    var precioDos;
    var precioTres;
    var suma;
    var totalConIva;
    precioUno=document.getElementById("PrecioUno").value;
    precioDos=document.getElementById("PrecioDos").value;
    precioTres=document.getElementById("PrecioTres").value;
    precioUno=parseInt(precioUno);
    precioDos=parseInt(precioDos);
    precioTres=parseInt(precioTres);
    suma=precioTres+precioDos+precioUno;
    totalConIva=suma*0.21+suma;
    alert("El precio de los productos mas IVA es: "+totalConIva);
}