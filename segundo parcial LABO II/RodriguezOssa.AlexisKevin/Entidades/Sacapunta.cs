using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
    public class Sacapunta : Utiles
    {
        public bool deMetal;
        public override bool PreciosCuidados
        {
            get { return true; }
        }
        public Sacapunta() { }
        public Sacapunta(bool deMetal, double precio, string marca)
            : base(marca, precio)
        {
            this.deMetal = deMetal;
        }
        protected override string UtilesToString()
        {
            StringBuilder sb = new StringBuilder();
            sb.Append(base.UtilesToString());
            sb.AppendLine($"es de metal: {this.deMetal}");

            return sb.ToString();
        }
        public override string ToString()
        {
            return this.UtilesToString();
        }
    }
}
