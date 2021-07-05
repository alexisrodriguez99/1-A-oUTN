using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Xml.Serialization;

namespace Entidades
{
    public class Lapiz : Utiles, ISerializa, IDeserializa
    {
        public ConsoleColor color;
        public ETipoTrazo trazo;

        public override bool PreciosCuidados
        {
            get { return true; }
        }

        public string Path
        {
            get { return Environment.GetFolderPath(Environment.SpecialFolder.Desktop)+@"\Segota.Ezequiel.Lapiz.xml"; }
        }

        public Lapiz()
            :base("",0)
        {

        }

        public bool Xml()
        {
            bool retorno = false;
            try
            {
                using (TextWriter writer = new StreamWriter(this.Path))
                {
                    XmlSerializer serializer = new XmlSerializer(typeof(Lapiz));
                    serializer.Serialize(writer, this);
                    retorno = true;
                }
            }
            catch(Exception error)
            {
                throw new Exception(error.Message);
            }
            return retorno;
        }

        bool IDeserializa.Xml(out Lapiz lapiz)
        {
            bool retorno = false;
            using (TextReader reader = new StreamReader(this.Path))
            {
                XmlSerializer serializer = new XmlSerializer(typeof(Lapiz));
                lapiz = (Lapiz)serializer.Deserialize(reader);
                retorno = true;
            }
            return retorno;
        }

        public Lapiz(ConsoleColor color, ETipoTrazo trazo, string marca, double precio)
        :base(marca,precio)
        {
            this.color = color;
            this.trazo = trazo;
        }

        protected override string UtilesToString()
        {
            StringBuilder sb = new StringBuilder();

            sb.Append(base.UtilesToString());
            sb.AppendFormat("- Color: {0} - Trazo: {1} - PreciosCuidados: {2}", this.color, this.trazo,this.PreciosCuidados);

            return sb.ToString();
        }

        public override string ToString()
        {
            return this.UtilesToString();
        }
    }
}
