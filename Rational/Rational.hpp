#pragma once

#include <Polynomial.hpp>

class Rational
{
  public:
    Rational();
    Rational(const Polynomial &nom, const Polynomial &denom);
    void Print() const;
    const Polynomial &GetNom() const;
    const Polynomial &GetDenom() const;

  private:
    Polynomial _nom;
    Polynomial _denom;
};

std::ostream &operator<<(std::ostream &os, const Rational &rational);
