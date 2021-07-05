using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;
using System.IO;

namespace Entidades
{
    public class Lapiz : Utiles, ISerializa, IDeserializa
    {
        //Lapiz-> color:ConsoleColor(público); trazo:ETipoTrazo(enum {Fino, Grueso, Medio}; público); PreciosCuidados->true; 
        //Reutilizar UtilesToString en ToString() (mostrar TODOS los valores).

        public ConsoleColor color;
        public ETipoTrazo trazo;

        public Lapiz(ConsoleColor color, ETipoTrazo trazo, string marca, double precio) : base(marca, precio)
        {
            this.color = color;
            this.trazo = trazo;
        }

        public Lapiz() : this(ConsoleColor.Black, ETipoTrazo.Grueso, "Marca Vacio", 0) { }

        public override bool PreciosCuidados
        {
            get
            {
                return true;
            }
        }

        public override string ToString()
        {
            return base.UtilesToString() + "\nColor: " + this.color + "\nTrazo: " + this.trazo + "\nEs Precios Cuidados: " + this.PreciosCuidados;
        }

        public string Path
        {
            get
            {
                return "Gonzalez.Teti.Florencia.lapiz.xml";
            }
        }
        public bool Xml()
        {
            bool seGuardo = true;
            try
            {
                XmlSerializer ser = new XmlSerializer(typeof(Lapiz));
                using (TextWriter escritor = new StreamWriter(Environment.GetFolderPath(Environment.SpecialFolder.Desktop) + "\\" + this.Path))
                {
                    ser.Serialize(escritor, this);
                }
            }
            catch (Exception)
            {
                seGuardo = false;
            }

            return seGuardo;
        }
        bool IDeserializa.Xml(out Lapiz lapiz)
        {
            bool sePudoLeer = true;
            lapiz = null;
            try
            {
                XmlSerializer ser = new XmlSerializer(typeof(Lapiz));
                using (TextReader lector = new StreamReader(Environment.GetFolderPath(Environment.SpecialFolder.Desktop) + "\\" + this.Path))
                {
                    lapiz = (Lapiz)ser.Deserialize(lector);
                }
            }
            catch (Exception)
            {
                sePudoLeer = false;
            }

            return sePudoLeer;
        }
    }
}
