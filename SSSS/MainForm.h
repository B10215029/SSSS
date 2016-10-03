#pragma once
#include "MeshViewPanel.h"

namespace SSSS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MainForm ���K�n
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO:  �b���[�J�غc�禡�{���X
			//
			gcnew MeshViewPanel(this->mainPanel, this->mainPanelTimer);
		}

	protected:
		/// <summary>
		/// �M������ϥΤ����귽�C
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
	private: System::ComponentModel::IContainer^  components;
	protected:

	private:
		/// <summary>
		/// �]�p�u��һݪ��ܼơC
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// �����]�p�u��䴩�һݪ���k - �ФŨϥε{���X�s�边�ק�
		/// �o�Ӥ�k�����e�C
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->mainPanel = (gcnew System::Windows::Forms::Panel());
			this->mainPanelTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// mainPanel
			// 
			this->mainPanel->Location = System::Drawing::Point(12, 12);
			this->mainPanel->Name = L"mainPanel";
			this->mainPanel->Size = System::Drawing::Size(760, 537);
			this->mainPanel->TabIndex = 0;
			// 
			// mainPanelTimer
			// 
			this->mainPanelTimer->Enabled = true;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(784, 561);
			this->Controls->Add(this->mainPanel);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
