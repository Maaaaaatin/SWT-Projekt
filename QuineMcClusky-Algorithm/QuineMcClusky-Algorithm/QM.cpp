#include "stdafx.h"
#include "QM.h"


QM::QM(int numberElements)
{
	VARIABLES = numberElements;
	dontcares->append(numberElements, '-');
}

vector<string> QM::getVars()
{
	vector<string> v;
	char* letters[20];
	int i = 0;
	while (i < strlen(*letters))
	{
		strcat(letters[i], strcat("x", i.ToString));
	}
	for (int i = 0; i<this->VARIABLES; i++)
		v.push_back(letters[i]);

	return v;
}
