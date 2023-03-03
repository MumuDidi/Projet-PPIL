#pragma once
#include "Forme.h"
#include "Vecteur2D.h"
#include "Segment.h"
#include <vector>

class Polygone : public Forme {
public:
    Polygone(const std::vector<Vecteur2D>& sommets, const Couleur& couleur);
    double aire() const override;
    std::string toString() const override;
    bool autoIntersection() const;
    friend std::ostream& operator<<(std::ostream& os, const Polygone& poly);

private:
     std::vector<Vecteur2D> sommets_;
};
