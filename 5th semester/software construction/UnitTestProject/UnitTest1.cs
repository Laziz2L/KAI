
using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using Kpo4311_Abdullaev.Lib;
using Kpo4311.Abdullaev.Lib;
using System.Collections.Generic;
using Kpo4311.Lib;

namespace Kpo4311_Abdullaev.Lib
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void TestMethod1()
        {
            Antelope antelope = new Antelope();
            string actual = antelope.Test1();

            Assert.IsTrue(actual == "Тест1");
        }

        [TestMethod]
        public void TestMethod2()
        {
            AntelopeListTestLoader loader = new AntelopeListTestLoader();
            loader.Execute();
            int actual = loader.TestCount();
            int expected = 3;
            Assert.AreEqual(expected, actual);
        }

        [TestMethod]
        public void TestMethod3()
        {
            AntelopeListTestLoader loader = new AntelopeListTestLoader();
            loader.Execute();
            int actual = loader.TheBiggestPopulationAntelope().population;
            int expected = 560000;
            Console.WriteLine(actual);
            Assert.AreEqual(expected, actual);
        }
    }
}
