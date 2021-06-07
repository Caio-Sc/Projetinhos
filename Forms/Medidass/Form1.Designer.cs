
using System;

namespace Medias
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.button1 = new System.Windows.Forms.Button();
            this.Prova1 = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.Prova2 = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.Atividade1 = new System.Windows.Forms.TextBox();
            this.Atividade2 = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.respostas = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.button2 = new System.Windows.Forms.Button();
            this.checkBox1 = new System.Windows.Forms.CheckBox();
            this.SuspendLayout();
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(135, 201);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(123, 51);
            this.button1.TabIndex = 0;
            this.button1.Text = "Gerar Nota";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // Prova1
            // 
            this.Prova1.Cursor = System.Windows.Forms.Cursors.Default;
            this.Prova1.Location = new System.Drawing.Point(75, 67);
            this.Prova1.Name = "Prova1";
            this.Prova1.Size = new System.Drawing.Size(48, 23);
            this.Prova1.TabIndex = 1;
            this.Prova1.TextChanged += new System.EventHandler(this.Prova1_TextChanged);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Cursor = System.Windows.Forms.Cursors.Default;
            this.label1.Location = new System.Drawing.Point(42, 33);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(111, 15);
            this.label1.TabIndex = 2;
            this.label1.Text = "Sua nota na prova 1";
            this.label1.Click += new System.EventHandler(this.label1_Click);
            // 
            // Prova2
            // 
            this.Prova2.Location = new System.Drawing.Point(268, 67);
            this.Prova2.Name = "Prova2";
            this.Prova2.Size = new System.Drawing.Size(48, 23);
            this.Prova2.TabIndex = 3;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Cursor = System.Windows.Forms.Cursors.Default;
            this.label2.Location = new System.Drawing.Point(235, 33);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(111, 15);
            this.label2.TabIndex = 4;
            this.label2.Text = "Sua nota na prova 2";
            // 
            // Atividade1
            // 
            this.Atividade1.Location = new System.Drawing.Point(75, 160);
            this.Atividade1.Name = "Atividade1";
            this.Atividade1.Size = new System.Drawing.Size(48, 23);
            this.Atividade1.TabIndex = 5;
            // 
            // Atividade2
            // 
            this.Atividade2.Location = new System.Drawing.Point(268, 160);
            this.Atividade2.Name = "Atividade2";
            this.Atividade2.Size = new System.Drawing.Size(48, 23);
            this.Atividade2.TabIndex = 6;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(12, 129);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(177, 15);
            this.label3.TabIndex = 7;
            this.label3.Text = "Soma das atividades antes da P1";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(220, 129);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(177, 15);
            this.label4.TabIndex = 8;
            this.label4.Text = "Soma das atividades antes da P2";
            // 
            // respostas
            // 
            this.respostas.AutoSize = true;
            this.respostas.Location = new System.Drawing.Point(135, 255);
            this.respostas.Name = "respostas";
            this.respostas.Size = new System.Drawing.Size(93, 15);
            this.respostas.TabIndex = 9;
            this.respostas.Text = "Esperando input";
            this.respostas.TextAlign = System.Drawing.ContentAlignment.BottomCenter;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("Gill Sans Ultra Bold", 25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.label5.ForeColor = System.Drawing.Color.Red;
            this.label5.Location = new System.Drawing.Point(62, 107);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(152, 48);
            this.label5.TabIndex = 10;
            this.label5.Text = "label5";
            this.label5.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.label5.Visible = false;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Font = new System.Drawing.Font("Gill Sans Ultra Bold", 25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.label6.ForeColor = System.Drawing.Color.Red;
            this.label6.Location = new System.Drawing.Point(75, 48);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(49, 48);
            this.label6.TabIndex = 11;
            this.label6.Text = "6";
            this.label6.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.label6.Visible = false;
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(135, 201);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(123, 51);
            this.button2.TabIndex = 12;
            this.button2.Text = "Voltar";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Visible = false;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // checkBox1
            // 
            this.checkBox1.AutoSize = true;
            this.checkBox1.Location = new System.Drawing.Point(284, 233);
            this.checkBox1.Name = "checkBox1";
            this.checkBox1.Size = new System.Drawing.Size(117, 19);
            this.checkBox1.TabIndex = 13;
            this.checkBox1.Text = "Sempre no Topo?";
            this.checkBox1.UseVisualStyleBackColor = true;
            this.checkBox1.CheckedChanged += new System.EventHandler(this.checkBox1_CheckedChanged);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(413, 296);
            this.Controls.Add(this.checkBox1);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.respostas);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.Atividade2);
            this.Controls.Add(this.Atividade1);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.Prova2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.Prova1);
            this.Controls.Add(this.button1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MaximizeBox = false;
            this.Name = "Form1";
            this.Text = "     ";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.TextBox Prova1;
        internal System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox Prova2;
        internal System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox Atividade1;
        private System.Windows.Forms.TextBox Atividade2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label respostas;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.CheckBox checkBox1;
    }
}

