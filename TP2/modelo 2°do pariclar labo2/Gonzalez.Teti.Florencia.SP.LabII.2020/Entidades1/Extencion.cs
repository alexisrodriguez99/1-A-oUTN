using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades1
{
   public static class Extencion
    {
        public static string InformarNovedad(this CartucheraLlenaExceptio e)
        {
            return "Error cartuchella llena" + e.Message;
        }
    }
}
