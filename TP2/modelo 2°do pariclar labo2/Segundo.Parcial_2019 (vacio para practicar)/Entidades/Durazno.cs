using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
   public class Durazno:Fruta
    {
        protected int _cantPelusa;
        public string Nombre
        {
            get { return "Manzana"; }
        }
        public override bool TieneCarozo
        {
            get { return true; }
        }
        public Durazno() : base(null, 0)
        {

        }

        public Durazno(string color, double peso, int pelusa) : base(color, peso)
        {
            this._cantPelusa = pelusa;
        }

        protected override string FrutaToString()
        {
            StringBuilder sb = new StringBuilder();
            sb.AppendLine($"Fruta: {this.Nombre}");
            sb.AppendLine(base.FrutaToString());
            sb.AppendLine($"Cantidad de pelusa= {this._cantPelusa}");
            sb.AppendLine($"Carozo= {this.TieneCarozo}");
            return sb.ToString();
        }
        public override string ToString()
        {
            return this.FrutaToString();
        }
    }
}
