using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Kpo4311.Abdullaev.Lib
{
    public enum LoadStatus
    {
        None = 0,
        Success = 1,
        FileNameIsEmpty = -1,
        FileNotExists = -2,
        GeneralError = -100
    }

    public interface IAntelopeListLoader
    {
        List<Antelope> antelopeList { get; }
        LoadStatus status { get; }
        States.ShowFileLoadResult showLoadResult { get; }
        void Execute();
    }
}
