using System;
using System.CodeDom;
using System.Collections.Generic;
using System.Diagnostics.Contracts;
using System.Linq;
using System.Net.Http.Headers;
using System.Text;
using System.Threading.Tasks;

namespace ModeloParcial
{
    public abstract class Mascota
    {
        string nombre;
        string raza;


        public string Nombre
        {
            get { return this.nombre; }
            
        }
        public string Raza
        {
            get { return this.raza; }
            
        }

        public Mascota(string nombre,string raza)
        {
            this.raza = raza;
            this.nombre = nombre;
        }

        protected abstract string Ficha();
        
        protected virtual string DatosComletos()
        {
            StringBuilder sb = new StringBuilder();
            sb.AppendLine($"Nombre: {this.nombre}-Raza: {this.raza}");
            return sb.ToString();
        }

        public static bool operator  ==(Mascota m1,Mascota m2)
        {
            bool verificar = false;
            if((m1.nombre == m2.nombre) && (m1.raza==m2.raza))
            {
                verificar = true;
            }
            return verificar;

        }
        public static bool operator != (Mascota m1,Mascota m2)
        {
            return !(m1 == m2);
        }

    }
}
