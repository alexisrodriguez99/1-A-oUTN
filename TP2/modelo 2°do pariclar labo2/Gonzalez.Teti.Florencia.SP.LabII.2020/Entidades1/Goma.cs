using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades1
{
   public class Goma:Utiles
    {
        public bool soloLapiz;

        public override bool PreciosCuidados
        {
            get {return true; }
        }
        public Goma() { }
        public Goma(bool soloLapiz,string marca, double precio)
            :base(marca,precio)
        {
            this.soloLapiz = soloLapiz;
        }
        protected override string UtilesToString()
        {
            StringBuilder sb = new StringBuilder();
            sb.Append(base.UtilesToString());
            sb.AppendLine($"solo lapiz: {this.soloLapiz}");

            return sb.ToString();
        }
        public override string ToString()
        {
            return this.UtilesToString();
        }
    }
}
