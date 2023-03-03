#include "Header/Segment.h"

Segment::Segment(const Vecteur2D& a, const Vecteur2D& b, const Couleur& couleur)
    : Forme(couleur), a_(a), b_(b) {}

double Segment::aire() const {
    return 0;
}

string Segment::toString() const {
    std::ostringstream oss;
    oss << "Segment ( " << a_ << " -> " << b_ << " , couleur : " << couleurToString(couleur_) << ")";
    return oss.str();
}

ostream& operator<<(std::ostream& os, const Segment& seg) {
    os << seg.toString() << endl;
    return os;
}

bool Segment::intersection(const Segment& s) const {
    // vecteur de ce segment
    Vecteur2D v1(b_.x - a_.x, b_.y - a_.y);
    // vecteur du segment s
    Vecteur2D v2(s.b_.x - s.a_.x, s.b_.y - s.a_.y);
    // vecteur entre les origines des deux segments
    Vecteur2D w(a_.x - s.a_.x, a_.y - s.a_.y);
    // calcul des produits vectoriels
    double prod1 = v1.prodVect(w);
    double prod2 = v2.prodVect(w);
    double prod3 = v1.prodVect(v2);
    // si les produits vectoriels sont de signes différents, les segments se croisent
    return ((prod1 * prod2 < 0) && (prod3 * prod2 < 0));
}