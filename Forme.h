#pragma once
#include <string>
#include "Vecteur2D.h"

enum class Couleur { BLACK, BLUE, RED, GREEN, YELLOW, CYAN };

class Forme {
public:
    Forme(Couleur couleur);
    virtual ~Forme() = default;
    virtual double aire() const = 0;
    virtual std::string toString() const;
    Couleur getCouleur() const;
    virtual void Translate(double dx, double dy) = 0;
    virtual void homothetie(const double& k, const Vecteur2D& centre) = 0;
    virtual void rotation(const double& angle, const Vecteur2D& centre) = 0;
protected:
    Couleur couleur_;
};

std::string couleurToString(Couleur couleur);
