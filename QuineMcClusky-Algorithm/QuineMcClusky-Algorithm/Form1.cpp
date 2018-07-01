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
	while (getline(str, s, ','))	//getline(instring, outstring, delim)
	{
		int term = atoi(s.data());
		minterms.push_back(q.zeroes(q.decToBin(term)));
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
