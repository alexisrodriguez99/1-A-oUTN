function mostrar()
{
var id;
var numero;
var cantidadPar=0;
var par;
numero=prompt("Ingrese un numero");
numero=parseInt(numero);
for(id=1;id<=numero;id++)
{
    
    par=id%2;
    if(par==0)
    {   
        
        alert("Los numero pares son: "+id);
        cantidadPar=1+cantidadPar;
        
    
    }

}
alert("La canatidad de numeros pares son: "+cantidadPar);



}//FIN DE LA FUNCIÓN