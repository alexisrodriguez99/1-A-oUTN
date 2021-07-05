using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;
using System.IO;
namespace Entidades
{
    public delegate void LimitePrecioDelegado(double precio);

    public class Cartuchera<T> where T : Utiles
    {
        protected int capacidad;
        protected List<T> elementos;

        public event LimitePrecioDelegado LimitePrecio;
        public List<T> Elementos
        {
            get { return this.elementos; }
        }

        public double PrecioTotal
        {
            get
            {
                double aux = 0;
                foreach (Utiles item in this.elementos)
                {
                    aux += item.precio;
                }
                
                if(aux>85)
                {
                    this.LimitePrecio(aux);
                }
                
                return aux;
            }
        }

        public Cartuchera()
        {
            this.elementos = new List<T>();
        }

        public Cartuchera(int capacidad)
            :this()
        {
            this.capacidad = capacidad;
        }

        public override string ToString()
        {
            StringBuilder sb = new StringBuilder();

            sb.AppendFormat("Cartuchera de:{0} - Capacidad: {1} - Cantidad actual: {2} - ", typeof(T).Name, this.capacidad, this.Elementos.Count);

            sb.AppendFormat("PrecioTotal: {0} - ", this.PrecioTotal);
            sb.AppendLine("Elementos en cartuchera:");
            foreach (Utiles item in this.Elementos)
            {
                if(item is Goma)
                {
                    sb.AppendLine(((Goma)item).ToString());
                }
                else if(item is Lapiz)
                {
                    sb.AppendLine(((Lapiz)item).ToString());
                }
                else if(item is Sacapunta)
                {
                    sb.AppendLine(((Sacapunta)item).ToString());
                }
            }

            return sb.ToString();
        }

        public static Cartuchera<T> operator +(Cartuchera<T> cartuchera, Utiles util)
        {
            if(cartuchera.Elementos.Count< cartuchera.capacidad)
            {
                cartuchera.Elementos.Add((T)util);
            }
            else
            {
                throw new CartucheraLlenaException();
            }
            return cartuchera;
        }

        public static bool ATexto(double precio)
        {
            bool ret = false;
            try
            {
                string documentos = Environment.GetFolderPath(Environment.SpecialFolder.MyDocuments);
                using (StreamWriter sw = new StreamWriter(documentos + @"\tickets.log", true))
                {
                    
                    sw.Write("LA FECHA ES: ");
                    sw.WriteLine(DateTime.Now);

                    sw.Write("El Precio es:");
                    sw.WriteLine(precio);
                    sw.WriteLine("-----------------------------");
                }
                ret = true;
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }
            
             return ret;
            
        }
    }
}
