#pragma once
#include "Functional.h"

namespace TradeCenter {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	public ref class NewForm : public System::Windows::Forms::Form
	{
	public:
		NewForm(void)
		{
			InitializeComponent();
			radioButton1->Checked = 1;
			for (int i = 0; i < getPlaces().size(); ++i) {
				(getPlaces()[i].occupated) ? NULL : this->comboBox1->Items->Add(getPlaces()[i].number + ". " + getPlaces()[i].square + L" м^2");
			}
			if (comboBox1->Items->Count > 0) {
				comboBox1->SelectedItem = comboBox1->Items[0];
			}
		}
	protected:
		~NewForm()
		{
			if (components)
			{
				delete components;
			}
		}
	public: String^ name = L"";
	public: String^ contactName = L"";
	public: String^ contact = L"";
	public: String^ dateStart = L"";
	public: String^ dateEnd = L"";
	public: String^ price = L"";
	public: int^ type = 0;
	public: String^ placeNumber = L"";
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::RadioButton^ radioButton1;
	private: System::Windows::Forms::RadioButton^ radioButton2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker1;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker2;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->dateTimePicker2 = (gcnew System::Windows::Forms::DateTimePicker());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(12, 15);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(126, 21);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Наименование";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(12, 50);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(147, 21);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Контактное лицо";
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(165, 47);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(296, 29);
			this->textBox1->TabIndex = 3;
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->radioButton1->Location = System::Drawing::Point(78, 274);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(121, 25);
			this->radioButton1->TabIndex = 4;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Помещение";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// radioButton2
			// 
			this->radioButton2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->radioButton2->AutoSize = true;
			this->radioButton2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->radioButton2->Location = System::Drawing::Point(284, 274);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(101, 25);
			this->radioButton2->TabIndex = 5;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"Площадь";
			this->radioButton2->UseVisualStyleBackColor = true;
			this->radioButton2->CheckedChanged += gcnew System::EventHandler(this, &NewForm::radioButton2_CheckedChanged);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(191, 327);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(103, 40);
			this->button1->TabIndex = 7;
			this->button1->Text = L"Добавить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &NewForm::button1_Click);
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox2->Location = System::Drawing::Point(165, 12);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(296, 29);
			this->textBox2->TabIndex = 8;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(12, 85);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(78, 21);
			this->label3->TabIndex = 9;
			this->label3->Text = L"Телефон";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(12, 124);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(104, 21);
			this->label4->TabIndex = 10;
			this->label4->Text = L"Дата начала";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(12, 159);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(137, 21);
			this->label5->TabIndex = 11;
			this->label5->Text = L"Дата окончания";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(12, 190);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(49, 21);
			this->label6->TabIndex = 12;
			this->label6->Text = L"Цена";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->Location = System::Drawing::Point(12, 228);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(61, 21);
			this->label7->TabIndex = 13;
			this->label7->Text = L"Место";
			// 
			// textBox3
			// 
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox3->Location = System::Drawing::Point(165, 82);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(296, 29);
			this->textBox3->TabIndex = 14;
			// 
			// textBox4
			// 
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox4->Location = System::Drawing::Point(165, 187);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(296, 29);
			this->textBox4->TabIndex = 15;
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->dateTimePicker1->Location = System::Drawing::Point(165, 117);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(200, 29);
			this->dateTimePicker1->TabIndex = 16;
			// 
			// dateTimePicker2
			// 
			this->dateTimePicker2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->dateTimePicker2->Location = System::Drawing::Point(165, 152);
			this->dateTimePicker2->Name = L"dateTimePicker2";
			this->dateTimePicker2->Size = System::Drawing::Size(200, 29);
			this->dateTimePicker2->TabIndex = 17;
			// 
			// comboBox1
			// 
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(165, 222);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(296, 32);
			this->comboBox1->TabIndex = 18;
			// 
			// NewForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->ClientSize = System::Drawing::Size(469, 379);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->dateTimePicker2);
			this->Controls->Add(this->dateTimePicker1);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->radioButton2);
			this->Controls->Add(this->radioButton1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"NewForm";
			this->Text = L"Добавить арендатора";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->textBox1->Text->Length == 0 || this->textBox2->Text->Length == 0 || this->textBox3->Text->Length == 0 || this->textBox4->Text->Length == 0) {
			MessageBox::Show("Заполните все поля");
			return;
		}
		else {
			this->name = this->textBox2->Text;
			this->contactName = this->textBox1->Text;
			this->contact = this->textBox3->Text;
			this->price = this->textBox4->Text;
			if (radioButton1->Checked) {
				if (comboBox1->SelectedIndex == -1) {
					MessageBox::Show("У арендатора должно быть помещение");
					return;
				}
				this->type = 2;
			}
			else
				this->type = 1;
			for (int i = 0; i < comboBox1->SelectedItem->ToString()->Length; ++i) {
				if (!comboBox1->SelectedItem->ToString()[i].Equals(L"."))
					placeNumber += comboBox1->SelectedItem->ToString()[i];
				else break;
			}
			this->dateStart = dateTimePicker1->Value.ToShortDateString()->ToString();
			this->dateEnd = dateTimePicker2->Value.ToShortDateString()->ToString();
			this->Close();
		}
	}
private: System::Void radioButton2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (radioButton2->Checked) {
		label7->Visible = false;
		comboBox1->Visible = false;
	}
	else {
		label7->Visible = true;
		comboBox1->Visible = true;
	}
}
};
}
