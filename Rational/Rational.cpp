#include "Rational.hpp"

#include <iostream>

Rational::Rational()
{
    _denom.SetCoeff(0, 1.0);
}

Rational::Rational(const Polynomial &nom, const Polynomial &denom) : _nom(nom), _denom(denom)
{
}

void Rational::Print() const
{
    std::cout << *this;
}

const Polynomial &Rational::GetNom() const
{
    return _nom;
}

const Polynomial &Rational::GetDenom() const
{
    return _denom;
}

std::ostream &operator<<(std::ostream &os, const Rational &rational)
{
    os << rational.GetNom();
    os << "--------------------------\n";
    os << rational.GetDenom();
    return os;
}
