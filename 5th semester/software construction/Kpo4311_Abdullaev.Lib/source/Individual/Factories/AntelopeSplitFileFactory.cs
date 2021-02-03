using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Kpo4311.Lib;

namespace Kpo4311.Abdullaev.Lib
{
    class AntelopeSplitFileFactory : IAntelopeFactory
    {
        public IAntelopeListSaver CreateAntelopeListSaver()
        {
            return new AntelopeListSplitFileSaver(AppGlobalSettings.dataFileName);

        }
        public IAntelopeListLoader CreateAntelopeListLoader()
        {
            return new AntelopeListSplitFileLoader(AppGlobalSettings.dataFileName);
        }
    }
}
