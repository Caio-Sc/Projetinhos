using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Medias
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void Prova1_TextChanged(object sender, EventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
                double Media;
                string stringValue = Prova1.Text.Replace('.', ',');
                if (stringValue == "")
                {
                    respostas.Text = "faltou a nota da P1";
                    return;
                }
                float P1 = float.Parse(stringValue);
                stringValue = Prova2.Text.Replace('.', ',');
                if (stringValue == "")
                {
                    respostas.Text = "faltou a nota da P2";
                    return;
                }
                float P2 = float.Parse(stringValue);
                stringValue = Atividade1.Text.Replace('.', ',');
                if (stringValue == "")
                {
                    respostas.Text = "faltou a nota da A1";
                    return;
                }
                float A1 = float.Parse(stringValue);
                stringValue = Atividade2.Text.Replace('.', ',');
                if (stringValue == "")
                {
                    respostas.Text = "faltou a nota da A2";
                    return;
                }
                float A2 = float.Parse(stringValue);
                if (P1 > 10.0 || P2 > 10 || A1 > 10 || A2 > 10)
                {
                    respostas.Text = "Os números não podem ser maiores que 10";
                }
                else {
                Media = ((((2 * P1 + A1) / 3) + ((2 * P2 + A2) / 3)) / 2) * (0.8 + (0.04 * 5));
                Prova1.Visible = false;
                Prova2.Visible = false;
                Atividade1.Visible = false;
                Atividade2.Visible = false;
                label1.Visible = false;
                label2.Visible = false;
                label3.Visible = false;
                label4.Visible = false;
                respostas.Visible = false;
                if (Media >= 5)
                {
                    label5.Text = "Você Passou!";
                    label6.Text = string.Format("Nota: {0:0.00}", Media);
                    label5.ForeColor = Color.Green;
                    label6.ForeColor = Color.Green;
                    label5.Visible = true;
                    label6.Visible = true;
                    button2.Visible = true;
                }
                else if (Media > 4.9 && Media < 5)
                {
                    label5.Text = "Talvez você tenha passado";
                    label5.Font = new Font("Gill Sans Ultra Bold", 15);
                    label6.Text = string.Format("Nota: {0:0.00}", Media);
                    label5.ForeColor = Color.Blue;
                    label6.ForeColor = Color.Blue;
                    label5.Visible = true;
                    label6.Visible = true;
                    button2.Visible = true;
                }
                else
                {
                    label5.Text = "Você Reprovou!";
                    label6.Text = string.Format("Nota: {0:0.00}", Media);
                    label5.ForeColor = Color.Red;
                    label6.ForeColor = Color.Red;
                    label5.Visible = true;
                    label6.Visible = true;
                    button2.Visible = true;
                }
            }
                
            
        }
        private void button2_Click(object sender, EventArgs e)
        {
            Prova1.Visible = true;
            Prova2.Visible = true;
            Atividade1.Visible = true;
            Atividade2.Visible = true;
            label1.Visible = true;
            label2.Visible = true;
            label3.Visible = true;
            label4.Visible = true;
            respostas.Visible = true;
            label5.Visible = false;
            label6.Visible = false;
            button2.Visible = false;
            respostas.Text = "Esperando input";
            label5.Font = new Font("Gill Sans Ultra Bold", 25);
        }

        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {
            if(TopMost == true)
            {
                TopMost = false;
            }
            else
            {
                TopMost = true;
            }
            
        }
    } 
}


