#pragma once
#include <msclr\marshal_cppstd.h>
#include "QM.h"

namespace QuineMcClusky_Algorithm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Zusammenfassung für Circuit
	/// </summary>
	public ref class Circuit : public System::Windows::Forms::Form
	{
	public:
		Circuit(void)
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
		~Circuit()
		{
			if (components)
			{
				delete components;
			}
		}

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
			this->SuspendLayout();
			// 
			// Circuit
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1264, 681);
			this->Name = L"Circuit";
			this->Text = L"Schaltplan";
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Circuit::Circuit_Paint);
			this->ResumeLayout(false);

		}

#pragma endregion

//---------------------------------------------------------------------------Properties

	public:
		property String^ Gleichung
		{
			void set(String^ _gleichung) { gl = _gleichung; }
		}

		property int Variablen
		{
			void set(int _variablen) { vars = _variablen; }
		}

//---------------------------------------------------------------------------Globale Variablen
		String^ gl;
		int vars;


private: System::Void Circuit_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {

	String^ gleichung = gl;
	int variablen = vars;

//---------------------------------------------------------------------------auftrennen

	istringstream str(msclr::interop::marshal_as<std::string>(gleichung));	//konvertiere von System::String zu std::string

	QM q(variablen);

	//Variablen holen
	vector<string> vTemp = q.getVars();

	//vector<string> -> vector<const char*>, zum weiteren berechnen notwendig
	vector<const char*> variables(vTemp.size(), nullptr);
	for (int i = 0; i<vTemp.size(); i++) {
		variables[i] = vTemp[i].c_str();
	}



}
	};
}
