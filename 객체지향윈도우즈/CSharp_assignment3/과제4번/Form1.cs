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

namespace 과제4번
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        int[,] m_nSadari;
        int[,] m_nVisit;
        int m_nSelUser;

        Pen m_penSadari;
        Pen[] m_penVisit = new Pen[6];

        const int SADARI_WIDTH = 80;
        const int START_X = 35;
        const int START_Y = 30;

        private void InitSadari()
        {
            MakeSadari((int)nudUserCnt.Value);
            MakeLabel((int)nudUserCnt.Value);

            picUser.Location = GetPos(0, 0);
        }

        private void MakeSadari(int nUserCnt)
        {
            
            m_nSadari = new int[nUserCnt, 100];
            m_nVisit = new int[nUserCnt, 100];

            for(int i =0; i<nUserCnt;i++)
            {
                for(int j = 0;j<100;j++)
                {
                    m_nSadari[i, j] = 1;
                    m_nVisit[i, j] = 0;
                }
            }

            int nRnd;
            int nCnt;

            Random rnd = new Random();

            for(int i = 0;i<=nUserCnt-2;i++)
            {
                nCnt = 0;
                while(true)
                {
                AAA:
                    nRnd = rnd.Next(4, 95);

                    for(int k = 0;k<4;k++)
                    {
                        if (m_nSadari[i, nRnd + k] != 1 || m_nSadari[i,nRnd - k] != 1)
                            goto AAA;
                    }

                    nCnt += 1;
                    m_nSadari[i, nRnd] = 2;
                    m_nSadari[i + 1, nRnd] = 3;
                    if (nCnt >= 7)
                        break;
                }

            }
        }

        private void MakeLabel(int nUserCnt)
        {
            for(int i = 0;i<nUserCnt;i++)
            {
                Label lbl1, lbl2;
                lbl1 = new Label();
                panel1.Controls.Add(lbl1);

                // 위쪽 label
                lbl1.Size = new Size(65, 20);
                lbl1.Location = new Point(5 + i * SADARI_WIDTH, 5);

                lbl1.Text = "User" + (i + 1).ToString();
                lbl1.Tag = "0" + i.ToString();

                lbl1.BorderStyle = BorderStyle.FixedSingle;
                lbl1.TextAlign = ContentAlignment.MiddleCenter;
                lbl1.BackColor = Color.WhiteSmoke;

                if(i ==0)
                {
                    m_nSelUser = 0;
                    lbl1.BackColor = Color.Yellow;
                }

                // 아래쪽 label
                lbl2 = new Label();
                panel1.Controls.Add(lbl2);

                lbl2.Size = new Size(65, 20);
                lbl2.Location = new Point(5 + i * SADARI_WIDTH, 305 + START_Y);

                lbl2.Text = ((i + 1) * 1).ToString() ;
                lbl2.Tag = "1" + i.ToString();

                lbl2.BorderStyle = BorderStyle.FixedSingle;
                lbl2.TextAlign = ContentAlignment.MiddleCenter;
                lbl2.BackColor = Color.WhiteSmoke;


                lbl1.Click += new EventHandler(lbl_Click);
                lbl1.DoubleClick += new EventHandler(lbl_DClick);
                lbl2.DoubleClick += new EventHandler(lbl_DClick);
            }
        }

        private Label GetLblCtrl(String strTage)
        {
            for(int i = 0; i<panel1.Controls.Count;i++)
            {
                if (panel1.Controls[i].Tag.ToString().Equals(strTage))
                    return (Label)panel1.Controls[i];
            }
            return null;
        }

        private void FindRoute(int nStartX)
        {
            int i, j = 0, k = 0;
            Point pos1, pos2;
            i = nStartX;

            while(true)
            {
                m_nVisit[i, j] = m_nSelUser + 1;
                picUser.Location = GetPos(i, j);
                if (m_nSadari[i, j] == 1)
                    j += 1;
                else if(m_nSadari[i,j]==2)
                {
                    pos1 = GetPos(i, j);
                    i += 1;
                    m_nVisit[i, j] = m_nSelUser + 1;
                    pos2 = GetPos(i, j);

                    for(k =pos1.X; k<=pos2.X;k+=5)
                    {
                        Application.DoEvents();
                        Thread.Sleep(50 - (int)nudSpeed.Value);
                        picUser.Location = new Point(k, pos1.Y);
                    }
                    j += 1;
                }
                else if (m_nSadari[i, j] == 3)
                {
                    pos2 = GetPos(i, j);
                    i -= 1;
                    pos1 = GetPos(i, j);
                    m_nVisit[i, j] = m_nSelUser + 1;

                    for(k=pos2.X; k>=pos1.X;k-=5)
                    {
                        Application.DoEvents();
                        Thread.Sleep(50 - (int)nudSpeed.Value);
                        picUser.Location = new Point(k, pos1.Y);
                    }

                    j += 1;
                }
                Application.DoEvents();
                Thread.Sleep(50 - (int)nudSpeed.Value);

                if (j >= 99)
                    break;
            }

            String strUser, strResult;
            strUser = GetLblCtrl("0" + m_nSelUser.ToString()).Text;
            strResult = GetLblCtrl("1" + i.ToString()).Text;

            MessageBox.Show(strUser + " : " + strResult);
           
        }

        private Point GetPos(int nX,int nY)
        {
            return new Point(nX * SADARI_WIDTH + START_X - 5, nY * 3 + START_Y - 5);
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            m_penSadari = new Pen(Color.Black, 3);

            m_penVisit[0] = new Pen(Color.FromArgb(255, 0, 0), 3);
            m_penVisit[1] = new Pen(Color.FromArgb(0, 255, 0), 3);
            m_penVisit[2] = new Pen(Color.FromArgb(255, 0, 255), 3);
            m_penVisit[3] = new Pen(Color.FromArgb(255, 255, 0), 3);
            m_penVisit[4] = new Pen(Color.FromArgb(0, 255, 255), 3);
            m_penVisit[5] = new Pen(Color.FromArgb(125, 125, 125), 3);

            InitSadari();
            panel1.Invalidate();
        }

        private void lbl_Click(object sender,EventArgs e)
        {
            Label lbl;

            lbl = GetLblCtrl("0" + m_nSelUser);
            lbl.BackColor = Color.WhiteSmoke;

            String strTage;
            ((Label)sender).BackColor = Color.Yellow;
            strTage = ((Label)sender).Tag.ToString();
            m_nSelUser = Convert.ToInt32(strTage.Substring(1, 1));
            picUser.Location = GetPos(m_nSelUser, 0);
        }

        private void lbl_DClick(object sender, EventArgs e)
        {
            Form2 form2 = new Form2();

            String strTag;
            strTag = ((Label)sender).Tag.ToString();

            if(strTag.Substring(0,1)== "0")
            {
                form2.Text = "사용자 입력";
                form2.lblStatus.Text = "사용자의 이름을 입력하세요";
            }
            else
            {
                form2.Text = " 점수 입력";
                form2.lblStatus.Text = "점수를 입력하세요";
            }

            if (form2.ShowDialog(this) == DialogResult.OK)
                ((Label)sender).Text = form2.txtInput.Text;
        }

        private void BtnReCreate_Click(object sender, EventArgs e)
        {
            InitSadari();
            panel1.Invalidate();
        }

        private void BtnInit_Click(object sender, EventArgs e)
        {
            for(int i =0;i<nudUserCnt.Value;i++)
            {
                for (int j = 0; j < 100; j++)
                    m_nVisit[i, j] = 0;
            }

            panel1.Invalidate();
        }

        private void BtnStart_Click(object sender, EventArgs e)
        {
            FindRoute(m_nSelUser);
        }

        private void NudUserCnt_ValueChanged(object sender, EventArgs e)
        {
            InitSadari();
            panel1.Invalidate();
        }

        private void Panel1_Paint(object sender, PaintEventArgs e)
        {
            int x1, y1, x2, y2;
            int i,j;
            for(i =0;i<(int)nudUserCnt.Value;i++)
            {
                for( j = 0; j<100 ; j++)
                {
                    if(m_nSadari[i,j] == 2)
                    {
                        x1 = i * SADARI_WIDTH + START_X;
                        y1 = START_Y + j * 3;
                        x2 = i * SADARI_WIDTH + START_X + SADARI_WIDTH;
                        y2 = START_Y + j * 3;

                        if (m_nVisit[i, j] != 0)
                            e.Graphics.DrawLine(m_penVisit[m_nVisit[i, j] - 1], x1, y1, x2, y2);
                        else
                            e.Graphics.DrawLine(m_penSadari, x1, y1, x2, y2);
                    }

                    if (j!=99)
                    {
                        x1 = i * SADARI_WIDTH + START_X;
                        y1 = START_Y + j * 3 - 1;
                        x2 = i * SADARI_WIDTH + START_X;
                        y2 = START_Y + (j + 1) * 3;

                       if (m_nVisit[i, j] != 0)
                           e.Graphics.DrawLine(m_penVisit[m_nVisit[i, j] - 1], x1, y1, x2, y2);
                       else
                           e.Graphics.DrawLine(m_penSadari, x1, y1, x2, y2);
                    }
                }
            }
        }
    }
}
