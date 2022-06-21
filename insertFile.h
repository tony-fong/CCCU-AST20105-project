#pragma once
#include"insertdata.h"
#include"mysql.h"
namespace GUIProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// insertFile 的摘要
	/// </summary>
	public ref class insertFile : public System::Windows::Forms::Form
	{
	public:
		Form ^obj1;
		insertFile(void)
		{
			InitializeComponent();
			//
			//TODO:  在此加入建構函式程式碼
			//
		}
		insertFile(Form ^f2)
		{
			obj1 = f2;
			InitializeComponent();
			
		}
	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~insertFile()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::ComboBox^  comboBox1;
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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(26, 85);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(249, 25);
			this->textBox1->TabIndex = 0;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &insertFile::textBox1_TextChanged);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(281, 85);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(93, 25);
			this->button1->TabIndex = 1;
			this->button1->Text = L"select file";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &insertFile::button1_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &insertFile::openFileDialog1_FileOk_1);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(299, 122);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 2;
			this->button2->Text = L"insert";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &insertFile::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(325, 151);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(49, 23);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Exit";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &insertFile::button3_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(26, 56);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 23);
			this->comboBox1->TabIndex = 4;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &insertFile::comboBox1_SelectedIndexChanged);
			// 
			// insertFile
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(386, 196);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Name = L"insertFile";
			this->Text = L"insertFile";
			this->Load += gcnew System::EventHandler(this, &insertFile::insertFile_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void fileSystemWatcher1_Changed(System::Object^  sender, System::IO::FileSystemEventArgs^  e) {
	}
	private: System::Void openFileDialog1_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
	}
	//select  txt file
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

		OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;
		//if (openFileDialog1.ShowDialog() == System.Windows.Forms.DialogResult.ok) {}
		openFileDialog1->ShowDialog();
		String ^name = openFileDialog1->FileName->ToString();
		textBox1->Text = name;
	
	}
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void insertFile_Load(System::Object^  sender, System::EventArgs^  e) {
		comboBox1->Items->Add("User");
		comboBox1->Items->Add("Equipment");
		
	}
	//imsert new data to database
	//when success it will diaplay how many data insert success
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	msclr::interop::marshal_context context;
	String ^ name = textBox1->Text;
	String ^ use;
	if (comboBox1->SelectedIndex != -1) {
		use = comboBox1->SelectedItem->ToString();
		string file = context.marshal_as<std::string>(name);
		std::string type = context.marshal_as<std::string>(use);
		if (type == "User") {
			int success = insertUserData(file);
			MessageBox::Show(success + "date import to user success");
		}
		else {
			int success = insertItemDate(file);
			MessageBox::Show(success + "date import to user success");
		}
	}else {
		MessageBox::Show("plase select data type!");
	}
	

}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Hide();
	obj1->Show();
}
private: System::Void openFileDialog1_FileOk_1(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
}
private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
}
};
}
