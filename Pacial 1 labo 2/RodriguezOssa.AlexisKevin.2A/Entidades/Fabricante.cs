using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
    public class Fabricante
    {
        string marca;
        EPais pais;

        public Fabricante(string marca, EPais pais)
        {
            this.marca = marca;
            this.pais = pais;
        }

        public static bool operator ==(Fabricante a, Fabricante b)
        {
            bool respuesta = false;
            if(a.marca==b.marca && a.pais==b.pais)
            {
                respuesta = true;
            }
            return respuesta;
        }
        public static bool operator !=(Fabricante a, Fabricante b)
        {
            return !(a == b);

        }
        public static implicit operator String(Fabricante f)

        {

            return f.marca + " - " + f.pais;
        }
    }
}
