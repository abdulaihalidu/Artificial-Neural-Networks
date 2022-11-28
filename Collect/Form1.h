#pragma once
#include "Process.h"
#include <iostream>
#include <fstream>
#include <string>

namespace CppCLRWinformsProjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace std;

	/// <summary>
	/// Zusammenfassung für Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzufügen.
			//
			Initialize();
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	protected:
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ComboBox^ ClassCountBox;

	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ComboBox^ ClassNoBox;

	private: System::Windows::Forms::Label^ label3;

	private:
		/// <summary>
		/// User Defined Variables
		int  numClass = 0, numSample = 0, inputDim = 2;
		float *Samples, *targets, *Weights, *bias;
		cli::array<Color>^ color;
		double mean_x;
		double mean_y;
		double std_x;
		double std_y;
	private: System::Windows::Forms::ToolStripMenuItem^ testToolStripMenuItem;
		   float* tempsamples;   // array to hold normalized data

		// member function to make initialization for testing
		void Initialize() {
			color = gcnew cli::array<Color>(10);
			color[0] = Color::Black; color[1] = Color::Red; color[2] = Color::Blue; color[3] = Color::Green; color[4] = Color::Yellow;
			color[5] = Color::Cyan; color[6] = Color::Indigo; color[7] = Color::Purple; color[8] = Color::Firebrick; color[9] = Color::OrangeRed;

			Test_Sample_Size = 4;
			Test_Output = new int[((pictureBox1->Width / Test_Sample_Size) + 1) * ((pictureBox1->Height / Test_Sample_Size) + 1)];

		}

	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ readDataToolStripMenuItem;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::ToolStripMenuItem^ saveDataToolStripMenuItem;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;
	private: System::Windows::Forms::ToolStripMenuItem^ processToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ singleLayerNeuralNetworkToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ perceptronToolStripMenuItem;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	private: System::Windows::Forms::ToolStripMenuItem^ deltaToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ multiCategoryPerceptronToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ multiCategoryDeltaToolStripMenuItem;
	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::ComboBox^ MaxCycle;



	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::ComboBox^ comboBoxMaxError;

	private: System::Windows::Forms::Button^ button2;




		   /// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->ClassCountBox = (gcnew System::Windows::Forms::ComboBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->ClassNoBox = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->readDataToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveDataToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->processToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->singleLayerNeuralNetworkToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->perceptronToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->deltaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->multiCategoryPerceptronToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->multiCategoryDeltaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->testToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->MaxCycle = (gcnew System::Windows::Forms::ComboBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->comboBoxMaxError = (gcnew System::Windows::Forms::ComboBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->groupBox3->SuspendLayout();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->pictureBox1->Location = System::Drawing::Point(17, 100);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(8, 7, 8, 7);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(2139, 1306);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::pictureBox1_Paint);
			this->pictureBox1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox1_MouseClick);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->ClassCountBox);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->groupBox1->Location = System::Drawing::Point(2317, 119);
			this->groupBox1->Margin = System::Windows::Forms::Padding(8, 7, 8, 7);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(8, 7, 8, 7);
			this->groupBox1->Size = System::Drawing::Size(533, 238);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Network Architecture";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(27, 145);
			this->button1->Margin = System::Windows::Forms::Padding(8, 7, 8, 7);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(349, 79);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Network Setting";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(288, 55);
			this->label1->Margin = System::Windows::Forms::Padding(8, 0, 8, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(194, 32);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Num of Class";
			// 
			// ClassCountBox
			// 
			this->ClassCountBox->FormattingEnabled = true;
			this->ClassCountBox->Items->AddRange(gcnew cli::array< System::Object^  >(6) { L"2", L"3", L"4", L"5", L"6", L"7" });
			this->ClassCountBox->Location = System::Drawing::Point(27, 48);
			this->ClassCountBox->Margin = System::Windows::Forms::Padding(8, 7, 8, 7);
			this->ClassCountBox->Name = L"ClassCountBox";
			this->ClassCountBox->Size = System::Drawing::Size(212, 39);
			this->ClassCountBox->TabIndex = 0;
			this->ClassCountBox->Text = L"2";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->label2);
			this->groupBox2->Controls->Add(this->ClassNoBox);
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->groupBox2->Location = System::Drawing::Point(2344, 455);
			this->groupBox2->Margin = System::Windows::Forms::Padding(8, 7, 8, 7);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Padding = System::Windows::Forms::Padding(8, 7, 8, 7);
			this->groupBox2->Size = System::Drawing::Size(507, 145);
			this->groupBox2->TabIndex = 2;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Data Collection";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(261, 55);
			this->label2->Margin = System::Windows::Forms::Padding(8, 0, 8, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(102, 32);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Target";
			// 
			// ClassNoBox
			// 
			this->ClassNoBox->FormattingEnabled = true;
			this->ClassNoBox->Items->AddRange(gcnew cli::array< System::Object^  >(9) {
				L"1", L"2", L"3", L"4", L"5", L"6", L"7", L"8",
					L"9"
			});
			this->ClassNoBox->Location = System::Drawing::Point(0, 48);
			this->ClassNoBox->Margin = System::Windows::Forms::Padding(8, 7, 8, 7);
			this->ClassNoBox->Name = L"ClassNoBox";
			this->ClassNoBox->Size = System::Drawing::Size(193, 39);
			this->ClassNoBox->TabIndex = 0;
			this->ClassNoBox->Text = L"1";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(2339, 582);
			this->label3->Margin = System::Windows::Forms::Padding(8, 0, 8, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(92, 32);
			this->label3->TabIndex = 3;
			this->label3->Text = L"label3";
			// 
			// menuStrip1
			// 
			this->menuStrip1->GripMargin = System::Windows::Forms::Padding(2, 2, 0, 2);
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(40, 40);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->fileToolStripMenuItem,
					this->processToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(16, 5, 0, 5);
			this->menuStrip1->Size = System::Drawing::Size(3844, 55);
			this->menuStrip1->TabIndex = 4;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->readDataToolStripMenuItem,
					this->saveDataToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(87, 45);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// readDataToolStripMenuItem
			// 
			this->readDataToolStripMenuItem->Name = L"readDataToolStripMenuItem";
			this->readDataToolStripMenuItem->Size = System::Drawing::Size(323, 54);
			this->readDataToolStripMenuItem->Text = L"Read_Data";
			this->readDataToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::readDataToolStripMenuItem_Click);
			// 
			// saveDataToolStripMenuItem
			// 
			this->saveDataToolStripMenuItem->Name = L"saveDataToolStripMenuItem";
			this->saveDataToolStripMenuItem->Size = System::Drawing::Size(323, 54);
			this->saveDataToolStripMenuItem->Text = L"Save_Data";
			this->saveDataToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::saveDataToolStripMenuItem_Click);
			// 
			// processToolStripMenuItem
			// 
			this->processToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->singleLayerNeuralNetworkToolStripMenuItem,
					this->testToolStripMenuItem
			});
			this->processToolStripMenuItem->Name = L"processToolStripMenuItem";
			this->processToolStripMenuItem->Size = System::Drawing::Size(143, 45);
			this->processToolStripMenuItem->Text = L"Process";
			// 
			// singleLayerNeuralNetworkToolStripMenuItem
			// 
			this->singleLayerNeuralNetworkToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->perceptronToolStripMenuItem,
					this->deltaToolStripMenuItem, this->multiCategoryPerceptronToolStripMenuItem, this->multiCategoryDeltaToolStripMenuItem
			});
			this->singleLayerNeuralNetworkToolStripMenuItem->Name = L"singleLayerNeuralNetworkToolStripMenuItem";
			this->singleLayerNeuralNetworkToolStripMenuItem->Size = System::Drawing::Size(559, 54);
			this->singleLayerNeuralNetworkToolStripMenuItem->Text = L"Single Layer Neural Network";
			// 
			// perceptronToolStripMenuItem
			// 
			this->perceptronToolStripMenuItem->Name = L"perceptronToolStripMenuItem";
			this->perceptronToolStripMenuItem->Size = System::Drawing::Size(534, 54);
			this->perceptronToolStripMenuItem->Text = L"Perceptron";
			this->perceptronToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::perceptronToolStripMenuItem_Click);
			// 
			// deltaToolStripMenuItem
			// 
			this->deltaToolStripMenuItem->Name = L"deltaToolStripMenuItem";
			this->deltaToolStripMenuItem->Size = System::Drawing::Size(534, 54);
			this->deltaToolStripMenuItem->Text = L"Delta";
			this->deltaToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::deltaToolStripMenuItem_Click);
			// 
			// multiCategoryPerceptronToolStripMenuItem
			// 
			this->multiCategoryPerceptronToolStripMenuItem->Name = L"multiCategoryPerceptronToolStripMenuItem";
			this->multiCategoryPerceptronToolStripMenuItem->Size = System::Drawing::Size(534, 54);
			this->multiCategoryPerceptronToolStripMenuItem->Text = L"Multi Category Perceptron";
			this->multiCategoryPerceptronToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::multiCategoryPerceptronToolStripMenuItem_Click);
			// 
			// multiCategoryDeltaToolStripMenuItem
			// 
			this->multiCategoryDeltaToolStripMenuItem->Name = L"multiCategoryDeltaToolStripMenuItem";
			this->multiCategoryDeltaToolStripMenuItem->Size = System::Drawing::Size(534, 54);
			this->multiCategoryDeltaToolStripMenuItem->Text = L"Multi Category Delta";
			this->multiCategoryDeltaToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::multiCategoryDeltaToolStripMenuItem_Click);
			// 
			// testToolStripMenuItem
			// 
			this->testToolStripMenuItem->Name = L"testToolStripMenuItem";
			this->testToolStripMenuItem->Size = System::Drawing::Size(559, 54);
			this->testToolStripMenuItem->Text = L"Test";
			this->testToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::testToolStripMenuItem_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(2344, 622);
			this->textBox1->Margin = System::Windows::Forms::Padding(8, 7, 8, 7);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(607, 71);
			this->textBox1->TabIndex = 5;
			// 
			// chart1
			// 
			chartArea2->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea2);
			legend2->Name = L"Legend1";
			this->chart1->Legends->Add(legend2);
			this->chart1->Location = System::Drawing::Point(2344, 723);
			this->chart1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->chart1->Name = L"chart1";
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series2->Color = System::Drawing::Color::Red;
			series2->Legend = L"Legend1";
			series2->Name = L"Error";
			this->chart1->Series->Add(series2);
			this->chart1->Size = System::Drawing::Size(909, 589);
			this->chart1->TabIndex = 6;
			this->chart1->Text = L"chart1";
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->label5);
			this->groupBox3->Controls->Add(this->MaxCycle);
			this->groupBox3->Controls->Add(this->label4);
			this->groupBox3->Controls->Add(this->comboBoxMaxError);
			this->groupBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->groupBox3->Location = System::Drawing::Point(3084, 119);
			this->groupBox3->Margin = System::Windows::Forms::Padding(8, 7, 8, 7);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Padding = System::Windows::Forms::Padding(8, 7, 8, 7);
			this->groupBox3->Size = System::Drawing::Size(533, 238);
			this->groupBox3->TabIndex = 7;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Network Config";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(288, 173);
			this->label5->Margin = System::Windows::Forms::Padding(8, 0, 8, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(154, 32);
			this->label5->TabIndex = 3;
			this->label5->Text = L"Max Cycle";
			// 
			// MaxCycle
			// 
			this->MaxCycle->FormattingEnabled = true;
			this->MaxCycle->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"100", L"500", L"1000", L"2500", L"5000" });
			this->MaxCycle->Location = System::Drawing::Point(27, 166);
			this->MaxCycle->Margin = System::Windows::Forms::Padding(8, 7, 8, 7);
			this->MaxCycle->Name = L"MaxCycle";
			this->MaxCycle->Size = System::Drawing::Size(212, 39);
			this->MaxCycle->TabIndex = 1;
			this->MaxCycle->Text = L"3000";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(288, 55);
			this->label4->Margin = System::Windows::Forms::Padding(8, 0, 8, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(163, 32);
			this->label4->TabIndex = 1;
			this->label4->Text = L"1/MaxError";
			// 
			// comboBoxMaxError
			// 
			this->comboBoxMaxError->FormattingEnabled = true;
			this->comboBoxMaxError->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"10", L"50", L"100", L"500", L"1000" });
			this->comboBoxMaxError->Location = System::Drawing::Point(27, 48);
			this->comboBoxMaxError->Margin = System::Windows::Forms::Padding(8, 7, 8, 7);
			this->comboBoxMaxError->Name = L"comboBoxMaxError";
			this->comboBoxMaxError->Size = System::Drawing::Size(212, 39);
			this->comboBoxMaxError->TabIndex = 0;
			this->comboBoxMaxError->Text = L"100";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(3084, 367);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(284, 88);
			this->button2->TabIndex = 8;
			this->button2->Text = L"Reset Network";
			this->button2->UseMnemonic = false;
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(16, 31);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(3844, 1711);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(8, 7, 8, 7);
			this->Name = L"Form1";
			this->Text = L"Form1";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		void LineCiz(float* w, float* bias, int NumberOfClass, float Carpan) {
			int x1, x2, y1, y2;
			Pen^ pen;
			float ww[2]; //inputDim=2
			//Line cizim için x1,y1, x2,y2 noktalarýn hesaplanmasý
			if (NumberOfClass == 2)
				NumberOfClass = 1;
			for (int i = 0; i < NumberOfClass; i++) {
				switch (i) {
				case 0: pen = gcnew Pen(Color::Black, 3.0f); break;
				case 1: pen = gcnew Pen(Color::Red, 3.0f); break;
				case 2: pen = gcnew Pen(Color::Blue, 3.0f); break;
				case 3: pen = gcnew Pen(Color::Green, 3.0f); break;
				case 4: pen = gcnew Pen(Color::Yellow, 3.0f); break;
				case 5: pen = gcnew Pen(Color::Orange, 3.0f); break;
				default: pen = gcnew Pen(Color::YellowGreen, 3.0f);
				}//switch
				ww[0] = w[i * 2 + 0];
				ww[1] = w[i * 2 + 1];
				x1 = -pictureBox1->Width / 2;     y1 = YPoint(x1, ww, bias[i], Carpan);
				x1 += pictureBox1->Width / 2;     y1 = pictureBox1->Height / 2 - y1;
				x2 = pictureBox1->Width / 2;      y2 = YPoint(x2, ww, bias[i], Carpan);
				x2 += pictureBox1->Width / 2;   y2 = pictureBox1->Height / 2 - y2;

				pictureBox1->CreateGraphics()->DrawLine(pen, x1, y1, x2, y2);
			}//for(int i=0...
		}//LineCÝz
		void draw_sample(int temp_x, int temp_y, int label) {
			Pen^ pen;// = gcnew Pen(Color::Black, 3.0f);
			switch (label) {
			case 0: pen = gcnew Pen(Color::Black, 3.0f); break;
			case 1: pen = gcnew Pen(Color::Red, 3.0f); break;
			case 2: pen = gcnew Pen(Color::Blue, 3.0f); break;
			case 3: pen = gcnew Pen(Color::Green, 3.0f); break;
			case 4: pen = gcnew Pen(Color::Yellow, 3.0f); break;
			case 5: pen = gcnew Pen(Color::Orange, 3.0f); break;
			default: pen = gcnew Pen(Color::YellowGreen, 3.0f);
			}//switch
			pictureBox1->CreateGraphics()->DrawLine(pen, temp_x - 5, temp_y, temp_x + 5, temp_y);
			pictureBox1->CreateGraphics()->DrawLine(pen, temp_x, temp_y - 5, temp_x, temp_y + 5);
		}//draw_sample
        #pragma endregion
	    private: System::Void pictureBox1_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
			if( numClass == 0)
				MessageBox::Show("The Network Architeture should be firtly set up");
			else {
				float* x;
				x = new float[inputDim];
				int temp_x = (System::Convert::ToInt32(e->X));
				int temp_y = (System::Convert::ToInt32(e->Y));

				x[0] = float(temp_x - (pictureBox1->Width / 2));
				x[1] = float(pictureBox1->Height / 2 - temp_y);
				int label;
				int numLabel = Convert::ToInt32(ClassNoBox->Text);
				if (numLabel > numClass)
					MessageBox::Show("The class label cannot be greater than the maximum number of classes.");
				else {
					label = numLabel - 1; //Dögüler 0 dan baþladýðýndan, bir eksiði alýnmýþtýr
					if (numSample == 0) { //Dinamik alýnan ilk örnek için sadece
						numSample = 1;  
						Samples = new float[numSample * inputDim]; targets = new float[numSample];
						for (int i = 0; i < inputDim; i++)
							Samples[i] = x[i];
						targets[0] = float(label);
					}
					else {
						numSample++;
						Samples = Add_Data(Samples, numSample, x, inputDim);
						targets = Add_Labels(targets, numSample, label);

					}//else
					draw_sample(temp_x, temp_y, label);
					label3->Text = "Samples Count: " + System::Convert::ToString(numSample);
				}//else of if (Etiket ...
			}//else
	    }//pictureMouseClick

		int Test_Sample_Size, *Test_Output; bool test_state;
        private: System::Void pictureBox1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
			//Ana eksen doðrularini cizdir
			Pen^ pen = gcnew Pen(Color::Black, 3.0f);
			int center_width, center_height;
			center_width = (int)(pictureBox1->Width / 2);
			center_height = (int)(pictureBox1->Height / 2);
			e->Graphics->DrawLine(pen, center_width, 0, center_width, pictureBox1->Height);
			e->Graphics->DrawLine(pen, 0, center_height, pictureBox1->Width, center_height);

			// paint the picture box according to the class of each sample
			if (test_state) {
				int i = 0;
				for (int x = 0; x < pictureBox1->Width; x += Test_Sample_Size) {
					for (int y = 0; y < pictureBox1->Height; y += Test_Sample_Size) {
						int index = Test_Output[i];
						SolidBrush^ brush = gcnew SolidBrush(Color::FromArgb(65, color[index].R, color[index].G, color[index].B));
						e->Graphics->FillRectangle(brush, x, y, Test_Sample_Size, Test_Sample_Size);
						i++;
					}
				}
				test_state = false;
			}
        }
        private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
			// Network is constructed
			numClass = Convert::ToInt32(ClassCountBox->Text);
			Weights = new float[numClass * inputDim];
			bias = new float[numClass];
			//initialize weights for single layer
			if (numClass > 2) {
				Weights = init_array_random(numClass * inputDim);
				bias = init_array_random(numClass);
				LineCiz(Weights, bias, numClass, 1.0);
			}
			else {
				int numOutNeuron = 1;
				Weights = init_array_random(inputDim);
				bias = init_array_random(numOutNeuron);
				LineCiz(Weights, bias, numClass, 1.0);
			}
			button1->Text = " Network is Ready : ";
        }
        private: System::Void readDataToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
			char** c = new char *[2];
			// Veri Kümesini okunacak 
			MessageBox::Show("Veri Kümesini Yükleyin");
			c[0] = "../Data/Samples.txt";
			c[1] = "../Data/weights.txt";
			ifstream file;
			int num, w, h, Dim, label;
			file.open(c[0]); 
			if (file.is_open()) {
				//MessageBox::Show("Dosya acildi");
				file >> Dim>> w >> h >>num;
				textBox1->Text += "Dimension: "+Convert::ToString(Dim) + " w: "+Convert::ToString(w)+" h:"+ Convert::ToString(h)+ " numClass: "+ Convert::ToString(num) +"\r\n";
				// Set network values
				numClass = num;
				inputDim = Dim;
				Weights = new float[numClass * inputDim];
				bias = new float[numClass];
				numSample = 0;
				float* x = new float[inputDim];
				while (!file.eof())
				{
					if (numSample == 0) { //ilk örnek için sadece
						numSample = 1;
						Samples = new float[inputDim]; targets = new float[numSample];
						for (int i = 0; i < inputDim; i++)
							   file>>Samples[i];
						file >> targets[0];
					}
					else {
						
						for (int i = 0; i < inputDim; i++)
							file >> x[i];
						file >> label;
						if (!file.eof()) {
							numSample++;
							Samples = Add_Data(Samples, numSample, x, inputDim);
							targets = Add_Labels(targets, numSample, label);
						}
					}//else
				} //while
				delete[]x;
				file.close();
				for (int i = 0; i < numSample; i++) {
					draw_sample(int(Samples[i*inputDim])+w, h-int(Samples[i*inputDim+1]), int(targets[i]));
					for (int j = 0; j < inputDim; j++)
						textBox1->Text += Convert::ToString(Samples[i * inputDim + j]) + " ";
					textBox1->Text += Convert::ToString(targets[i]) + "\r\n";
				}
				//draw_sample(temp_x, temp_y, label);
				label3->Text = "Samples Count: " + System::Convert::ToString(numSample);
				MessageBox::Show("Dosya basari ile okundu");
			}//file.is_open
			else MessageBox::Show("Dosya acilamadi");
			//Get weights
			int Layer;
			file.open(c[1]);
			if (file.is_open()) {
				file >> Layer >> Dim >> num;
				numClass = num;
				inputDim = Dim;
				Weights = new float[numClass * inputDim];
				bias = new float[numClass];
				textBox1->Text += "Layer: " + Convert::ToString(Layer) + " Dimension: " + Convert::ToString(Dim) + " numClass:" + Convert::ToString(num) + "\r\n";
				while (!file.eof())
				{
					for (int i = 0; i < numClass; i++)
						for (int j = 0; j < inputDim; j++)
							file >> Weights[i * inputDim + j];
					for (int i = 0; i < numClass; i++)
						file >> bias[i];
				}
				file.close();
				LineCiz(Weights, bias, numClass, 1.0);
			}//file.is_open
			delete[]c;
        }//Read_Data
        private: System::Void saveDataToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
			if (numSample != 0) {
				char** c = new char* [2];
				// Veri Kümesi yazýlacak
				c[0] = "../Data/Samples.txt";
				c[1] = "../Data/weights.txt";
				ofstream ofs(c[0]);
				if (!ofs.bad()) {
					// Width,  Height, number of Class, data+label
					ofs <<inputDim<<" "<< pictureBox1->Width / 2 << " " << pictureBox1->Height / 2 <<" "<<numClass<< endl;
					for (int i = 0; i < numSample; i++) {
						for (int d = 0; d < inputDim; d++)
							ofs << Samples[i*inputDim+d] << " ";
						ofs << targets[i] << endl;
					}
					ofs.close();
				}
				else MessageBox::Show("Samples icin dosya acilamadi");
				ofstream file(c[1]);
				if (!file.bad()) {
					// #Layer Dimension numClass weights biases
					file << 1 <<" "<<inputDim << " " << numClass << endl;
					for (int k = 0; k < numClass*inputDim; k++) 
							file << Weights[k] << " ";
					file << endl;
					for (int k = 0; k < numClass; k++)
						file << bias[k] << " ";
					file.close();
				}
				else MessageBox::Show("Weight icin dosya acilamadi");
				delete[]c;	
			}
			else MessageBox::Show("At least one sample should be given");
        }//Save_Data
	private: System::Void perceptronToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		
		int step = 0; // number of iterations
		//float c = 1.0f;
		float totalErr ;

		// clear chart
		chart1->Series["Error"]->Points->Clear();

		do {
			step++;
			totalErr = perceptronTraining(Samples, Weights, targets, bias, numSample, inputDim);
			textBox1->Text = "Cycles: " + step + "     Total Error: " + totalErr;
			
			pictureBox1->Refresh();
			chart1->Series["Error"]->Points->AddXY(step, totalErr);
			// redraw samples
			for (int i = 0; i < numSample; i++) {
				draw_sample(Samples[i * inputDim + 0] + pictureBox1->Width / 2, -Samples[i * inputDim + 1] + pictureBox1->Height / 2, targets[i]);
			}
			LineCiz(Weights, bias, numClass, 1.0);
		}while(totalErr > 0 && step < 5000);
		
		} 

