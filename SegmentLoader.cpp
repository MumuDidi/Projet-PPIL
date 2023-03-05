#include "SegmentLoader.h"
#include "Segment.h"
#include <regex>

SegmentLoader::SegmentLoader(Loader_COR* suivant) : Loader_COR(suivant) {}


Forme* SegmentLoader::Transform(string line) const {
	
	double x1, y1, x2, y2;
	string coul;
    Couleur c1;
	regex reg("Segment\\(\\(-?[0-9]+.?[0-9]*,-?[0-9]+.?[0-9]*\\),\\(-?[0-9]+.?[0-9]*,-?[0-9]+.?[0-9]*\\),(Blue|Black|Red|Green|Yellow|Cyan)\\)");
	if (regex_search(line, reg)) {
		cout << "Création d'un Segment" << endl;
		const char* line2 = line.c_str();
		const char* line3 = _strdup(line2);
		sscanf_s(line3, "Segment((%lf,%lf),(%lf,%lf),%s", &x1, &y1, &x2, &y2, coul, 5);
        Vecteur2D v1(x1, y1);
        Vecteur2D v2(x2, y2);
        c1 = stringToCouleur(coul);
		Segment* result = new Segment(v1, v2, c1);
		return result;
	}
	else
	{
		return NULL;
	}
}
