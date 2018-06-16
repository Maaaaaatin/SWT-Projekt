#pragma once

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
	private: System::Windows::Forms::TextBox^  tbGleichung;
	private: System::Windows::Forms::GroupBox^  gbSettings;
	private: System::Windows::Forms::GroupBox^  gbControll;
	private: System::Windows::Forms::GroupBox^  gbMain;
	private: System::Windows::Forms::Button^  bShowCircuit;


	private: System::Windows::Forms::Button^  bNextStep;
	private: System::Windows::Forms::Button^  bSave;
	private: System::Windows::Forms::Button^  bCalc;
	private: System::Windows::Forms::RadioButton^  rbFull;
	private: System::Windows::Forms::RadioButton^  rbStepwise;
	private: System::Windows::Forms::Label^  lGleichungen;


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
			this->gbControll = (gcnew System::Windows::Forms::GroupBox());
			this->bShowCircuit = (gcnew System::Windows::Forms::Button());
			this->bNextStep = (gcnew System::Windows::Forms::Button());
			this->bSave = (gcnew System::Windows::Forms::Button());
			this->bCalc = (gcnew System::Windows::Forms::Button());
			this->gbSettings = (gcnew System::Windows::Forms::GroupBox());
			this->rbFull = (gcnew System::Windows::Forms::RadioButton());
			this->rbStepwise = (gcnew System::Windows::Forms::RadioButton());
			this->gbGleichung = (gcnew System::Windows::Forms::GroupBox());
			this->lGleichungen = (gcnew System::Windows::Forms::Label());
			this->tbGleichung = (gcnew System::Windows::Forms::TextBox());
			this->gbControll->SuspendLayout();
			this->gbSettings->SuspendLayout();
			this->gbGleichung->SuspendLayout();
			this->SuspendLayout();
			// 
			// gbMain
			// 
			this->gbMain->CausesValidation = false;
			this->gbMain->Location = System::Drawing::Point(12, 12);
			this->gbMain->Name = L"gbMain";
			this->gbMain->Size = System::Drawing::Size(1000, 550);
			this->gbMain->TabIndex = 8;
			this->gbMain->TabStop = false;
			// 
			// gbControll
			// 
			this->gbControll->Controls->Add(this->bShowCircuit);
			this->gbControll->Controls->Add(this->bNextStep);
			this->gbControll->Controls->Add(this->bSave);
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
			this->bShowCircuit->Location = System::Drawing::Point(3, 501);
			this->bShowCircuit->Name = L"bShowCircuit";
			this->bShowCircuit->Size = System::Drawing::Size(224, 23);
			this->bShowCircuit->TabIndex = 3;
			this->bShowCircuit->Text = L"Schaltung anzeigen";
			this->bShowCircuit->UseVisualStyleBackColor = true;
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
			// 
			// bSave
			// 
			this->bSave->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->bSave->Location = System::Drawing::Point(3, 524);
			this->bSave->Name = L"bSave";
			this->bSave->Size = System::Drawing::Size(224, 23);
			this->bSave->TabIndex = 1;
			this->bSave->Text = L"Speichern";
			this->bSave->UseVisualStyleBackColor = true;
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
			this->rbStepwise->TabStop = true;
			this->rbStepwise->Text = L"Ergebnis schrittweise anzeigen";
			this->rbStepwise->UseVisualStyleBackColor = true;
			// 
			// gbGleichung
			// 
			this->gbGleichung->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->gbGleichung->Controls->Add(this->lGleichungen);
			this->gbGleichung->Controls->Add(this->tbGleichung);
			this->gbGleichung->Location = System::Drawing::Point(12, 568);
			this->gbGleichung->Name = L"gbGleichung";
			this->gbGleichung->Size = System::Drawing::Size(800, 100);
			this->gbGleichung->TabIndex = 5;
			this->gbGleichung->TabStop = false;
			// 
			// lGleichungen
			// 
			this->lGleichungen->AutoSize = true;
			this->lGleichungen->Dock = System::Windows::Forms::DockStyle::Top;
			this->lGleichungen->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lGleichungen->Location = System::Drawing::Point(3, 16);
			this->lGleichungen->Name = L"lGleichungen";
			this->lGleichungen->Size = System::Drawing::Size(142, 20);
			this->lGleichungen->TabIndex = 1;
			this->lGleichungen->Text = L"Ausgangsfunktion:";
			// 
			// tbGleichung
			// 
			this->tbGleichung->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->tbGleichung->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbGleichung->Location = System::Drawing::Point(3, 71);
			this->tbGleichung->Name = L"tbGleichung";
			this->tbGleichung->Size = System::Drawing::Size(794, 26);
			this->tbGleichung->TabIndex = 0;
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
			this->Text = L"Form1";
			this->gbControll->ResumeLayout(false);
			this->gbSettings->ResumeLayout(false);
			this->gbSettings->PerformLayout();
			this->gbGleichung->ResumeLayout(false);
			this->gbGleichung->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
};
}
