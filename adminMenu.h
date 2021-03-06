#pragma once
#include"mysql.h"
#include"equipmentListForm.h"
#include"insertFile.h"
#include"update.h"
#include"displayloanRecord.h"
#include"configForm.h"
namespace GUIProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// adminMenu 的摘要
	/// </summary>
	public ref class adminMenu : public System::Windows::Forms::Form
	{
	public:
		Form ^obj1;
		adminMenu(void)
		{
			InitializeComponent();
			//
			//TODO:  在此加入建構函式程式碼
			//
		}
		adminMenu(Form ^f1)
		{
			obj1 = f1;
			InitializeComponent();
			//
			//TODO:  在此加入建構函式程式碼
			//
		}
	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~adminMenu()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	protected:
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button7;


	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改
		/// 這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(198, 37);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(113, 33);
			this->button1->TabIndex = 0;
			this->button1->Text = L"insert file";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &adminMenu::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(36, 92);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(113, 42);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Display list of camp equipment";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &adminMenu::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(36, 160);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(275, 31);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Update condition of equipment";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &adminMenu::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(36, 247);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(113, 35);
			this->button4->TabIndex = 3;
			this->button4->Text = L"Exit program";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &adminMenu::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(198, 92);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(113, 42);
			this->button5->TabIndex = 4;
			this->button5->Text = L"Display user loan record";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &adminMenu::button5_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(36, 37);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(113, 33);
			this->button6->TabIndex = 5;
			this->button6->Text = L"Mysql config";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &adminMenu::button6_Click);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(196, 247);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(115, 35);
			this->button7->TabIndex = 6;
			this->button7->Text = L"log out";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &adminMenu::button7_Click);
			// 
			// adminMenu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(340, 336);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"adminMenu";
			this->Text = L"adminMenu";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Hide();
		insertFile ^f2 = gcnew insertFile(this);
		f2->ShowDialog();

	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Hide();
		equipmentListForm ^f2 = gcnew equipmentListForm(this);
		f2->ShowDialog();
	}
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Hide();
		update ^f2 = gcnew update(this);
		f2->ShowDialog();
	}
	private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
		 this->Hide();
		 displayloanRecord ^f2 = gcnew displayloanRecord(this);
		 f2->ShowDialog();
	}
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
		Application::Exit();
	}
	
	private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Hide();
		configForm ^ f2 = gcnew configForm(this);
		f2->ShowDialog();
	}
private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Hide();
	obj1->Show();
}
private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {
}
};
}
