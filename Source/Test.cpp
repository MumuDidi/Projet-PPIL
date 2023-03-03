#include <iostream>
#include "Segment.h"
#include "Cercle.h"
#include "Triangle.h"
#include "Polygone.h"
#include "Vecteur2D.h"

int main() {
	// création des formes géométriques

	Segment s1(Vecteur2D(0, 0), Vecteur2D(1, 1), Couleur::RED);
	Cercle c1(Vecteur2D(2, 2), 1, Couleur::BLUE);
	Triangle t1(Vecteur2D(0, 0), Vecteur2D(1, 0), Vecteur2D(0, 1), Couleur::GREEN);
	vector<Vecteur2D> points = { Vecteur2D(0, 0), Vecteur2D(0, 1), Vecteur2D(1,0),Vecteur2D(1,1) };
	Polygone p1(points, Couleur::YELLOW);



	// affichage des formes géométriques
	std::cout << s1 << std::endl;
	std::cout << c1 << std::endl;
	std::cout << t1 << std::endl;
	std::cout << p1 << std::endl;

	return 0;
}
