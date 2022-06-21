#pragma once
#include <msclr\marshal_cppstd.h>
#include<sstream>
#include"getdate.h"
#include"mysql.h"
#include"user.h"
#include"checkType.h"
namespace GUIProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// borrowForm 的摘要
	/// </summary>
	public ref class borrowForm : public System::Windows::Forms::Form
	{
	public:
		Form ^obj1;
		borrowForm(void)
		{
			InitializeComponent();
			//
			//TODO:  在此加入建構函式程式碼
			//
		}
		borrowForm(Form ^f2) {
			obj1 = f2;
			InitializeComponent();
		}
	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~borrowForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(25, 31);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(863, 277);
			this->textBox1->TabIndex = 0;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &borrowForm::textBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(25, 315);
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->Size = System::Drawing::Size(167, 25);
			this->textBox2->TabIndex = 1;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &borrowForm::textBox2_TextChanged);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(25, 362);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(167, 25);
			this->textBox3->TabIndex = 2;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &borrowForm::textBox3_TextChanged);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(213, 362);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(91, 25);
			this->button1->TabIndex = 3;
			this->button1->Text = L"borrow";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &borrowForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(813, 364);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Exit";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &borrowForm::button2_Click);
			// 
			// borrowForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(928, 415);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Name = L"borrowForm";
			this->Text = L"borrowForm";
			this->Load += gcnew System::EventHandler(this, &borrowForm::borrowForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		msclr::interop::marshal_context context;

		MYSQL_RES *res_set;
		MYSQL_ROW row;
		mysql display;
		mysql updata;
		string temp;
		stringstream s;
		String ^ Code = textBox3->Text;
		string code = context.marshal_as<string>(Code);
		//count user borrow how many item.
		int numReturn;
		display.link();
		temp = "where userID = '" + USER.getID() + "'" + "AND  inDate IS NULL";
		res_set = display.select_query("*", "borrow", temp);
		numReturn = mysql_num_rows(res_set);
		
		display.link();
		if ((USER.getlimit() - numReturn) == 0){
			MessageBox::Show("max");
		}else{
		if (code == "") {
			MessageBox::Show("plase intput item code");
		}
		if (code == to_string(-1)) {
		}
		else {
			string nowdate = date();
			string type = checkType(code);
			string in = "in";
			string out = "out";

			res_set = display.select("name,type,status", type, "code", code);
			if (mysql_num_rows(res_set) != 0) {
				row = mysql_fetch_row(res_set);
				if (row[2] == in) {
					temp = "'" + USER.getID() + "', " + "'" + USER.getName() + "', " + "'" + code + "', " + "'" + row[1] + "', " + "'" + row[0] + "', " + "'" + nowdate + "'";
					//insert userID , name , user borrow item code , item name and borrow date to borrow table
					updata.link();
					if (updata.insert("borrow", "`userID`, `name`, `code`, `type`, `ItemName`, `outDate`", temp) == 0) {
						MessageBox::Show("borrow successful");
						updata.link();
						updata.update(type, "status = 'out'", "code", code);
						textBox3->Text = "";	
						
						// update user how many item can borrow
						display.link();
						temp = "where userID = '" + USER.getID() + "'" + "AND  inDate IS NULL";
						res_set = display.select_query("*", "borrow", temp);
						numReturn = mysql_num_rows(res_set);
						textBox2->Text = "you cna borrow " + (USER.getlimit() - numReturn) + " item!";
					}
					else {
						MessageBox::Show("fail!please check your input");
					}
					



					//refresh the text
					display.link();
					for (int i = 0; i < 3; i++) {

						string type[3] = { "tent", "stove", "lantern" };
						res_set = display.select_query("*", type[i], "where conditions ='good' and status = 'in'");
						int num = mysql_num_fields(res_set);
						while (row = mysql_fetch_row(res_set)) {
							for (int i = 0; i < num; i++) {
								s << row[i];
								s << " | ";
							}s << "\r\n";
						}
					}


					String^ str2 = gcnew String(s.str().c_str());
					//textBox1->AppendText(str2);
					textBox1->Text = str2;
				}
				else if (row[2] == out) {
					cout << "the item has borrow" << endl;
					MessageBox::Show("the item has borrow");
				}
			}
			else {
				cout << "fail please check your input!" << endl;
				MessageBox::Show("fail please check your input!");
			}
		}
		}
	}
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void borrowForm_Load(System::Object^  sender, System::EventArgs^  e) {
	//display item can borrow
	mysql display;
	MYSQL_RES *res_set;
	MYSQL_ROW row;
	stringstream s;
	display.link();
	//display user can borrow which item 
	for (int i = 0; i < 3; i++) {
		string type[3] = { "tent", "stove", "lantern" };
		res_set = display.select_query("*", type[i], "where conditions ='good' and status = 'in'");
		int num = mysql_num_fields(res_set);
		while (row = mysql_fetch_row(res_set)) {
			for (int i = 0; i < num; i++) {
				s << row[i];
				s << " | ";
			}s << "\r\n";
		}
	}
	String^ str2 = gcnew String(s.str().c_str());
	textBox1->Text = str2;
	mysql_free_result(res_set);

	// display how many item user can borrow
	textBox2->Text = "you cna borrow " + USER.getlimit() + " item!";
}
private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Hide();
	obj1->Show();
}
private: System::Void textBox3_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
};
}
