using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
    public class Sacapunta : Utiles
    {
        //Sacapunta-> deMetal:bool(público); 
        //Reutilizar UtilesToString en ToString() (mostrar TODOS los valores).
        public bool deMetal;

        public Sacapunta(bool deMetal, double precio, string marca) : base(marca, precio)
        {
            this.deMetal = deMetal;
        }
        public override bool PreciosCuidados
        {
            get
            {
                return false;
            }
        }

        public override string ToString()
        {
            return base.UtilesToString() + "\nEs de metal: " + this.deMetal + "\nEs Precios Cuidados: " + this.PreciosCuidados;
        }
    }
}
