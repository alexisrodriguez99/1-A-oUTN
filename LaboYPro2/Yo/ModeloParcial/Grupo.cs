using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace ModeloParcial
{
   public class Grupo
    {
        List<Mascota> manada;
        string nombre;
        static EtipoManada tipo;


        public EtipoManada Tipo
        {
            set { Grupo.tipo = value; }
        }
        static Grupo()
        {
            Grupo.tipo = EtipoManada.Unica;
        }
        private Grupo()
        {
            this.manada = new List<Mascota>();
        }
        public Grupo(string nombre) : this()
        {
            this.nombre = nombre;
        }
        public Grupo(string nombre, EtipoManada tipo) : this(nombre)
        {
            this.Tipo = tipo;
        }

        public static bool operator ==(Grupo g, Mascota m)
        {
            bool verificar = false;
            foreach (Mascota aux in g.manada)
            {
                if (/*aux == m*/ m.Equals(aux))
                {
                    verificar = true;
                    break;
                }
            }
            return verificar;
        }
        public static bool operator !=(Grupo g, Mascota m)
        {
            return !(g == m);
        }
        public static Grupo operator +(Grupo g,Mascota m)
        {
            if((g!=m))
            {
                g.manada.Add(m);
            }
            else
            {
                Console.WriteLine("Ya esta en la lista: {0}", m.ToString());
            }
            return g;
        }
        public static Grupo operator -(Grupo g, Mascota m)
        {
            if(g==m)
            {
                g.manada.Remove(m);
            }
            return g;
        }
        public static implicit operator string(Grupo g)
        {
            StringBuilder sb = new StringBuilder();
            sb.AppendLine($"Grupo: {g.nombre}- tipo: {Grupo.tipo}");
            sb.AppendLine($"Integrantes ({g.manada.Count})");
            foreach(Mascota aux in g.manada)
            {
                sb.AppendLine(aux.ToString());
            }
            return sb.ToString();
            
        }


    }
}
