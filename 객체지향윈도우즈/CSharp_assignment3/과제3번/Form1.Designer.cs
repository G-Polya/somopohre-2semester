namespace 과제3번
{
    partial class Form1
    {
        /// <summary>
        /// 필수 디자이너 변수입니다.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 사용 중인 모든 리소스를 정리합니다.
        /// </summary>
        /// <param name="disposing">관리되는 리소스를 삭제해야 하면 true이고, 그렇지 않으면 false입니다.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form 디자이너에서 생성한 코드

        /// <summary>
        /// 디자이너 지원에 필요한 메서드입니다. 
        /// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.Flip = new System.Windows.Forms.RadioButton();
            this.rotation = new System.Windows.Forms.RadioButton();
            this.clockwise = new System.Windows.Forms.RadioButton();
            this.counterClock = new System.Windows.Forms.RadioButton();
            this.radioButton5 = new System.Windows.Forms.RadioButton();
            this.button1 = new System.Windows.Forms.Button();
            this.panel1 = new System.Windows.Forms.Panel();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.panel1.SuspendLayout();
            this.SuspendLayout();
            // 
            // pictureBox1
            // 
            this.pictureBox1.Image = ((System.Drawing.Image)(resources.GetObject("pictureBox1.Image")));
            this.pictureBox1.Location = new System.Drawing.Point(3, 3);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(700, 347);
            this.pictureBox1.TabIndex = 6;
            this.pictureBox1.TabStop = false;
            this.pictureBox1.Paint += new System.Windows.Forms.PaintEventHandler(this.PictureBox1_Paint);
            this.pictureBox1.MouseDown += new System.Windows.Forms.MouseEventHandler(this.PictureBox1_MouseDown);
            this.pictureBox1.MouseMove += new System.Windows.Forms.MouseEventHandler(this.PictureBox1_MouseMove);
            this.pictureBox1.MouseUp += new System.Windows.Forms.MouseEventHandler(this.PictureBox1_MouseUp);
            // 
            // Flip
            // 
            this.Flip.AutoSize = true;
            this.Flip.Location = new System.Drawing.Point(40, 30);
            this.Flip.Name = "Flip";
            this.Flip.Size = new System.Drawing.Size(47, 16);
            this.Flip.TabIndex = 7;
            this.Flip.TabStop = true;
            this.Flip.Text = "반전";
            this.Flip.UseVisualStyleBackColor = true;
            // 
            // rotation
            // 
            this.rotation.AutoSize = true;
            this.rotation.Location = new System.Drawing.Point(170, 30);
            this.rotation.Name = "rotation";
            this.rotation.Size = new System.Drawing.Size(47, 16);
            this.rotation.TabIndex = 8;
            this.rotation.TabStop = true;
            this.rotation.Text = "회전";
            this.rotation.UseVisualStyleBackColor = true;
            // 
            // clockwise
            // 
            this.clockwise.AutoSize = true;
            this.clockwise.Location = new System.Drawing.Point(295, 30);
            this.clockwise.Name = "clockwise";
            this.clockwise.Size = new System.Drawing.Size(95, 16);
            this.clockwise.TabIndex = 9;
            this.clockwise.TabStop = true;
            this.clockwise.Text = "시계방향이동";
            this.clockwise.UseVisualStyleBackColor = true;
            // 
            // counterClock
            // 
            this.counterClock.AutoSize = true;
            this.counterClock.Location = new System.Drawing.Point(414, 30);
            this.counterClock.Name = "counterClock";
            this.counterClock.Size = new System.Drawing.Size(83, 16);
            this.counterClock.TabIndex = 10;
            this.counterClock.TabStop = true;
            this.counterClock.Text = "반시계방향";
            this.counterClock.UseVisualStyleBackColor = true;
            // 
            // radioButton5
            // 
            this.radioButton5.AutoSize = true;
            this.radioButton5.Location = new System.Drawing.Point(532, 30);
            this.radioButton5.Name = "radioButton5";
            this.radioButton5.Size = new System.Drawing.Size(119, 16);
            this.radioButton5.TabIndex = 11;
            this.radioButton5.TabStop = true;
            this.radioButton5.Text = "마우스따라서이동";
            this.radioButton5.UseVisualStyleBackColor = true;
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(671, 30);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(75, 23);
            this.button1.TabIndex = 12;
            this.button1.Text = "확인";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.Button1_Click);
            // 
            // panel1
            // 
            this.panel1.Controls.Add(this.pictureBox1);
            this.panel1.Location = new System.Drawing.Point(40, 59);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(706, 350);
            this.panel1.TabIndex = 13;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.radioButton5);
            this.Controls.Add(this.counterClock);
            this.Controls.Add(this.clockwise);
            this.Controls.Add(this.rotation);
            this.Controls.Add(this.Flip);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.panel1.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.RadioButton Flip;
        private System.Windows.Forms.RadioButton rotation;
        private System.Windows.Forms.RadioButton clockwise;
        private System.Windows.Forms.RadioButton counterClock;
        private System.Windows.Forms.RadioButton radioButton5;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Panel panel1;
    }
}

