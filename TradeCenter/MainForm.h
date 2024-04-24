#pragma once

#include "NewForm.h"

namespace TradeCenter {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
		}
	protected:
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: String^ find = L"";
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::RadioButton^ radioButton1;
	private: System::Windows::Forms::RadioButton^ radioButton2;
	private: System::Windows::Forms::RadioButton^ radioButton3;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button1;

	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Label^ label2;
	private:
		System::ComponentModel::Container ^components;
		std::wstring netStringToCString(String^ str) {
			std::wstring temp = L"";
			for each (wchar_t c in str) { temp.push_back(c); }
			return temp;
		}
		String^ cStringToNetString(std::wstring str) {
			String^ temp = "";
			temp = gcnew String(str.c_str());
			return temp;
		}
#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(349, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(190, 22);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Список арендаторов";
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->EditMode = System::Windows::Forms::DataGridViewEditMode::EditProgrammatically;
			this->dataGridView1->Location = System::Drawing::Point(134, 37);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::CellSelect;
			this->dataGridView1->Size = System::Drawing::Size(719, 493);
			this->dataGridView1->TabIndex = 1;
			// 
			// radioButton1
			// 
			this->radioButton1->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->radioButton1->AutoSize = true;
			this->radioButton1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->radioButton1->Location = System::Drawing::Point(12, 258);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(107, 42);
			this->radioButton1->TabIndex = 2;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Все\r\nарендаторы";
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &MainForm::radioButton1_CheckedChanged);
			// 
			// radioButton2
			// 
			this->radioButton2->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->radioButton2->AutoSize = true;
			this->radioButton2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->radioButton2->Location = System::Drawing::Point(12, 306);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(111, 42);
			this->radioButton2->TabIndex = 3;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"Арендаторы\r\nпомещений";
			this->radioButton2->UseVisualStyleBackColor = true;
			this->radioButton2->CheckedChanged += gcnew System::EventHandler(this, &MainForm::radioButton1_CheckedChanged);
			// 
			// radioButton3
			// 
			this->radioButton3->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->radioButton3->AutoSize = true;
			this->radioButton3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->radioButton3->Location = System::Drawing::Point(12, 354);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(111, 42);
			this->radioButton3->TabIndex = 4;
			this->radioButton3->TabStop = true;
			this->radioButton3->Text = L"Арендаторы\r\nмест";
			this->radioButton3->UseVisualStyleBackColor = true;
			this->radioButton3->CheckedChanged += gcnew System::EventHandler(this, &MainForm::radioButton1_CheckedChanged);
			// 
			// textBox1
			// 
			this->textBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(11, 536);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(842, 26);
			this->textBox1->TabIndex = 6;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MainForm::textBox1_TextChanged);
			// 
			// button1
			// 
			this->button1->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->button1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(11, 117);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(101, 28);
			this->button1->TabIndex = 9;
			this->button1->Text = L"Добавить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
			// 
			// button3
			// 
			this->button3->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->button3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->Location = System::Drawing::Point(11, 151);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(101, 26);
			this->button3->TabIndex = 11;
			this->button3->Text = L"Удалить";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MainForm::button3_Click);
			// 
			// label2
			// 
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(12, 512);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(65, 21);
			this->label2->TabIndex = 12;
			this->label2->Text = L"Поиск:";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(874, 574);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->radioButton3);
			this->Controls->Add(this->radioButton2);
			this->Controls->Add(this->radioButton1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->label1);
			this->Name = L"MainForm";
			this->Text = L"Торговый Центр";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
		radioButton1->Checked = 1;
		radioButton1_CheckedChanged(dataGridView1, gcnew EventArgs());
		MainForm::Update();

	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		find = textBox1->Text;
		radioButton1_CheckedChanged(dataGridView1, gcnew EventArgs());
	}
	private: System::Void radioButton1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		dataGridView1->Rows->Clear();
		dataGridView1->Columns->Clear();
		DataGridViewColumn^ c = gcnew DataGridViewColumn();
		DataGridViewCell^ td = gcnew DataGridViewTextBoxCell();
		c->HeaderText = L"Наименование";
		c->Name = "Column" + (dataGridView1->ColumnCount + 1);
		c->CellTemplate = td;
		dataGridView1->Columns->Add(c);
		c = gcnew DataGridViewColumn();
		td = gcnew DataGridViewTextBoxCell();
		c->HeaderText = L"Контактное лицо";
		c->Name = "Column" + (dataGridView1->ColumnCount + 1);
		c->CellTemplate = td;
		dataGridView1->Columns->Add(c);
		c = gcnew DataGridViewColumn();
		td = gcnew DataGridViewTextBoxCell();
		c->HeaderText = L"Телефон";
		c->Name = "Column" + (dataGridView1->ColumnCount + 1);
		c->CellTemplate = td;
		dataGridView1->Columns->Add(c);
		c = gcnew DataGridViewColumn();
		td = gcnew DataGridViewTextBoxCell();
		c->HeaderText = L"Дата начала аренды";
		c->Name = "Column" + (dataGridView1->ColumnCount + 1);
		c->CellTemplate = td;
		dataGridView1->Columns->Add(c);
		c = gcnew DataGridViewColumn();
		td = gcnew DataGridViewTextBoxCell();
		c->HeaderText = L"Дата конца аренды";
		c->Name = "Column" + (dataGridView1->ColumnCount + 1);
		c->CellTemplate = td;
		dataGridView1->Columns->Add(c);
		c = gcnew DataGridViewColumn();
		td = gcnew DataGridViewTextBoxCell();
		c->HeaderText = L"Цена аренды";
		c->Name = "Column" + (dataGridView1->ColumnCount + 1);
		c->CellTemplate = td;
		dataGridView1->Columns->Add(c);
		c = gcnew DataGridViewColumn();
		td = gcnew DataGridViewTextBoxCell();
		c->HeaderText = L"Номер помещения";
		c->Name = "Column" + (dataGridView1->ColumnCount + 1);
		c->CellTemplate = td;
		dataGridView1->Columns->Add(c);
		c = gcnew DataGridViewColumn();
		td = gcnew DataGridViewTextBoxCell();
		c->HeaderText = L"Площадь";
		c->Name = "Column" + (dataGridView1->ColumnCount + 1);
		c->CellTemplate = td;
		dataGridView1->Columns->Add(c);
		std::vector<std::vector<std::wstring>> data;
		if (radioButton3->Checked) 
			getData(data, netStringToCString(find->ToString()), 1);
		else if (radioButton2->Checked) 
			getData(data, netStringToCString(find->ToString()), 2);
		else if (radioButton1->Checked) 
			getData(data, netStringToCString(find->ToString()), 0);
		for (int i = 0; i < data.size(); ++i) {
			DataGridViewRow^ r = gcnew DataGridViewRow();
			r->HeaderCell->Value = L"";
			r->CreateCells(dataGridView1);
			cli::array<String^>^ Values = gcnew cli::array<String^>(dataGridView1->ColumnCount);
			for (int j = 0; j < data[i].size(); ++j)
				Values[j] = cStringToNetString(data[i][j]);
			r->SetValues(Values);
			dataGridView1->Rows->Add(r);
			dataGridView1->RowHeadersWidth = 200;
		}
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		TradeCenter::NewForm newform;
		newform.ShowDialog();
		if (newform.name->Length != 0 && newform.contactName->Length != 0 && newform.contact->Length != 0 && newform.dateStart->Length != 0 && newform.dateEnd->Length != 0) {
			String^ name = newform.name;
			String^ contactName = newform.contactName;
			String^ contact = newform.contact;
			String^ dateStart = newform.dateStart;
			String^ dateEnd = newform.dateEnd;
			String^ price = newform.price;
			int^ type = newform.type;
			String^ placeNumber = newform.placeNumber;
			addRent((int) type, netStringToCString(name), netStringToCString(contactName), netStringToCString(contact), netStringToCString(dateStart), netStringToCString(dateEnd), stoi(netStringToCString(price)), stoi(netStringToCString(placeNumber)));
			radioButton1_CheckedChanged(dataGridView1, gcnew EventArgs());
			MainForm::Update();
		}
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		int tempid = dataGridView1->CurrentCell->RowIndex;
		if (tempid >= 0 && tempid < dataGridView1->RowCount) {
			System::Windows::Forms::DialogResult dialogRes = MessageBox::Show(this, L"Вы уверены, что хотите удалить аренду?", "Подтверждение", MessageBoxButtons::OKCancel, MessageBoxIcon::Question);
			if (System::Windows::Forms::DialogResult::OK == dialogRes) {
				deleteRent(netStringToCString(this->dataGridView1->Rows[tempid]->Cells[0]->Value->ToString()), netStringToCString(this->dataGridView1->Rows[tempid]->Cells[6]->Value->ToString()));
				radioButton1_CheckedChanged(dataGridView1, gcnew EventArgs());
				MainForm::Update();
			}
		}
	}
};
}
