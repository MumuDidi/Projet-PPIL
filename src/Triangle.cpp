#include "../include/Triangle.h"
#include <cmath>

Triangle::Triangle(const Vecteur2D& a, const Vecteur2D& b, const Vecteur2D& c, const Couleur& couleur)
    : Forme(couleur), a_(a), b_(b), c_(c) {}

double Triangle::aire() const {
    double ab = (b_ - a_).norme();
    double bc = (c_ - b_).norme();
    double ac = (c_ - a_).norme();
    double p = (ab + bc + ac) / 2;
    return sqrt(p * (p - ab) * (p - bc) * (p - ac));
}

std::string Triangle::toString() const {
    std::ostringstream os;
    os << "Triangle[" << a_ << "," << b_ << "," << c_ << "," << couleurToString(couleur_) << "," << aire() <<"]";
    return os.str();
}

std::ostream& operator<<(std::ostream& os, const Triangle& t) {
    os << t.toString() << endl;
    return os;
}

void Triangle::Translate(double dx, double dy){
    a_.Translate(dx, dy);
    b_.Translate(dx, dy);
    c_.Translate(dx, dy);
}

void Triangle::homothetie(const double& k, const Vecteur2D& centre){
    a_.homothetie(k, centre);
    b_.homothetie(k, centre);
    c_.homothetie(k, centre);
}

void Triangle::rotation(const double& angle, const Vecteur2D& centre){
    a_.rotation(angle, centre);
    b_.rotation(angle, centre);
    c_.rotation(angle, centre);
}