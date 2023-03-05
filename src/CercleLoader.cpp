#include "CercleLoader.h"
#include "Cercle.h"
#include <regex>

CercleLoader::CercleLoader(Loader_COR* suivant) : Loader_COR(suivant) {}


Forme* CercleLoader::Transform(string line) const {
	
	double x1, y1, r;
	string coul;
    Couleur c1;
	regex reg("Cercle\\(\\(-?[0-9]+.?[0-9]*,-?[0-9]+.?[0-9]*\\),[1-9][0-9]*.?[0-9]*,(Blue|Black|Red|Green|Yellow|Cyan)\\)");
	if (regex_search(line, reg)) {
		cout << "Création d'un Cercle" << endl;
		const char* line2 = line.c_str();
		const char* line3 = _strdup(line2);
		sscanf_s(line3, "Cercle((%lf,%lf),%lf,%s)", &x1, &y1, &r, coul, 4);
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
