#pragma once
#include "MeshViewPanel.h"
#include "OpenGLEventTrigger.h"

namespace SSSS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MainForm 的摘要
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO:  在此加入建構函式程式碼
			//
			meshView = new MeshViewPanel;
			gcnew OpenGLEventTrigger(this->mainPanel, this->mainPanelTimer, meshView);
			meshView->faceColor.r = label1->BackColor.R / 255.0;
			meshView->faceColor.g = label1->BackColor.G / 255.0;
			meshView->faceColor.b = label1->BackColor.B / 255.0;
			meshView->lineColor.r = label2->BackColor.R / 255.0;
			meshView->lineColor.g = label2->BackColor.G / 255.0;
			meshView->lineColor.b = label2->BackColor.B / 255.0;
			meshView->pointColor.r = label3->BackColor.R / 255.0;
			meshView->pointColor.g = label3->BackColor.G / 255.0;
			meshView->pointColor.b = label3->BackColor.B / 255.0;
			meshView->drawFace = checkBox1->Checked;
			meshView->drawLine = checkBox2->Checked;
			meshView->drawPoint = checkBox3->Checked;
			meshView->isLighting = checkBox4->Checked;
			try
			{
				meshView->lineWidth = float::Parse(textBox1->Text);
			}
			catch (System::FormatException^ e)
			{
				meshView->lineWidth = 1;
			}
			try
			{
				meshView->pointSize = float::Parse(textBox2->Text);
			}
			catch (System::FormatException^ e)
			{
				meshView->pointSize = 2;
			}
		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  mainPanel;
	private: System::Windows::Forms::Timer^  mainPanelTimer;

	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  readModelToolStripMenuItem;
	private: System::ComponentModel::IContainer^  components;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel2;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::ColorDialog^  faceColorDialog;
	private: System::Windows::Forms::ColorDialog^  lineColorDialog;

	private: System::Windows::Forms::ColorDialog^  pointColorDialog;




	private: System::Windows::Forms::CheckBox^  checkBox2;
	private: System::Windows::Forms::CheckBox^  checkBox3;
	private: System::Windows::Forms::CheckBox^  checkBox4;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel3;

	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::ToolStripMenuItem^  saveModelToolStripMenuItem;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel4;
	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::RadioButton^  radioButton3;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel5;
	private: System::Windows::Forms::GroupBox^  groupBox4;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel6;
	private: System::Windows::Forms::GroupBox^  groupBox5;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel7;
	private: System::Windows::Forms::Button^  buttonBottomView;

	private: System::Windows::Forms::Button^  buttonTopView;
	private: System::Windows::Forms::Button^  buttonFrontView;
	private: System::Windows::Forms::Button^  buttonBackView;
	private: System::Windows::Forms::Button^  buttonFTRView;
	private: System::Windows::Forms::Button^  buttonBBLView;


private: System::Windows::Forms::Button^  buttonResetView;

