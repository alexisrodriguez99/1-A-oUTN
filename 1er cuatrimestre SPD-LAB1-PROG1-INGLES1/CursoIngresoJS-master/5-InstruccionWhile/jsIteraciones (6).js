function mostrar()
{

	var contador=0;
	var acumulador=0;
	var suma=0;
	
	
	while(contador<5)
	{
		
		acumulador=prompt("elija un numero");
		acumulador=parseInt(acumulador);
		while(isNaN(acumulador))
		{
			acumulador=prompt("Eso no es un numero. Ingrese un numero")
		}
		suma=suma+acumulador;
		contador=contador+1
	}



document.getElementById('suma').value=suma;
document.getElementById('promedio').value=suma/5;

}//FIN DE LA FUNCIÓN