using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Threading;

namespace 과제3번
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }


        int button_count = 0;

        Bitmap bitmap1;
        private void Form1_Load(object sender, EventArgs e)
        {

            bitmap1 = (Bitmap)Bitmap.FromFile("face.jpg");
            pictureBox1.Image = bitmap1;
        }

        private void Button1_Click(object sender, EventArgs e)
        {
            button_count += 1;
            
            if (bitmap1 != null)
            {
                if (Flip.Checked)
                {
                    if (button_count % 2 == 1)
                    {
                        pictureBox1.Image.RotateFlip(RotateFlipType.Rotate180FlipY);
                        pictureBox1.Image = bitmap1;
                    }
                 
                    else if (button_count % 2 == 0)
                    {
                        pictureBox1.Image.RotateFlip(RotateFlipType.Rotate180FlipX);
                        pictureBox1.Image = bitmap1;
                    }
                }
                if (rotation.Checked)
                {                                         
                    pictureBox1.Image.RotateFlip(RotateFlipType.Rotate90FlipNone);
                                       
                    pictureBox1.Image = bitmap1;
                }

                if(clockwise.Checked)
                {
                    if (button_count % 4 == 0)
                        pictureBox1.Location = new Point(3, 3);
                    else if (button_count % 4 == 1)
                        pictureBox1.Location = new Point(565, 3);
                    else if (button_count % 4 == 2)
                        pictureBox1.Location = new Point(565, 192);
                    else
                        pictureBox1.Location = new Point(3, 192);
                }

                if(counterClock.Checked)
                {
                    if (button_count % 4 == 0)
                        pictureBox1.Location = new Point(3, 3);
                    else if (button_count % 4 == 1)
                        pictureBox1.Location = new Point(3, 192);
                    else if (button_count % 4 == 2)
                        pictureBox1.Location = new Point(565, 192);
                    else
                        pictureBox1.Location = new Point(565, 3);

                }
                
                if(radioButton5.Checked)
                {

                }


            }


        }

        private Point startPoint = Point.Empty;
        private Point movePoint = Point.Empty;
        bool isClick = false;
        private void PictureBox1_MouseDown(object sender, MouseEventArgs e)
        {
            if(e.Button == MouseButtons.Left)
            {
                isClick = true;
                this.startPoint = new Point(e.Location.X - movePoint.X, e.Location.Y - movePoint.Y);
            }
        }

        private void PictureBox1_MouseMove(object sender, MouseEventArgs e)
        {
            if(isClick)
            {
                this.movePoint = new Point(e.Location.X - startPoint.X, e.Location.Y - startPoint.Y);
                this.pictureBox1.Invalidate();
            }
        }

        private void PictureBox1_MouseUp(object sender, MouseEventArgs e)
        {
            if (isClick) isClick = false;
        }

        private void PictureBox1_Paint(object sender, PaintEventArgs e)
        {
            e.Graphics.Clear(Color.White);

            if (this.pictureBox1.Image != null)
                e.Graphics.DrawImage(this.pictureBox1.Image, movePoint);
        }
    }
}
