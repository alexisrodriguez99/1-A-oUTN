function mostrar()
{

	var contador=0;
	var positivo=0;
	var negativo=1;
	var numero=0;
	
	var respuesta="si";
	do // uso do while porque quiero que entre a la funcion almenos una vez
	{
		numero=prompt("Ingrese un numero");
		numero=parseInt(numero);
		while(isNaN(numero)) //valido que sea un numero :)
		{
			numero=prompt("Eso no es un numero. Ingrese un numero");
			numero=parseInt(numero);
		}
		if(numero>=0)
		{
			positivo=positivo+numero;
		}
		else 
		{
			negativo=negativo*numero;
			contador=contador+1
		}
		respuesta=prompt("si quiere seguir con las operacion escriba 'si', en caso contrario escriba cualqueir cosa");
		
	}while(respuesta=="si");

if (contador==0)
{
	negativo=0;
}
document.getElementById('suma').value=positivo;
document.getElementById('producto').value=negativo;

}//FIN DE LA FUNCIÓN