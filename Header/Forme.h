#pragma once
#include <string>

enum class Couleur { BLACK, BLUE, RED, GREEN, YELLOW, CYAN };

class Forme {
public:
    Forme(Couleur couleur);
    virtual ~Forme() = default;
    virtual double aire() const = 0;
    virtual std::string toString() const;
    Couleur getCouleur() const;
protected:
    Couleur couleur_;
};

std::string couleurToString(Couleur couleur);
