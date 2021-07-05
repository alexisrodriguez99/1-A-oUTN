using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
namespace Entidades
{
    public class Ticketeadora
    {
        public static bool ImprimirTicket(double precio)
        {
            bool verificar = false;
            StringBuilder sb = new StringBuilder();
            sb.AppendLine(DateTime.Now.ToString());
            sb.AppendLine($"total de la cartuchera: {precio}");
            string ruta = Environment.GetFolderPath(Environment.SpecialFolder.MyDocuments) + "\\tickets.log";
            try
            {
                using (StreamWriter sw = new StreamWriter(ruta, true))
                {
                    verificar = true;
                    sw.WriteLine(sb.ToString());

                }
            }
            catch (Exception)
            {
            }
            return verificar;
        }
    }
}
