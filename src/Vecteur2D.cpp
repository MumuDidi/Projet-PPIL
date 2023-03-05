#include "Vecteur2D.h"
#include <cmath>
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

void Vecteur2D::Translate(const double& dx, const double& dy)
{
	x += dx;
	y += dy;
}

void Vecteur2D::homothetie(const double& k, const Vecteur2D& centre)
{
	x = centre.x + k * (x - centre.x);
	y = centre.y + k * (y - centre.y);
}

void Vecteur2D::rotation(const double& angle, const Vecteur2D& centre)
{
	double x1 = x - centre.x;
	double y1 = y - centre.y;
	x = centre.x + x1 * cos(angle) - y1 * sin(angle);
	y = centre.y + x1 * sin(angle) + y1 * cos(angle);
}