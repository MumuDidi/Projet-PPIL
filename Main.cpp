#define _USE_MATH_DEFINES
#include <iostream>
#include "Segment.h"
#include "Cercle.h"
#include "Triangle.h"
#include "Polygone.h"
#include "Vecteur2D.h"
#include "Groupe.h"
#include <cmath>



int main() {
	// création des formes géométriques

	Segment s1(Vecteur2D(0, 0), Vecteur2D(1, 1), Couleur::RED);
	Cercle c1(Vecteur2D(2, 2), 1, Couleur::BLUE);
	Triangle t1(Vecteur2D(0, 0), Vecteur2D(1, 0), Vecteur2D(0, 1), Couleur::GREEN);
	vector<Vecteur2D> points = { Vecteur2D(0, 0), Vecteur2D(1, 0), Vecteur2D(1,1),Vecteur2D(0,1) };
	Polygone p1(points, Couleur::YELLOW);
	vector<Forme*> formes = { &s1, &c1, &t1, &p1 };
	Groupe g1(formes, Couleur::BLACK);


	// affichage des formes géométriques
	std::cout << "Affichage des formes géométriques" << std::endl;
	std::cout << g1 << std::endl;

	// déplacement des formes géométriques
	g1.Translate(1, 1);

	// affichage des formes géométriques
	std::cout << "Affichage des formes géométriques après déplacement" << std::endl;
	std::cout << g1 << std::endl;

	// homothétie des formes géométriques
	g1.homothetie(2, Vecteur2D(0, 0));

	// affichage des formes géométriques
	std::cout << "Affichage des formes géométriques après homothétie" << std::endl;
	std::cout << g1 << std::endl;

	// rotation des formes géométriques
	g1.rotation(M_PI / 2, Vecteur2D(0, 0));

	// affichage des formes géométriques
	std::cout << "Affichage des formes géométriques après rotation" << std::endl;
	std::cout << g1 << std::endl;

	return 0;
}
