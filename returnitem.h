#pragma once

#include<sstream>
#include"checkType.h"
#include"getdate.h"
#include"mysql.h"
#include"user.h"
namespace GUIProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// returnitem 的摘要
	/// </summary>
	public ref class returnitem : public System::Windows::Forms::Form
	{
	public:
		Form ^obj1;
		returnitem(void)
		{
			InitializeComponent();
			//
			//TODO:  在此加入建構函式程式碼
			//
		}
		returnitem(Form^f2) {
			obj1 = f2;
			InitializeComponent();
		
		}
	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~returnitem()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::ComponentModel::IContainer^  components;
	protected:

	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改
		/// 這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 12);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(610, 192);
			this->textBox1->TabIndex = 0;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &returnitem::textBox1_TextChanged);
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(61, 4);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(12, 249);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(132, 25);
			this->textBox2->TabIndex = 2;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &returnitem::textBox2_TextChanged);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(175, 249);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(98, 24);
			this->button1->TabIndex = 3;
			this->button1->Text = L"return item";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &returnitem::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(514, 249);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(89, 24);
			this->button2->TabIndex = 4;
			this->button2->Text = L"return";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &returnitem::button2_Click);
			// 
			// returnitem
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(634, 339);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Name = L"returnitem";
			this->Text = L"returnitem";
			this->Load += gcnew System::EventHandler(this, &returnitem::returnitem_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void returnitem_Load(System::Object^  sender, System::EventArgs^  e) {
		mysql loan;

		MYSQL_RES *res_set;
		MYSQL_ROW row;
		stringstream str;
		string temp;
		int num;

		loan.link();
		temp = "where userID = '" + USER.getID() + "' and inDate IS NULL";
		res_set = loan.select_query("*", "borrow", temp);
		num = mysql_num_fields(res_set);
		//cout << num << endl;
		while (row = mysql_fetch_row(res_set)) {
			for (int i = 0; i < num; i++) {
				if (row[6] == NULL && row[i] != NULL) {
					str << row[i];
					str << "|";
				}
			}str << "\r\n";
		}
		String^ str2 = gcnew String(str.str().c_str());
		textBox1->Text = str2;
		mysql_free_result(res_set);
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		mysql reitem;
		cout << "plasue input return item code" << endl;
		cout << "enter -1 to exit" << endl;

		msclr::interop::marshal_context context;
		String ^ Code = textBox2->Text;
		string code = context.marshal_as<std::string>(Code);
		if (code == to_string(-1)) {}
		else {
			reitem.link();
			string type = checkType(code);
			string nowdate = date();
			string value = "inDate = '" + nowdate + "'";
			if (reitem.update("borrow", value, "code", code)==0) {
				reitem.link();
				reitem.update(type, "status = 'in'", "code", code);
				MessageBox::Show("return item success");
				textBox2->Text = "";
			}else {
				MessageBox::Show("somthing worng please your input");
			}
			
		}

		//refresh textBox1
		MYSQL_RES *res_set;
		MYSQL_ROW row;
		string temp;
		stringstream str;
		int num;
		mysql loan;
		loan.link();
		temp = "where userID = '" + USER.getID() + "' and inDate IS NULL";
		res_set = loan.select_query("*","borrow", temp);
		num = mysql_num_fields(res_set);
		//cout << num << endl;
		while (row = mysql_fetch_row(res_set)) {
			for (int i = 0; i < num; i++) {
				if (row[6] == NULL && row[i] != NULL) {
					str << row[i];
					str << " | ";
				}
			}str << "\r\n";
		}
		String^ str2 = gcnew String(str.str().c_str());
		textBox1->Text = str2;
	}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Hide();
	obj1->Show();
}
private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
};
}
