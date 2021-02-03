using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Kpo4311.Abdullaev.Lib
{
    public class AntelopeListSplitFileLoader : IAntelopeListLoader
    {
        public AntelopeListSplitFileLoader(string dataFileName)
        {
            _dataFileName = dataFileName;
        }


        private readonly string _dataFileName;
        private List<Antelope> _antelopeList = new List<Antelope>();
        private LoadStatus _status = LoadStatus.None;
        private States.ShowFileLoadResult _showLoadResult;

        public List<Antelope> antelopeList
        {
            get => _antelopeList;
        }

        public LoadStatus status
        {
            get => _status;
        }

        public States.ShowFileLoadResult showLoadResult
        {
            get { return _showLoadResult; }
        }

        public void Message(string str)
        {
            MessageBox.Show(str);
        }

        public async void AsyncMessage()
        {
            await Task.Run(() => Message("Асинхронность!"));
        }

        public void Execute()
        {
            try
            {
                AsyncMessage();

                //Инициализировать статус выполнения чтения данных 
                _status = LoadStatus.None;

                //Если имя файла не указано то вызвать искючение
                if (_dataFileName == "")
                {
                    _status = LoadStatus.FileNameIsEmpty;
                    throw new Exception("Путь к файлу не указан");
                }
                //Если файл не существует то вызвать искючение
                if (!File.Exists(_dataFileName))
                {
                    _status = LoadStatus.FileNotExists;
                    throw new Exception("Файл не найден");
                }


                //..прочитать файл построчно
                StreamReader sr = null;
                using (sr = new StreamReader(_dataFileName))
                {
                    while (!sr.EndOfStream)
                    {
                        string str = sr.ReadLine();

                        try
                        {
                            string[] arr = str.Split('|');
                            Antelope antelope = new Antelope
                            {
                                name = arr[0],
                                group = arr[1],
                                habitat = arr[2],
                                population = int.Parse(arr[3])
                            };
                            _antelopeList.Add(antelope);
                        }
                        catch (Exception ex)
                        {
                            LogUtility.ErrorLog(ex);
                            _status = LoadStatus.GeneralError;
                        }
                    }
                }
                _status = LoadStatus.Success;
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
                _status = LoadStatus.GeneralError;
            }

            if (_status == LoadStatus.Success)
            {
                _showLoadResult = States.setShowFileLoadResultState("success");
            }
            else
            {
                _showLoadResult = States.setShowFileLoadResultState("failure");
            }
        }

        
    }
}

