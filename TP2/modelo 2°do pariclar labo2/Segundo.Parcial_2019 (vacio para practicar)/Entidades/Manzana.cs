using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml;
using System.Xml.Serialization;
namespace Entidades
{
    public class Manzana : Fruta,IDeserializar,ISerializar
    {
        protected string _provinciaOrigen;

        public string Nombre
        {
            get { return "Manzana"; }
        }
        public override bool TieneCarozo
        {
            get { return true; }
        }
        public Manzana() : base(null, 0)
        {

        }

        public Manzana(string color, double peso, string provincia):base(color,peso)
        {
            this._provinciaOrigen = provincia;
        }

        protected override string FrutaToString()
        {
            StringBuilder sb = new StringBuilder();
            sb.AppendLine($"Fruta: {this.Nombre}");
            sb.AppendLine(base.FrutaToString());
            sb.AppendLine($"Provincia de origen= {this._provinciaOrigen}");
            sb.AppendLine($"Carozo= {this.TieneCarozo}");
            return sb.ToString();
        }
        public override string ToString()
        {
            return this.FrutaToString();
        }
        public bool Xml(string ruta)
        {
            string ruta2 = "\\" + ruta;
            bool verificar = false;
            Encoding codificacion = Encoding.UTF8;
            try
            {
                using (XmlTextWriter xw = new XmlTextWriter((((Environment.GetFolderPath(Environment.SpecialFolder.Desktop) + ruta2))), codificacion))
                {
                    XmlSerializer serializar = new XmlSerializer(typeof(Manzana));
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
        bool IDeserializar.Xml(string ruta, out Fruta dato)
        {
            string ruta2 = "\\" + ruta;
            dato = null;
            bool verificar = false;
            try
            {
                if (ruta != null)
                {
                    using (XmlTextReader xr = new XmlTextReader((((Environment.GetFolderPath(Environment.SpecialFolder.Desktop) + ruta2)))))
                    {
                        XmlSerializer serializar = new XmlSerializer(typeof(Manzana));
                        dato = (Manzana)serializar.Deserialize(xr);
                        verificar = true;
                    }
                }
            
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }
            return verificar;
        }
    }
}
