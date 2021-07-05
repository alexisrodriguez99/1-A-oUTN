using System;
using System.CodeDom;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
   public class Manual:Libro
    {
        ETipo tipo;

        public Manual(string titulo, string apellido, string nombre, float precio, ETipo tipo)
            :base(titulo,apellido,nombre,precio)
        {
            this.tipo = tipo;
        }

        public override bool Equals(object obj)
        {
            bool rta = false;
            if(obj is Manual)
            {
                rta = this == (Manual)obj;
            }
            return rta;
        }
        public static bool operator ==(Manual a,Manual b)
        {
            bool rta = false;
            if((Libro)a==b && a.tipo==b.tipo)
            {
                rta = true;
            }
            return rta;
        }
        public static bool operator !=(Manual a, Manual b)
        {
            return !(a == b);
        }
        public static explicit operator Single(Manual m)
        {
            return m.precio;
        }
        public override string ToString()
        {
            StringBuilder sb = new StringBuilder();
            sb.Append((string)this);
            sb.AppendLine($"TIPO: {this.tipo}");
            return sb.ToString();
        }
    }

}
