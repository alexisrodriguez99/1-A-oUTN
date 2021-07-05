using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Entidades
{
   public class Manejadora
    {
        public bool GuardarTxt(double precio)
        {
            bool validar = false;
            Encoding codificacion = Encoding.UTF8;

            StringBuilder sb = new StringBuilder();
            sb.AppendLine(DateTime.Now.ToString());
            sb.AppendLine("PRECIO total: "+ precio.ToString());
            try
            {
                using (StreamWriter sw = new StreamWriter(Environment.GetFolderPath(Environment.SpecialFolder.Desktop) + "//ArchivoEvento.txt", false))
                {
                    sw.Write(sb);
                    validar = true;
                }
            }
            catch (Exception excepcion)
            {
                Console.WriteLine(new Exception(excepcion.Message));

            }

            return validar;
        }
    }
}
