function mostrar()
{
/*
b)Para la gestión de un hotel,
ingresar los siguientes datos validados de una reserva
nombre del huésped
cantidad de personas
cantidad de dia de estadia
forma de pago(efectivo , tarjeta o QR)

informar el huésped que trajo más personas en una sola reserva.
la cantidad de personas que se quedaron más días
la forma de pago más utilizada.
el promedio de cantidad de días por reserva
*/
var nombre;
var cantidadPersona;
var cantidadDEstadia;
var formaPago;
var respuesta;
var cantidadPersonaMayor;
var flag=0;
var nombreMayor;
var cantidadDEstadiaMayor;
var cantidadPersonaMayorEstadia;
var contador=0;
var promedio;
var acumuladorDias=0;
var contadorT=0;
var contadorQ=0;
var contadorE=0;
var formaPagoMayorUsada;

do{

  nombre=prompt("Ingrese su nombre").toLowerCase();
  while(nombre<'a' || nombre>'z')
  {
    nombre=prompt("Nombre invalido. Ingrese su nombre");
  }


  cantidadPersona=parseInt(prompt("Ingrese la cantidad de personas"));
  while(isNaN(cantidadPersona) || cantidadPersona<=0)
  {
    cantidadPersona=parseInt(prompt("Cantidad invalida. Ingrese la cantidad de personas"))
  }


  formaPago=prompt("Ingrese la forma de pago: 'efectivo', 'tarjeta' o 'qr'").toLowerCase();    //isNaN()= no es un numero
  while(formaPago!="efectivo" && formaPago!="tarjeta" && formaPago!="qr" || !isNaN(formaPago))//!isNaN() = es un numero
  {
    formaPago=prompt("Forma de pago incorrecta. Ingrese la forma de pago: 'efectivo', 'tarjeta' o 'QR'")
  }


  cantidadDEstadia=parseInt(prompt("Ingrese la cantidad de dia/dias de estadia"));
  while(isNaN(cantidadDEstadia))
  {
    cantidadDEstadia=parseInt(prompt("Cantidad de dias invalida. Ingrese la cantidad de dia/dias de estadia"));
  }

  if(flag==0 || cantidadPersona>cantidadPersonaMayor)
  {
    nombreMayor=nombre;
    cantidadPersonaMayor=cantidadPersona;

  }
  if (flag==0 || cantidadDEstadia>cantidadDEstadiaMayor)
  {
    cantidadPersonaMayorEstadia=cantidadPersona;
    cantidadDEstadiaMayor=cantidadDEstadia;
    flag=1;
  }

  if(formaPago=="efectivo")
  {
    contadorE++;
  }
  else if (formaPago=="tarjeta")
  {
    contadorT++;
  }
  else
  {
    contadorQ++;
  }


  acumuladorDias=acumuladorDias+cantidadDEstadia;
  contador++;
    respuesta=prompt("si quiere ingresar mas datos escriba 'si'");
}while(respuesta=="si");


if(contadorE>contadorQ && contadorE>contadorT)
  {
    formaPagoMayorUsada="efectivo"
  }
else if(contadorT>contadorQ)
  {
    formaPagoMayorUsada="tarjeta"
  }
else{
  formaPagoMayorUsada="qr"
}

promedio=acumuladorDias/contador;
document.write("el hueped que trajo mas personas en una solo reserva es: "+nombreMayor+" y la cantidad de personas fueron: "+cantidadPersonaMayor);
document.write("</br>la cantidad de personas que se quedaron mas dias es de "+cantidadPersonaMayorEstadia+" y su cantidad de dia es de "+cantidadDEstadiaMayor+"dias");
document.write("</br>la forma de pago mas utilizada es: "+formaPagoMayorUsada);
document.write("</br>el promedio de cantidad de dias por reserva es de: "+promedio);

}
