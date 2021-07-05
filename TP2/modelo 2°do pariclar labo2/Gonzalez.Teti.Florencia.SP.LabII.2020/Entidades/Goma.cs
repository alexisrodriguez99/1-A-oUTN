using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
    public class Goma : Utiles
    {
        //Goma-> soloLapiz:bool(público); PreciosCuidados->true; 
        //Reutilizar UtilesToString en ToString() (mostrar TODOS los valores).
        public bool soloLapiz;

        public Goma(bool soloLapiz, string marca, double precio) : base(marca, precio)
        {
            this.soloLapiz = soloLapiz;
        }
        public override bool PreciosCuidados
        {
            get
            {
                return true;
            }
        }

        public override string ToString()
        {
            return base.UtilesToString() + "\nEs solo para lapiz: " + this.soloLapiz + "\nEs Precios Cuidados: " + this.PreciosCuidados;
        }
    }
}
