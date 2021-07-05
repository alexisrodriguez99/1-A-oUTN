using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;
using System.Xml;
using System.Xml.Serialization;
namespace Entidades
{
    public delegate bool precioPasadoDelegado(double precio);
    public class Cajon<T>:ISerializar
    {
        public event precioPasadoDelegado EventoPrecio;

        int _capacidad;
        List<T> _elementos;
        protected double _precioUnitario;

        public List<T> Elementos
        {
            get { return this._elementos; }
        }

        public double PrecioTotal
        {
            get
            {
               

                return this._precioUnitario * this._elementos.Count;
            }
        }
        public Cajon()
        {
            this._elementos = new List<T>();
        }
        public Cajon(int capacidad):this()
        {
            this._capacidad = capacidad;
        }
        public Cajon(double precio, int capacidad):this(capacidad)
            {
            this._precioUnitario = precio;
        }

        public override string ToString()
        {
            StringBuilder sb = new StringBuilder();
            sb.AppendLine($"Capacidad: {this._capacidad}");
            sb.AppendLine($"Cantidad actual: {this._elementos.Count}");
            sb.AppendLine($"Precio total: {this.PrecioTotal}");
            foreach(T aux in this._elementos)
            {
                sb.AppendLine($"\n{aux.ToString()}");

            }

            return sb.ToString();
        }
        public static Cajon<T> operator +(Cajon<T> c, T f)
        {
            if(c._capacidad>c._elementos.Count)
            {
                c._elementos.Add(f);
                if(c is Cajon<Banana> && c.PrecioTotal>55)
                {
                    c.EventoPrecio(c.PrecioTotal);
                }
            }
            else
            {
              throw  new Excespciones("Error cajon lleno");
            }
            return c;
        }
        public bool Xml (string ruta)
        {
            string ruta2 = "\\" + ruta;
            bool verificar = false;
            Encoding codificacion = Encoding.UTF8;
            try
            {
                using (XmlTextWriter xw = new XmlTextWriter((((Environment.GetFolderPath(Environment.SpecialFolder.Desktop) + ruta2))), codificacion))
                {
                    XmlSerializer serializar = new XmlSerializer(typeof(Cajon<T>));
                    serializar.Serialize(xw, this);
                    verificar = true;

                }
            }
            catch (Exception excepcion)
            {
                Console.WriteLine(excepcion.Message);

            }
            return verificar;
        }
    }
}