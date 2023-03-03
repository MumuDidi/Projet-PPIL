#include "Cercle.h"

Cercle::Cercle(const Vecteur2D& centre, double rayon, const Couleur& couleur)
    : Forme(couleur), centre_(centre), rayon_(rayon) {}

double Cercle::aire() const {
    return 3.14159 * rayon_ * rayon_;
}

std::string Cercle::toString() const {
    std::ostringstream oss;
    oss << "Cercle ( centre : " << centre_ << ", rayon : " << rayon_ << ", couleur : " << couleurToString(couleur_) << ", aire : " << aire() << ")";
    return oss.str();
}

std::ostream& operator<<(std::ostream& os, const Cercle& c) {
    os << c.toString() << endl;
    return os;
}
