using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
    public class Moto : Vehiculo
    {
        ECilindrada cilindrada;

        public Moto(string marca, EPais pais, string modelo, float precio, ECilindrada cilindrada)
             : base(marca, pais, modelo, precio)
        {
            this.cilindrada = cilindrada;
        }
        public static bool operator ==(Moto a, Moto b)
        {
            bool respuesta = false;
            if ((Vehiculo)a == b && a.cilindrada == b.cilindrada)
            {
                respuesta = true;
            }
            return respuesta;
        }
        public static bool operator !=(Moto a, Moto b)
        {
            return !(a == b);
        }
        public static implicit operator Single(Moto a)
        {
            return a.precio;
        }
        public override bool Equals(object obj)
        {
            bool rta = false;
            if (obj is Moto)
            {
                rta = this == (Moto)obj;
            }
            return rta;
        }
        public override string ToString()
        {
            StringBuilder sb = new StringBuilder();
            sb.Append((String)this);
            sb.AppendLine($"CILINDRADA: {this.cilindrada}");
            return sb.ToString();
        }

    }
}
