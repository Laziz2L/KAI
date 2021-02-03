using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Kpo4311.Abdullaev.Lib
{
    public class Antelope
    {
        public Antelope()
        {
            name = group = habitat = "";
            population = 0;
        }

        public string name { get; set; }
        public string group { get; set; }
        public string habitat { get; set; }
        public int population { get; set; }

        public string Inf()
        {
            return "Название - " + name + ", Группа - " + group + ", Место обитания - " + habitat +
               ", Численность популяции - " + population;
        }

        public string Test1()
        {
            return "Тест1";
        }
    }
}
