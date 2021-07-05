using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
    public class Auto : Vehiculo
    {
        ETipo tipo;

        public Auto(string modelo, float precio, Fabricante fabri, ETipo tipo)
            : base(precio, modelo, fabri)
        {
            this.tipo = tipo;
        }

        public static bool operator ==(Auto a, Auto b)
        {
            bool respuesta = false;
            if ((Vehiculo)a == b && a.tipo == b.tipo)
            {
                respuesta = true;
            }
            return respuesta;
        }
        public static bool operator !=(Auto a, Auto b)
        {
            return !(a == b);
        }
        public static explicit operator Single(Auto a)
        {
            return a.precio;
        }
        public override bool Equals(object obj)
        {
            bool rta = false;
            if (obj is Auto)
            {
                rta = this == (Auto)obj;
            }
            return rta;
        }
        public override string ToString()
        {
            StringBuilder sb = new StringBuilder();
            sb.Append((String)this);
            sb.AppendLine($"TIPO: {this.tipo}");
            return sb.ToString();
        }



    }
}
