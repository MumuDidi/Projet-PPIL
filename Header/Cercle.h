#pragma once
#include "Forme.h"
#include "Vecteur2D.h"

class Cercle : public Forme {
public:
    Cercle(const Vecteur2D& centre, double rayon, const Couleur& couleur);
    double aire() const override;
    std::string toString() const override;
    friend std::ostream& operator<<(std::ostream& os, const Cercle& c);

private:
    Vecteur2D centre_;
    double rayon_;
};


