#include "stdafx.h"
#include "Form1.h"
// #include "Form1.h"

void CppCLR_WinformsProjekt::Form1::makeTable(vector<const char*> variables, vector<string> minterms)
{
	//Tabelle leeren
	this->dGVTabelle->Rows->Clear();
	this->dGVTabelle->Columns->Clear();

	//spaltennamen nach variablen hinzufügen
	for (int i = 0; i < variables.size(); i++)
	{
		this->dGVTabelle->Columns->Add(i.ToString(), gcnew String(variables[i]));
	}

	int j = 0;
	
	//Minterme in Zeilen eintragen
	for each (string s in minterms)
	{
		//zeile hinzufügen
		this->dGVTabelle->Rows->Add();
		for (int i = 0; i < variables.size(); i++)
		{
			//aktuellen element zwischenspeichern (funktioniert sonst nicht)
			char strEl = s[i];
			
			//Zelle füllen
			this->dGVTabelle->Rows[j]->Cells[i]->Value = gcnew String(&strEl);
		}
		j++;
	}

	//tabelle sichtbar machen, falls notwendig
	this->dGVTabelle->Visible = true;
}

string CppCLR_WinformsProjekt::Form1::DoQM(bool full, int cycle)
{
	//Klasse anlegen mit anzahl der Variablen
	QM q((int)this->nUDVars->Value);

//---------------------------------------------------------------------------Einlesen

	//Holen der Gleichung
	String^ inputGl = gcnew String(this->tbGleichung->Text);

	//input string splitten
	istringstream str(msclr::interop::marshal_as<std::string>(inputGl));	//konvertiere von System::String zu std::string
	
	vector<string> minterms;
	string s = "";

	//Variablen holen
	vector<string> vTemp = q.getVars();
	
	//vector<string> -> vector<const char*>, zum weiteren berechnen notwendig
	vector<const char*> variables(vTemp.size(), nullptr);
	for (int i = 0; i<vTemp.size(); i++) {
		variables[i] = vTemp[i].c_str();
	}


	while (getline(str, s, ','))	//getline(instring, outstring, delim)
	{
		//aktuellen Datensatz abrufen
		char* sdata = (char*)malloc(sizeof(char)* s.size());
		sdata = const_cast<char*>(s.c_str());
		
		string data = "";
		int nots = 0;
		
		//Umwandeln der Buchstaben in Binärwerte
		//z.B. a'bc -> 101
		for (int i = 0; i < variables.size() + nots; i++)
		{
			char sdata_temp = NULL;
			if(sdata[i]) sdata_temp = sdata[i];
			
			//ist aktuelle variable negiert?
			if (strcmp("'", &sdata_temp) == 0)//ja
			{
				nots++;
				i++;
				data += "0";
			}
			else
			{
				data += "1";
			}
		}

		//Binärwerte in Minterme speichern
		minterms.push_back(data);
	}

	//Minterme sortieren
	sort(minterms.begin(), minterms.end());
	
//---------------------------------------------------------------------------Reduzieren

	do
	{
		//soll schrittweise gerechnet werden
		if (full == false)
		{	//ja
			cycle--;
			
			//Buttons freigeben/sperren
			this->bCalc->Enabled = false;
			this->bNextStep->Enabled = true;
			this->bNextStep->Visible = true;
		}

		//Minterme reduzieren, sortieren
		minterms = q.reduce(minterms);
		sort(minterms.begin(), minterms.end());

		//wiederholen bis nicht weiter reduzierbar oder ende des cycles erreicht (nur bei schrittweiser berechnung)
	} while ((!q.EqualVectors(minterms, q.reduce(minterms))) && (cycle > 0));

	//Tabelle erstellen
	makeTable(variables, minterms);

//---------------------------------------------------------------------------Ausgabe

	//Rückgabestring
	string back = "";

	//Minterme in Rückgabestring schreiben
	for (size_t i = 0; i<minterms.size() - 1; i++)
		back += q.toCharacter(minterms[i]) + ",";
	back += q.toCharacter(minterms[minterms.size()-1]);

	//Buttons wieder frei geben, falls Minterme nicht weiter reduzierbar (nur bei schrittweiser berechnung)
	if (q.EqualVectors(minterms, q.reduce(minterms)))
	{
		this->bCalc->Enabled = true;
		this->bNextStep->Enabled = false;
		this->bShowCircuit->Visible = true;
		this->bSave->Visible = true;
	}

	return back;
}
