function mostrar()
{
var id;
var numero;
var primo;
var flag=0;
numero=prompt("Ingrese un numerp");


for(id=2;id<numero;id++)
{
    
    if(numero%id==0)
    {
        
        flag=1;
    }

}
if(flag==0)
{
    alert("El numero es primo");

}
else
{
    alert("El numero es no es primo");
}


}//FIN DE LA FUNCIÓN

