function mostrar()
{
var nota;
var sexo;
var suma=0;
var notaBaja;
var sexoBajo;
var contadorM=0;

for(var id=0; id<=5; id++)
{
    nota=parseInt(prompt("Ingrese una nota de 0 al 10"));
    while(isNaN(nota) || nota<0 || nota>10)
    {
        nota=parent(prompt("Nota invalida. Ingrese una nota de 0 a 10"));
    }
    
    sexo=prompt("Ingrese un sexo, escribiendo 'f' o 'm'").toLowerCase();
    while(sexo!="f" && sexo!="m")
    {
        sexo=prompt("sexo invalido. ingrese el sexo");
    }
   if(id==0 || nota<notaBaja)
    {
        notaBaja=nota;
        sexoBajo=sexo;
        
    }
    if(sexo=="m" && nota>=6)
    {
        contadorM++;
    }

suma=suma+nota;
}
alert("el promedio de las notas es "+suma/5);
alert("la nota mas baja es "+notaBaja+" y su sexo es "+sexoBajo);
alert("la cantidad de varones con nota mayor a 6 son: "+contadorM);
}
/*
var nota;
var sexo;
var contador=0;
var mayor;
var sexoMayor;
var menor;
var sexoMenor;
var contadorNota=0;
for(var id=0;id<5;id++)
{
    
    nota=parseInt(prompt("Ingrese la nota"));
    
    while(nota<0 || nota>10)
    {
        nota=parseInt(prompt("NOTA invalida. Ingrese la nota"));
    }
    sexo=prompt("Ingrese el sexo, escribiendo solo 'f' o 'm'").toLowerCase();

    while(sexo!="f" && sexo!="m")
    {
        sexo=prompt("Sexo Incorrecto. Ingrese el sexo, escribiendo 'f' o 'm'").toLowerCase();
    }
    if(id==0 || nota>mayor)
    {
        mayor=nota;
        sexoMayor=sexo;
    }
    if(id==0 || nota<menor)
    {
        menor=nota;
        sexoMenor=sexo;
    }
    if(sexo=="m" && nota>=6)
    {
        contador++;
    }
    contadorNota=contador+nota;
}
alert("El promedio de las notas es "+contadorNota/5);
alert("La nota mas baja es "+menor+" y su sexo es "+sexoMenor);
alert("La cantidad de varones que su nota es mayor o igual a 6 es: "+contador);
*/

/*

function mostrar() {
    var nota;
    var sexo;
    var acumuladorNotas = 0;
    var promedioNotas;
    var notaBaja;
    var sexoBajo;
    var flag = 0;
    var contadorVaronesMas6 = 0;

    for (var i = 0; i < 5; i++) {
        // pido nota y la valido
        nota = parseInt(prompt("Ingrese nota(0-10): "));
        while (nota < 0 || nota > 10 || isNaN(nota)) {
            nota = parseInt(prompt("Nota invalida. Ingrese nota(0-10): "));
        }
        // pido sexo y lo valido
        sexo = prompt("Ingrese sexo: ");
        while (sexo != 'f' && sexo != 'm') {
            sexo = prompt("Sexo invalido. Ingrese sexo: ");
        }

        acumuladorNotas = acumuladorNotas + nota;

        if (nota < notaBaja || flag == 0) {
            notaBaja = nota;
            sexoBajo = sexo;
            flag = 1;
        }

        if (sexo == 'm' && nota >= 6) {
            contadorVaronesMas6++;
        }

    }

    promedioNotas = acumuladorNotas / 5;

    alert("Promedio notas: " + promedioNotas
        + "\nNota mas baja: "
        + notaBaja + "\nSexo de la persona con nota baja: "
        + sexoBajo + "\nCantidad varones con nota >= 6: "
        + contadorVaronesMas6
    );

}


*/