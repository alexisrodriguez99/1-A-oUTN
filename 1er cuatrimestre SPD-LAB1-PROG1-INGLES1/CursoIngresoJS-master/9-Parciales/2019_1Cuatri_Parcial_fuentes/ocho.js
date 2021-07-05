function mostrar()

{
    /*
    Realizar el algoritmo que permita iterar el ingreso de dos datos, una letra y un número entre -100 y 100 (validar) hasta que el usuario quiera e informar al terminar el ingreso por document.write: 
a) La cantidad de números pares. 
b) La cantidad de números impares. 
c) La cantidad de ceros. 
d) El promedio de todos los números positivos ingresados. 
e) La suma de todos los números negativos. 
f) El número y la letra del máximo y el mínimo. 
    */
   var letra;
   var numero;
   var respuesta;
   var contPar=0;
   var contImpar=0;
   var contCeros=0;
   var acumuladorPositivos=0;
   var acumuladorNegativos=0;
   var numeroMax;
   var numeroMin;
   var letraMax;
   var letraMin;
   var contador=0;
   var promedio;
   var contadorPositivos=0;

   do{
       letra=prompt("ingrese una letra").toLowerCase();
       while(letra<"a" || letra>"z")
       {
            letra=prompt("Letra incorrecta. Ingrese una letra").toLowerCase();
       }
        numero=parseInt(prompt("ingrese un numero"));
       while(isNaN(numero) || numero<-100 || numero>100)
       {
            numero=parseInt(prompt("Error. ingrese un numero"));
       }
       if (numero%2==0)
       {
            contPar++;
       }
       else
       {
           contImpar++;
       }
       if(numero==0)
       {
           contCeros;
       }
       if(numero>=0)
       {
            acumuladorPositivos=acumuladorPositivos+numero;
            contadorPositivos++;
       }
       else
       {
           acumuladorNegativos=acumuladorNegativos+numero;
       }
       if(contador==0 || numero>numeroMax)
       {
           numeroMax=numero;
           letraMax=letra;
       }
       if(contador==0 || numero<numeroMin)
       {
           numeroMin=numero;
           letraMin=letra;
       }


    contador++;
    respuesta=prompt("Si quiere seguir ingresando datos escriba 'si'");
   }while(respuesta=="si");

   if(contadorPositivos==0)
   {
       promeidio=0;
   }
   else{
       promedio=acumuladorPositivos/contadorPositivos;
   }
   document.write("La cantidad e numero pares es "+contPar);
   document.write("</br>La cantidad de numeros impares es"+contImpar);
   document.write("</br>El promedio de todos los numeros positivos es "+promedio);
   document.write("</br>La suma de todos los numeros negativos es"+acumuladorNegativos);
   document.write("</br>El numero y letra maximo es "+numeroMax+" y "+letraMax+" respectivament. Y el minimo es "+numeroMin+" y "+letraMin);
}





