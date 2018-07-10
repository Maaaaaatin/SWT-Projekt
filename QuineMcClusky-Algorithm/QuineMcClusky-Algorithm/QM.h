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
	//wandelt dezimal zahlen in bin�r
	string decToBin(int number);
	//Nullen auff�llen
	string zeroes(string binStr);
	//auf Grey-Code �berpr�fen
	bool isGreyCode(string a, string b);
	//dontcares einf�gen
	string makeDontcares(string a, string b);
	//check ob b schon in Vektor a vorhanden ist
	bool isInVector(vector<string> a, string b);
	//gleichung reduzieren
	vector<string> reduce(vector<string> toReduce);
	//bool'sche ausdr�cke in Buchstaben umwandeln
	string toCharacter(string boolStr);
	//check ob 2 Vektoren gleich sind
	bool EqualVectors(vector<string> a, vector<string> b);
private:
	int numVars;
	string* dontcares;
};

