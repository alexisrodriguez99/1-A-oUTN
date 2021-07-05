using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;
using System.Data.SqlClient;
using System.Data.Sql;
using System.Data;

namespace Entidades
{
   public static class extencio
    {
        public static bool EliminarFruta(this Cajon<Manzana> c, int id)
        {
            SqlConnection cn = new SqlConnection(Properties.Settings.Default.Valor);
            SqlCommand coman = new SqlCommand();

            coman.Parameters.AddWithValue("@id", id);
            coman.CommandType = CommandType.Text;
            coman.CommandText = "DELETE FROM frutas WHERE id=@id";
            coman.Connection = cn;
            cn.Open();
            bool validad = false;
            int filas = coman.ExecuteNonQuery();
            if (filas > 0)
            {
                validad = true;
            }
            cn.Close();

            return validad;

        }
    }
}
