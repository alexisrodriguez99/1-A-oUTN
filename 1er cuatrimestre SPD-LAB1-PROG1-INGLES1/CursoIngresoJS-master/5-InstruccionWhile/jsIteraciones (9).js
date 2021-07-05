function mostrar()
{

	var contador=0;
	var numeroMayor=0;
	var numeroMenor=0;
	var numero=0;
	// declarar variables
	
	var respuesta='si';
	

	do
	{
		numero=prompt("elija un numero, sin miedo, usted puede GANBARUUUUU");
		numero=parseInt(numero);
		while(isNaN(numero)) //valido que sea un numero :)
		{
			numero=prompt("Eso no es un numero. Ingrese un numero");
			nuumero=parseInt(numero);
		}
		if (contador==0)
		{
			numeroMayor=numero;
			numeroMenor=numero;
		}
		else if(numeroMayor<numero)
		{
			numeroMayor=numero;
		}
		else if(numeroMenor>numero)
		{
			numeroMenor=numero;
		}
		respuesta=prompt("si ya no quiere seguir siendo una GANBARU, por favor escriba 'no' ");
		contador=contador+1;
	
	}while(respuesta!='no')
	document.getElementById("maximo").value=numeroMayor;
	document.getElementById("minimo").value=numeroMenor;

/* otra forma de hacerlo (mejor)
var contador=0;
	var numeroMayor=0;
	var numeroMenor=0;
	var numero=0;
	// declarar variables
	
	var respuesta='si';
	

	do
	{
		numero=prompt("elija un numero, sin miedo, usted puede GANBARUUUUU");
		numero=parseInt(numero);
		while(isNaN(numero)) //valido que sea un numero :)
		{
			numero=prompt("Eso no es un numero. Ingrese un numero");
			nuumero=parseInt(numero);
		}
		if(flag==0 || numero>maximo)
		{
			maximo=numero;
		}
		if (flag==0 || numero<minimo)
		{
			minimo=numero;
			flag=1
		}
		respuesta=prompt("si ya no quiere seguir siendo una GANBARU, por favor escriba 'no' ");
		contador=contador+1;
	
	}while(respuesta!='no')
	document.getElementById("maximo").value=numeroMayor;
	document.getElementById("minimo").value=numeroMenor;
	*/

}//FIN DE LA FUNCIÓN