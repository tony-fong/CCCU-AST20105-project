#pragma once
#include"mysql.h"
#include"checkType.h"
namespace GUIProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// update 的摘要
	/// </summary>
	public ref class update : public System::Windows::Forms::Form
	{
	public:
		Form ^obj1;
		update(void)
		{
			InitializeComponent();
			//
			//TODO:  在此加入建構函式程式碼
			//
		}
		update(Form ^f2) {
			obj1 = f2;
			InitializeComponent();
		}
	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~update()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;


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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(141, 364);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 25);
			this->textBox1->TabIndex = 1;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(406, 364);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 25);
			this->textBox2->TabIndex = 2;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &update::textBox2_TextChanged);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(565, 363);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 3;
			this->button1->Text = L"update condition";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &update::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(655, 401);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(42, 24);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Exit";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &update::button2_Click);
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(12, 12);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->ReadOnly = true;
			this->richTextBox1->Size = System::Drawing::Size(703, 326);
			this->richTextBox1->TabIndex = 5;
			this->richTextBox1->Text = L"";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"新細明體", 10));
			this->label1->Location = System::Drawing::Point(12, 372);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(111, 17);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Equipment code";
			this->label1->Click += gcnew System::EventHandler(this, &update::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"新細明體", 10));
			this->label2->Location = System::Drawing::Point(303, 372);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(67, 17);
			this->label2->TabIndex = 7;
			this->label2->Text = L"condition";
			// 
			// update
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(727, 437);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Name = L"update";
			this->Text = L"update";
			this->Load += gcnew System::EventHandler(this, &update::update_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		mysql item;
		MYSQL_RES *res_set;
		MYSQL_ROW row;
		stringstream s;
		msclr::interop::marshal_context context;
		String ^Code = textBox1->Text;
		String ^Value = textBox2->Text;
		string code = context.marshal_as<std::string>(Code);
		string value = context.marshal_as<std::string>(Value);
		//MessageBox::Show(Value);
		cout << value;
		item.link();
		if (Value == "damaged" || value == "being" || value == "repaired" || value == "disposed") {
			string temp = "conditions = '" + value + "'";
			int check = item.update(checkType(code), temp, "code", code);
			if (check == 0) {
				MessageBox::Show("update successful");

				//update text
				MYSQL_RES *res_set;
				MYSQL_ROW row;
				stringstream s;
				mysql display;
				for (int i = 0; i < 3; i++) {
					string type[3] = { "tent", "stove", "lantern" };
					display.link();
					res_set = display.select_query("*", type[i], "");

					int num = mysql_num_fields(res_set);
					while (row = mysql_fetch_row(res_set)) {
						for (int i = 0; i < num; i++) {
							s << row[i];
							s << " | ";
						}s << "\r\n";
					}
					String^ str2 = gcnew String(s.str().c_str());
					richTextBox1->Text = str2;
				}
			}
		}else{
			MessageBox::Show("please input correct condition");
		}
	}
	private: System::Void richTextBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void update_Load(System::Object^  sender, System::EventArgs^  e) {
	MYSQL_RES *res_set;
	MYSQL_ROW row;
	stringstream s;
	mysql display;
	for (int i = 0; i < 3; i++) {
		string type[3] = { "tent", "stove", "lantern" };
		display.link();
		res_set = display.select_query("*", type[i], "");

		int num = mysql_num_fields(res_set);
		while (row = mysql_fetch_row(res_set)) {
			for (int i = 0; i < num; i++) {
				s << row[i];
				s << " | ";
			}s << "\r\n";
		}
		String^ str2 = gcnew String(s.str().c_str());
		richTextBox1->Text = str2;
	}

}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Hide();
	obj1->Show();
}
private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
}
};
}
