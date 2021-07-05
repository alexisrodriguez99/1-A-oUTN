function mostrar()
{
/*
c)Se pide la carga de datos de un contenedor  de alimento canino con un máximo de carga de 1000kg,
cargar hasta que el cliente quiera o se llene el contenedor.
se pide:
marca
kilos por bolsa
cantidad de bolsa
importe por bolsa

que marca tiene más kilos en el contenedor
que marca tiene más bolsas de alimento en el contenedor
que marca tiene el mayor importe por bolsa de alimento
el importe y la marca de la bolsa de alimento menos pesada.

*/

var marca;
var kilos;
var cantidadBolsas;
var ImporteBolsas;
var contenedor=1000;
var respuesta;
var contador=0;
var kilosMax;
var cantidadBolsasMax;
var marcaMaxKilos;
var marcaMaxBolsas;
var marcaMaxImporte;
var ImporteBolsasMax;
var importeMenor;
var marcaMenor;
var kilosMin;
var acumuladorKilos=0;
do
{

  if(contenedor<acumuladorKilos)
  {
    break;
  }
  marca=prompt("Ingrese una marca").toLowercase();
  while(marca<'a' || marca>'z')
  {
    marca=prompt("Marca invalida. Ingrese una marca");
  }

  kilos=parseInt(prompt("Ingrese los kilos por bolsa"));
  while(isNaN(kilos) || kilos<=0)
  {
    kilos=parseInt(prompt("Error. Ingrese los kilos por bolsa"));

  }

  cantidadBolsas=parseInt(prompt("Ingrese la cantidad de bolsa"));
  while(isNaN(cantidadBolsas) || cantidadBolsas<=0)
  {
    cantidadBolsas=parseInt(prompt("Ingrese la cantidad de bolsa"));
  }

  ImporteBolsas=parseInt(prompt("Ingrese el importe por bolsa"));
  while(isNaN(ImporteBolsas) || ImporteBolsas<=0)
  {
    ImporteBolsas=parseInt(prompt("Ingrese el importe por bolsa"));
  }

   if(kilos>kilosMax || contador==0)
   {
     kilosMax=kilos;
     marcaMaxKilos=marca;
   }

   if(cantidadBolsas>cantidadBolsasMax || contador==0)
   {
     marcaMaxBolsas=marca;
     cantidadBolsasMax=cantidadBolsas;
   }

   if(ImporteBolsas>ImporteBolsasMax || contador==0)
   {
     ImporteBolsasMax=ImporteBolsas;
     marcaMaxImporte=marca;
   }

   if(kilos<kilosMin || contador==0)
   {
     kilosMin=kilos;
     importeMenor=ImporteBolsas;
     marcaMenor=marca;
   }

   acumuladorKilos=acumuladorKilos+kilos;
   contador++;
  respuesta=prompt("Ingrese 's' para ingresar mas datos");
}while(respuesta=="s");

document.write("la marca que tiene mas kilos es "+marcaMaxKilos+" y su cantidad de kilos es de "+kilosMax);
document.write("</br>la marca que tiene mas bolsas de alimento es "+marcaMaxBolsas+" y su cantidad de bolsas es de "+cantidadBolsasMax);
document.write("</br>la marca que tiene el mayor importe por bolsa es "+marcaMaxImporte+" y su iporte es de "+ImporteBolsasMax);
document.write("</br>el importe y la marca de la bolsa de aliemto menos pesada es de "+importeMenor+"$ , su marca es "+marcaMenor+" y el peso de la bolsa es de "+kilosMin);
}
