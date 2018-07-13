#include "stdafx.h"
#include "Circuit.h"

System::Void CppCLR_WinformsProjekt::Circuit::Circuit_Paint(System::Object ^ sender, System::Windows::Forms::PaintEventArgs ^ e)
{
	//Globale variablen lokal machen
	String^ gleichung = gl;
	int variablen = vars;

	//Variablen für Zeichnung
	Brush^ b = gcnew SolidBrush(System::Drawing::Color::Black);
	System::Drawing::Pen^ pen = gcnew System::Drawing::Pen(System::Drawing::Color::Black, 3);
	System::Drawing::Font^ f = gcnew System::Drawing::Font("Arial", 12);
	Graphics^ g = e->Graphics;

	//Punkte für Zeichnung
	Point p1, p2, endpoint, savepoint;

	//input string splitten (wird 2 mal benötigt)
	istringstream str(msclr::interop::marshal_as<std::string>(gleichung));	//konvertiere von System::String zu std::string
	istringstream terms(msclr::interop::marshal_as<std::string>(gleichung));	//konvertiere von System::String zu std::string
	string sTemp = "";

	//Variablen holen
	QM q(variablen);

	vector<string> vTemp = q.getVars();

	//vector<string> -> vector<const char*>, zum weiteren berechnen notwendig
	vector<const char*> variables(vTemp.size(), nullptr);
	for (unsigned int i = 0; i<vTemp.size(); i++) {
		variables[i] = vTemp[i].c_str();
	}

	//Mineterme zählen
	int minterms = 0;
	while (getline(str, sTemp, ',')) minterms++;

//Logikgatter zeichnen
	//Rechteck für "oder"
	//Eckpunkt
	p1 = Point(50 + 2*295 + (720 / (minterms + 2)), 270);
	savepoint = p1;
	//Größe
	System::Drawing::Size varSize = System::Drawing::Size(90, 180);
	System::Drawing::Rectangle r = System::Drawing::Rectangle(p1, varSize);
	//Zeichnen
	e->Graphics->DrawRectangle(pen, r);
	//">=1" hinzufügen
	p1.X = (p1.X - (1.5 * 12)) + varSize.Width / 2;
	p1.Y = (p1.Y - (0.5 * 12)) + varSize.Height / 2;
	e->Graphics->DrawString(">=1", f, b, p1);

	endpoint = p1;

	//"Y" hinzufügen
	p2.X = endpoint.X + 295;
	p2.Y = endpoint.Y;
	e->Graphics->DrawString("Y", f, b, p2);

	//Linie zwischen "oder", "Y"
	endpoint.X = 50 + 2 * 295 + (720 / (minterms + 2)) + 90;
	endpoint.Y += 6;
	p2.X -= 10;
	p2.Y += 6;
	e->Graphics->DrawLine(pen, endpoint, p2);

	//Vektor für Gatterpunkte (kann nicht als vector<Point> angelegt werden)
	vector<int> p_endVect_x;
	vector<int> p_endVect_y;

	//Rechtecke für "und"
	for (int i = 0; i < minterms; i++)
	{
		//Eckpunkt
		p2 = Point(50 + 295, i*(720 / (minterms + 1)) + (360 / (minterms + 1)));

		//Größe
		System::Drawing::Size varSize = System::Drawing::Size((720 / (minterms + 2)) / 1.5, 720 / (minterms + 1));
		System::Drawing::Rectangle r = System::Drawing::Rectangle(p2, varSize);
		
		//Endpunkte zwischenspeichern
		p_endVect_x.push_back(p2.X);
		p_endVect_y.push_back(p2.Y);
		
		//Zeichnen
		e->Graphics->DrawRectangle(pen, r);
		
		//"&" hinzufügen
		p2.X = (p2.X - 6) + varSize.Width / 2;
		p2.Y = (p2.Y - 6) + varSize.Height / 2;
		e->Graphics->DrawString("&", f, b, p2);

		//Punkte festlegen
		savepoint.Y += 180 / (minterms+1);

		p2.X += varSize.Width/2 + 6;
		p2.Y += 6;

		//Linien zwischen "und"-, "oder"-Gatter
		e->Graphics->DrawLine(pen, savepoint, p2);
}

	//Vektor für Variablenpunkte (kann nicht als vector<Point> angelegt werden)
	vector<int> p_varVect_x;
	vector<int> p_varVect_y;

	//Variablennamen schreiben
	for (int i = 0; i < variablen; i++)
	{
		p1 = Point(50, i*(720 / (variablen + 1)) + (540 / (variablen + 1)));
		String^ s = gcnew String(variables[i]);
		e->Graphics->DrawString(s, f, b, p1);
		p_varVect_x.push_back(p1.X);
		p_varVect_y.push_back(p1.Y);
	}

	//Linien zwischen Variablen, Gittern ziehen
	int loop = 0;
	while (getline(terms, sTemp, ','))//aktuellen Minterm erfassen
	{
		Point p_var, p_end;//Anfangs-, Endpunkt anlegen
		for (size_t i = 0; i < sTemp.size(); i++)//für alle Buchstaben im aktuellen Minterm:
		{
			//Einzelnes Zeichen auswählen
			char sdata_temp = NULL;
			sdata_temp = sTemp[i];

			int j = 0;
			while(j < variablen)//für alle Variablen wiederholen
			{
				//aktuelle Variable auswählen
				char currentElem = NULL;
				strcpy(&currentElem, variables[j]);
				j++;

				//ist aktuelles Zeichen Negierung?
				if (strcmp("'", &sdata_temp) == 0)
				{//ja
					//nächstes Zeichen auswählen
					i++;
					sdata_temp = sTemp[i];
					
					//mit allen variablen vergleichen
					int k = 0;
					while (k < variablen)
					{
						//aktuelles Zeichen = aktuelle Variable?
						if (strcmp(&sdata_temp, &currentElem) != 0)
						{//nein
							//nächste Variable auswählen
							k++;
							strcpy(&currentElem, variables[k]);
							continue;
						}
						break;
					}

					//Linienpunkte festlegen
					p_var = Point(p_varVect_x[k] + 24, p_varVect_y[k] + 6);
					p_end = Point(p_endVect_x[loop], p_endVect_y[loop]);
					p_end.Y += (720 / (minterms + 2)) / (variablen + 1) * (k + 1);

					//Brush erstellen
					Brush^ ellipseBr = gcnew SolidBrush(System::Drawing::Color::White);

					//Linien, Negation einzeichnen
					e->Graphics->DrawLine(pen, p_var, p_end);
					e->Graphics->FillEllipse(ellipseBr, p_end.X - 5, p_end.Y - 5, 10, 10);
					e->Graphics->DrawEllipse(pen, p_end.X - 6, p_end.Y - 6, 12, 12);

					break;
				}
				else
				{
					//aktuelles Zeichen = aktuelle Variable?	nein -> nächste Variable auswählen
					if (strcmp(&sdata_temp, &currentElem) != 0) continue;

					//Linienpunkte festlegen
					p_var = Point(p_varVect_x[j-1] + 24, p_varVect_y[j-1] + 6);
					p_end = Point(p_endVect_x[loop], p_endVect_y[loop]);
					p_end.Y += (720 / (minterms + 2)) / (variablen + 1) * j;

					//Linien einzeichnen
					e->Graphics->DrawLine(pen, p_var, p_end);
					break;
				}
			}
		}
		loop++;
	}
}
