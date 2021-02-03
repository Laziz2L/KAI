using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Castle.Windsor;
using Castle.MicroKernel.Registration;
using Kpo4311.Lib;
using Kpo4311.Abdullaev.Lib;

namespace Kpo4311_Abdullaev.Lib
{
    public static class IoC
    {
        public static WindsorContainer container { get; private set; }
        public static int choose;

        static IoC()
        {
            container = new WindsorContainer();

            if (AppGlobalSettings.testOrSplit == "splitFile")
            {
                container.Register(Component
                    .For<IAntelopeListLoader>()
                    .ImplementedBy<AntelopeListSplitFileLoader>()
                    .DynamicParameters((r, k) => { k["dataFileName"] = AppGlobalSettings.dataFileName; })
                    );
                container.Register(Component
                    .For<IAntelopeListSaver>()
                    .ImplementedBy<AntelopeListSplitFileSaver>()
                    .DynamicParameters((r, k) => { k["dataFileName"] = AppGlobalSettings.dataFileName; })
                    );
            }
            else if (AppGlobalSettings.testOrSplit == "test")
            {
                container.Register(Component
                    .For<IAntelopeListLoader>()
                    .ImplementedBy<AntelopeListTestLoader>()
                    );
                container.Register(Component
                    .For<IAntelopeListSaver>()
                    .ImplementedBy<AntelopeListTestSaver>()
                    );
            }
        }

    }
}