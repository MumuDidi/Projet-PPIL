#pragma once
#include "Forme.h"
#include "Vecteur2D.h"

class Segment : public Forme {
public:
    Segment(const Vecteur2D& a, const Vecteur2D& b, const Couleur& couleur);
    double aire() const override;
    std::string toString() const override;
    bool intersection(const Segment& s) const;
    friend std::ostream& operator<<(std::ostream& os, const Segment& seg);

private:
    Vecteur2D a_, b_;
};