private: System::Windows::Forms::Button^  buttonLeftView;

	private: System::Windows::Forms::Button^  buttonRightView;

	protected:

	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>
		MeshViewPanel* meshView;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改
		/// 這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->mainPanel = (gcnew System::Windows::Forms::Panel());
			this->mainPanelTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->checkBox4 = (gcnew System::Windows::Forms::CheckBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->readModelToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveModelToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->faceColorDialog = (gcnew System::Windows::Forms::ColorDialog());
			this->lineColorDialog = (gcnew System::Windows::Forms::ColorDialog());
			this->pointColorDialog = (gcnew System::Windows::Forms::ColorDialog());
			this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel4 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel5 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel6 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel7 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->buttonBottomView = (gcnew System::Windows::Forms::Button());
			this->buttonTopView = (gcnew System::Windows::Forms::Button());
			this->buttonFrontView = (gcnew System::Windows::Forms::Button());
			this->buttonBackView = (gcnew System::Windows::Forms::Button());
			this->buttonFTRView = (gcnew System::Windows::Forms::Button());
			this->buttonBBLView = (gcnew System::Windows::Forms::Button());
			this->buttonResetView = (gcnew System::Windows::Forms::Button());
			this->buttonLeftView = (gcnew System::Windows::Forms::Button());
			this->buttonRightView = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->tableLayoutPanel2->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->tableLayoutPanel3->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->tableLayoutPanel4->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->groupBox5->SuspendLayout();
			this->tableLayoutPanel7->SuspendLayout();
			this->tableLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// mainPanel
			// 
			this->mainPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->mainPanel->Location = System::Drawing::Point(3, 3);
			this->mainPanel->Name = L"mainPanel";
			this->mainPanel->Size = System::Drawing::Size(621, 531);
			this->mainPanel->TabIndex = 0;
			// 
			// mainPanelTimer
			// 
			this->mainPanelTimer->Enabled = true;
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 3;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				60)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				20)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				20)));
			this->tableLayoutPanel2->Controls->Add(this->checkBox1, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->label1, 2, 0);
			this->tableLayoutPanel2->Controls->Add(this->checkBox2, 0, 1);
			this->tableLayoutPanel2->Controls->Add(this->checkBox3, 0, 2);
			this->tableLayoutPanel2->Controls->Add(this->label2, 2, 1);
			this->tableLayoutPanel2->Controls->Add(this->label3, 2, 2);
			this->tableLayoutPanel2->Controls->Add(this->checkBox4, 1, 0);
			this->tableLayoutPanel2->Controls->Add(this->textBox1, 1, 1);
			this->tableLayoutPanel2->Controls->Add(this->textBox2, 1, 2);
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel2->Location = System::Drawing::Point(3, 18);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 3;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(139, 79);
			this->tableLayoutPanel2->TabIndex = 5;
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Checked = true;
			this->checkBox1->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->checkBox1->Location = System::Drawing::Point(3, 3);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(77, 20);
			this->checkBox1->TabIndex = 4;
			this->checkBox1->Text = L"Show Face";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox1_CheckedChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->label1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label1->Location = System::Drawing::Point(113, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(23, 26);
			this->label1->TabIndex = 3;
			this->label1->Click += gcnew System::EventHandler(this, &MainForm::label1_Click);
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Checked = true;
			this->checkBox2->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->checkBox2->Location = System::Drawing::Point(3, 29);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(77, 20);
			this->checkBox2->TabIndex = 5;
			this->checkBox2->Text = L"Show Line";
			this->checkBox2->UseVisualStyleBackColor = true;
			this->checkBox2->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox2_CheckedChanged);
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->checkBox3->Location = System::Drawing::Point(3, 55);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(77, 21);
			this->checkBox3->TabIndex = 6;
			this->checkBox3->Text = L"Show Point";
			this->checkBox3->UseVisualStyleBackColor = true;
			this->checkBox3->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox3_CheckedChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Black;
			this->label2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label2->Location = System::Drawing::Point(113, 26);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(23, 26);
			this->label2->TabIndex = 8;
			this->label2->Click += gcnew System::EventHandler(this, &MainForm::label2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Blue;
			this->label3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label3->Location = System::Drawing::Point(113, 52);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(23, 27);
			this->label3->TabIndex = 9;
			this->label3->Click += gcnew System::EventHandler(this, &MainForm::label3_Click);
			// 
			// checkBox4
			// 
			this->checkBox4->AutoSize = true;
			this->checkBox4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->checkBox4->Location = System::Drawing::Point(86, 3);
			this->checkBox4->Name = L"checkBox4";
			this->checkBox4->Size = System::Drawing::Size(21, 20);
			this->checkBox4->TabIndex = 7;
			this->checkBox4->UseVisualStyleBackColor = true;
			this->checkBox4->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox4_CheckedChanged);
			// 
			// textBox1
			// 
			this->textBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBox1->Location = System::Drawing::Point(86, 29);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(21, 22);
			this->textBox1->TabIndex = 10;
			this->textBox1->Text = L"1";
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MainForm::textBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBox2->Location = System::Drawing::Point(86, 55);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(21, 22);
			this->textBox2->TabIndex = 11;
			this->textBox2->Text = L"2";
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MainForm::textBox2_TextChanged);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->fileToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(784, 24);
			this->menuStrip1->TabIndex = 2;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->readModelToolStripMenuItem,
					this->saveModelToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(38, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// readModelToolStripMenuItem
			// 
			this->readModelToolStripMenuItem->Name = L"readModelToolStripMenuItem";
			this->readModelToolStripMenuItem->Size = System::Drawing::Size(144, 22);
			this->readModelToolStripMenuItem->Text = L"Load Model";
			this->readModelToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::readModelToolStripMenuItem_Click);
			// 
			// saveModelToolStripMenuItem
			// 
			this->saveModelToolStripMenuItem->Name = L"saveModelToolStripMenuItem";
			this->saveModelToolStripMenuItem->Size = System::Drawing::Size(144, 22);
			this->saveModelToolStripMenuItem->Text = L"Save Model";
			// 
			// tableLayoutPanel3
			// 
			this->tableLayoutPanel3->ColumnCount = 1;
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel3->Controls->Add(this->groupBox1, 0, 0);
			this->tableLayoutPanel3->Controls->Add(this->groupBox2, 0, 1);
			this->tableLayoutPanel3->Controls->Add(this->groupBox3, 0, 2);
			this->tableLayoutPanel3->Controls->Add(this->groupBox4, 0, 3);
			this->tableLayoutPanel3->Controls->Add(this->groupBox5, 0, 4);
			this->tableLayoutPanel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel3->Location = System::Drawing::Point(630, 3);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			this->tableLayoutPanel3->RowCount = 5;
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 20)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 20)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 20)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 20)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 20)));
			this->tableLayoutPanel3->Size = System::Drawing::Size(151, 531);
			this->tableLayoutPanel3->TabIndex = 1;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->tableLayoutPanel2);
			this->groupBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox1->Location = System::Drawing::Point(3, 3);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(145, 100);
			this->groupBox1->TabIndex = 6;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"顯示設定";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->tableLayoutPanel4);
			this->groupBox2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox2->Location = System::Drawing::Point(3, 109);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(145, 100);
			this->groupBox2->TabIndex = 7;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"選取工具";
			// 
			// tableLayoutPanel4
			// 
			this->tableLayoutPanel4->ColumnCount = 1;
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				20)));
			this->tableLayoutPanel4->Controls->Add(this->radioButton1, 0, 0);
			this->tableLayoutPanel4->Controls->Add(this->radioButton2, 0, 1);
			this->tableLayoutPanel4->Controls->Add(this->radioButton3, 0, 2);
			this->tableLayoutPanel4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel4->Location = System::Drawing::Point(3, 18);
			this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
			this->tableLayoutPanel4->RowCount = 3;
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tableLayoutPanel4->Size = System::Drawing::Size(139, 79);
			this->tableLayoutPanel4->TabIndex = 0;
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(3, 3);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(47, 16);
			this->radioButton1->TabIndex = 0;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"選點";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(3, 29);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(47, 16);
			this->radioButton2->TabIndex = 1;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"選邊";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(3, 55);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(47, 16);
			this->radioButton3->TabIndex = 2;
			this->radioButton3->TabStop = true;
			this->radioButton3->Text = L"選面";
			this->radioButton3->UseVisualStyleBackColor = true;
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->tableLayoutPanel5);
			this->groupBox3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox3->Location = System::Drawing::Point(3, 215);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(145, 100);
			this->groupBox3->TabIndex = 8;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"減面工具";
			// 
			// tableLayoutPanel5
			// 
			this->tableLayoutPanel5->ColumnCount = 2;
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel5->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel5->Location = System::Drawing::Point(3, 18);
			this->tableLayoutPanel5->Name = L"tableLayoutPanel5";
			this->tableLayoutPanel5->RowCount = 2;
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel5->Size = System::Drawing::Size(139, 79);
			this->tableLayoutPanel5->TabIndex = 0;
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->tableLayoutPanel6);
			this->groupBox4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox4->Location = System::Drawing::Point(3, 321);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(145, 100);
			this->groupBox4->TabIndex = 9;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"骨架工具";
			// 
			// tableLayoutPanel6
			// 
			this->tableLayoutPanel6->ColumnCount = 2;
			this->tableLayoutPanel6->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel6->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel6->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel6->Location = System::Drawing::Point(3, 18);
			this->tableLayoutPanel6->Name = L"tableLayoutPanel6";
			this->tableLayoutPanel6->RowCount = 2;
			this->tableLayoutPanel6->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel6->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel6->Size = System::Drawing::Size(139, 79);
			this->tableLayoutPanel6->TabIndex = 0;
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->tableLayoutPanel7);
			this->groupBox5->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox5->Location = System::Drawing::Point(3, 427);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(145, 101);
			this->groupBox5->TabIndex = 10;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"視角設定";
			// 
			// tableLayoutPanel7
			// 
			this->tableLayoutPanel7->ColumnCount = 3;
			this->tableLayoutPanel7->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				33.33333F)));
			this->tableLayoutPanel7->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				33.33333F)));
			this->tableLayoutPanel7->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				33.33333F)));
			this->tableLayoutPanel7->Controls->Add(this->buttonBottomView, 1, 1);
			this->tableLayoutPanel7->Controls->Add(this->buttonTopView, 1, 0);
			this->tableLayoutPanel7->Controls->Add(this->buttonFrontView, 0, 0);
			this->tableLayoutPanel7->Controls->Add(this->buttonBackView, 0, 1);
			this->tableLayoutPanel7->Controls->Add(this->buttonFTRView, 0, 2);
			this->tableLayoutPanel7->Controls->Add(this->buttonBBLView, 1, 2);
			this->tableLayoutPanel7->Controls->Add(this->buttonResetView, 2, 2);
			this->tableLayoutPanel7->Controls->Add(this->buttonLeftView, 2, 1);
			this->tableLayoutPanel7->Controls->Add(this->buttonRightView, 2, 0);
			this->tableLayoutPanel7->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel7->Location = System::Drawing::Point(3, 18);
			this->tableLayoutPanel7->Name = L"tableLayoutPanel7";
			this->tableLayoutPanel7->RowCount = 3;
			this->tableLayoutPanel7->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tableLayoutPanel7->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tableLayoutPanel7->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tableLayoutPanel7->Size = System::Drawing::Size(139, 80);
			this->tableLayoutPanel7->TabIndex = 0;
			// 
			// buttonBottomView
			// 
			this->buttonBottomView->Dock = System::Windows::Forms::DockStyle::Fill;
			this->buttonBottomView->Location = System::Drawing::Point(49, 29);
			this->buttonBottomView->Name = L"buttonBottomView";
			this->buttonBottomView->Size = System::Drawing::Size(40, 20);
			this->buttonBottomView->TabIndex = 0;
			this->buttonBottomView->Text = L"Bottom";
			this->buttonBottomView->UseVisualStyleBackColor = true;
			this->buttonBottomView->Click += gcnew System::EventHandler(this, &MainForm::buttonBottomView_Click);
			// 
			// buttonTopView
			// 
			this->buttonTopView->Dock = System::Windows::Forms::DockStyle::Fill;
			this->buttonTopView->Location = System::Drawing::Point(49, 3);
			this->buttonTopView->Name = L"buttonTopView";
			this->buttonTopView->Size = System::Drawing::Size(40, 20);
			this->buttonTopView->TabIndex = 1;
			this->buttonTopView->Text = L"Top";
			this->buttonTopView->UseVisualStyleBackColor = true;
			this->buttonTopView->Click += gcnew System::EventHandler(this, &MainForm::buttonTopView_Click);
			// 
			// buttonFrontView
			// 
			this->buttonFrontView->Dock = System::Windows::Forms::DockStyle::Fill;
			this->buttonFrontView->Location = System::Drawing::Point(3, 3);
			this->buttonFrontView->Name = L"buttonFrontView";
			this->buttonFrontView->Size = System::Drawing::Size(40, 20);
			this->buttonFrontView->TabIndex = 2;
			this->buttonFrontView->Text = L"Front";
			this->buttonFrontView->UseVisualStyleBackColor = true;
			this->buttonFrontView->Click += gcnew System::EventHandler(this, &MainForm::buttonFrontView_Click);
			// 
			// buttonBackView
			// 
			this->buttonBackView->Dock = System::Windows::Forms::DockStyle::Fill;
			this->buttonBackView->Location = System::Drawing::Point(3, 29);
			this->buttonBackView->Name = L"buttonBackView";
			this->buttonBackView->Size = System::Drawing::Size(40, 20);
			this->buttonBackView->TabIndex = 3;
			this->buttonBackView->Text = L"Back";
			this->buttonBackView->UseVisualStyleBackColor = true;
			this->buttonBackView->Click += gcnew System::EventHandler(this, &MainForm::buttonBackView_Click);
			// 
			// buttonFTRView
			// 
			this->buttonFTRView->Dock = System::Windows::Forms::DockStyle::Fill;
			this->buttonFTRView->Location = System::Drawing::Point(3, 55);
			this->buttonFTRView->Name = L"buttonFTRView";
			this->buttonFTRView->Size = System::Drawing::Size(40, 22);
			this->buttonFTRView->TabIndex = 4;
			this->buttonFTRView->Text = L"FTR";
			this->buttonFTRView->UseVisualStyleBackColor = true;
			this->buttonFTRView->Click += gcnew System::EventHandler(this, &MainForm::buttonFTRView_Click);
			// 
			// buttonBBLView
			// 
			this->buttonBBLView->Dock = System::Windows::Forms::DockStyle::Fill;
			this->buttonBBLView->Location = System::Drawing::Point(49, 55);
			this->buttonBBLView->Name = L"buttonBBLView";
			this->buttonBBLView->Size = System::Drawing::Size(40, 22);
			this->buttonBBLView->TabIndex = 5;
			this->buttonBBLView->Text = L"BBL";
			this->buttonBBLView->UseVisualStyleBackColor = true;
			this->buttonBBLView->Click += gcnew System::EventHandler(this, &MainForm::buttonBBLView_Click);
			// 
			// buttonResetView
			// 
			this->buttonResetView->Dock = System::Windows::Forms::DockStyle::Fill;
			this->buttonResetView->Location = System::Drawing::Point(95, 55);
			this->buttonResetView->Name = L"buttonResetView";
			this->buttonResetView->Size = System::Drawing::Size(41, 22);
			this->buttonResetView->TabIndex = 6;
			this->buttonResetView->Text = L"Reset";
			this->buttonResetView->UseVisualStyleBackColor = true;
			this->buttonResetView->Click += gcnew System::EventHandler(this, &MainForm::buttonResetView_Click);
			// 
			// buttonLeftView
			// 
			this->buttonLeftView->Dock = System::Windows::Forms::DockStyle::Fill;
			this->buttonLeftView->Location = System::Drawing::Point(95, 29);
			this->buttonLeftView->Name = L"buttonLeftView";
			this->buttonLeftView->Size = System::Drawing::Size(41, 20);
			this->buttonLeftView->TabIndex = 7;
			this->buttonLeftView->Text = L"Left";
			this->buttonLeftView->UseVisualStyleBackColor = true;
			this->buttonLeftView->Click += gcnew System::EventHandler(this, &MainForm::buttonLeftView_Click);
			// 
			// buttonRightView
			// 
			this->buttonRightView->Dock = System::Windows::Forms::DockStyle::Fill;
			this->buttonRightView->Location = System::Drawing::Point(95, 3);
			this->buttonRightView->Name = L"buttonRightView";
			this->buttonRightView->Size = System::Drawing::Size(41, 20);
			this->buttonRightView->TabIndex = 8;
			this->buttonRightView->Text = L"Right";
			this->buttonRightView->UseVisualStyleBackColor = true;
			this->buttonRightView->Click += gcnew System::EventHandler(this, &MainForm::buttonRightView_Click);
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				80)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				20)));
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel3, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->mainPanel, 0, 0);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 24);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 1;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(784, 537);
			this->tableLayoutPanel1->TabIndex = 4;
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(784, 561);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->tableLayoutPanel2->ResumeLayout(false);
			this->tableLayoutPanel2->PerformLayout();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->tableLayoutPanel3->ResumeLayout(false);
			this->groupBox1->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->tableLayoutPanel4->ResumeLayout(false);
			this->tableLayoutPanel4->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox4->ResumeLayout(false);
			this->groupBox5->ResumeLayout(false);
			this->tableLayoutPanel7->ResumeLayout(false);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
	if (faceColorDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		label1->BackColor = faceColorDialog->Color;
		meshView->faceColor.r = label1->BackColor.R / 255.0;
		meshView->faceColor.g = label1->BackColor.G / 255.0;
		meshView->faceColor.b = label1->BackColor.B / 255.0;
	}
}
private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
	if (lineColorDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		label2->BackColor = lineColorDialog->Color;
		meshView->lineColor.r = label2->BackColor.R / 255.0;
		meshView->lineColor.g = label2->BackColor.G / 255.0;
		meshView->lineColor.b = label2->BackColor.B / 255.0;
	}
}
private: System::Void label3_Click(System::Object^  sender, System::EventArgs^  e) {
	if (pointColorDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		label3->BackColor = pointColorDialog->Color;
		meshView->pointColor.r = label3->BackColor.R / 255.0;
		meshView->pointColor.g = label3->BackColor.G / 255.0;
		meshView->pointColor.b = label3->BackColor.B / 255.0;
	}
}
private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	meshView->drawFace = checkBox1->Checked;
}
private: System::Void checkBox2_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	meshView->drawLine = checkBox2->Checked;
}
private: System::Void checkBox3_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	meshView->drawPoint = checkBox3->Checked;
}
private: System::Void checkBox4_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	meshView->isLighting = checkBox4->Checked;
}
private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	try
	{
		meshView->lineWidth = float::Parse(textBox1->Text);
	}
	catch (System::FormatException^ e)
	{

	}
}
private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	try
	{
		meshView->pointSize = float::Parse(textBox2->Text);
	}
	catch (System::FormatException^ e)
	{

	}
}

