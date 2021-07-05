using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;

namespace ModeloParcial
{
    public class Gato:Mascota
    {

            public Gato(string nombre, string raza):base(nombre,raza)
            {

            }
        protected override string Ficha()
        {
            StringBuilder sb = new StringBuilder();

            sb.AppendFormat("gato-{0}", base.DatosComletos());
          
            return sb.ToString();
        }
        public static bool operator ==(Gato g1, Gato g2)
        {
            bool verificar = false;
            if((g1.Nombre == g2.Nombre) && (g1.Raza== g2.Raza))
            {
                verificar = true;

            }
            return verificar;
        }
        public static bool operator !=(Gato g1, Gato g2)
        {
            return !(g1 == g2);
        }
        public override string ToString()
        {
            return this.Ficha();
        }
        public override bool Equals(object obj)
        {
            bool validar=false;
            if (obj is Gato)
            {
                validar = this == (Gato)obj;
            }
            return validar;
        }
    }
}
