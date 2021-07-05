using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
    public static class CartucheraLlenaExceptionExtendida
    {
        public static string InformarNovedad(this CartucheraLlenaException ex)
        {
            return "Esta cartuchera ha llegado al maximo de su capacidad!";
        }
    }
}
