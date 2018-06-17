#include "stdafx.h"
#include "QM.h"

#define MAX_VARIABLES 20
QM::QM(int numberElements)
{
	VARIABLES = numberElements;
	dontcares->append(numberElements, '-');
}

vector<string> QM::getVars()
{
	vector<string> v;
	string letters[MAX_VARIABLES];
	int i = 0;

	while (i < MAX_VARIABLES)
	{
		letters[i] = "x" + to_string(i);
	}
	for (int i = 0; i<this->VARIABLES; i++)
		v.push_back(letters[i]);

	return v;
}

string QM::decToBin(int number)
{
	if (number == 0 || number == 1)
		return to_string(number) + "";

	if (number % 2 == 0)
		return decToBin(number / 2) + "0";
	else
		return decToBin(number / 2) + "1";
}

string QM::zeroes(string binStr)
{
	int max = VARIABLES - binStr.length();
	for (int i = 0; i<max; i++)
		binStr = "0" + binStr;
	return binStr;
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
			//alle Elemente auf Grey-Code überprüfen, ggf. dontcares einfügen
			if (isGreyCode(toReduce[i], toReduce[j]))
			{
				checked[i] = 1;
				checked[j] = 1;
				if (!isInVector(reduced, makeDontcares(toReduce[i], toReduce[j])))
					reduced.push_back(makeDontcares(toReduce[i], toReduce[j]));
			}
		}
	}

	//übrige Elemente in neuen Vektor schreiben und zurück geben
	for (int i = 0; i<max; i++)
	{
		if (checked[i] != 1 && !isInVector(reduced, toReduce[i]))
			reduced.push_back(toReduce[i]);
	}

	return reduced;
}

string QM::toCharacter(string boolStr)
{
	string temp = "";
	vector<string> vars = this->getVars();
	if (boolStr.compare(*dontcares) == 0)
		return "1";

	for (unsigned int i = 0; i<boolStr.length(); i++)
	{
		if (boolStr[i] != '-')
		{
			if (boolStr[i] == '0')
				temp = temp + vars[i] + "\'";
			else
				temp = temp + vars[i];
		}
	}
	return temp;
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