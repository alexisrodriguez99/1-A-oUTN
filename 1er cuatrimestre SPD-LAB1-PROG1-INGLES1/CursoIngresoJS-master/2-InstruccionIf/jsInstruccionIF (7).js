function mostrar()
{
//tomo la edad  
var edad;
var estadoCivil

estadoCivil=document.getElementById("estadoCivil").value;
edad=document.getElementById("edad").value;

if(edad<=17 && estadoCivil=="Casado")
{
    alert("Es muy pequeño para no ser soltero");
}
else if(edad<=17 && estadoCivil=="Divorciado")
{
    alert("Es muy pequeño para no ser soltero");
}
	


}//FIN DE LA FUNCIÓN