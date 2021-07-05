using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace Entidades1
{
    public delegate void SuperaPrecioDelegado(double precio);

   public class Cartuchera<T> where T:Utiles
    {
        public event SuperaPrecioDelegado EventoPrecio;
       protected int capacidad;
       protected List<T> elementos;
        
        public List<T> Elementos
        {
            get { return this.elementos; }
        }
        public double PrecioTotal
        {
            get 
            {
                double precioTotal=0;
              foreach(T elemento in this.elementos)
                {
                    precioTotal = precioTotal + elemento.precio;
                }
                return precioTotal;
            }
        }
        public Cartuchera()
        {
            this.elementos = new List<T>();
        }
        public Cartuchera(int capacidad):this()
        {
            this.capacidad = capacidad;
        }
        public override string ToString()
        {
            StringBuilder sb = new StringBuilder();
            sb.AppendLine($"Tipo de cartuchera: {typeof(T).Name}");
            sb.AppendLine($"Capacidad: {this.capacidad}");
            sb.AppendLine($"Precio total: {this.PrecioTotal}");
            foreach (T aux in this.elementos)
            {
                sb.AppendLine(aux.ToString());
            }
            
            return sb.ToString();
        }
        public static Cartuchera<T> operator +(Cartuchera<T> c, T u)
        {

            if (c.capacidad > c.elementos.Count)
            {

                c.elementos.Add(u);
                if(c.PrecioTotal>85 && c is Cartuchera<Goma>)
                {
                    c.EventoPrecio(c.PrecioTotal);
                }
            }
            else
            {
                throw new CartucheraLlenaExceptio();
            }
            return c;
        }
    }
}
