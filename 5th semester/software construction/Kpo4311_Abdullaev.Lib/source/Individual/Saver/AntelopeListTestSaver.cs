using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Kpo4311.Abdullaev.Lib
{
    class AntelopeListTestSaver : IAntelopeListSaver
    {
        private List<Antelope> _antelopeList;
        public AntelopeListTestSaver()
        {
            _antelopeList = null;
        }

        public List<Antelope> antelopeList
        {
            set => _antelopeList = value;
        }

        private SaveStatus _status = SaveStatus.None;
        public SaveStatus status
        {
            get => _status;
        }

        public void Execute()
        {
            try
            {
                if (_antelopeList == null) throw new Exception("Данных нет");
                _status = SaveStatus.Success;
            }
            catch (Exception ex)
            {
                MessageBox.Show("Ошибка: " + ex.Message);
                LogUtility.ErrorLog(ex);
                _status = SaveStatus.NoData;
            }
        }
    }
}
