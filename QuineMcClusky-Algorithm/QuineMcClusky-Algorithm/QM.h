#pragma once
#include <string>
#include <vector>

using namespace std;

ref class QM
{
public:
	QM(int numberElements);
	vector<string> getVars();
private:
	int VARIABLES;
	string* dontcares;
};

