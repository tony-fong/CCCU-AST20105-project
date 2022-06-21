#pragma once
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
	/// loanRecordForm 的摘要
	/// </summary>
	public ref class loanRecordForm : public System::Windows::Forms::Form
	{
	public:
		Form ^obj1;
		loanRecordForm(void)
		{
			InitializeComponent();
			//
			//TODO:  在此加入建構函式程式碼
			//
		}
		loanRecordForm(Form ^f2)
		{
			obj1 = f2;
			InitializeComponent();
			//
			//TODO:  在此加入建構函式程式碼
			//
		}


	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~loanRecordForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::Button^  button1;

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
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(12, 12);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->ReadOnly = true;
			this->richTextBox1->Size = System::Drawing::Size(767, 280);
			this->richTextBox1->TabIndex = 0;
			this->richTextBox1->Text = L"";
			this->richTextBox1->TextChanged += gcnew System::EventHandler(this, &loanRecordForm::richTextBox1_TextChanged);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(691, 340);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(88, 27);
			this->button1->TabIndex = 1;
			this->button1->Text = L"return";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &loanRecordForm::button1_Click);
			// 
			// loanRecordForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(791, 410);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->richTextBox1);
			this->Name = L"loanRecordForm";
			this->Text = L"loanRecordForm";
			this->Load += gcnew System::EventHandler(this, &loanRecordForm::loanRecordForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void richTextBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	
	}
	//display user which item is borrow now
	private: System::Void loanRecordForm_Load(System::Object^  sender, System::EventArgs^  e) {
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
					str << " | ";
				}
			}str << "\r\n";
		}
		String^ str2 = gcnew String(str.str().c_str());
		richTextBox1->Text = str2;
		mysql_free_result(res_set);
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Hide();
		obj1->Show();
	}
};
}
