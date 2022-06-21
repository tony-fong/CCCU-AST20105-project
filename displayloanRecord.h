#pragma once
#include"mysql.h"
namespace GUIProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// displayloanRecord 的摘要
	/// </summary>
	public ref class displayloanRecord : public System::Windows::Forms::Form
	{
	public:
		Form ^obj1;
		displayloanRecord(void)
		{
			InitializeComponent();
			//
			//TODO:  在此加入建構函式程式碼
			//
		}
		displayloanRecord(Form ^f2) {
			obj1 = f2;
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~displayloanRecord()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::RichTextBox^  richTextBox2;
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
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(13, 42);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->ReadOnly = true;
			this->richTextBox1->Size = System::Drawing::Size(917, 303);
			this->richTextBox1->TabIndex = 0;
			this->richTextBox1->Text = L"";
			this->richTextBox1->TextChanged += gcnew System::EventHandler(this, &displayloanRecord::richTextBox1_TextChanged);
			// 
			// richTextBox2
			// 
			this->richTextBox2->Location = System::Drawing::Point(13, 17);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->ReadOnly = true;
			this->richTextBox2->Size = System::Drawing::Size(917, 47);
			this->richTextBox2->TabIndex = 1;
			this->richTextBox2->Text = L"";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(840, 373);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Exit";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &displayloanRecord::button1_Click);
			// 
			// displayloanRecord
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(942, 408);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->richTextBox2);
			this->Name = L"displayloanRecord";
			this->Text = L"displayloanRecord";
			this->Load += gcnew System::EventHandler(this, &displayloanRecord::displayloanRecord_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void richTextBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	//display all user loan record
	private: System::Void displayloanRecord_Load(System::Object^  sender, System::EventArgs^  e) {
		mysql loan;
		stringstream str;
		MYSQL_RES *res_set;
		MYSQL_ROW row;
		int num;
		
		loan.link();
		res_set = loan.select_query("*", "borrow","");
		num = mysql_num_fields(res_set);
		//cout << num << endl;
		richTextBox2->Text = "userID|	username|		code|	type|	equipment name|	borrow time|		return time|";
		while (row = mysql_fetch_row(res_set)) {
			for (int i = 0; i < num; i++) {
				str << row[i];
				str << " | ";
			}str << "\r\n";
		}	
		String^ str2 = gcnew String(str.str().c_str());
		richTextBox1->Text = str2;
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Hide();
		obj1->Show();
	}
};
}
