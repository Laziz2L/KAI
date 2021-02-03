using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Kpo4311.Abdullaev.Lib;
using Kpo4311.Utility;

namespace Kpo4311.Lib
{
    public static class AppGlobalSettings
    {
        private static string _logPath = null;
        private static string _dataFileName;
        private static IAntelopeFactory _antelopeFactory;
        private static string _testOrSplit;

        public static string logPath
        {
            get => _logPath;
        }

        public static string dataFileName
        {
            get => _dataFileName;
        }

        public static IAntelopeFactory antelopeFactory
        {
            get => _antelopeFactory;
        }

        public static string testOrSplit
        {
            get => _testOrSplit;
        }

        public static void Initialize()
        {
            AppConfigUtility conf = new AppConfigUtility();

            _logPath = conf.AppSettings("logPath");
            //if (_logPath == null) _logPath = "error.log";

            _dataFileName = conf.AppSettings("dataFileName");
            if (conf.AppSettings("antelopeFactory") == "SplitFile")
                _testOrSplit = "splitFile";
            else
                _testOrSplit = "test";

            //System.Diagnostics.Debug.Assert(_logPath == null, "Не указано имя файла протокола.");
        }
    }
}
