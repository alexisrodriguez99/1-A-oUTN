function mostrar()
{
//tomo la edad  
var edad;
edad=document.getElementById("edad").value;
if(edad>=18)
{
    alert("Esta persona es mayor de edad y tiene "+edad+" años");
}
else
{
    alert("Esta persona es menor de edad y tiene "+edad+" años");
}

}//FIN DE LA FUNCIÓN