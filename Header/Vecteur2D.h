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
	 * DONNEES : s respectant le format "(  nombre réel, nombre réel)"
	 *
	 * */
	//inline Vecteur2D(const char* s);
	const Vecteur2D operator + (const Vecteur2D& u) const;
	inline const Vecteur2D operator * (const double& a) const;
	/**
	 * - unaire (c'est-à- dire opposé d'un vecteur)
	 * */
	const Vecteur2D operator - () const;
	const double prodVect(const Vecteur2D& u) const;
	const double norme() const;
}; // classe Vecteur2D

inline const Vecteur2D operator *(const double& a, const Vecteur2D& u) { return u * a; }
inline std::ostream& operator<<(std::ostream& os, const Vecteur2D& v)
{
	os << "(" << v.x << ", " << v.y << ")";
	return os;
}