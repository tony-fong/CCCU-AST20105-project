#include <msclr\marshal_cppstd.h>
#include<iostream>
#include<cstdio>
#include<string>
#include<sstream>

#include"MyForm.h"
namespace GUIProject {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	/// <summary>
	/// GUI 的摘要
	/// </summary>
	public ref class GUI : public System::Windows::Forms::Form
	{
	public:
		GUI(void)
		{
			InitializeComponent();
			//
			//TODO:  在此加入建構函式程式碼
			//
		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~GUI()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::IO::FileSystemWatcher^  fileSystemWatcher1;


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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->fileSystemWatcher1 = (gcnew System::IO::FileSystemWatcher());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fileSystemWatcher1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"新細明體", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button1->Location = System::Drawing::Point(111, 188);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(87, 33);
			this->button1->TabIndex = 0;
			this->button1->Text = L"login";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &GUI::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"新細明體", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label1->Location = System::Drawing::Point(78, 94);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(109, 24);
			this->label1->TabIndex = 1;
			this->label1->Text = L"username :";
			this->label1->Click += gcnew System::EventHandler(this, &GUI::username_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(193, 94);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(194, 25);
			this->textBox1->TabIndex = 2;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &GUI::textBox1_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"新細明體", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label2->Location = System::Drawing::Point(78, 133);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(107, 24);
			this->label2->TabIndex = 3;
			this->label2->Text = L"password :";
			this->label2->Click += gcnew System::EventHandler(this, &GUI::password_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(194, 133);
			this->textBox2->Name = L"textBox2";
			this->textBox2->PasswordChar = '*';
			this->textBox2->Size = System::Drawing::Size(193, 25);
			this->textBox2->TabIndex = 4;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"新細明體", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label3->Location = System::Drawing::Point(115, 28);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(232, 33);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Scout Company";
			this->label3->Click += gcnew System::EventHandler(this, &GUI::scout_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"新細明體", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button2->Location = System::Drawing::Point(247, 188);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(124, 33);
			this->button2->TabIndex = 6;
			this->button2->Text = L"forget password";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &GUI::button2_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"新細明體", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button3->Location = System::Drawing::Point(406, 221);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 29);
			this->button3->TabIndex = 7;
			this->button3->Text = L"Exit";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &GUI::button3_Click);
			// 
			// fileSystemWatcher1
			// 
			this->fileSystemWatcher1->EnableRaisingEvents = true;
			this->fileSystemWatcher1->SynchronizingObject = this;
			this->fileSystemWatcher1->Changed += gcnew System::IO::FileSystemEventHandler(this, &GUI::fileSystemWatcher1_Changed);
			// 
			// GUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(502, 256);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Name = L"GUI";
			this->Text = L"GUI";
			this->Load += gcnew System::EventHandler(this, &GUI::GUI_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fileSystemWatcher1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	// when user star up the program , it will check database have or not create database "borrow system"
	private: System::Void GUI_Load(System::Object^  sender, System::EventArgs^  e) {
		//MessageBox::Show("DataBase building");
		if (createDB()) {
			MessageBox::Show("DataBase build up successful");
			creatTable();
			insertuserData();
			insertitemDate();
		}

	}
	//check username and password
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
	{
		msclr::interop::marshal_context context;
		String ^ use = textBox1->Text;
		String ^ pass = textBox2->Text;
		String ID = Context.marshal_as<std::string>(use);
		String PW = Context.marshal_as<std::string>(pass);
		//admin login 
		if (ID == "admin" && PW == "admin") {
			this->Hide();
			adminMenu ^f2 = gcnew adminMenu(this);
			f2->ShowDialog();
		}
		else {
			//user login
			bool success = login(ID, PW);
			if (success) {
				MessageBox::Show("login success!");
				textBox1->Text = "";
				textBox2->Text = "";
				this->Hide();
				MenuForm^ f2 = gcnew MenuForm(this);
				f2->ShowDialog();
			}
			else {
				MessageBox::Show("login fail");

			}
		}
	}
	private: System::Void username_Click(System::Object^  sender, System::EventArgs^  e) {

	}
	private: System::Void password_Click(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void scout_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}

private: System::Void textBox3_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	Application::Exit();
}
private: System::Void fileSystemWatcher1_Changed(System::Object^  sender, System::IO::FileSystemEventArgs^  e) {
}
};
}
