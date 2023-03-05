#include "../include/TriangleLoader.h"
#include "../include/Vecteur2D.h"
#include "../include/Triangle.h"
#include <iostream>

#include <regex>

TriangleLoader::TriangleLoader(Loader_COR* suivant) : Loader_COR(suivant) {}


Forme* TriangleLoader::Transform(string line) const {
	regex reg("Triangle\\(\\(-?[0-9]+.?[0-9]*,-?[0-9]+.?[0-9]*\\),\\(-?[0-9]+.?[0-9]*,-?[0-9]+.?[0-9]*\\),\\(-?[0-9]+.?[0-9]*,-?[0-9]+.?[0-9]*\\),(Blue|Black|Red|Green|Yellow|Cyan) \\)");
    double x1, y1, x2, y2, x3, y3;
	char coul[10];
    Couleur c1;
	if (regex_search(line, reg)) {
		cout << "Création d'un triangle" << endl;
		sscanf(line.c_str(), "Triangle((%lf,%lf),(%lf,%lf),(%lf,%lf),%9s)", &x1, &y1, &x2, &y2, &x3, &y3, coul);
		cout << "x1 = " << x1 << " y1 = " << y1 << " x2 = " << x2 << " y2 = " << y2 << " x3 = " << x3 << " y3 = " << y3 << " couleur = " << coul << endl;
        Vecteur2D v1(x1, y1);
        Vecteur2D v2(x2, y2);
        Vecteur2D v3(x3, y3);
        c1 = stringToCouleur(coul);
		Triangle* result = new Triangle(v1, v2, v3, c1);
		return result;
	}
	else
	{
		return NULL;
	}
	
}