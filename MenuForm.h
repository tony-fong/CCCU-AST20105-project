#include"user.h"
#include <msclr\marshal_cppstd.h>
#include<iostream>
#include<fstream>
#include<cstdio>
#include<string>
#include<sstream>
#include"mysql.h"
#include"displayItem.h"
#include"borrowForm.h"
#include"returnitem.h"
#include"loanRecordForm.h"


namespace GUIProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MenuForm 的摘要
	/// </summary>
	public ref class MenuForm : public System::Windows::Forms::Form
	{
	public:
		Form ^obj1;
		MenuForm(void)
		{
			InitializeComponent();
			//
			//TODO:  在此加入建構函式程式碼
			//
		}
		MenuForm(Form ^f1) {
			obj1 = f1;
			InitializeComponent();
		}
	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~MenuForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;



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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"新細明體", 25.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label1->Location = System::Drawing::Point(12, 41);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(290, 43);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Scout Company";
			this->label1->Click += gcnew System::EventHandler(this, &MenuForm::label1_Click);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"新細明體", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button1->Location = System::Drawing::Point(69, 111);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(183, 41);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Display avaliable item";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MenuForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"新細明體", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button2->Location = System::Drawing::Point(69, 183);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(183, 49);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Display user record";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MenuForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"新細明體", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button3->Location = System::Drawing::Point(69, 260);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(183, 36);
			this->button3->TabIndex = 3;
			this->button3->Text = L"sub menu";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MenuForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"新細明體", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button4->Location = System::Drawing::Point(69, 329);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(183, 40);
			this->button4->TabIndex = 4;
			this->button4->Text = L"Return item";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MenuForm::button4_Click);
			// 
			// button5
			// 
			this->button5->Font = (gcnew System::Drawing::Font(L"新細明體", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button5->Location = System::Drawing::Point(69, 391);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(94, 33);
			this->button5->TabIndex = 5;
			this->button5->Text = L"Exit";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MenuForm::button5_Click);
			// 
			// button6
			// 
			this->button6->Font = (gcnew System::Drawing::Font(L"新細明體", 9, System::Drawing::FontStyle::Bold));
			this->button6->Location = System::Drawing::Point(169, 391);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(83, 33);
			this->button6->TabIndex = 6;
			this->button6->Text = L"log out";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MenuForm::button6_Click_1);
			// 
			// MenuForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(350, 464);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Name = L"MenuForm";
			this->Text = L"MenuForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
		Application::Exit();
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	
		this->Hide();
		MyForm ^f2 = gcnew MyForm(this);
		f2->ShowDialog();
	}

private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
	
	
	
	
}
private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	mysql loan;

	MYSQL_RES *res_set;
	MYSQL_ROW row;
	string code;
	int numReturn = 0;

	loan.link();
	string temp = "where userID = '" + USER.getID() + "'" + "AND  inDate IS NULL";
	res_set = loan.select_query("*", "borrow", temp);
	numReturn = mysql_num_rows(res_set);
	//cout << numReturn << endl;

	if (numReturn == 0) {
		MessageBox::Show("you have not borrow item yet");
	}
	else {
		this->Hide();
		loanRecordForm ^f2 = gcnew loanRecordForm(this);
		f2->ShowDialog();
		
	}
}
private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	MYSQL_RES *res_set;
	MYSQL_ROW row;
	mysql display;
	mysql updata;
	string temp;

	int numReturn;
	display.link();
	temp = "where userID = '" + USER.getID() + "'" + "AND  inDate IS NULL";
	res_set = display.select_query("*", "borrow", temp);
	numReturn = mysql_num_rows(res_set);
	//cout << numReturn << endl;
	//int cou = USER.getlimit();
	if (numReturn != 0) {
		MessageBox::Show("you have some item not return yet");
		cout << "you have not return the item" << endl;
	}else {
		this->Hide();
		borrowForm ^f2 = gcnew borrowForm(this);
		f2->ShowDialog();
	}
}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
	mysql loan;
	
	MYSQL_RES *res_set;
	MYSQL_ROW row;
	string code;
	int numReturn = 0;

	loan.link();
	string temp = "where userID = '" + USER.getID() + "'" + "AND  inDate IS NULL";
	res_set = loan.select_query("*", "borrow", temp);
	numReturn = mysql_num_rows(res_set);
	//cout << numReturn << endl;

	if (numReturn == 0) {
		MessageBox::Show("you have not borrow item yet");
	}else {
		this->Hide();
		returnitem ^f2 = gcnew returnitem(this);
		f2->ShowDialog();
	}
}
private: System::Void button6_Click_1(System::Object^  sender, System::EventArgs^  e) {
	this->Hide();
	obj1->Show();
}
};
}