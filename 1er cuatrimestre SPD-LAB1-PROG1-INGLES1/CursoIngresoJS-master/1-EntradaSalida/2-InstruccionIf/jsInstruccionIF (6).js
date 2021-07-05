function mostrar()
{
//tomo la edad  
var edad;
edad=document.getElementById("edad").value;// me volvi a olvidar el VALUEEEEEEE AHHHHH DIOSSSS UnU
if(edad>0 && edad<13)
{
    alert("Esta persona es un niño y tiene "+edad+" años");
}
else if (edad>=13 && edad<=17)
{
    alert("Esta persona es un adolescente y tiene "+edad+" años");
}
else if (edad>=18)
{
    alert("Esta persona es un mayor de edad y tiene "+edad+" años");
}
else 
{
    alert("No existe una persona con esa edad ");
}



}//FIN DE LA FUNCIÓN