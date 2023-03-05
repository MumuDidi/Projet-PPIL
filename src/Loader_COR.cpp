#include "../include/Loader_COR.h"

#include <cstring>

Loader_COR::Loader_COR(Loader_COR* formatSuivant) :suivant(formatSuivant) { }


Forme* Loader_COR::Load(string fichier) const {
	Forme* F = this->Transform(fichier); // cet expert tente de résoudre le problème
	if (F != NULL) // cet expert a trouvé une solution
		return F;
	else // échec de cet expert
		if (this->suivant != NULL) // le problème est transmis à l’expert suivant
			return this->suivant->Load(fichier);
		else // cet expert est le dernier de la chaîne
			cout << "Aucun format trouvé" << endl;
			return NULL; // donc échec de la chaîne
}

Couleur Loader_COR::stringToCouleur(char* couleur) const{
	if (strcmp(couleur, "Black") == 0)
		return Couleur::BLACK;
	else if (strcmp(couleur, "Blue") == 0)
		return Couleur::BLUE;
	else if (strcmp(couleur, "Red") == 0)
		return Couleur::RED;
	else if (strcmp(couleur, "Green") == 0)
		return Couleur::GREEN;
	else if (strcmp(couleur, "Yellow") == 0)
		return Couleur::YELLOW;
	else if (strcmp(couleur, "Cyan") == 0)
		return Couleur::CYAN;
	else
		return Couleur::BLACK;
}
	