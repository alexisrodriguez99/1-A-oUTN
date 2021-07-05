function mostrar()
{

	var contador=0;
	var acumulador=0;
	var suma=0;
	var respuesta="si";
while(respuesta=="si")
{
	acumulador=prompt("elija un numero");
	acumulador=parseInt(acumulador);
	suma=suma+acumulador;
	respuesta=prompt("si desea seguir con la suma escriba 'si', si no desea continuar escriba cualquier cosa" );
	contador=contador+1;
}

document.getElementById("suma").value=suma;
document.getElementById("promedio").value=suma/contador;

}//FIN DE LA FUNCIÓN