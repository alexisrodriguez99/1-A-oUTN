using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
   public class Novela:Libro
    {
        public EGenero genero;

        public Novela(string titulo, float precio, Autor autor,EGenero genero ) : base(precio,titulo,autor)
        {
            this.genero = genero;
        }
        public override bool Equals(object obj)
        {
            bool sonIguales = false;
            if (obj is Novela)
            {
                sonIguales = this == (Novela)obj;
            }
            return sonIguales;
        }
        public static bool operator ==(Novela a, Novela b)
        {
            bool sonIguales = false;
            if ((a.genero == b.genero) && ((Libro)a == b))
            {
                sonIguales = true;
            }
            return sonIguales;
        }
        public static bool operator !=(Novela a, Novela b)
        {
            return !(a == b);
        }
        public static explicit operator Single(Novela n)
        {
            return n.precio;
        }
        public override string ToString()
        {
            StringBuilder sb = new StringBuilder();
            sb.Append((string)this);
            sb.AppendLine($"TIPO: {this.genero}");
            return sb.ToString();
        }
    }
}
