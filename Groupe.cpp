#include "Groupe.h"
#include <iostream>
#include <string>


Groupe::Groupe(const std::vector<Forme* >& formes, const Couleur& couleur)
    : Forme(couleur), formes_(formes)
{
}
void Groupe::ajouter(Forme* forme) {
    formes_.push_back(forme);
}

void Groupe::supprimer(Forme* forme) {
    for (auto it = formes_.begin(); it != formes_.end(); ++it) {
        if (*it == forme) {
            formes_.erase(it);
            break;
        }
    }
}
std::vector<Forme*> Groupe::getFormes() const {
    return formes_;
}

double Groupe::aire() const {
    double aire = 0;
    for (auto forme : formes_) {
        aire += forme->aire();
    }
    return aire;
}

std::string Groupe::toString() const {
    std::string s = "Groupe de couleur " + couleurToString(couleur_) + " constitué de " + std::to_string(formes_.size()) + " forme(s) : ";
    for (auto forme : formes_) {
        s += "\n     " + forme->toString();
    }
    return s;
}

void Groupe::Translate(double dx, double dy) {
    for (auto forme : formes_) {
        forme->Translate(dx, dy);
    }
}

void Groupe::homothetie(const double& k, const Vecteur2D& centre) {
    for (auto forme : formes_) {
        forme->homothetie(k, centre);
    }
}

void Groupe::rotation(const double& angle, const Vecteur2D& centre) {
    for (auto forme : formes_) {
        forme->rotation(angle, centre);
    }
}

std::ostream& operator<<(std::ostream& os, const Groupe& groupe) {
    os << groupe.toString() << std::endl;
    return os;
}

