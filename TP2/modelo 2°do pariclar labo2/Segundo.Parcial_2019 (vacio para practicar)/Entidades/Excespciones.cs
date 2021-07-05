using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
  public  class Excespciones:Exception
    {
        public Excespciones(string cadena):base(cadena)
        {

        }
    }
}
