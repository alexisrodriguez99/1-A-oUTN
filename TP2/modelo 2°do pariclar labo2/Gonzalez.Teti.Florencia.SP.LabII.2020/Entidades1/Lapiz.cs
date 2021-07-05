using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;
using System.Xml;
using System.IO;
using System.Xml.Serialization;

namespace Entidades1
{
    public class Lapiz : Utiles, ISerializa, IDeserializa
    {

        public ConsoleColor color;
        public ETipoTrazo trazo;

        public Lapiz()
        {

        }
        public Lapiz(ConsoleColor color, ETipoTrazo trazo, string marca, double precio)
            : base(marca, precio)
        {
            this.color = color;
            this.trazo = trazo;
        }
        public override bool PreciosCuidados
        {
            get { return true; }
        }
        public string Path
        {
            get { return Environment.GetFolderPath(Environment.SpecialFolder.Desktop) + "\\Rodriguez.Ossa.Alexis.Kevin.xml"; }
        }
        public bool Xml()
        {bool validar = false;
            try
            {
Encoding codificacion = Encoding.UTF8;
            using (XmlTextWriter xw = new XmlTextWriter(this.Path, codificacion))
            {
                XmlSerializer serializar = new XmlSerializer(typeof(Lapiz));
                serializar.Serialize(xw, this);
                validar = true;
            }
            }
            catch (Exception)
            {

                validar = false;
            }
            
            
            return validar;
        }
        bool IDeserializa.Xml(out Lapiz lapiz)
        {

            bool validar = false;
            lapiz = null;
            try
            {
                using (XmlTextReader xr = new XmlTextReader(this.Path))
                {
                    XmlSerializer serializar = new XmlSerializer(typeof(Lapiz));
                    lapiz = (Lapiz)serializar.Deserialize(xr);
                    validar = true;
                }
            }
            catch (Exception)
            {

                validar = false;
            }

            return validar;
        }

        protected override string UtilesToString()
        {
            StringBuilder sb = new StringBuilder();
            sb.Append(base.UtilesToString());
            sb.AppendLine($"trazo: {this.trazo} - conlor: {this.color}");

            return sb.ToString();
        }
        public override string ToString()
        {
            return this.UtilesToString();
        }
    }
}
