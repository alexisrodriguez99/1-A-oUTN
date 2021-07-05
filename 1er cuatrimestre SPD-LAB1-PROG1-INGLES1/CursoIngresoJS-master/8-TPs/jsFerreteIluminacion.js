/*4.	Para el departamento de iluminación:
Tomando en cuenta que todas las lámparas están en oferta al mismo precio de $35 pesos final.
A.	Si compra 6 o más  lamparitas bajo consumo tiene un descuento del 50%. 
B.	Si compra 5  lamparitas bajo consumo marca "ArgentinaLuz" se hace un descuento del 40 % y si es de otra marca el descuento es del 30%.
C.	Si compra 4  lamparitas bajo consumo marca "ArgentinaLuz" o “FelipeLamparas” se hace un descuento del 25 % y si es de otra marca el descuento es del 20%.
D.	Si compra 3  lamparitas bajo consumo marca "ArgentinaLuz"  el descuento es del 15%, si es  “FelipeLamparas” se hace un descuento del 10 % y si es de otra marca un 5%.
E.	Si el importe final con descuento suma más de $120  se debe sumar un 10% de ingresos brutos en informar del impuesto con el siguiente mensaje:
 ”Usted pago X de IIBB.”, siendo X el impuesto que se pagó. 

 */
function CalcularPrecio () 
{
     var lamparas;
     var marca;
     var precioConDescuento;
     var precioLampara;
    marca=document.getElementById("Marca").value;
     lamparas=document.getElementById("Cantidad").value;
     lamparas=parseInt(lamparas);
     precioLampara=lamparas*35;
     
     if(lamparas>=6)
     {
          document.getElementById("precioDescuento").value=precioLampara-precioLampara*0.5;
          precioConDescuento=precioLampara-precioLampara*0.5;
          if(precioConDescuento>120)
          {
               alert("IIBB Usted pago $"+precioLampara*0.10);
               
          }
     }

     else if(lamparas==5)
     {
          switch (marca)
          {
               case "ArgentinaLuz":
                    {
                         document.getElementById("precioDescuento").value=precioLampara-precioLampara*0.4;
                         break;
                    }
               
               default:
                    {
                         document.getElementById("precioDescuento").value=precioLampara-precioLampara*0.3;
                    }
          }
          precioConDescuento=precioLampara-precioLampara*0.3;
          if(precioConDescuento>=120)
          {
               alert("IIBB usted pago $"+precioConDescuento*0.1);
          }
     }
     else if (lamparas==4)
     {
          switch(marca)
          {
               case "ArgentinaLuz":
               case "FelipeLamparas":
                    {
                         document.getElementById("precioDescuento").value=precioLampara-precioLampara*0.25;
                         break;
                    }
               default:
                    {
                       document.getElementById("precioDescuento").value=precioLampara-precioLampara*0.20;  
                    }
          }
     }
     else if(lamparas==3)
     {
          switch(marca)
          {
               case "ArgentinaLuz":
                    {
                         document.getElementById("precioDescuento").value=precioLampara-precioLampara*0.15;
                         break;
                    }
               case "FelipeLamparas":
                    {
                         document.getElementById("precioDescuento").value=precioLampara-precioLampara*0.10;
                         break;
                    }
               default:
                    {
                         document.getElementById("precioDescuento").value=precioLampara-precioLampara*0.05;
                    }
          }
     }
     else if (lamparas==2 || lamparas==1 )
     {
          document.getElementById("precioDescuento").value=precioLampara;
     }
}
/*{
var cantidad;
var descuento;
var precioFinal;
var precioConDescuento;
var marca;
var precio;
var impuesto;
precio=35;
cantidad=parseInt(document.getElementById(Cantidad).value);
marca=document.getElementById(Marca).value;



swtich(cantidad)
{
    case 1:
    case 2:
    {
        descuento=0
    }
    case 3:
    {
        if (marca==ArgentinaLuz)
        {
            descuento=15;
        }
        else is (marca==FelipeLamparas)
        {
            descuento=10;
        }
        else 
        {
            descuento=5;
        }
    }
    case 4:
    {
        if (marca==ArgentinaLuz || marca==FelipeLamparas)
        {
            descuento=25;
        }
        else 
        {
            descuento=20;
        }
    }
    case 5
    {
        if (marca==ArgentinaLuz)
        {
            descuento=40;
        }
        else 
        {
            descuento=30;
        }
    }
}

precioConDescuento=precio*descuento/100;
preciodFinal=precion-cantidad*precioConDescuento;
document.getElementById("precioDescuento").value=precionConDescuento;
if(precioFinal>120)
{
    impuesto=precio+precio*0.10;
    precioFinal=impuesto+precio*cantidad;
    alert("IIBB Usted pago "+impuesto);

}



}
*/



/*
ECHO EN CLASE
4.	Para el departamento de iluminación:
Tomando en cuenta que todas las lámparas están en oferta al mismo precio de $35 pesos final.
A.	Si compra 6 o más  lamparitas bajo consumo tiene un descuento del 50%. 
B.	Si compra 5  lamparitas bajo consumo marca "ArgentinaLuz" se hace un descuento del 40 % y si es de otra marca el descuento es del 30%.
C.	Si compra 4  lamparitas bajo consumo marca "ArgentinaLuz" o “FelipeLamparas” se hace un descuento del 25 % y si es de otra marca el descuento es del 20%.
D.	Si compra 3  lamparitas bajo consumo marca "ArgentinaLuz"  el descuento es del 15%, si es  “FelipeLamparas” se hace un descuento del 10 % y si es de otra marca un 5%.
E.	Si el importe final con descuento suma más de $120  se debe sumar un 10% de ingresos brutos en informar del impuesto con el siguiente mensaje:
 ”Usted pago X de IIBB.”, siendo X el impuesto que se pagó. 


function CalcularPrecio() {
    var cantidad;
    var marca;
    var precio = 35;
    var porcDescuento;
    var descuento;
    var IIBB;
    var importeFinal;
    var precioConDescuento;


    cantidad = parseInt(document.getElementById("Cantidad").value);
    marca = document.getElementById("Marca").value;

    if (cantidad >= 1) {

        switch (cantidad) {
            case 1:
            case 2:
                porcDescuento = 0;
                break;
            case 3:
                if (marca == "ArgentinaLuz") {
                    porcDescuento = 15;
                } else if (marca == "FelipeLamparas") {
                    porcDescuento = 10;
                } else {
                    porcDescuento = 5;
                }
                break;
            case 4:
                if (marca == "ArgentinaLuz" || marca == "FelipeLamparas") {
                    porcDescuento = 25;
                }
                else {
                    porcDescuento = 20;
                }
                break;
            case 5:
                if (marca == "ArgentinaLuz") {
                    porcDescuento = 40;
                }
                else {
                    porcDescuento = 30;
                }
                break;
            default:
                porcDescuento = 50;
        }

        // calculo el descuento
        descuento = precio * porcDescuento / 100;
        // al precio unitario le resto el descuento
        precioConDescuento = precio - descuento;

        // muestro el precio unitario en la caja inferior
        document.getElementById("precioDescuento").value = precioConDescuento;

        // ahora que ya se el precio de cada lampara
        // calculo el total
        importeFinal = precioConDescuento * cantidad;

        if (importeFinal > 120) {
            IIBB = importeFinal * 10 / 100;
            importeFinal = importeFinal + IIBB;
            alert("El importe final es $ " + importeFinal + "\nUsted pago $ " + IIBB + " de ingresos brutos");

        } else {
            alert("El importe final es $ " + importeFinal);
        }

    } else {
        alert("No es una cantidad valida");
    }


}
*/