private: System::Void deltaToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	int step = 0; // number of iterations
	//float c = 1.0f;
	float totalErr;
	float* tempSamples = new float[numSample * inputDim];
	tempSamples = normalizeData(Samples, numSample, inputDim, mean_x, mean_y, std_x, std_y);

	// clear chart
	chart1->Series["Error"]->Points->Clear(); 

	do {
		step++;
		totalErr = deltaTraining(tempSamples, Weights, targets, bias, numSample, inputDim);

		pictureBox1->Refresh();
		chart1->Series["Error"]->Points->AddXY(step, totalErr);
		// redraw samples
		for (int i = 0; i < numSample; i++) {
			draw_sample(tempSamples[i * inputDim + 0] + pictureBox1->Width / 2, -tempSamples[i * inputDim + 1] + pictureBox1->Height / 2, targets[i]);
		}
		LineCiz(Weights, bias, numClass, 1.0);
	} while (totalErr > 0.01 && step < 5000);
	textBox1->Text = "Cycles: " + step + "     Total Error: " + totalErr;
}
private: System::Void multiCategoryPerceptronToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	int step = 0; // number of iterations
	//float c = 1.0f;
	float totalErr;
	float* tempSamples = new float[numSample * inputDim];
	//tempSamples = normalizeData(Samples, numSample, inputDim);

	// clear chart
	chart1->Series["Error"]->Points->Clear();

	do {
		step++;
		totalErr = multiPerceptronTraining(Samples, Weights, targets, bias, numSample, inputDim, numClass);
		textBox1->Text = "Cycles: " + step + "     Total Error: " + totalErr;

		pictureBox1->Refresh();
		chart1->Series["Error"]->Points->AddXY(step, totalErr);
		// redraw samples
		for (int i = 0; i < numSample; i++) {
			draw_sample(Samples[i * inputDim + 0] + pictureBox1->Width / 2, -Samples[i * inputDim + 1] + pictureBox1->Height / 2, targets[i]);
		}
		LineCiz(Weights, bias, numClass, 1.0);
	} while (totalErr > 0 && step < 5000);

}
private: System::Void multiCategoryDeltaToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	int step = 0; // number of iterations
	float maxErr = 1.0 /(Convert::ToInt32(comboBoxMaxError->Text)); // Allowed max error
	int maxCycle = Convert::ToInt32(MaxCycle->Text);   // maximum cycle
	float totalErr;
	float* tempSamples = new float[numSample * inputDim];
	tempSamples = normalizeData(Samples, numSample, inputDim, mean_x, mean_y, std_x, std_y);

	// clear chart
	chart1->Series["Error"]->Points->Clear();

	do {
		step++;
		totalErr = multiDeltaTraining(tempSamples, Weights, targets, bias, numSample, inputDim, numClass);

		pictureBox1->Refresh();
		chart1->Series["Error"]->Points->AddXY(step, totalErr);
		// redraw samples
		for (int i = 0; i < numSample; i++) {
			draw_sample(tempSamples[i * inputDim + 0] + pictureBox1->Width / 2, -tempSamples[i * inputDim + 1] + pictureBox1->Height / 2, targets[i]);
		}
		
		LineCiz(Weights, bias, numClass, 1.0);
	} while (totalErr > maxErr && step < maxCycle);
	textBox1->Text = "Cycles: " + step + "     Total Error: " + totalErr;
	
	pictureBox1->Refresh();
	for (int i = 0; i < numSample; i++) {
		draw_sample(tempSamples[i * inputDim + 0] * 100 + pictureBox1->Width / 2, -tempSamples[i * inputDim + 1] * 100 + pictureBox1->Height / 2, targets[i]);
	}
	for (int b = 0; b < numClass; b++) {
		bias[b] = bias[b] * 100;
	}
	LineCiz(Weights, bias, numClass, 1.0);
}

