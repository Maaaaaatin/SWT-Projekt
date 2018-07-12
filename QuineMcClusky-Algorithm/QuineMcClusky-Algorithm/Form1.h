#pragma once
#include "QM.h"
#include <msclr\marshal_cppstd.h>
#include <typeinfo>
#include "Circuit.h"

namespace CppCLR_WinformsProjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

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
	private: System::Windows::Forms::GroupBox^  gbGleichung;
	protected:

	private: System::Windows::Forms::GroupBox^  gbSettings;
	private: System::Windows::Forms::GroupBox^  gbControll;
	private: System::Windows::Forms::GroupBox^  gbMain;
	private: System::Windows::Forms::Button^  bSave;



	private: System::Windows::Forms::Button^  bNextStep;
	private: System::Windows::Forms::Button^  bLoad;

	private: System::Windows::Forms::Button^  bCalc;
	private: System::Windows::Forms::RadioButton^  rbFull;
	private: System::Windows::Forms::RadioButton^  rbStepwise;


	private: System::Windows::Forms::TextBox^  tbGleichung;
	private: System::Windows::Forms::NumericUpDown^  nUDVars;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  lFunktion;
	private: System::Windows::Forms::DataGridView^  dGVTabelle;
	private: System::Windows::Forms::Button^  bShowCircuit;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;





	protected:

	protected:





	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->gbMain = (gcnew System::Windows::Forms::GroupBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->dGVTabelle = (gcnew System::Windows::Forms::DataGridView());
			this->gbControll = (gcnew System::Windows::Forms::GroupBox());
			this->bShowCircuit = (gcnew System::Windows::Forms::Button());
			this->bSave = (gcnew System::Windows::Forms::Button());
			this->bNextStep = (gcnew System::Windows::Forms::Button());
			this->bLoad = (gcnew System::Windows::Forms::Button());
			this->bCalc = (gcnew System::Windows::Forms::Button());
			this->gbSettings = (gcnew System::Windows::Forms::GroupBox());
			this->rbFull = (gcnew System::Windows::Forms::RadioButton());
			this->rbStepwise = (gcnew System::Windows::Forms::RadioButton());
			this->gbGleichung = (gcnew System::Windows::Forms::GroupBox());
			this->lFunktion = (gcnew System::Windows::Forms::Label());
			this->nUDVars = (gcnew System::Windows::Forms::NumericUpDown());
			this->tbGleichung = (gcnew System::Windows::Forms::TextBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->gbMain->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dGVTabelle))->BeginInit();
			this->gbControll->SuspendLayout();
			this->gbSettings->SuspendLayout();
			this->gbGleichung->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nUDVars))->BeginInit();
			this->SuspendLayout();
			// 
			// gbMain
			// 
			this->gbMain->CausesValidation = false;
			this->gbMain->Controls->Add(this->label1);
			this->gbMain->Controls->Add(this->dGVTabelle);
			this->gbMain->Location = System::Drawing::Point(12, 12);
			this->gbMain->Name = L"gbMain";
			this->gbMain->Size = System::Drawing::Size(1000, 550);
			this->gbMain->TabIndex = 8;
			this->gbMain->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(6, 504);
			this->label1->MaximumSize = System::Drawing::Size(224, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(91, 20);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Zielfunktion";
			this->label1->Visible = false;
			// 
			// dGVTabelle
			// 
			this->dGVTabelle->AllowUserToAddRows = false;
			this->dGVTabelle->AllowUserToDeleteRows = false;
			this->dGVTabelle->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::ColumnHeader;
			this->dGVTabelle->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllHeaders;
			this->dGVTabelle->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dGVTabelle->Location = System::Drawing::Point(6, 16);
			this->dGVTabelle->Name = L"dGVTabelle";
			this->dGVTabelle->Size = System::Drawing::Size(988, 485);
			this->dGVTabelle->TabIndex = 1;
			this->dGVTabelle->Visible = false;
			// 
			// gbControll
			// 
			this->gbControll->Controls->Add(this->bShowCircuit);
			this->gbControll->Controls->Add(this->bSave);
			this->gbControll->Controls->Add(this->bNextStep);
			this->gbControll->Controls->Add(this->bLoad);
			this->gbControll->Controls->Add(this->bCalc);
			this->gbControll->Location = System::Drawing::Point(1018, 12);
			this->gbControll->Name = L"gbControll";
			this->gbControll->Size = System::Drawing::Size(230, 550);
			this->gbControll->TabIndex = 7;
			this->gbControll->TabStop = false;
			// 
			// bShowCircuit
			// 
			this->bShowCircuit->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->bShowCircuit->Location = System::Drawing::Point(3, 478);
			this->bShowCircuit->Name = L"bShowCircuit";
			this->bShowCircuit->Size = System::Drawing::Size(224, 23);
			this->bShowCircuit->TabIndex = 4;
			this->bShowCircuit->Text = L"Schaltplan anzeigen";
			this->bShowCircuit->UseVisualStyleBackColor = true;
			this->bShowCircuit->Visible = false;
			// 
			// bSave
			// 
			this->bSave->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->bSave->Location = System::Drawing::Point(3, 501);
			this->bSave->Name = L"bSave";
			this->bSave->Size = System::Drawing::Size(224, 23);
			this->bSave->TabIndex = 3;
			this->bSave->Text = L"Speichern";
			this->bSave->UseVisualStyleBackColor = true;
			this->bSave->Visible = false;
			this->bSave->Click += gcnew System::EventHandler(this, &Form1::bSave_Click);
			// 
			// bNextStep
			// 
			this->bNextStep->Dock = System::Windows::Forms::DockStyle::Top;
			this->bNextStep->Location = System::Drawing::Point(3, 39);
			this->bNextStep->Name = L"bNextStep";
			this->bNextStep->Size = System::Drawing::Size(224, 23);
			this->bNextStep->TabIndex = 2;
			this->bNextStep->Text = L"Nächster Schritt";
			this->bNextStep->UseVisualStyleBackColor = true;
			this->bNextStep->Visible = false;
			this->bNextStep->Click += gcnew System::EventHandler(this, &Form1::bNextStep_Click);
			// 
			// bLoad
			// 
			this->bLoad->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->bLoad->Location = System::Drawing::Point(3, 524);
			this->bLoad->Name = L"bLoad";
			this->bLoad->Size = System::Drawing::Size(224, 23);
			this->bLoad->TabIndex = 1;
			this->bLoad->Text = L"Laden";
			this->bLoad->UseVisualStyleBackColor = true;
			this->bLoad->Click += gcnew System::EventHandler(this, &Form1::bLoad_Click);
			// 
			// bCalc
			// 
			this->bCalc->Dock = System::Windows::Forms::DockStyle::Top;
			this->bCalc->Location = System::Drawing::Point(3, 16);
			this->bCalc->Name = L"bCalc";
			this->bCalc->Size = System::Drawing::Size(224, 23);
			this->bCalc->TabIndex = 0;
			this->bCalc->Text = L"Berechnen";
			this->bCalc->UseVisualStyleBackColor = true;
			this->bCalc->Click += gcnew System::EventHandler(this, &Form1::bCalc_Click);
			// 
			// gbSettings
			// 
			this->gbSettings->Controls->Add(this->rbFull);
			this->gbSettings->Controls->Add(this->rbStepwise);
			this->gbSettings->Location = System::Drawing::Point(818, 568);
			this->gbSettings->Name = L"gbSettings";
			this->gbSettings->Size = System::Drawing::Size(430, 100);
			this->gbSettings->TabIndex = 6;
			this->gbSettings->TabStop = false;
			// 
			// rbFull
			// 
			this->rbFull->AutoSize = true;
			this->rbFull->Checked = true;
			this->rbFull->Location = System::Drawing::Point(7, 50);
			this->rbFull->Name = L"rbFull";
			this->rbFull->Size = System::Drawing::Size(222, 17);
			this->rbFull->TabIndex = 1;
			this->rbFull->TabStop = true;
			this->rbFull->Text = L"Ergebnis ohne Zwischenschritte anzeigen";
			this->rbFull->UseVisualStyleBackColor = true;
			// 
			// rbStepwise
			// 
			this->rbStepwise->AutoSize = true;
			this->rbStepwise->Location = System::Drawing::Point(7, 20);
			this->rbStepwise->Name = L"rbStepwise";
			this->rbStepwise->Size = System::Drawing::Size(170, 17);
			this->rbStepwise->TabIndex = 0;
			this->rbStepwise->Text = L"Ergebnis schrittweise anzeigen";
			this->rbStepwise->UseVisualStyleBackColor = true;
			// 
			// gbGleichung
			// 
			this->gbGleichung->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->gbGleichung->Controls->Add(this->lFunktion);
			this->gbGleichung->Controls->Add(this->nUDVars);
			this->gbGleichung->Controls->Add(this->tbGleichung);
			this->gbGleichung->Location = System::Drawing::Point(12, 568);
			this->gbGleichung->Name = L"gbGleichung";
			this->gbGleichung->Size = System::Drawing::Size(800, 100);
			this->gbGleichung->TabIndex = 5;
			this->gbGleichung->TabStop = false;
			// 
			// lFunktion
			// 
			this->lFunktion->AutoSize = true;
			this->lFunktion->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->lFunktion->Location = System::Drawing::Point(6, 30);
			this->lFunktion->Name = L"lFunktion";
			this->lFunktion->Size = System::Drawing::Size(291, 20);
			this->lFunktion->TabIndex = 6;
			this->lFunktion->Text = L"Ausgangsfunktion und Variablenanzahl:";
			// 
			// nUDVars
			// 
			this->nUDVars->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->nUDVars->Location = System::Drawing::Point(744, 68);
			this->nUDVars->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 20, 0, 0, 0 });
			this->nUDVars->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->nUDVars->Name = L"nUDVars";
			this->nUDVars->Size = System::Drawing::Size(50, 26);
			this->nUDVars->TabIndex = 4;
			this->nUDVars->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 4, 0, 0, 0 });
			// 
			// tbGleichung
			// 
			this->tbGleichung->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbGleichung->Location = System::Drawing::Point(6, 68);
			this->tbGleichung->Name = L"tbGleichung";
			this->tbGleichung->Size = System::Drawing::Size(732, 26);
			this->tbGleichung->TabIndex = 2;
			this->tbGleichung->Text = L"\'a\'b\'cd,\'a\'bcd,\'ab\'c\'d,\'ab\'cd,\'abc\'d,a\'b\'cd,a\'bcd,\'a\'b\'c\'d,a\'b\'c\'d";
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1264, 681);
			this->Controls->Add(this->gbMain);
			this->Controls->Add(this->gbControll);
			this->Controls->Add(this->gbSettings);
			this->Controls->Add(this->gbGleichung);
			this->Name = L"Form1";
			this->Text = L"QM-Calculator";
			this->gbMain->ResumeLayout(false);
			this->gbMain->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dGVTabelle))->EndInit();
			this->gbControll->ResumeLayout(false);
			this->gbSettings->ResumeLayout(false);
			this->gbSettings->PerformLayout();
			this->gbGleichung->ResumeLayout(false);
			this->gbGleichung->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nUDVars))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

