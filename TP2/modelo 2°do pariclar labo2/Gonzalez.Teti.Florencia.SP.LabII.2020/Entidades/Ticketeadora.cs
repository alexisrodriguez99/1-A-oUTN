using Microsoft.SqlServer.Server;
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
        public static bool ImprimirTicket(Cartuchera<Goma> cartuchera)
        {
            bool seGuardo = false;
            try
            {
                string ticket = DateTime.Now.ToString() + "\nEl precio de la cartuchera es mas de $85. Precio actual: " + cartuchera.PrecioTotal;
                string path = Environment.GetFolderPath(Environment.SpecialFolder.MyDocuments) + "\\tickets.log";

                using (StreamWriter escritor = new StreamWriter(path, true))
                {
                    escritor.WriteLine(ticket);
                    escritor.Close();
                    seGuardo = true;
                }
            }
            catch (Exception ex) { }

            return seGuardo;
        }
    }
}