private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	if (Weights)
		delete[] Weights;
	if (Samples)
		delete[] Samples;
	if (targets)
		delete[] targets;
	if (bias)
		delete[] bias;
	if (tempsamples)
		delete[] tempsamples;

	numClass = 0;
	numSample = 0;
	mean_x = 0;
	mean_y = 0;
	std_x = 0;
	std_y = 0;
	pictureBox1->Refresh();
	chart1->Series["Error"]->Points->Clear();
	textBox1->Text = "";
}
private: System::Void testToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	test_state = true;
	int i = 0;
	for (int x = 0; x < pictureBox1->Width; x += Test_Sample_Size) {
		for (int y = 0; y < pictureBox1->Height; y += Test_Sample_Size) {
			double test_x = x + (Test_Sample_Size / 2);
			double test_y = y + (Test_Sample_Size / 2);

			//Converting to graph scale
			test_x = test_x - (pictureBox1->Width / 2);
			test_y = (pictureBox1->Height / 2) - test_y;

			//normalizing data
			test_x = ((double)(test_x)-mean_x) / std_x;
			test_y = ((double)(test_y)-mean_y) / std_y;

			float* data;
			/*data.X.push_back(test_x); data.X.push_back(test_y); data.class_id = 0;

			network->Feed_Forward(data);
			Matrix<double> output_layer = network->get_output_layer(); */
			int index;
			for (index = 0; index < numClass; index++) {
				if (index == targets[numSample-1]) break;
			}
			Test_Output[i] = index;
			i++;
		}
	}
	
	pictureBox1->Refresh();
}
};
}
