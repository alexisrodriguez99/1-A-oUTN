function mostrar()
{
//tomo la edad  
var edad
edad=document.getElementById("edad").value;
if(edad>0)
{
    if (edad>=17 || edad<=13)
    {
        alert("Esta persona no es un adolescente por que tiene "+edad+" años");
    }
    
}
else 
{
    alert("No existe tal criatura cuyos años son negativos")
}

}//FIN DE LA FUNCIÓN