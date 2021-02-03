using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Kpo4311.Abdullaev.Lib
{
    class AntelopeTestFactory : IAntelopeFactory
    {
        public IAntelopeListSaver CreateAntelopeListSaver()
        {
            return new AntelopeListTestSaver();
        }

        public IAntelopeListLoader CreateAntelopeListLoader()
        {
            return new AntelopeListTestLoader();
        }
    }
 }

