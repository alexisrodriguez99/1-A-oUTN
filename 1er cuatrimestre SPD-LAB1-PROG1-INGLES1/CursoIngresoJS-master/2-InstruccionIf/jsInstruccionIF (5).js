function mostrar()
{
//tomo la edad  
var edad;
edad=document.getElementById("edad").value;
if(edad<13 || edad>17)
{
    alert("Esta persona no es un adolescente y tiene "+edad+" años");
}

}//FIN DE LA FUNCIÓN