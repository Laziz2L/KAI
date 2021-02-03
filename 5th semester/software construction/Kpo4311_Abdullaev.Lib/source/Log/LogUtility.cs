using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Kpo4311.Abdullaev.Lib
{
    public static class LogUtility
    {
        public static void ErrorLog(string message)
        {
            File.AppendAllText("error.log", DateTime.Now.ToString("F") + " : " + message + "\n");
        }

        public static void ErrorLog(Exception ex)
        {
            File.AppendAllText("error.log", DateTime.Now.ToString("F") + " : " + ex.Message + "\n");
        }
    }
}

