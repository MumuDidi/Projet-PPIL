#define _USE_MATH_DEFINES
#include "../include/Cercle.h"
#include <cmath>

Cercle::Cercle(const Vecteur2D& centre, double rayon, const Couleur& couleur)
    : Forme(couleur), centre_(centre), rayon_(rayon) {}

double Cercle::aire() const {
    return M_PI * rayon_ * rayon_;
}

std::string Cercle::toString() const {
    std::ostringstream oss;
    oss << centre_ << ";" << rayon_ << ";" << couleurToString(couleur_) << ";" << aire();
    return oss.str();
}

std::ostream& operator<<(std::ostream& os, const Cercle& c) {
    os << c.toString() << endl;
    return os;
}

void Cercle::Translate(double dx, double dy){
    centre_.Translate(dx, dy);
}

void Cercle::homothetie(const double& k, const Vecteur2D& centre){
    centre_.homothetie(k, centre);
    rayon_ *= k;
}

void Cercle::rotation(const double& angle, const Vecteur2D& centre){
    centre_.rotation(angle, centre);
}