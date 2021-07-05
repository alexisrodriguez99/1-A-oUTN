using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using System.Text;
using System.Threading.Tasks;

namespace ModeloParcial
{
   public class Perro:Mascota
    {
        int edad;
        bool esAlfa;

        public Perro(string nombre,string raza):base(nombre,raza)
        {
            this.edad = 0;
            this.esAlfa = false;
        }
        public Perro(string nombre,string raza,int edad,bool esAlfa):this(nombre,raza)
        {
            this.edad = edad;
            this.esAlfa = esAlfa;
        }
        protected override string Ficha()
        {
            StringBuilder sb = new StringBuilder();

            sb.AppendFormat("perro-{0}",base.DatosComletos());
            if(this.esAlfa==true)
            {
                sb.AppendFormat(", alfa de la manada, edad-{0}", this.edad);
            }
            else
            {
                sb.AppendFormat(", edad-{0}", this.edad);
            }
            return  sb.ToString();
        }
        public static bool operator ==(Perro p1,Perro p2)
        {
            bool validar=false;
            if (((Mascota)p1 == (Mascota)p2) && ((int)p1 == (int)p2))
            {
                validar = true;
            }
            return validar;
        }
        public static bool operator !=(Perro p1, Perro p2)
        {
            return !(p1 == p2);
        }

        public override string ToString()
        {
            return this.Ficha();
        }
        public override bool Equals(object obj)
        {
            bool validar = false;
            if(obj is Perro)
            {
                validar = this == (Perro)obj;
            }
            return validar;
        }
        public static explicit operator int(Perro p)
        {
            return p.edad;
        }
    }
}
