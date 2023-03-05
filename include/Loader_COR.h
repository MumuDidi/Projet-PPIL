#pragma once
#include "Loader.h"


class Loader_COR : public Loader
{
public:
	Loader_COR* suivant;
	Forme* Load(string fichier) const;
	Loader_COR(Loader_COR* formatSuivant);
	virtual Forme* Transform(string line) const = 0;
	Couleur stringToCouleur(string couleur) const;

	
};