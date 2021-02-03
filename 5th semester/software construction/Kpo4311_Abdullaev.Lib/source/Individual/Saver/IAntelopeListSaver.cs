using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;



namespace Kpo4311.Abdullaev.Lib
{
    public enum SaveStatus
    {
        None = 0,
        Success = 1,
        FileNameIsEmpty = -1,
        FileNotExists = -2,
        NoData = -3,
        GeneralError = -100
    }

    public interface IAntelopeListSaver
    {
        List<Antelope> antelopeList { set; }
        SaveStatus status { get; }
        void Execute();
    }
}
