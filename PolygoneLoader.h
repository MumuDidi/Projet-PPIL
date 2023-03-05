#pragma once
#include "Loader_COR.h"

// Chargeur de PolygonesFraction
class PolygoneLoader : public Loader_COR
{
public:
	PolygoneLoader(Loader_COR* suivant);
	Forme* Transform(string line) const;

};