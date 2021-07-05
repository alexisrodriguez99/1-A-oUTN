using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
   public class Banana:Fruta
    {
        protected string _paisOrigen;
        public string Nombre
        {
            get { return "Banana"; }
        }
        public override bool TieneCarozo
        {
            get { return false; }
        }
        public Banana() : base(null, 0)
        {

        }

        public Banana(string color, double peso, string pais) : base(color, peso)
        {
            this._paisOrigen = pais;
        }

        protected override string FrutaToString()
        {
            StringBuilder sb = new StringBuilder();
            sb.AppendLine($"Fruta: {this.Nombre}");
            sb.AppendLine(base.FrutaToString());
            sb.AppendLine($"pais de origen= {this._paisOrigen}");
            sb.AppendLine($"Carozo= {this.TieneCarozo}");
            return sb.ToString();
        }
        public override string ToString()
        {
            return this.FrutaToString();
        }
    }
}