//---------------------------------------------------------------------------Globale Variablen

		int cycle = 0;
		String^ temp = "";

//---------------------------------------------------------------------------Funktionen

//Tabellen erstellen
private: void makeTable(vector<const char*> variables, vector<string> minterms);

//eigentlicher Algorithmus
private: string DoQM(bool full, int cycle);

//"Berechnen"-Button
private: System::Void bCalc_Click(System::Object^  sender, System::EventArgs^  e) {
	//Auswählen wie berechnet werden soll
	if (this->rbFull->Checked == true)//ohne Zwischenschritte
	{
		//Ausgabestring berechnen über Algorithmus
		temp = gcnew String(DoQM(true, 1).c_str());
		label1->Visible = true;
		label1->Text = temp;
	}
	else//mit Zwischenschritten
	{
		this->bShowCircuit->Visible = false;
		this->bSave->Visible = false;
		
		//aktueller zyklus
		cycle = 1;

		//Ausgabestring berechnen über Algorithmus
		temp = gcnew String(DoQM(false, cycle).c_str());
		label1->Visible = true;
		label1->Text = temp;
	}
}

//"Nächster Schritt"-Button
private: System::Void bNextStep_Click(System::Object^  sender, System::EventArgs^  e) {

	//aktueller zyklus
	cycle++;

	//Ausgabestring berechnen über Algorithmus
	temp = gcnew String(DoQM(false, cycle).c_str());
	label1->Visible = true;
	label1->Text = temp;
}

