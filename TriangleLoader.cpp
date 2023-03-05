#include "TriangleLoader.h"
#include "Vecteur2D.h"
#include "Triangle.h"
#include <iostream>

#include <regex>

TriangleLoader::TriangleLoader(Loader_COR* suivant) : Loader_COR(suivant) {}


Forme* TriangleLoader::Transform(string line) const {
	regex reg("Triangle\\(\\(-?[0-9]+.?[0-9]*,-?[0-9]+.?[0-9]*\\),\\(-?[0-9]+.?[0-9]*,-?[0-9]+.?[0-9]*\\),\\(-?[0-9]+.?[0-9]*,-?[0-9]+.?[0-9]*\\),(Blue|Black|Red|Green|Yellow|Cyan)\\)");
    double x1, y1, x2, y2, x3, y3;
	string coul;
    Couleur c1;
	if (regex_search(line, reg)) {
		cout << "Création d'un triangle" << endl;
		const char* line2 = line.c_str();
		const char* line3 = _strdup(line2);
		sscanf_s(line3, "Triangle((%lf,%lf),(%lf,%lf),(%lf,%lf),%s)", &x1, &y1, &x2, &y2, &x3, &y3, coul,7);
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