function mostrar()
{
//tomo la edad  
var edad;
edad=document.getElementById("edad").value;
if(edad>0 && edad<=13)
{
    alert("Esta persona es un niño y tiene "+edad+" años");
}
else if(edad>13 && edad<=17)
{
    alert("Esta persona es un adolescente y tiene "+edad+" años");
}
else
{
    alert("Esta persona es un mayor de edad y tiene "+edad+" años");
}


}//FIN DE LA FUNCIÓN