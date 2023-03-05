#pragma once
#include "Loader_COR.h"

// Chargeur de SegmentsFraction
class SegmentLoader : public Loader_COR
{
public:
	SegmentLoader(Loader_COR* suivant);
	Forme* Transform(string line) const;

};