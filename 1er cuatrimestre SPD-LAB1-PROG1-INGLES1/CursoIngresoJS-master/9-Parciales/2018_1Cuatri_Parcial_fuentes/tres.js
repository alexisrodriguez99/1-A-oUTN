function mostrar()
{
var precio;
var descuento;
var precioDescuento;
precio=parseInt(prompt("Ingrese el precio"));
descuento=parseInt(prompt("Ingrese el descuento"));
precioDescuento=precio-(precio*descuento/100);
document.getElementById("elPrecioFinal").value=precioDescuento;
}
