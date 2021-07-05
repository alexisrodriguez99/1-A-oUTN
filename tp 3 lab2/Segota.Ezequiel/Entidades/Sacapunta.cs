using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
    public class Sacapunta:Utiles
    {
        public bool deMetal;

        public Sacapunta(bool deMetal,  double precio, string marca)
            : base(marca, precio)
        {
            this.deMetal = deMetal;
        }

        public override bool PreciosCuidados
        {
            get { return false; }
        }

        protected override string UtilesToString()
        {
            StringBuilder sb = new StringBuilder();

            sb.Append(base.UtilesToString());
            sb.AppendFormat("- De Metal: {0} - PreciosCuidados: {1}", this.deMetal, this.PreciosCuidados);

            return sb.ToString();
        }
        public override string ToString()
        {
            return this.UtilesToString();
        }
        
    }
}
