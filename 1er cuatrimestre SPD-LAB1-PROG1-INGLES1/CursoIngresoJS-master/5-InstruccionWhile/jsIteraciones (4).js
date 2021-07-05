function mostrar()
{

	var numero = prompt("ingrese un número entre 0 y 10.");
	// while (!(numero>=0 && numero<=9)) 
	while(numero>10 || numero<0 || isNaN(numero))//isNaN es verdadero si la variable numero no es un numero
	{
		
		numero=prompt("Incorrecto, ingrese un numero entre 0 y 10.");
		numero=parseInt(numero);
	}
	document.getElementById("Numero").value=numero;

}//FIN DE LA FUNCIÓN