private: System::Void readModelToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		meshView->LoadMainMesh((const char*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(openFileDialog1->FileName).ToPointer());
		//System::Console::WriteLine(openFileDialog1->FileName);
	}
}
private: System::Void buttonFrontView_Click(System::Object^  sender, System::EventArgs^  e) {
	meshView->SetView(MeshViewPanel::ViewDirection::FrontView);
}
private: System::Void buttonTopView_Click(System::Object^  sender, System::EventArgs^  e) {
	meshView->SetView(MeshViewPanel::ViewDirection::TopView);
}
private: System::Void buttonRightView_Click(System::Object^  sender, System::EventArgs^  e) {
	meshView->SetView(MeshViewPanel::ViewDirection::RightView);
}
private: System::Void buttonBackView_Click(System::Object^  sender, System::EventArgs^  e) {
	meshView->SetView(MeshViewPanel::ViewDirection::BackView);
}
private: System::Void buttonBottomView_Click(System::Object^  sender, System::EventArgs^  e) {
	meshView->SetView(MeshViewPanel::ViewDirection::BottomView);
}
private: System::Void buttonLeftView_Click(System::Object^  sender, System::EventArgs^  e) {
	meshView->SetView(MeshViewPanel::ViewDirection::LeftView);
}
private: System::Void buttonFTRView_Click(System::Object^  sender, System::EventArgs^  e) {
	meshView->SetView(MeshViewPanel::ViewDirection::FTRView);
}
private: System::Void buttonBBLView_Click(System::Object^  sender, System::EventArgs^  e) {
	meshView->SetView(MeshViewPanel::ViewDirection::BBLView);
}
private: System::Void buttonResetView_Click(System::Object^  sender, System::EventArgs^  e) {
	meshView->SetView(MeshViewPanel::ViewDirection::ResetView);
}
};
}
