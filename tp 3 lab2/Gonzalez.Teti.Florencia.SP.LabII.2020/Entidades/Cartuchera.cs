using System;
using System.Collections.Generic;
using System.Linq;
using System.Linq.Expressions;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
    public class Cartuchera<T> where T : Utiles
    {
        //Sobrecarga de operadores:
        //(+) Será el encargado de agregar elementos a la cartuchera, 
        //siempre y cuando no supere la capacidad máxima de la misma.

        protected int capacidad;
        protected List<T> elementos;

        public delegate void DelegadoEventoPrecio(object sender, EventArgs e);
        public event DelegadoEventoPrecio EventoPrecio;

        public Cartuchera()
        {
            this.elementos = new List<T>();
        }

        public Cartuchera(int capacidad) : this()
        {
            this.capacidad = capacidad;
        }

        public List<T> Elementos
        {
            get
            {
                return this.elementos;
            }
        }

        public double PrecioTotal
        {
            get
            {
                double precioTotal = 0;
                foreach (T util in this.elementos)
                {
                    precioTotal += util.precio;
                }
                return precioTotal;
            }
        }

        public static Cartuchera<T> operator +(Cartuchera<T> cartuchera, T util)
        {
            if (cartuchera.Elementos.Count < cartuchera.capacidad)
            {
                cartuchera.Elementos.Add(util);

                if(cartuchera is Cartuchera<Goma> && cartuchera.PrecioTotal > 85)
                {
                    cartuchera.EventoPrecio(cartuchera, new EventArgs());
                }
            }
            else
            {
                throw new CartucheraLlenaException();
            }

            return cartuchera;
        }
        public override string ToString()
        {
            StringBuilder cartuchera = new StringBuilder();

            cartuchera.AppendLine("Cartuchera");
            cartuchera.AppendLine("Capacidad: " + this.capacidad);
            cartuchera.AppendLine("Cantidad de elementos actuales: " + this.Elementos.Count);
            cartuchera.AppendLine("Precio total: " + this.PrecioTotal);
            cartuchera.AppendLine("Contiene: ");

            foreach (T util in this.elementos)
            {
                cartuchera.AppendLine("\n" + util.ToString());
            }

            return cartuchera.ToString();
        }





    }
}
