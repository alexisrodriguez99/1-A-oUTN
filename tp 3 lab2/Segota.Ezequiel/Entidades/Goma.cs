using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
    public class Goma:Utiles
    {
        public bool soloLapiz;

        public Goma(bool soloLapiz, string marca, double precio)
            :base(marca,precio)
        {
            this.soloLapiz = soloLapiz;
        }

        public override bool PreciosCuidados
        {
            get { return true; }
        }

        protected override string UtilesToString()
        {
            StringBuilder sb = new StringBuilder();

            sb.Append(base.UtilesToString());
            sb.AppendFormat("- Solo Lapiz: {0} - PreciosCuidados: {1}", this.soloLapiz,this.PreciosCuidados);

            return sb.ToString();
        }
        
        public override string ToString()
        {
            return this.UtilesToString();
        }
    }
}
