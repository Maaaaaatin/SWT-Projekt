#include "stdafx.h"
#include "Form1.h"
// #include "Form1.h"

string CppCLR_WinformsProjekt::Form1::DoQM(bool full)
{
	QM q((int)this->nUDVars->Value);
	
	//Holen der Gleichung
	String^ temp = gcnew String(this->tbGleichung->Text);
		
	//input string splitten
	vector<string> minterms;
	istringstream str(msclr::interop::marshal_as<std::string>(temp));	//konvertiere von System::String zu std::string
	string s = "";

	//Variablen holen
	vector<string> vTemp = q.getVars();
	
	//vector<string> -> vector<const char*>
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
		minterms = q.reduce(minterms);
		sort(minterms.begin(), minterms.end());
	} while (!q.EqualVectors(minterms, q.reduce(minterms)));

	string back = "";
	int lastElem = minterms.size();
	for (unsigned int i = 0; i<lastElem - 1; i++)
		back += q.toCharacter(minterms[i]) + "+";
	back += q.toCharacter(minterms[lastElem-1]);

//	this->label1->Text->Replace(this->label1->Text, gcnew String(back.c_str()));
	return back;
}
