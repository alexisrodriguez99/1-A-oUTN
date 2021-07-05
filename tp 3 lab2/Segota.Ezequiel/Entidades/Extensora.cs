using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
    public static class Extensora
    {
        public static string InformarNovedad(this CartucheraLlenaException ex)
        {
            return "\nLa cartuchera esta llena";
        }
    }
}
