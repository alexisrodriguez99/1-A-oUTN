function mostrar()
{
var id;
var numero;
var resto;
var contador=0;
numero=prompt("Ingrese un numero");
numero=parseInt(numero);
id=parseInt(id);
while(isNaN(numero))
{
    numero=parseInt(prompt("Eso no es un numero. Ingrese un numero"))
}

if(numero>=0)//no hace falta poner un if else ya que no hay un for que no cumple
{
    for(id=1;id<=numero;id++)
    {
    resto=numero%id;
    if(resto==0)
        {
         alert(id+" es un numero divisor");
         contador++;
        }
    }
}
else
{
    for(id=1;id>=numero;id--)
{
 resto=numero%id;
 if(resto==0)
 {
     alert(id+" es un numero divisor");
     contador++;
 }
}
}
alert("La cantidad de numero divisores son: "+contador);


}//FIN DE LA FUNCIÓN