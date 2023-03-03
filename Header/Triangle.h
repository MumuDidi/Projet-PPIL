#pragma once
#include "Forme.h"
#include "Vecteur2D.h"

class Triangle : public Forme {
public:
    Triangle(const Vecteur2D& a, const Vecteur2D& b, const Vecteur2D& c, const Couleur& couleur);
    double aire() const override;
    std::string toString() const override;
    friend std::ostream& operator<<(std::ostream& os, const Triangle& t);

private:
    Vecteur2D a_, b_, c_;
};
