using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Text.RegularExpressions;
using System.IO;

namespace Ceaser
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            List<char> abc = new List<char> { ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' }; // lista char
            if (checkBox3.Checked == true)
            {
            abc.Remove(abc[0]);
            }
            string valor = coeficiente.Text.Replace(",", "");
            valor = valor.Replace(".", "");
            string[] brute = new string[26];
            if (valor == "")
            {
                resposta.Text = "Faltou coeficiente";
            }
            else
            {
                string respostaf = "";
                string codigu = codigo.Text.ToLower();
                List<char> codi = new List<char>(codigu);
                int k = Convert.ToInt32(valor);
                int lenght = abc.Count;
                if(checkBox1.Checked == true)
                {
                    k = k - 2 * k;
                }
                resposta.Text = string.Format("{0}", k);
                for(int i = 0; codi.Count > i; i++)
                {
                    for (int j = 0; abc.Count > j; j++) // Loop no alfabeto
                    {
                        if (codi[i] == abc[j]) // Checa se a letra da lista ta na do alfabeto
                        {
                            k = k % lenght; // Resultato = quantidade de voltas / Resto = quanto de k foi na volta
                            if (checkBox1.Checked == true && (j + k) < 0)
                            {

                                j = ((j + k) + lenght);
                                respostaf += abc[j];
                                break;
                            }
                            else if (checkBox1.Checked == true && (j + k) > 0)
                            {
                                respostaf += abc[j + k];
                                break;
                            }

                            if (checkBox2.Checked == true)
                            {
                                for (int p = 0; p < 26; p++)
                                {
                                    if(codi[i] == abc[j])
                                    {
                                        if ((j - p) < 0)
                                        {
                                            respostaf = abc[(j - p) + lenght].ToString();
                                            brute[p] += respostaf;
                                        }
                                        else if ((j - p) > 0)
                                        {
                                            respostaf = abc[j - p].ToString();
                                            brute[p] += respostaf;
                                        }
                                    }
                                }

                            }

                            else if (j + k >= lenght && checkBox2.Checked == false)
                            {
                                j = ((j + k) - lenght);
                                respostaf += abc[j];
                                break;
                            }
                            else if (j + k < lenght && checkBox2.Checked == false)
                            {
                                respostaf += abc[j + k];
                                break;
                            }
                        }
                    }
                    
                }
                if (checkBox2.Checked == true)
                {
                    System.IO.File.Delete(@"C:\Users\pudim\Desktop\Cesar-Brute.txt");
                    for (int p = 0; p < 26; p++)
                    {
                    System.IO.File.AppendAllText(@"C:\Users\pudim\Desktop\Cesar-Brute.txt", brute[p] + Environment.NewLine + Environment.NewLine);
                    }
                }
                resposta.Text = respostaf;
            }
        }
    }
}