#include "Vecteur2D.h"
inline  Vecteur2D::Vecteur2D(const double& x, const double& y) : x(x), y(y) {}

const Vecteur2D Vecteur2D::operator + (const Vecteur2D& u) const
{
	return Vecteur2D(x + u.x, y + u.y);
}

const Vecteur2D Vecteur2D::operator * (const double& a) const
{
	return Vecteur2D(x * a, y * a);
}

const Vecteur2D Vecteur2D::operator - () const
{
	return Vecteur2D(-x, -y);
}

const double Vecteur2D::norme() const
{
	return std::sqrt(x * x + y * y);
}

const double Vecteur2D::prodVect(const Vecteur2D& u) const{
	return (u.x * y )- (u.y * x);
}
