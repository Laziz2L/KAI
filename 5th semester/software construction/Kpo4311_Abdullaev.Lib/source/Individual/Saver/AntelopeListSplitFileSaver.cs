using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Kpo4311.Abdullaev.Lib
{
    class AntelopeListSplitFileSaver : IAntelopeListSaver
    {
        private readonly string _datafilename;
        private List<Antelope> _antelopeList;
        public AntelopeListSplitFileSaver(string datafilename)
        {
            _datafilename = datafilename;
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
            _status = SaveStatus.None;
            try
            {
                if (_datafilename == "")
                {
                    _status = SaveStatus.FileNameIsEmpty;
                    throw new Exception("Путь к файлу пуст");
                }

                if (_antelopeList == null)
                {
                    _status = SaveStatus.NoData;
                    throw new Exception("Данных нет");
                }

                using (StreamWriter sw = new StreamWriter(_datafilename, false))
                {
                    if (_antelopeList.Count != 0)
                        for (int i = 0; i < _antelopeList.Count; i++)
                        {
                            try
                            {
                                Antelope det = _antelopeList.ElementAt(i);
                                sw.WriteLine(det.name + '|' + det.group + '|' + det.habitat + '|' + det.population);
                            }
                            catch (Exception ex)
                            {
                                LogUtility.ErrorLog(ex);
                                _status = SaveStatus.GeneralError;
                            }
                        }
                }
                _status = SaveStatus.Success;
            }
            catch (NullReferenceException ex)
            {
                LogUtility.ErrorLog(ex.Message);
                System.Windows.Forms.MessageBox.Show(ex.Message);
            }
            catch (FileNotFoundException ex)
            {
                LogUtility.ErrorLog(ex.Message);
                System.Windows.Forms.MessageBox.Show(ex.Message);
            }
            catch (Exception ex)
            {
                LogUtility.ErrorLog(ex.Message);
                _status = SaveStatus.GeneralError;
            }
        }
    }
}
