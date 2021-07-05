using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
    public abstract class Vehiculo
    {
        protected Fabricante fabricante;
        protected static Random generadorDeVelocidad;
        protected string modelo;
        protected float precio;
        protected int velocidadMaxima;


        public int VelocidadMaxima
        {
            get
            {
                if (velocidadMaxima == 0)
                {
                    this.velocidadMaxima = Vehiculo.generadorDeVelocidad.Next(100, 280);
                }
                return this.velocidadMaxima;
            }
        }


        static Vehiculo()
        {
            Vehiculo.generadorDeVelocidad = new Random();
        }

        public Vehiculo(float precio, string modelo, Fabricante fabri)
        {
            this.precio = precio;
            this.modelo = modelo;
            this.fabricante = fabri;
        }
        public Vehiculo(string marca, EPais pais, string modelo, float precio)
            : this(precio, modelo, new Fabricante(marca, pais))
        {

        }
        private static string Mostrar(Vehiculo v)
        {
            StringBuilder sb = new StringBuilder();
            sb.AppendLine($"FABRICANTE: {(String)v.fabricante}");
            sb.AppendLine($"MODELO: {v.modelo}");
            sb.AppendLine($"VELOCIDAD MAXIMA: {v.VelocidadMaxima}");
            sb.AppendLine($"PRECIO: {v.precio}");

            return sb.ToString();

        }
        public static bool operator ==(Vehiculo a, Vehiculo b)
        {
            bool respuesta = false;
            if (a.fabricante == b.fabricante && a.modelo == b.modelo)
            {
                respuesta = true;
            }
            return respuesta;
        }
        public static bool operator !=(Vehiculo a, Vehiculo b)
        {
            return !(a == b);
        }
        public static explicit operator String(Vehiculo v)
        {
            return Vehiculo.Mostrar(v);
        }


    }
}
