using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
   public class Biblioteca
    {
        int capacidad;
        List<Libro> libros;



        private Biblioteca()
        {
            this.libros = new List<Libro>();
        }
        private Biblioteca(int capacidad):this()
        {
            this.capacidad = capacidad;
        }



        public double PrecioDeManuales
        {
            get
            {
                double precioM = 0;

                foreach (Libro aux in this.libros)
                {
                    if (aux is Manual)
                    {
                        precioM = precioM + (Single)(Manual)aux;
                    }


                }
                return precioM;
            }

        }
        public double PrecioDeNovelas
        {
            get
            {
                double precioM = 0;

                foreach (Libro aux in this.libros)
                {
                    if (aux is Novela)
                    {
                        precioM = precioM + (Single)(Novela)aux;
                    }


                }
                return precioM;
            }

        }
        public double PrecioTotal
        {
            get
            {
                double total = 0;
                total = this.PrecioDeManuales + this.PrecioDeNovelas;
                return total;
            }

        }



        public static string Mostrar(Biblioteca b)
        {
            StringBuilder sb = new StringBuilder();
            sb.AppendLine($"Capacidad: {b.capacidad}");
            sb.AppendLine($"Total por manuales: {b.PrecioDeManuales}");
            sb.AppendLine($"Total por novelas: {b.PrecioDeNovelas}");
            sb.AppendLine($"Total: {b.PrecioTotal}");

            foreach(Libro aux in b.libros)
            {
                sb.AppendLine(aux.ToString());
            }
            return sb.ToString();


        }
        public static implicit operator Biblioteca(int capacidad)
        {
            return new Biblioteca(capacidad);
        }
        public static bool operator ==(Biblioteca b,Libro l)
        {
            bool rta=false;
            foreach(Libro aux in b.libros)
            {
                if(l.Equals(aux))
                {
                    rta = true;
                    break;
                }
            }
            return rta;
        }
        public static bool operator !=(Biblioteca b, Libro l)
        {
            return !(b == l);
        }
        public static Biblioteca operator +(Biblioteca b, Libro l)
        {
            if(b.capacidad>b.libros.Count && b!=l)
            {
                b.libros.Add(l);
            }

            return b;
        }
        private double ObtenerPrecio(ELibro tipoLibro)
        {
            double precion = 0;
            switch(tipoLibro)
            {
                case ELibro.PrecioDeManuales:
                    {
                        precion = this.PrecioDeManuales;
                        break;
                    }
                case ELibro.PrecioDeNovelas:
                    {
                        precion = this.PrecioDeNovelas;
                        break;
                    }
                case ELibro.PrecioTotal:
                    {
                        precion = this.PrecioTotal;
                        break;
                    }
            }
            return precion;
        }
    }
}
