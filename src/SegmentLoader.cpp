#include "../include/SegmentLoader.h"
#include "../include/Segment.h"
#include <regex>

SegmentLoader::SegmentLoader(Loader_COR* suivant) : Loader_COR(suivant) {}


Forme* SegmentLoader::Transform(string line) const {
	
	double x1, y1, x2, y2;
	char coul[10];
    Couleur c1;
	regex reg("Segment\\(\\(-?[0-9]+.?[0-9]*,-?[0-9]+.?[0-9]*\\),\\(-?[0-9]+.?[0-9]*,-?[0-9]+.?[0-9]*\\),(Blue|Black|Red|Green|Yellow|Cyan) \\)");
	if (regex_search(line, reg)) {
		cout << "Création d'un Segment" << endl;

		sscanf(line.c_str(), "Segment((%lf,%lf),(%lf,%lf),%9s", &x1, &y1, &x2, &y2, coul, 5);
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
