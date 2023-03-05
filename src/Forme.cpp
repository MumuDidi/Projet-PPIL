#include "Forme.h"

Forme::Forme(Couleur couleur) : couleur_(couleur) {}

std::string Forme::toString() const {
    return "Couleur : " + couleurToString(couleur_);
}

Couleur Forme::getCouleur() const {
    return couleur_;
}

std::string couleurToString(Couleur couleur) {
    switch (couleur) {
    case Couleur::BLACK:
        return "black";
    case Couleur::BLUE:
        return "blue";
    case Couleur::RED:
        return "red";
    case Couleur::GREEN:
        return "green";
    case Couleur::YELLOW:
        return "yellow";
    case Couleur::CYAN:
        return "cyan";
    default:
        return "unknown";
    }
}


ostream& operator << (ostream& os, const Forme& f)
{
	return os << f.toString();
}