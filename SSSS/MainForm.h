#pragma once
#include "MeshViewPanel.h"
#include "OpenGLPanel.h"

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
			meshView = new MeshView;
			gcnew OpenGLPanel(this->mainPanel, this->mainPanelTimer, meshView);
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
	protected:

	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>
		MeshView* meshView;

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
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->tableLayoutPanel2->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->tableLayoutPanel3->SuspendLayout();
			this->groupBox1->SuspendLayout();
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
};
}
