using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Kpo4311.Abdullaev.Lib
{
    public class States
    {
        public delegate bool ShowFileLoadResult();

        public static ShowFileLoadResult setShowFileLoadResultState(string state)
        {
            ShowFileLoadResult showFileLoadResultDelegate;
            if (state == "success")
            {
                showFileLoadResultDelegate = fileLoadSuccess;
            }
            else if (state == "failure")
            {
                showFileLoadResultDelegate = fileLoadFailure;
            }
            else
            {
                showFileLoadResultDelegate = fileLoadUnknownState;
            }
            return showFileLoadResultDelegate;
        }

        public static bool fileLoadSuccess()
        {
            MessageBox.Show("Файл успешно загружен!");
            return true;
        }

        public static bool fileLoadFailure()
        {
            MessageBox.Show("Файл не загружен!");
            return false;
        }

        public static bool fileLoadUnknownState()
        {
            MessageBox.Show("Неизвестная ошибка при загрузке файла!");
            return false;
        }
    }
}
