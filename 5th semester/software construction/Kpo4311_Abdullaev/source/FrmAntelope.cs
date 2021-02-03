using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Kpo4311.Abdullaev.Lib;

namespace Kpo4311.Abdullaev.Main.source
{
    public partial class FrmAntelope : Form
    {
        public FrmAntelope()
        {
            InitializeComponent();
            _antelope = null;
        }

        private Antelope _antelope = null;

        public Antelope antelope
        {
            get { return _antelope; }
        }

        public void SetAntelope(Antelope antelope)
        {
            //инициализировать скрытое поля класса
            this._antelope = antelope;
            //присвоить значение данных сотрудника элементам редактирования
            this.textBoxName.Text = antelope.name;
            this.textBoxGroup.Text = antelope.group;
            this.textBoxHabitat.Text = antelope.habitat;
            this.textBoxPopulation.Text = "" + antelope.population;
        }

        private void FrmAntelope_Load(object sender, EventArgs e)
        {

        }

        private void textBoxName_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
