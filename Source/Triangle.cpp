#include "Triangle.h"
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
    os << "Triangle(" << a_ << "," << b_ << "," << c_ << ", couleur : " << couleurToString(couleur_) << ", aire : " << aire() <<")";
    return os.str();
}

std::ostream& operator<<(std::ostream& os, const Triangle& t) {
    os << t.toString() << endl;
    return os;
}
