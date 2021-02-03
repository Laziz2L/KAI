namespace Kpo4311.Abdullaev.Main
{
    partial class FrmMain
    {
        /// <summary>
        /// Обязательная переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            this.MMenu = new System.Windows.Forms.MenuStrip();
            this.mmFile = new System.Windows.Forms.ToolStripMenuItem();
            this.mnExit = new System.Windows.Forms.ToolStripMenuItem();
            this.mnOpen = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.mmAntelopes = new System.Windows.Forms.ToolStripMenuItem();
            this.mnOpenAntelope = new System.Windows.Forms.ToolStripMenuItem();
            this.SStatus = new System.Windows.Forms.StatusStrip();
            this.dgvAntelope = new System.Windows.Forms.DataGridView();
            this.label1 = new System.Windows.Forms.Label();
            this.mnSave = new System.Windows.Forms.ToolStripMenuItem();
            this.MMenu.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dgvAntelope)).BeginInit();
            this.SuspendLayout();
            // 
            // MMenu
            // 
            this.MMenu.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.MMenu.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.mmFile,
            this.toolStripMenuItem1,
            this.mmAntelopes});
            this.MMenu.Location = new System.Drawing.Point(0, 0);
            this.MMenu.Name = "MMenu";
            this.MMenu.Size = new System.Drawing.Size(800, 28);
            this.MMenu.TabIndex = 0;
            this.MMenu.Text = "Mmenu";
            // 
            // mmFile
            // 
            this.mmFile.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.mnExit,
            this.mnOpen,
            this.mnSave});
            this.mmFile.Name = "mmFile";
            this.mmFile.Size = new System.Drawing.Size(72, 24);
            this.mmFile.Text = "1&.Файл ";
            this.mmFile.Click += new System.EventHandler(this.mmFile_Click);
            // 
            // mnExit
            // 
            this.mnExit.Name = "mnExit";
            this.mnExit.Size = new System.Drawing.Size(216, 26);
            this.mnExit.Text = "Выход";
            this.mnExit.Click += new System.EventHandler(this.mnExit_Click);
            // 
            // mnOpen
            // 
            this.mnOpen.Name = "mnOpen";
            this.mnOpen.Size = new System.Drawing.Size(216, 26);
            this.mnOpen.Text = "Открыть";
            this.mnOpen.Click += new System.EventHandler(this.mnOpen_Click);
            // 
            // toolStripMenuItem1
            // 
            this.toolStripMenuItem1.Name = "toolStripMenuItem1";
            this.toolStripMenuItem1.Size = new System.Drawing.Size(12, 24);
            // 
            // mmAntelopes
            // 
            this.mmAntelopes.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.mnOpenAntelope});
            this.mmAntelopes.Name = "mmAntelopes";
            this.mmAntelopes.Size = new System.Drawing.Size(103, 24);
            this.mmAntelopes.Text = "2&.Антилопы";
            this.mmAntelopes.Click += new System.EventHandler(this.mmAntelopes_Click);
            // 
            // mnOpenAntelope
            // 
            this.mnOpenAntelope.Name = "mnOpenAntelope";
            this.mnOpenAntelope.Size = new System.Drawing.Size(272, 26);
            this.mnOpenAntelope.Text = "Открыть данные антилопы";
            this.mnOpenAntelope.Click += new System.EventHandler(this.mnOpenAntelope_Click);
            // 
            // SStatus
            // 
            this.SStatus.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.SStatus.Location = new System.Drawing.Point(0, 428);
            this.SStatus.Name = "SStatus";
            this.SStatus.Size = new System.Drawing.Size(800, 22);
            this.SStatus.TabIndex = 1;
            this.SStatus.Text = "statusStrip1";
            // 
            // dgvAntelope
            // 
            this.dgvAntelope.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dgvAntelope.Location = new System.Drawing.Point(0, 45);
            this.dgvAntelope.Name = "dgvAntelope";
            this.dgvAntelope.RowTemplate.Height = 24;
            this.dgvAntelope.Size = new System.Drawing.Size(660, 341);
            this.dgvAntelope.TabIndex = 2;
            this.dgvAntelope.CellContentClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.dgvAntelope_CellContentClick);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(315, 402);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(46, 17);
            this.label1.TabIndex = 3;
            this.label1.Text = "label1";
            this.label1.Click += new System.EventHandler(this.label1_Click);
            // 
            // mnSave
            // 
            this.mnSave.Name = "mnSave";
            this.mnSave.Size = new System.Drawing.Size(216, 26);
            this.mnSave.Text = "Сохранить";
            this.mnSave.Click += new System.EventHandler(this.mnSave_Click);
            // 
            // FrmMain
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.dgvAntelope);
            this.Controls.Add(this.SStatus);
            this.Controls.Add(this.MMenu);
            this.MainMenuStrip = this.MMenu;
            this.Name = "FrmMain";
            this.Text = "КПО:4311:Абдуллаев";
            this.Load += new System.EventHandler(this.FrmMain_Load);
            this.MMenu.ResumeLayout(false);
            this.MMenu.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dgvAntelope)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip MMenu;
        private System.Windows.Forms.ToolStripMenuItem mmFile;
        private System.Windows.Forms.ToolStripMenuItem mnExit;
        private System.Windows.Forms.ToolStripMenuItem mnOpen;
        private System.Windows.Forms.StatusStrip SStatus;
        private System.Windows.Forms.DataGridView dgvAntelope;
        private System.Windows.Forms.ToolStripMenuItem toolStripMenuItem1;
        private System.Windows.Forms.ToolStripMenuItem mmAntelopes;
        private System.Windows.Forms.ToolStripMenuItem mnOpenAntelope;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.ToolStripMenuItem mnSave;
    }
}

