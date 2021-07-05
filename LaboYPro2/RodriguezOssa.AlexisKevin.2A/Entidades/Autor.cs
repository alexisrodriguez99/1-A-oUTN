using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
    public class Autor
    {
        string apellido;
        string nombre;
        
        public Autor(string nombre, string apellido)
        {
            this.apellido = apellido;
            this.nombre = nombre;
        }
        public static bool operator ==(Autor a,Autor b)
        {
            bool rta = false;
            if(a.nombre==b.nombre && a.apellido==b.apellido)
            {
                rta = true;

            }
            return rta;
        }
        public static bool operator !=(Autor a, Autor b)
        {
            return !(a == b);
        }
        public static implicit operator string(Autor a)
        {
            string datos;
            datos = a.nombre+" " + a.apellido;
            return datos;
        }
    }
}
