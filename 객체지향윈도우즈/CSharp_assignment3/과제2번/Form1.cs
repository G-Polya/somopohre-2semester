using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 과제2번
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        
        private static DateTime Delay(int ms)
        {
            DateTime thisMoment = DateTime.Now;
            TimeSpan duration = new TimeSpan(0, 0, 0, 0, ms);
            DateTime afterWards = thisMoment.Add(duration);

            while(afterWards >= thisMoment)
            {
                System.Windows.Forms.Application.DoEvents();
                thisMoment = DateTime.Now;
            }

            return DateTime.Now;
        }
      
        
        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            Graphics g;
            Pen p = new Pen(Color.Black);
            while(true)
            {
                g = CreateGraphics();

                digital_clock(g, p);
                Delay(900);
                g.Clear(Color.White);   // 겹쳐짐현상 방지
            }
        }

        private void digital_clock(Graphics g, Pen p)
        {
            Point hour1 = new Point(60, 60);
            Point hour2 = new Point(110, 60);

            Point min1 = new Point(210, 60);
            Point min2 = new Point(260, 60);

            Point sec1 = new Point(360, 60);
            Point sec2 = new Point(410, 60);


            DateTime now = DateTime.Now;
            int hour = now.Hour;
            int min = now.Minute;
            int sec = now.Second;

            SegmentDisplay.DrawSegments(g, p.Color, hour / 10, hour1, 3, 25);
            SegmentDisplay.DrawSegments(g, p.Color, hour % 10, hour2,3, 25);
            SegmentDisplay.DrawSegments(g, p.Color, min / 10, min1, 3, 25);
            SegmentDisplay.DrawSegments(g, p.Color, min % 10, min2, 3, 25);
            SegmentDisplay.DrawSegments(g, p.Color, sec / 10, sec1, 3, 25);
            SegmentDisplay.DrawSegments(g, p.Color, sec % 10, sec2, 3, 25);

        }



    }
    
    static class SegmentDisplay
    {

      

        static void DrawHorizondalSegment(Graphics gx, Color clr, int x, int y, int l, int w)
        {
            gx.FillPolygon(new SolidBrush(clr), new Point[] {
                new Point(x, y), new Point(x + l, y-l), new Point(x+w-l, y - l),
                new Point(x +w, y),new Point(x+w-l,y+l) ,new Point(x+l,y+l)
            });
        }

        static void DrawVerticalSegment(Graphics gx, Color clr, int x, int y, int l, int w)
        {
            gx.FillPolygon(new SolidBrush(clr), new Point[] {
                new Point(x, y), new Point(x + l, y+l), new Point(x+l, y +w - l),
                new Point(x , y+w),new Point(x-l,y+w-l) ,new Point(x-l,y+l)
            });
        }

        /// <summary>
        /// Use this method to draw segments.Use this to get a One digit number and 
        /// extend to get any number of digits.(2 digit already availaible)
        /// </summary>
        /// <param name="gx">Graphics attribute
        /// <param name="clr">color of segment
        /// <param name="n">The number to display.
        /// <param name="p">The position of P</param>
        /// <param name="l">Thickness of half segment
        /// <param name="w">width of each segment
        public static void DrawSegments(Graphics gx, Color clr, int n, Point p, int l, int w)
        {

            ///<summary>
            /// Mapping of segment
            /// 
            ///      3
            ///      __
            ///   1 |__| 4
            ///   2 |__| 5
            ///      
            ///      6
            /// </summary>
            ///
            ///


            byte[][] segment = new byte[10][];
            segment[0] = new byte[] { 1, 1, 1, 1, 1, 1, 0 }; ///Mapping of segment for number 0
            segment[1] = new byte[] { 1, 1, 0, 0, 0, 0, 0 }; ///Mapping of segment for number 1
            segment[2] = new byte[] { 0, 1, 1, 1, 0, 1, 1 }; ///Mapping of segment for number 2
            segment[3] = new byte[] { 0, 0, 1, 1, 1, 1, 1 }; ///Mapping of segment for number 3
            segment[4] = new byte[] { 1, 0, 0, 1, 1, 0, 1 }; ///Mapping of segment for number 4
            segment[5] = new byte[] { 1, 0, 1, 0, 1, 1, 1 }; ///Mapping of segment for number 5
            segment[6] = new byte[] { 1, 1, 1, 0, 1, 1, 1 }; ///Mapping of segment for number 6
            segment[7] = new byte[] { 0, 0, 1, 1, 1, 0, 0 }; ///Mapping of segment for number 7
            segment[8] = new byte[] { 1, 1, 1, 1, 1, 1, 1 }; ///Mapping of segment for number 8
            segment[9] = new byte[] { 1, 0, 1, 1, 1, 0, 1 }; ///Mapping of segment for number 9

            if (segment[n][0] == 1)
                DrawVerticalSegment(gx, clr, p.X + 2, p.Y + 4, l, w);            ///1st segment (Refer to above mapping)
            if (segment[n][1] == 1)
                DrawVerticalSegment(gx, clr, p.X + 2, p.Y + 8 + w, l, w);        ///2st segment (Refer to above mapping)
            if (segment[n][2] == 1)
                DrawHorizondalSegment(gx, clr, p.X + 2, p.Y + 2, l, w);          ///3st segment (Refer to above mapping)
            if (segment[n][3] == 1)
                DrawVerticalSegment(gx, clr, p.X + 2 + w, p.Y + 4, l, w);        ///4st segment (Refer to above mapping)
            if (segment[n][4] == 1)
                DrawVerticalSegment(gx, clr, p.X + 2 + w, p.Y + 8 + w, l, w);    ///5st segment (Refer to above mapping)
            if (segment[n][5] == 1)
                DrawHorizondalSegment(gx, clr, p.X + 2, p.Y + 10 + 2 * w, l, w); ///6st segment (Refer to above mapping)
            if (segment[n][6] == 1)
                DrawHorizondalSegment(gx, clr, p.X + 2, p.Y + 6 + w, l, w);      ///7st segment (Refer to above mapping)


        }



    }
}
