#pragma once
#include<fstream>
#include"mysql.h"
namespace GUIProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// configForm 的摘要
	/// </summary>
	public ref class configForm : public System::Windows::Forms::Form
	{
	public:
		Form ^ obj1;
		configForm(void)
		{
			InitializeComponent();
			//
			//TODO:  在此加入建構函式程式碼
			//
		}
		configForm(Form ^f2)
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
		~configForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected:
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;

	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox4;

	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::Button^  button2;
	private: System::ComponentModel::IContainer^  components;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(59, 68);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(44, 15);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Server";
			this->label1->Click += gcnew System::EventHandler(this, &configForm::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(73, 99);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(30, 15);
			this->label2->TabIndex = 1;
			this->label2->Text = L"user";
			this->label2->Click += gcnew System::EventHandler(this, &configForm::label2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(44, 130);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(59, 15);
			this->label3->TabIndex = 2;
			this->label3->Text = L"password";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(44, 161);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(59, 15);
			this->label5->TabIndex = 4;
			this->label5->Text = L"DataBase";
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(61, 4);
			this->contextMenuStrip1->Text = L"configForm";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(109, 65);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 25);
			this->textBox1->TabIndex = 6;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(109, 96);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 25);
			this->textBox2->TabIndex = 7;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(109, 127);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 25);
			this->textBox3->TabIndex = 8;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(109, 158);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(100, 25);
			this->textBox4->TabIndex = 9;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"新細明體", 10));
			this->button1->Location = System::Drawing::Point(85, 225);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(70, 25);
			this->button1->TabIndex = 11;
			this->button1->Text = L"update";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &configForm::button1_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(73, 197);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(30, 15);
			this->label4->TabIndex = 12;
			this->label4->Text = L"port";
			this->label4->Click += gcnew System::EventHandler(this, &configForm::label4_Click);
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(109, 189);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(100, 25);
			this->textBox5->TabIndex = 13;
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"新細明體", 10));
			this->button2->Location = System::Drawing::Point(172, 225);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(62, 27);
			this->button2->TabIndex = 14;
			this->button2->Text = L"Exit";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &configForm::button2_Click);
			// 
			// configForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(281, 278);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"configForm";
			this->Text = L"t";
			this->Load += gcnew System::EventHandler(this, &configForm::configForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
	
}
private: System::Void configForm_Load(System::Object^  sender, System::EventArgs^  e) {
	string line;
	string local;
	string user;
	string pw;
	string db;
	string Sport;

	ifstream file;
	file.open("config.txt");
	if (file) {
		msclr::interop::marshal_context context;
		getline(file, line);
		istringstream iss(line);
		getline(iss, local, '|');
		getline(iss, user, '|');
		getline(iss, pw, '|');
		getline(iss, db, '|');
		getline(iss, Sport, '|');

		String^ Server = gcnew String(local.c_str());
		String^ User = gcnew String(user.c_str());
		String^ PW = gcnew String(pw.c_str());
		String^ DB = gcnew String(db.c_str());
		String^ Port = gcnew String(Sport.c_str());

		textBox1->Text = Server;
		textBox2->Text = User;
		textBox3->Text = PW;
		textBox4->Text = DB;
		textBox5->Text = Port;
	}
}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	msclr::interop::marshal_context context;
	String ^ Server = textBox1->Text;
	String ^ User = textBox2->Text;
	String ^ Password = textBox3->Text;
	String ^ DataBase = textBox4->Text;
	String ^ Port = textBox5->Text;

	string server = context.marshal_as<string>(Server);
	string user = context.marshal_as<string>(User);
	string password = context.marshal_as<string>(Password);
	string database = context.marshal_as<string>(DataBase);
	string port = context.marshal_as<string>(Port);

	string temp = server + "|" + user + "|" + password + "|" + database + "|" + port + "|";

	ofstream write;
	write.open("config.txt");
	write << temp; 
	MessageBox::Show("update success");

}
private: System::Void label4_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Hide();
	obj1->Show();
}
};
}
