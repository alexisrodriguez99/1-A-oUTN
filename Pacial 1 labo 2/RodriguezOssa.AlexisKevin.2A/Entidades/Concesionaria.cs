using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices.WindowsRuntime;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
    public class Concesionaria
    {
        int capacidad;
        List<Vehiculo> vehiculos;


        public double PrecioDeAutos
        {
            get
            {
                double precioAutos = 0;
                foreach (Vehiculo aux in this.vehiculos)
                {
                    if (aux is Auto)
                    {
                        precioAutos = precioAutos + (Single)(Auto)aux;
                    }
                }
                return precioAutos;
            }
        }
        public double PrecioDeMotos
        {
            get
            {
                double precioMotos = 0;
                foreach (Vehiculo aux in this.vehiculos)
                {
                    if (aux is Moto)
                    {
                        precioMotos = precioMotos + (Single)(Moto)aux;
                    }
                }
                return precioMotos;
            }
        }
        public double PrecioTotal
        {
            get
            {
                double precioTotal = 0;
                precioTotal = this.PrecioDeAutos + this.PrecioDeMotos;

                return precioTotal;
            }
        }
        private Concesionaria()
        {
            this.vehiculos = new List<Vehiculo>();
        }
        private Concesionaria(int capacidad) : this()
        {
            this.capacidad = capacidad;
        }
        public static implicit operator Concesionaria(int capacidad)
        {
            return new Concesionaria(capacidad);
        }
        public static bool operator ==(Concesionaria c, Vehiculo v)
        {
            bool respuesta = false;
            foreach (Vehiculo aux in c.vehiculos)
            {
                if (v.Equals(aux))
                {
                    respuesta = true;
                    break;
                }
            }
            return respuesta;
        }
        public static bool operator !=(Concesionaria c, Vehiculo v)
        {
            return !(c == v);
        }
        public static Concesionaria operator +(Concesionaria c, Vehiculo v)
        {
            if (c.vehiculos.Count < c.capacidad)
            {
                if (c != v)
                {
                    c.vehiculos.Add(v);
                }
                else
                {
                    Console.WriteLine("El vehiculo ya esta en la concecionaria!!!");
                }
            }
            else
            {
                Console.WriteLine("No hay mas lugar en la concesionaria!!!");
            }
            return c;
        }
        private double ObtenerPrecio(EVehiculo tipoVehiculo)
        {
            double precio = 0;
            switch (tipoVehiculo)
            {
                case EVehiculo.PrecioDeAutos:
                    {
                        precio = this.PrecioDeAutos;
                        break;
                    }
                case EVehiculo.PrecioDeMotos:
                    {
                        precio = this.PrecioDeMotos;
                        break;
                    }
                case EVehiculo.PrecioTotal:
                    {
                        precio = this.PrecioTotal;
                        break;
                    }
            }
            return precio;

        }

        public static string Mostrar(Concesionaria c)
        {
            StringBuilder sb = new StringBuilder();
            sb.AppendLine($"Capacidad: {c.capacidad}");
            sb.AppendLine($"Total por autos: {c.ObtenerPrecio(EVehiculo.PrecioDeAutos)}");
            sb.AppendLine($"Total por Motos: {c.ObtenerPrecio(EVehiculo.PrecioDeMotos)}");
            sb.AppendLine($"Total: {c.ObtenerPrecio(EVehiculo.PrecioTotal)}");
            sb.AppendLine("***************************************");
            sb.AppendLine("Listado de vehiculos");
            sb.AppendLine("***************************************");
            foreach (Vehiculo aux in c.vehiculos)
            {
                sb.AppendLine(aux.ToString());
            }
            return sb.ToString();
        }
    }
}
