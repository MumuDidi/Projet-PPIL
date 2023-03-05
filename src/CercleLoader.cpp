#include "../include/CercleLoader.h"
#include "../include/Cercle.h"
#include <regex>

CercleLoader::CercleLoader(Loader_COR* suivant) : Loader_COR(suivant) {}


Forme* CercleLoader::Transform(string line) const {
	
	double x1, y1, r;
	char coul[10];
    Couleur c1;
	regex reg("Cercle\\(\\(-?[0-9]+.?[0-9]*,-?[0-9]+.?[0-9]*\\),[1-9][0-9]*.?[0-9]*,(Blue|Black|Red|Green|Yellow|Cyan) \\)");
	if (regex_search(line, reg)) {
		cout << "Création d'un Cercle" << endl;
		sscanf(line.c_str(), "Cercle((%lf,%lf),%lf,%9s)", &x1, &y1, &r, coul, 4);
        Vecteur2D v1(x1, y1);
        c1 = stringToCouleur(coul);
		Cercle* result = new Cercle(v1, r, c1);
		return result;
	}
	else
	{
		return NULL;
	}
}
