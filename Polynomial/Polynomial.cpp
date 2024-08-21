#include "Polynomial.hpp"

#include <algorithm>
#include <cassert>
#include <cstring>
#include <format>

std::size_t Polynomial::s_maxDegree{0};

Polynomial::Polynomial(const std::size_t degree) : _degree(degree)
{
    _coefficients = new double[degree + 1]();
}

Polynomial::Polynomial(const double *const coefficients, const std::size_t degree) : Polynomial(degree)
{
    std::memcpy(_coefficients, coefficients, sizeof(double) * (_degree + 1));
    Polynomial::s_maxDegree = std::max(Polynomial::s_maxDegree, _degree);
}

Polynomial::Polynomial(const Polynomial &polynomial) : Polynomial(polynomial._coefficients, polynomial._degree)
{
}

Polynomial::~Polynomial()
{
    delete[] _coefficients;
    _coefficients = nullptr;
}

std::size_t Polynomial::GetDegree(const bool real) const
{
    if (!real)
        return _degree;
    for (std::size_t i{_degree}; i; --i)
    {
        if (_coefficients[i] != 0.0)
            return i;
    }
    return 0;
}

void Polynomial::SetCoeff(const std::size_t degree, const double coefficient)
{
    assert(degree <= this->GetDegree(false));
    _coefficients[degree] = coefficient;
    if (coefficient != 0.0 && degree > Polynomial::s_maxDegree)
        Polynomial::s_maxDegree = degree;
}

std::size_t Polynomial::GetMaxDegree()
{
    return Polynomial::s_maxDegree;
}

std::ostream &operator<<(std::ostream &os, const Polynomial &polynomial)
{
    os << "Polynomial = " << polynomial._coefficients[0];
    const std::size_t realDegree = polynomial.GetDegree(true);
    for (std::size_t i{1}; i <= realDegree; ++i)
    {
        os << std::format("+{}X^{}", polynomial._coefficients[i], i);
    }
    return os << std::endl;
}
