using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Kpo4311.Abdullaev.Lib
{
    public interface IAntelopeFactory
    {
        IAntelopeListSaver CreateAntelopeListSaver();
        IAntelopeListLoader CreateAntelopeListLoader();
    }
}
