#pragma once
#include "QM.h"
#include <msclr\marshal_cppstd.h>


namespace CppCLR_WinformsProjekt {

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
			this->components = gcnew System::ComponentModel::Container();
			this->Size = System::Drawing::Size(1280,720);
			this->Text = L"Circuit";
			this->Padding = System::Windows::Forms::Padding(0);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Circuit::Circuit_Paint);

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

private:
	String^ gl;
	int vars;

//---------------------------------------------------------------------------Zeichnen

private: System::Void Circuit_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e);
	};
}
