#include "stdafx.h"
#include "QM.h"

#define MAX_numVars 20
QM::QM(int numberElements)
{
	numVars = numberElements;
}

vector<string> QM::getVars()
{
	vector<string> v;
	for (int i = 0; i < this->numVars; i++)
	{
		char letter = static_cast<char>(97 + i);
		v.push_back(string(1, letter));
	}

	return v;
}

bool QM::isGreyCode(string a, string b)
{
	int flag = 0;
	for (unsigned int i = 0; i<a.length(); i++)
	{
		if (a[i] != b[i])
			flag++;
	}
	return (flag == 1);
}


string QM::makeDontcares(string a, string b)
{
	string temp = "";
	for (unsigned int i = 0; i < a.length(); i++)
	{
		if (a[i] != b[i])
			temp = temp + "-";
		else
			temp = temp + a[i];
	}
	return temp;
}

bool QM::isInVector(vector<string> a, string b)
{
	for (unsigned int i = 0; i<a.size(); i++)
		if (a[i].compare(b) == 0)
			return true;
	return false;
}

vector<string> QM::reduce(vector<string> toReduce)
{
	vector<string> reduced;

	int max = toReduce.size();
	int* checked = (int*) malloc(max * sizeof(int));
	for (int i = 0; i<max; i++)
	{
		for (int j = i; j<max; j++)
		{
			//alle Elemente auf Grey-Code �berpr�fen, ggf. dontcares einf�gen
			if (isGreyCode(toReduce[i], toReduce[j]))
			{
				checked[i] = 1;
				checked[j] = 1;
				if (!isInVector(reduced, makeDontcares(toReduce[i], toReduce[j])))
					reduced.push_back(makeDontcares(toReduce[i], toReduce[j]));
			}
		}
	}

	//�brige Elemente in neuen Vektor schreiben und zur�ck geben
	for (int i = 0; i<max; i++)
	{
		if (checked[i] != 1 && !isInVector(reduced, toReduce[i]))
			reduced.push_back(toReduce[i]);
	}

	return reduced;
}

bool QM::EqualVectors(vector<string> a, vector<string> b)
{
	if (a.size() != b.size())
		return false;

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	for (unsigned int i = 0; i<a.size(); i++)
	{
		if (a[i] != b[i])
			return false;
	}
	return true;
}

string QM::toCharacter(string boolStr)
{
	string temp = "";
	string dontcares = "";
	dontcares.append(this->numVars, '-');
	vector<string> vars = this->getVars();
	if (boolStr == dontcares)
		return "1";

	for (unsigned int i = 0; i< boolStr.length(); i++)
	{
		if (boolStr[i] != '-')
		{
			if (boolStr[i] == '0')
				temp = temp + "\'" + vars[i];
			else
				temp = temp + vars[i];
		}
	}
	return temp;
}