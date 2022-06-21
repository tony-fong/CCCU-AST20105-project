#pragma once
#include"mysql.h"
#include<sstream>
namespace GUIProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// equipmentListForm 的摘要
	/// </summary>
	public ref class equipmentListForm : public System::Windows::Forms::Form
	{
	public:
		Form ^obj1;
		equipmentListForm(void)
		{
			InitializeComponent();
			//
			//TODO:  在此加入建構函式程式碼
			//
		}
		equipmentListForm(Form ^f2) {
			obj1 = f2;
			InitializeComponent();
		}
	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~equipmentListForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	protected:
	private: System::Windows::Forms::Button^  button1;

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
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(5, 43);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->ReadOnly = true;
			this->richTextBox1->Size = System::Drawing::Size(603, 259);
			this->richTextBox1->TabIndex = 0;
			this->richTextBox1->Text = L"";
			this->richTextBox1->TextChanged += gcnew System::EventHandler(this, &equipmentListForm::richTextBox1_TextChanged);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(510, 332);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Exit";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &equipmentListForm::button1_Click);
			// 
			// equipmentListForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(613, 387);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->richTextBox1);
			this->Name = L"equipmentListForm";
			this->Text = L"equipmentListForm";
			this->Load += gcnew System::EventHandler(this, &equipmentListForm::equipmentListForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	//display all camp equipment
	private: System::Void equipmentListForm_Load(System::Object^  sender, System::EventArgs^  e) {
		MYSQL_RES *res_set;
		MYSQL_ROW row;
		stringstream s;
		mysql display;
		for (int i = 0; i < 3; i++) {
			string type[3] = { "tent", "stove", "lantern" };
			display.link();
			res_set = display.select_query("*", type[i],"");

			int num = mysql_num_fields(res_set);
			while (row = mysql_fetch_row(res_set)) {
				for (int i = 0; i < num; i++) {
					s << row[i] << "|";
				}
				s << "\r\n";
			}
			String^ str2 = gcnew String(s.str().c_str());
			richTextBox1->Text = str2;
		}
	}
	private: System::Void richTextBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Hide();
		obj1->Show();
	}
};
	
}