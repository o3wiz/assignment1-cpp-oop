#include "Polynomial.hpp"
#include "Rational.hpp"
#include <iostream>

using namespace std;

void testPolynomial()
{
    cout << "----- start testPolynomial ---------" << endl;
    cout << "test0 :" << Polynomial::GetMaxDegree() << endl;
    Polynomial p1;
    cout << "test1: " << p1;
    Polynomial p2(6);
    p2.SetCoeff(2, 0.4);
    cout << "test2: " << p2 << "degree=" << p2.GetDegree(false) << endl;
    double c[5] = {0.1, 0.2, 0, 11.5, 1.3};
    Polynomial p3(c, 4);
    cout << "test3: " << p3;
    p2.SetCoeff(2, 0.0);
    cout << "test4: " << p2;
    cout << "test6 :maxDegree = " << Polynomial::GetMaxDegree() << endl;
    cout << "______________" << endl;
}
void testRational()
{
    cout << "----- start testRational ---------" << endl;
    cout << "test7" << endl;
    Rational r1;
    r1.Print();
    cout << r1;
    double c[] = {0, 2, 2, 3, 4, 5};
    Polynomial p1(c, 5);
    c[0] = 1.2;
    Polynomial p2(c, 3);
    Rational r2(p1, p2);
    cout << "test8" << endl;
    r2.Print();
    cout << endl << r2 << endl;
    cout << "test9" << endl;
    cout << "nom = " << r2.GetNom();
    cout << "denom = " << r2.GetDenom();

    cout << "test10 :maxDegree = " << Polynomial::GetMaxDegree() << endl;
    cout << "__________________________" << endl;
}

int main()
{
    testPolynomial();
    testRational();
}
