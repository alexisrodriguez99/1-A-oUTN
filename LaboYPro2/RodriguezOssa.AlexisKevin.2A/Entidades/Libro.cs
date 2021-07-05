using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
   public abstract class Libro
    {
        protected Autor autor;
        protected int cantidadDePaginas;
        protected static Random genedaorDePagina;
        protected float precio;
        protected string titulo;

        

        public int CantidadDePaginas
        {
            get { 
                if(this.cantidadDePaginas==0)
                {
                   // Libro.genedaorDePagina = new Random();
                    this.cantidadDePaginas = genedaorDePagina.Next(10, 570);
                }
                return this.cantidadDePaginas; 
            }
            
        }

        static Libro()
        {
           genedaorDePagina = new Random();
        }
        public Libro(float precio, string titulo, Autor autor)
        {
            this.precio = precio;
            this.titulo = titulo;
            this.autor = autor;
        }
        public Libro(string titulo, string apellido, string nombre, float precio)
           :this(precio,titulo,new Autor(nombre,apellido))
        {

        }
       static string Mostrar(Libro l)
        {
            StringBuilder sb = new StringBuilder();
            sb.AppendLine($"AUTOR: {(string)l.autor}");
            sb.AppendLine($"TITULO: {l.titulo}");
            sb.AppendLine($"CANTIDAD DE PAGINAS: {l.CantidadDePaginas}");
            sb.AppendLine($"Precion: {l.precio}");

            return sb.ToString();

        }
        public static bool operator ==(Libro a, Libro b)
        {
            bool rta = false;
            if(a.titulo==b.titulo && a.autor==b.autor)
            {
                rta = true;
            }
            return rta;
        }
        public static bool operator !=(Libro a, Libro b)
        {
            return !(a == b);

        }
        public static explicit operator string(Libro l)
        {
            return Libro.Mostrar(l);
        }
    }
}
