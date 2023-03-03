#include "Polygone.h"
#include <cmath>
#include <sstream>

Polygone::Polygone(const std::vector<Vecteur2D>& sommets, const Couleur& couleur)
    : Forme(couleur), sommets_(sommets)
{
}

double Polygone::aire() const
{
    double res = 0;
    int n = sommets_.size();

    for (int i = 0; i < n; i++) {
        const Vecteur2D& p1 = sommets_[i];
        const Vecteur2D& p2 = sommets_[(i + 1) % n];
        res += p1.prodVect(p2);
    }

    return 0.5 * std::abs(res);
}

std::string Polygone::toString() const
{
    std::ostringstream oss;
    oss << "Polygone(";
    for (const auto& sommet : sommets_) {
        oss << sommet << ", ";
    }
    oss << "couleur : " << couleurToString(couleur_) << ", aire : " << aire() << ")";
    oss << "Intersection ?" << autoIntersection() << endl;
    return oss.str();
}

std::ostream& operator<<(std::ostream& os, const Polygone& poly) {
    os << poly.toString() << endl;
    return os;
}

bool Polygone::autoIntersection() const {
    for (unsigned int i = 0; i < sommets_.size(); i++) {
        Segment s1(sommets_[i], sommets_[(i + 1) % sommets_.size()], Couleur::BLACK);
        for (unsigned int j = i + 2; j < sommets_.size(); j++) {
            Segment s2(sommets_[j], sommets_[(j + 1) % sommets_.size()], Couleur::BLACK);
            if (s1.intersection(s2)) {
                return true;
                
            }
        }
    }
    return false;
}
