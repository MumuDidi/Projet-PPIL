#pragma once
#include <vector>
#include "Forme.h"

class Groupe : public Forme{
public:
    Groupe(const std::vector<Forme*>& formes, const Couleur& couleur);
    void ajouter(Forme* forme);
    void supprimer(Forme* forme);
    std::vector<Forme *> getFormes() const;
    double aire() const override;
    std::string toString() const override;
    void Translate(double dx, double dy) override;
    void homothetie(const double& k, const Vecteur2D& centre);
    void rotation(const double& angle, const Vecteur2D& centre);
    friend std::ostream& operator<<(std::ostream& os, const Groupe& g);

private:
    std::vector<Forme* > formes_;
};