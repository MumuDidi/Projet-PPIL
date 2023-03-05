#include "Loader_COR.h"

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

Couleur Loader_COR::stringToCouleur(string couleur) const{
    if (couleur == "black") {
        return Couleur::BLACK;
    }
    else if (couleur == "blue") {
        return Couleur::BLUE;
    }
    else if (couleur == "red") {
        return Couleur::RED;
    }
    else if (couleur == "green") {
        return Couleur::GREEN;
    }
    else if (couleur == "yellow") {
        return Couleur::YELLOW;
    }
    else if (couleur == "cyan") {
        return Couleur::CYAN;
    }
    else {
        return Couleur::BLACK;
    }
}