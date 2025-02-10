#pragma once

namespace ShortcutProperties {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^ tabControl1;
	protected:

	protected:

	protected:

	protected:

	protected:
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::TabPage^ tabPage2;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ txtWorkingDir;

	private: System::Windows::Forms::TextBox^ txtObject;
	private: System::Windows::Forms::Button^ btnOpenFileLocation;
	private: System::Windows::Forms::Button^ btnChangeIcon;
	private: System::Windows::Forms::TextBox^ txtWindowState;
	private: System::Windows::Forms::TextBox^ txtShortcutKey;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::CheckBox^ chkAdmin;
	private: System::Windows::Forms::CheckBox^ chkWin7;
	private: System::Windows::Forms::CheckBox^ chkWinXP;



	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->txtObject = (gcnew System::Windows::Forms::TextBox());
			this->txtWorkingDir = (gcnew System::Windows::Forms::TextBox());
			this->txtShortcutKey = (gcnew System::Windows::Forms::TextBox());
			this->txtWindowState = (gcnew System::Windows::Forms::TextBox());
			this->btnChangeIcon = (gcnew System::Windows::Forms::Button());
			this->btnOpenFileLocation = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->chkAdmin = (gcnew System::Windows::Forms::CheckBox());
			this->chkWinXP = (gcnew System::Windows::Forms::CheckBox());
			this->chkWin7 = (gcnew System::Windows::Forms::CheckBox());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Location = System::Drawing::Point(12, 12);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(409, 274);
			this->tabControl1->TabIndex = 0;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->btnOpenFileLocation);
			this->tabPage1->Controls->Add(this->btnChangeIcon);
			this->tabPage1->Controls->Add(this->txtWindowState);
			this->tabPage1->Controls->Add(this->txtShortcutKey);
			this->tabPage1->Controls->Add(this->txtWorkingDir);
			this->tabPage1->Controls->Add(this->txtObject);
			this->tabPage1->Controls->Add(this->label4);
			this->tabPage1->Controls->Add(this->label3);
			this->tabPage1->Controls->Add(this->label2);
			this->tabPage1->Controls->Add(this->label1);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(401, 248);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Ярлык";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->groupBox1);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(401, 248);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Совместимость";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->Location = System::Drawing::Point(27, 35);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(51, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Объект:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(27, 76);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(85, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Рабочая папка:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(27, 113);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(96, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Клавиша вызова:";
			this->label3->Click += gcnew System::EventHandler(this, &MyForm::label3_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(31, 144);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(92, 13);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Начальное окно:";
			// 
			// txtObject
			// 
			this->txtObject->Location = System::Drawing::Point(261, 32);
			this->txtObject->Name = L"txtObject";
			this->txtObject->Size = System::Drawing::Size(100, 20);
			this->txtObject->TabIndex = 4;
			this->txtObject->TextChanged += gcnew System::EventHandler(this, &MyForm::txtObject_TextChanged);
			// 
			// txtWorkingDir
			// 
			this->txtWorkingDir->Location = System::Drawing::Point(261, 69);
			this->txtWorkingDir->Name = L"txtWorkingDir";
			this->txtWorkingDir->Size = System::Drawing::Size(100, 20);
			this->txtWorkingDir->TabIndex = 5;
			// 
			// txtShortcutKey
			// 
			this->txtShortcutKey->Location = System::Drawing::Point(261, 106);
			this->txtShortcutKey->Name = L"txtShortcutKey";
			this->txtShortcutKey->Size = System::Drawing::Size(100, 20);
			this->txtShortcutKey->TabIndex = 6;
			// 
			// txtWindowState
			// 
			this->txtWindowState->Location = System::Drawing::Point(261, 141);
			this->txtWindowState->Name = L"txtWindowState";
			this->txtWindowState->Size = System::Drawing::Size(100, 20);
			this->txtWindowState->TabIndex = 7;
			// 
			// btnChangeIcon
			// 
			this->btnChangeIcon->Location = System::Drawing::Point(30, 183);
			this->btnChangeIcon->Name = L"btnChangeIcon";
			this->btnChangeIcon->Size = System::Drawing::Size(156, 23);
			this->btnChangeIcon->TabIndex = 8;
			this->btnChangeIcon->Text = L"Изменить значок";
			this->btnChangeIcon->UseVisualStyleBackColor = true;
			// 
			// btnOpenFileLocation
			// 
			this->btnOpenFileLocation->Location = System::Drawing::Point(207, 176);
			this->btnOpenFileLocation->Name = L"btnOpenFileLocation";
			this->btnOpenFileLocation->Size = System::Drawing::Size(154, 36);
			this->btnOpenFileLocation->TabIndex = 9;
			this->btnOpenFileLocation->Text = L"Открыть расположение файла";
			this->btnOpenFileLocation->UseVisualStyleBackColor = true;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->chkWin7);
			this->groupBox1->Controls->Add(this->chkWinXP);
			this->groupBox1->Controls->Add(this->chkAdmin);
			this->groupBox1->Location = System::Drawing::Point(30, 18);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(337, 209);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Настройки совместимости";
			// 
			// chkAdmin
			// 
			this->chkAdmin->AutoSize = true;
			this->chkAdmin->Location = System::Drawing::Point(22, 32);
			this->chkAdmin->Name = L"chkAdmin";
			this->chkAdmin->Size = System::Drawing::Size(215, 17);
			this->chkAdmin->TabIndex = 0;
			this->chkAdmin->Text = L"Запускать от имени администратора";
			this->chkAdmin->UseVisualStyleBackColor = true;
			// 
			// chkWinXP
			// 
			this->chkWinXP->AutoSize = true;
			this->chkWinXP->Location = System::Drawing::Point(22, 66);
			this->chkWinXP->Name = L"chkWinXP";
			this->chkWinXP->Size = System::Drawing::Size(217, 17);
			this->chkWinXP->TabIndex = 1;
			this->chkWinXP->Text = L"Режим совместимости с Windows XP";
			this->chkWinXP->UseVisualStyleBackColor = true;
			// 
			// chkWin7
			// 
			this->chkWin7->AutoSize = true;
			this->chkWin7->Location = System::Drawing::Point(22, 103);
			this->chkWin7->Name = L"chkWin7";
			this->chkWin7->Size = System::Drawing::Size(209, 17);
			this->chkWin7->TabIndex = 2;
			this->chkWin7->Text = L"Режим совместимости с Windows 7";
			this->chkWin7->UseVisualStyleBackColor = true;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(433, 297);
			this->Controls->Add(this->tabControl1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion


private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void txtObject_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
