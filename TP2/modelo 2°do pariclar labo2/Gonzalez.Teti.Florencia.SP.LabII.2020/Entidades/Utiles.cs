using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
    public abstract class Utiles
    {
        //Utiles-> marca:string y precio:double (públicos); PreciosCuidados:bool (prop. s/l, abstracta);
        //constructor con 2 parametros y UtilesToString():string (protegido y virtual, retorna los valores del útil)
        //ToString():string (polimorfismo; reutilizar código)
        public string marca;
        public double precio;

        public Utiles(string marca, double precio)
        {
            this.marca = marca;
            this.precio = precio;
        }

        public abstract bool PreciosCuidados { get; }

        protected virtual string UtilesToString()
        {
            return "Marca: " + this.marca + "\nPrecio: " + this.precio;
        }

        public override string ToString()
        {
            return this.UtilesToString();
        }

    }
}
