#pragma once

#include <cstddef>
#include <ostream>

class Polynomial
{
    friend std::ostream &operator<<(std::ostream &os, const Polynomial &polynomial);

  public:
    Polynomial(const std::size_t degree = 0);
    Polynomial(const double *const coefficients, const std::size_t degree);
    Polynomial(const Polynomial& polynomial);
    ~Polynomial();

    std::size_t GetDegree(const bool real) const;
    void SetCoeff(const std::size_t degree, const double coefficient);

    static std::size_t GetMaxDegree();

  private:
    static std::size_t s_maxDegree;
    double *_coefficients{nullptr};
    const std::size_t _degree{0};
};
