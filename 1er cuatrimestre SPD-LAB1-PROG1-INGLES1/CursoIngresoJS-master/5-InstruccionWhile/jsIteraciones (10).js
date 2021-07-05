function mostrar()
{

	var contadorPositivo=0;
	var contadorCero=0;
	var contadoNegativo=0;
	var numero=0;
	var negativo=0;
	var positivo=0;
	var diferencia;
	var promedioPositivos=0;
	var promedioNegativos=0;
	var contadorPar=0;
	
	//declarar contadores y variables 
	
	var respuesta="si";

	do
	{
		numero=prompt("Ingrese un numero");
		numero=parseInt(numero);
		while(isNaN(numero)) //valido que sea un numero :)
		{
			numero=prompt("Eso no es un numero. Ingrese un numero");
			numero=parseInt(numero);
		}
		if(numero%2==0)
		{
			contadorPar=contadorPar+1;
		}
		if(numero>0)
		{
			positivo=numero+positivo;
			contadorPositivo=contadorPositivo+1;
			flag1=1;
			
		
		
		}
		else if(numero<0)
		{
			negativo=numero+negativo;
			contadoNegativo=contadoNegativo+1;
			flag2=1;
		
		}
		else
		{
			contadorCero=contadorCero+1;
		}
		respuesta=prompt("Si ya no desea poner mas numeros escriba 'no', caso contrario escriba cualquier cosa");
		
	}while(respuesta!="no");
	if(contadoNegativo!=0)
	{
		promedioNegativos=negativo/contadoNegativo;
	}
	if(contadorPositivo!=0)
	{
		promedioPositivos=positivo/contadorPositivo;
	}
	diferencia=positivo-negativo;
	
	
	
	
	document.write("1) La diferencia entre positivos y negativos es: "+diferencia+"<br/>");//</br>
	document.write("2) La suma de los negativos es: "+negativo+"</br>");
	document.write("3) La suma de los positivos es: "+positivo+"<br/>");
	document.write("4) La cantidad de positivos es: "+contadorPositivo+"<br/>");
	document.write("5) La cantidad de negativos es: "+contadoNegativo+"<br/>");
	document.write("6) La cantidad de ceros es: "+contadorCero+"<br/>");
	document.write("7) La cantidad del promedio de los numeros positivos es: "+promedioPositivos+"<br/>");
	document.write("8) La cantidad del promedio de los numeros negativos es: "+promedioNegativos+"<br/>");
	document.write("9) La cantidad de numeros pares es: "+contadorPar);



}//FIN DE LA FUNCIÓN