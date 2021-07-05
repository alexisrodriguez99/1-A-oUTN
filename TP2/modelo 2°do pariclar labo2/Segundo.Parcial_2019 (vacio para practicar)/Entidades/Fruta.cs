using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
    public abstract class Fruta
    {
        protected string _color;
        protected double _peso;

        public abstract bool TieneCarozo
        { get; }

        public Fruta(string color, double peso)
        {
            this._color = color;
            this._peso = peso;
        }
        protected virtual string FrutaToString()
        {
            StringBuilder sb = new StringBuilder();
            sb.AppendLine($"Color= {this._color}");
            sb.AppendLine($"Peso= {this._peso}");
            return sb.ToString();
        }


    }
}
