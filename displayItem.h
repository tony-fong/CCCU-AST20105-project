#include"user.h"
#include <msclr\marshal_cppstd.h>
#include<iostream>
#include<fstream>
#include<cstdio>
#include<string>
#include<sstream>
#include"mysql.h"

namespace GUIProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MyForm 的摘要
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		Form ^obj1;
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO:  在此加入建構函式程式碼
			//
		}
		MyForm(Form ^f2)
		{
			obj1 = f2;
			InitializeComponent();
		}
	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button6;
	protected:

	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;

	protected:


	protected:






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
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->SuspendLayout();
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(653, 40);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(143, 35);
			this->button6->TabIndex = 15;
			this->button6->Text = L"start to search";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click_1);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"新細明體", 18));
			this->label4->Location = System::Drawing::Point(16, 38);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(313, 30);
			this->label4->TabIndex = 13;
			this->label4->Text = L"Please choose your option";
			// 
			// comboBox1
			// 
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"新細明體", 18));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(346, 35);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(128, 38);
			this->comboBox1->TabIndex = 12;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(802, 40);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(86, 33);
			this->button1->TabIndex = 16;
			this->button1->Text = L"Exit";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(21, 89);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->ReadOnly = true;
			this->richTextBox1->Size = System::Drawing::Size(867, 320);
			this->richTextBox1->TabIndex = 17;
			this->richTextBox1->Text = L"";
			this->richTextBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::richTextBox1_TextChanged);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(900, 421);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->comboBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	


private: System::Void button6_Click_1(System::Object^  sender, System::EventArgs^  e) {
	
	msclr::interop::marshal_context context;
	String ^ use = comboBox1->SelectedItem->ToString();
	std::string type = context.marshal_as<std::string>(use);
	stringstream s;
	MYSQL_RES *res_set;
	MYSQL_ROW row;
	//display available item
	mysql display;
	display.link();
	res_set = display.select_query("*", type, "where conditions ='good' and status = 'in'");
	int num = mysql_num_fields(res_set);
	while (row = mysql_fetch_row(res_set)) {
		for (int i = 0; i < num; i++) {
			s << row[i];
			s << " | ";
		}
		s << "\r\n";
	}
	String^ str2 = gcnew String(s.str().c_str());
	if (use == "tent") {
		richTextBox1->Text = str2;
	}
	if (use == "stove") {
		richTextBox1->Text = str2;
	}
	if (use == "lantern") {
		richTextBox1->Text = str2;
	}
	s.str("");
}
private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	comboBox1->Items->Add("tent");
	comboBox1->Items->Add("stove");
	comboBox1->Items->Add("lantern");
}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Hide();
	obj1->Show();

}
private: System::Void richTextBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
};
}