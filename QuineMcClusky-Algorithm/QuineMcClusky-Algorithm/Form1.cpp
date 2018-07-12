#include "stdafx.h"
#include "Form1.h"
// #include "Form1.h"

void CppCLR_WinformsProjekt::Form1::makeTable(vector<const char*> variables, vector<string> minterms)
{
	this->dGVTabelle->Rows->Clear();
	dGVTabelle->Columns->Clear();
	for (int i = 0; i < variables.size(); i++)
	{
		dGVTabelle->Columns->Add(i.ToString(), gcnew String(variables[i]));
	}
	int j = 0;
	for each (string s in minterms)
	{
		dGVTabelle->Rows->Add();
		for (int i = 0; i < variables.size(); i++)
		{
			char strEl = s[i];
			dGVTabelle->Rows[j]->Cells[i]->Value = gcnew String(&strEl);
		}
		j++;
	}

	dGVTabelle->Visible = true;
}

string CppCLR_WinformsProjekt::Form1::DoQM(bool full, int cycle)
{
	QM q((int)this->nUDVars->Value);

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
		char* sdata = (char*)malloc(sizeof(char)* s.size());
		sdata = const_cast<char*>(s.c_str());
		string data = "";
		int nots = 0;
		for (int i = 0; i < variables.size() + nots; i++)
		{
			char sdata_temp = NULL;
			if(sdata[i]) sdata_temp = sdata[i];
			if (strcmp("'", &sdata_temp) == 0)
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
		minterms.push_back(data);
	}

	sort(minterms.begin(), minterms.end());

	do
	{
		if (full == false)
		{
			makeTable(variables, minterms);
			cycle--;
		}

		minterms = q.reduce(minterms);
		sort(minterms.begin(), minterms.end());
	} while ((!q.EqualVectors(minterms, q.reduce(minterms))) && (cycle > 0));

	makeTable(variables, minterms);

	string back = "";
	int lastElem = minterms.size();
	for (unsigned int i = 0; i<lastElem - 1; i++)
		back += q.toCharacter(minterms[i]) + " , ";
	back += q.toCharacter(minterms[lastElem-1]);

	return back;
}
