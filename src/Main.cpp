#define _USE_MATH_DEFINES
#include <iostream>
#include "SegmentLoader.h"
#include "TriangleLoader.h"
#include "CercleLoader.h"


#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;



int main() {
	// chargement des formes depuis un fichier
	Loader* Loader1;
	Loader_COR* TriangleLoader1, * SegmentLoader1, * CercleLoader1;
	TriangleLoader1 = new TriangleLoader(NULL);
	SegmentLoader1 = new SegmentLoader(TriangleLoader1);
	CercleLoader1 = new CercleLoader(SegmentLoader1);

	Loader1 = CercleLoader1;
	string line;

	vector<Forme*> Vff;
	ifstream f("Formes.txt");
	while (getline(f,line)) {
		cout << line << endl;
		Vff.push_back(Loader1->Load(line));	
	}

	vector<Forme*>::iterator it;
	cout << "Les formes crées a partir du fichier texte sont :" << endl << endl;
	for (it = Vff.begin(); it != Vff.end(); ++it) {
		if (*it != NULL) {
			cout << **it << endl;
		}
	}
	return 0;
}