//Schaltplan anzeigen
private: System::Void bShowCircuit_Click(System::Object^  sender, System::EventArgs^  e) {
	
}

//Speichern
private: System::Void bSave_Click(System::Object^  sender, System::EventArgs^  e) {

	//Speicher-Dialog öffnen
	if (this->saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		//Dateiname angeben
		IO::StreamWriter^ save = IO::File::CreateText(saveFileDialog1->FileName);
		
		//Inhalt der Datei
		save->WriteLine(this->tbGleichung->Text);
		save->WriteLine(this->nUDVars->Value);
	
		//Speichern abschließen
		save->Close();
	}
}

//Laden
private: System::Void bLoad_Click(System::Object^  sender, System::EventArgs^  e) {

	//Gleichung löschen
	tbGleichung->Clear();

	//Zu öffnende Datei auswählen
	this->openFileDialog1->ShowDialog();
	String^ filename = this->openFileDialog1->FileName;
	IO::StreamReader^ save = IO::File::OpenText(openFileDialog1->FileName);
	
	//Gleichung, Anzahl Variablen lesen
	this->tbGleichung->Text = save->ReadLine();
	this->nUDVars->Value = INT32::Parse(save->ReadLine());
	
	//Datei schließen
	save->Close();

	//Neuberechnung des Ausgabestrings
	temp = gcnew String(DoQM(true, 1).c_str());
	label1->Visible = true;
	label1->Text = temp;
}

};
}
