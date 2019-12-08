namespace 과제4번
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
            this.panel1 = new System.Windows.Forms.Panel();
            this.btnReCreate = new System.Windows.Forms.Button();
            this.btnInit = new System.Windows.Forms.Button();
            this.btnStart = new System.Windows.Forms.Button();
            this.nudUserCnt = new System.Windows.Forms.NumericUpDown();
            this.nudSpeed = new System.Windows.Forms.NumericUpDown();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.picUser = new System.Windows.Forms.PictureBox();
            ((System.ComponentModel.ISupportInitialize)(this.nudUserCnt)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.nudSpeed)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.picUser)).BeginInit();
            this.SuspendLayout();
            // 
            // panel1
            // 
            this.panel1.Location = new System.Drawing.Point(3, 3);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(485, 365);
            this.panel1.TabIndex = 0;
            this.panel1.Paint += new System.Windows.Forms.PaintEventHandler(this.Panel1_Paint);
            // 
            // btnReCreate
            // 
            this.btnReCreate.Location = new System.Drawing.Point(680, 235);
            this.btnReCreate.Name = "btnReCreate";
            this.btnReCreate.Size = new System.Drawing.Size(108, 23);
            this.btnReCreate.TabIndex = 1;
            this.btnReCreate.Text = "다시만들기";
            this.btnReCreate.UseVisualStyleBackColor = true;
            this.btnReCreate.Click += new System.EventHandler(this.BtnReCreate_Click);
            // 
            // btnInit
            // 
            this.btnInit.Location = new System.Drawing.Point(680, 343);
            this.btnInit.Name = "btnInit";
            this.btnInit.Size = new System.Drawing.Size(108, 23);
            this.btnInit.TabIndex = 2;
            this.btnInit.Text = "초기화";
            this.btnInit.UseVisualStyleBackColor = true;
            this.btnInit.Click += new System.EventHandler(this.BtnInit_Click);
            // 
            // btnStart
            // 
            this.btnStart.Location = new System.Drawing.Point(680, 390);
            this.btnStart.Name = "btnStart";
            this.btnStart.Size = new System.Drawing.Size(108, 23);
            this.btnStart.TabIndex = 3;
            this.btnStart.Text = "시작";
            this.btnStart.UseVisualStyleBackColor = true;
            this.btnStart.Click += new System.EventHandler(this.BtnStart_Click);
            // 
            // nudUserCnt
            // 
            this.nudUserCnt.Location = new System.Drawing.Point(680, 191);
            this.nudUserCnt.Maximum = new decimal(new int[] {
            8,
            0,
            0,
            0});
            this.nudUserCnt.Minimum = new decimal(new int[] {
            3,
            0,
            0,
            0});
            this.nudUserCnt.Name = "nudUserCnt";
            this.nudUserCnt.Size = new System.Drawing.Size(64, 21);
            this.nudUserCnt.TabIndex = 4;
            this.nudUserCnt.Value = new decimal(new int[] {
            3,
            0,
            0,
            0});
            this.nudUserCnt.ValueChanged += new System.EventHandler(this.NudUserCnt_ValueChanged);
            // 
            // nudSpeed
            // 
            this.nudSpeed.Location = new System.Drawing.Point(724, 305);
            this.nudSpeed.Maximum = new decimal(new int[] {
            50,
            0,
            0,
            0});
            this.nudSpeed.Minimum = new decimal(new int[] {
            25,
            0,
            0,
            0});
            this.nudSpeed.Name = "nudSpeed";
            this.nudSpeed.Size = new System.Drawing.Size(64, 21);
            this.nudSpeed.TabIndex = 5;
            this.nudSpeed.Value = new decimal(new int[] {
            25,
            0,
            0,
            0});
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(680, 309);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(29, 12);
            this.label1.TabIndex = 6;
            this.label1.Text = "속도";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(750, 197);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(29, 12);
            this.label2.TabIndex = 7;
            this.label2.Text = "인용";
            // 
            // picUser
            // 
            this.picUser.Location = new System.Drawing.Point(682, 13);
            this.picUser.Name = "picUser";
            this.picUser.Size = new System.Drawing.Size(25, 25);
            this.picUser.TabIndex = 8;
            this.picUser.TabStop = false;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.picUser);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.nudSpeed);
            this.Controls.Add(this.nudUserCnt);
            this.Controls.Add(this.btnStart);
            this.Controls.Add(this.btnInit);
            this.Controls.Add(this.btnReCreate);
            this.Controls.Add(this.panel1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.nudUserCnt)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.nudSpeed)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.picUser)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Button btnReCreate;
        private System.Windows.Forms.Button btnInit;
        private System.Windows.Forms.Button btnStart;
        private System.Windows.Forms.NumericUpDown nudUserCnt;
        private System.Windows.Forms.NumericUpDown nudSpeed;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.PictureBox picUser;
    }
}

