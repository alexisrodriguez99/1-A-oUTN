function mostrar()
{

var sexo = prompt("ingrese f ó m .").tou;


while(sexo!="f" && sexo!="m")// o tambien while(!(sexo==f || sexo==m))
{
   
    sexo=prompt("Incorrecto, ingrese f o m .");  
}

document.getElementById("Sexo").value=sexo;

}//FIN DE LA FUNCIÓN