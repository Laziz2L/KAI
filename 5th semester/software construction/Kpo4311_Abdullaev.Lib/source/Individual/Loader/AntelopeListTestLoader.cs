using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Kpo4311.Abdullaev.Lib
{
    public class AntelopeListTestLoader : IAntelopeListLoader
    {
        public AntelopeListTestLoader()
        {
            this._antelopeList = new List<Antelope>();
        }

        private LoadStatus _status = LoadStatus.None;
        public LoadStatus status
        {
            get { return _status; }
        }

        private readonly string _dataFileName = "";
        private List<Antelope> _antelopeList = new List<Antelope>();
        private States.ShowFileLoadResult _showLoadResult;


        public List<Antelope> antelopeList
        {
            get
            {
                return _antelopeList;
            }
        }

        public States.ShowFileLoadResult showLoadResult
        {
            get { return _showLoadResult; }
        }

        public void Execute()
        {   try
            {
                {
                    Antelope antelope = new Antelope()
                    {
                        name = "Джейран",
                        group = "A",
                        habitat = "Азия",
                        population = 30000
                    };

                    antelopeList.Add(antelope);
                }
                {
                    Antelope antelope = new Antelope()
                    {
                        name = "Гну",
                        group = "B",
                        habitat = "Африка",
                        population = 560000
                    };
                    antelopeList.Add(antelope);
                }
                {
                    Antelope antelope = new Antelope()
                    {
                        name = "Джейран",
                        group = "H",
                        habitat = "Африка",
                        population = 2500
                    };
                    antelopeList.Add(antelope);
                }
                _status = LoadStatus.Success;
            }
            catch (Exception ex)
            {
                LogUtility.ErrorLog(ex.Message);
                System.Windows.Forms.MessageBox.Show(ex.Message);
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

        public int TestCount()
        {
            int count = 0;
            count = _antelopeList.Count();
            return count;
        }


        //Этот метод проходит по всему списку антилоп и возвращает объект антилопы с самой большой популяцией
        public Antelope TheBiggestPopulationAntelope()
        {
            //используем конструкцию обработки ошибок
            try
            {   
                //если список антилоп пустой
                if (_antelopeList == null)
                {
                    //выбрасываем новое исключение с сообщением о том, что список антилоп пуст
                    throw new Exception("Список не создан!");
                }
                //создаем переменную антелопы, которая будет хранить результат работы программы, записываем туда первую антилопу из списка
                Antelope result = _antelopeList[0];
                //для каждой антилопы из списка
                foreach (Antelope antelope in _antelopeList)
                {
                    //если популяция текущей антилопы больше популяции результирующей
                    if (antelope.population > result.population)
                    {
                        //результату приравниваем текущую антилопу
                        result = antelope;
                    }
                }
                //возвращаем результат
                return result;
            }
            //если поймали исключение
            catch (Exception ex)
            {
                //показываем сообщение исключения
                MessageBox.Show("Ошибка: " + ex.Message);
                //записываем сообщение исключения в журнал
                LogUtility.ErrorLog("Ошибка: " + ex.Message);
                //возвращаем пустое значение
                return null;
            }
}
    }
}
