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

		String^ gl;
		int vars;

//---------------------------------------------------------------------------Zeichnen



	private: System::Void Circuit_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
	
		Brush^ b = gcnew SolidBrush(System::Drawing::Color::Black);
		System::Drawing::Font^ f = gcnew System::Drawing::Font("Arial", 12);
		Graphics^ g = e->Graphics;

		Point p;

		RectangleF^ r;

		String^ gleichung = gl;
		int variablen = vars;

		//input string splitten
		istringstream str(msclr::interop::marshal_as<std::string>(gleichung));	//konvertiere von System::String zu std::string

		//Variablen holen
		QM q(variablen);

		vector<string> vTemp = q.getVars();

		//vector<string> -> vector<const char*>, zum weiteren berechnen notwendig
		vector<const char*> variables(vTemp.size(), nullptr);
		for (int i = 0; i<vTemp.size(); i++) {
			variables[i] = vTemp[i].c_str();
		}

		for (int i = 0; i < variablen; i++)
		{
			p = Point(12, i*(720 / (variablen + 1)));
			String^ s = gcnew String(variables[i]);
			e->Graphics->DrawString(s, f, b, p);

		}


	}
	};
}
