#pragma once
#include "Loader_COR.h"

// Chargeur de triangles
class TriangleLoader : public Loader_COR
{
public:
	TriangleLoader(Loader_COR* suivant);
	Forme* Transform(string line) const;

};