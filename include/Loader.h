#pragma once
#include "Forme.h"
#include <string>

using namespace std;

// Classe abstraite Loader
class Loader {
public:
    virtual Forme* Load(string fichier)const = 0;
};
