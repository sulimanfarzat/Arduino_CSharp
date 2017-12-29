using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using System.IO.Ports;

namespace WindowsFormsApp1
{

    public partial class Form1 : Form
    {

        public static System.IO.Ports.SerialPort serialPort1;
        private delegate void LineReceivedEvent(string line);
        private bool start = false;

        public Form1()
        {

            InitializeComponent();
            System.ComponentModel.IContainer components = new System.ComponentModel.Container();
            serialPort1 = new System.IO.Ports.SerialPort(components);
            serialPort1.PortName = "COM3";
            serialPort1.BaudRate = 9600;
            serialPort1.DtrEnable = true;
            serialPort1.Open();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            serialPort1.Write(new byte[] { Convert.ToByte("1") }, 0, 1);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            serialPort1.Write(new byte[] { Convert.ToByte("0") }, 0, 1);
            start = false;
        }

        private void button3_Click(object sender, EventArgs e)
        {

            start = true;
            int i = 0;
            do
            {
                if (start == true)
                {
                    serialPort1.Write(new byte[] { Convert.ToByte("2") }, 0, 1);
                    i++;
                }
                else{
                    break;

                }

            } while (i < 50);
        }


    }
}
