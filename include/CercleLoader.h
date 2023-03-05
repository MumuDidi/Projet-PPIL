#pragma once
#include "Loader_COR.h"

// Chargeur de CerclesFraction
class CercleLoader : public Loader_COR
{
public:
	CercleLoader(Loader_COR* suivant);
	Forme* Transform(string line) const;

};