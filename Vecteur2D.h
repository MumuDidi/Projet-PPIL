#pragma once

#include <sstream>
#include <iostream>
#include <string>

using namespace std;

template <class T>
inline const T operator - (const T& u, const T& v)
{
	return u + -v;
}



class Vecteur2D
{
public:
	double x, y;

	inline explicit Vecteur2D(const double& x = 0, const double& y = 0);

	/**
	 * DONNEES : s respectant le format "(  nombre r�el, nombre r�el)"
	 *
	 * */
	//inline Vecteur2D(const char* s);
	const Vecteur2D operator + (const Vecteur2D& u) const;
	inline const Vecteur2D operator * (const double& a) const;
	/**
	 * - unaire (c'est-�- dire oppos� d'un vecteur)
	 * */
	const Vecteur2D operator - () const;
	const double prodVect(const Vecteur2D& u) const;
	const double norme() const;
	//Translation : Une translation est définie par un vecteur de translation (dx, dy).
	void Translate(const double& dx, const double& dy);
	//Homothétie : Une homothétie est définie par un point invariant (le centre de l'homothétie) et par un coefficient k > 0.
	void homothetie(const double& k, const Vecteur2D& centre);
	//Rotation : Une rotation est définie par un point invariant (le centre de la rotation) et par un angle signé donné en radians.
	void rotation(const double& angle, const Vecteur2D& centre);
}; // classe Vecteur2D

inline const Vecteur2D operator *(const double& a, const Vecteur2D& u) { return u * a; }
inline std::ostream& operator<<(std::ostream& os, const Vecteur2D& v)
{
	os << "(" << v.x << ", " << v.y << ")";
	return os;
}