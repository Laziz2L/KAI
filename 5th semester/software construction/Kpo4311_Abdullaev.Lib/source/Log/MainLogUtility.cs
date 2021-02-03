using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using Kpo4311.Lib;

namespace Kpo4311.Abdullaev.Lib
{
    class MainLogUtility
    {
        private static string _logPath = AppGlobalSettings.logPath;

        public static void ErrorLog(Exception ex)
        {
            FileStream fs = null;
            try
            {
                fs = File.OpenWrite(_logPath);
                byte[] sendData = Encoding.UTF8.GetBytes(DateTime.Now.ToString() + " " + ex.Message + "\n");
                fs.Write(sendData, 0, sendData.Count());

            }
            catch (Exception e)
            {
                System.Windows.Forms.MessageBox.Show(DateTime.Now.ToString() + " " + e.Message + Environment.NewLine);
            }
            finally
            {
                fs.Dispose();
            }
        }
    }
}
