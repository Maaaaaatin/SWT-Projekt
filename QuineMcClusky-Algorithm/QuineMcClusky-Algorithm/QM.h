#pragma once
#include <string>
#include <string.h>
#include <sstream>	//istringstream
#include <vector>
#include <stdlib.h>
#include <algorithm>

using namespace std;

ref class QM
{
public:
	QM(int numberElements);
	//um die boolean Variablen zu erhalten
	vector<string> getVars();
	//wandelt dezimal zahlen in binär
	string decToBin(int number);
	//Nullen auffüllen
	string zeroes(string binStr);
	//auf Grey-Code überprüfen
	bool isGreyCode(string a, string b);
	//dontcares einfügen
	string makeDontcares(string a, string b);
	//check ob b schon in Vektor a vorhanden ist
	bool isInVector(vector<string> a, string b);
	//gleichung reduzieren
	vector<string> reduce(vector<string> toReduce);
	//bool'sche ausdrücke in Buchstaben umwandeln
	string toCharacter(string boolStr);
	//check ob 2 Vektoren gleich sind
	bool EqualVectors(vector<string> a, vector<string> b);
private:
	int numVars;
	string* dontcares;
};

