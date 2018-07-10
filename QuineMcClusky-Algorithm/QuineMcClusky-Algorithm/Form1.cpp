#include "stdafx.h"
#include "Form1.h"
// #include "Form1.h"

void CppCLR_WinformsProjekt::Form1::DoQM(bool full)
{
	QM q((int)this->nUDVars->Value);
	
	//Holen der Gleichung
	String^ temp = gcnew String(this->tbGleichung->Text);
		
	//input string splitten
	vector<string> minterms;
	istringstream str(msclr::interop::marshal_as<std::string>(temp));	//konvertiere von System::String zu std::string
	string s = "";
	vector<string> vTemp = q.getVars();
	vector<const char*> variables(vTemp.size(), nullptr);
	for (int i = 0; i<vTemp.size(); i++) {
		variables[i] = vTemp[i].c_str();
	}
	string nulls = "0000000";
	while (getline(str, s, ','))	//getline(instring, outstring, delim)
	{
		char* sdata = const_cast<char*>(s.c_str());
		string data = "";
		for (int i = 0; i < strlen(sdata); i++)
		{
			int j = 0;
			while (j < variables.size())
			{
				if (strcmp(variables[j], &sdata[i]) == 1)
				{
					int term = int(sdata[i]);
					data += q.decToBin(term);
				}
				else
				{
					data += nulls;
				}
				j++;
			}
		}
		data = q.zeroes(data);
		minterms.push_back(data);
	}

	sort(minterms.begin(), minterms.end());

	do
	{
		minterms = q.reduce(minterms);
		sort(minterms.begin(), minterms.end());
	} while (!q.EqualVectors(minterms, q.reduce(minterms)));

	string back = "";
	for (unsigned int i = 0; i<minterms.size() - 1; i++)
		back += q.toCharacter(minterms[i]) + "+";
	back += q.toCharacter(minterms[minterms.size()]);

	this->label1->Text->Replace(this->label1->Text, gcnew String(back.c_str()));
}
