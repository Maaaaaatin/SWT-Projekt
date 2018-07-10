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

	while (getline(str, s, ','))	//getline(instring, outstring, delim)
	{
		char* sdata = (char*)malloc(sizeof(char)* s.size());
		sdata = const_cast<char*>(s.c_str());
		string data = "";
		for (int i = 0; i < s.size(); i++)
		{
			int j = i;
			char sdata_temp = NULL;
			if(sdata[i]) sdata_temp = sdata[i];
			while (j < variables.size())
			{
				if (strcmp(variables[j], &sdata_temp) == 0)
				{
					int term = int(sdata[i]);
					data += q.decToBin(term);
					break;
				}
				else
				{
					string nulls = "00000";
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
