using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Kpo4311.Abdullaev.Lib;
using Kpo4311.Abdullaev.Main.source;
using Kpo4311.Lib;
using Kpo4311_Abdullaev.Lib;

namespace Kpo4311.Abdullaev.Main
{
    public partial class FrmMain : Form
    {
        public FrmMain()
        {
            InitializeComponent();

            label1.Text = "Журнал: " + AppGlobalSettings.logPath +
                "\nИмя файла данных: " + AppGlobalSettings.dataFileName;
        }

        private List<Antelope> antelopeList = new List<Antelope>();
        private BindingSource bsAntelope = new BindingSource();

        private void FrmMain_Load(object sender, EventArgs e)
        {

        }

        private void mmFile_Click(object sender, EventArgs e)
        {

        }

        private void mnExit_Click(object sender, EventArgs e)
        {
            Close();
        }

        private void mnOpen_Click(object sender, EventArgs e)
        {
            try
            {
                ////Вызов исключения "Метод не реализован"
                //throw new NotImplementedException();      
                ////Вызов базового исключения                 
                //throw new Exception("Неправильные входные параметры");
                //AntelopeListTestLoader loader = new AntelopeListTestLoader();
                //IAntelopeListLoader loader = AppGlobalSettings.antelopeFactory.CreateAntelopeListLoader();

                //throw new AntelopeListLoadException("файл не открывается");

                IAntelopeListLoader loader = IoC.container.Resolve<IAntelopeListLoader>();
                loader.Execute();

                antelopeList = loader.antelopeList;
                bsAntelope.DataSource = antelopeList;
                dgvAntelope.DataSource = bsAntelope;

                bool loadFlagResult = loader.showLoadResult();
            }
            //обработка исключения "Метод не реализован"             
            catch (NotImplementedException ex)
            {
                MessageBox.Show("Ошибка №1: " + ex.Message);
            }
            //обработка остальных исключений            
            catch (AntelopeListLoadException ex)
            {
                MessageBox.Show("Ошибка №2: " + ex.Message);
                LogUtility.ErrorLog("Ошибка №2: " + ex.Message);
            }
        }

        private void dgvAntelope_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void mmAntelopes_Click(object sender, EventArgs e)
        {

        }

        private void mnOpenAntelope_Click(object sender, EventArgs e)
        {
            try
            {
                // Создать экземпляр формы
                FrmAntelope frmAntelope = new FrmAntelope();

                // Задать ссылку на текущий объект в таблице
                Antelope antelope = (bsAntelope.Current as Antelope);
                frmAntelope.SetAntelope(antelope);

                // Открыть форму в модальном режиме
                frmAntelope.ShowDialog();
            }
            //обработка исключения "Метод не реализован"
            catch (NotImplementedException ex)
            {
                MessageBox.Show("Ошибка №1: " + ex.Message);
            }
            //обработка остальных исключений
            catch (Exception ex)
            {
                MessageBox.Show("Ошибка №2: " + ex.Message);
                LogUtility.ErrorLog("Ошибка №2: " + ex.Message);
            }
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void mnSave_Click(object sender, EventArgs e)
        {
            try
            {
                if (antelopeList == null || antelopeList.Count == 0)
                    throw new Exception("Таблица пуста");

                //IAntelopeListSaver saver = AppGlobalSettings.antelopeFactory.CreateAntelopeListSaver();
                IAntelopeListSaver saver = IoC.container.Resolve<IAntelopeListSaver>();

                saver.antelopeList = antelopeList;
                saver.Execute();
            }
            //обработка исключения "Метод не реализован"
            catch (NotImplementedException ex)
            {
                MessageBox.Show("Ошибка №1: " + ex.Message);
            }
            //обработка остальных исключений
            catch (Exception ex)
            {
                MessageBox.Show("Ошибка №2: " + ex.Message);
                LogUtility.ErrorLog("Ошибка №2: " + ex.Message);
            }
        }
    }
}
