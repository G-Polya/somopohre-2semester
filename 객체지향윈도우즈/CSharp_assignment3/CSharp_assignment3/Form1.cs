using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CSharp_assignment3
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
          
        }
        int player = 1;
        int game_count = 0;
      

        private void button1_Paint(object sender, PaintEventArgs e)
        {
            if (player % 2 == 0)
            {
                e.Graphics.DrawLine(Pens.Black, button1.Width, 0, 0, button1.Height);
                e.Graphics.DrawLine(Pens.Black, 0, 0, button1.Width, button1.Height);
            }
            else if (player % 2 == 1)
            {
                Rectangle rect = new Rectangle(0, 0, button1.Width, button1.Height);
                e.Graphics.DrawEllipse(Pens.Black, rect);
            }
        }
        

        private void Button_Click(object sender, EventArgs e)
        {
            Button bt = (Button)sender;
     
            if (player % 2 == 0)
            {
                bt.Paint += new PaintEventHandler(button1_Paint);
                player += 1;
            }
            else if (player % 2 == 1)
            {
                bt.Paint += new PaintEventHandler(button1_Paint);
                player += 1;
                bt.Tag = (Int32.Parse((String)bt.Tag) + 1).ToString();
            }
            bt.Enabled = false;

            game_count++;

            if (game_count == 9)
            {
                MessageBox.Show("Game finished!");
            }


        }

  
        private void disableButtons()
        {
            try
            {
                foreach (Control c in Controls)
                {
                    Button b = (Button)c;
                    b.Enabled = false;
                }
            }
            catch  { }
        }
    }
}

