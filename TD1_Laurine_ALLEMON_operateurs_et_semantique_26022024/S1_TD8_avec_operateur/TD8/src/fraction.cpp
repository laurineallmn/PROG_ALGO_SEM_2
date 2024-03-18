#include "fraction.hpp"
#include "utils.hpp"

#include <iostream>

// void Fraction::display()
// {
//     std::cout << numerator << "/" << denominator;
// }

//ON ENELEVE LE "const" ET LE "&" DE f1 CAR IL FAUT QU4IL SOIT MODIFIABLE
//COMME ON LUI AJOUTE UNE VALEUR ET "&" CAR COMME CA ON A UNE COPIE ET
//ON NE MODIFIE PAS DIRECTEMENT f1
Fraction operator+(Fraction f1, Fraction const &f2)
{
    f1 += f2;
    return f1;
}
// Fraction operator+(Fraction const &f1, Fraction const &f2)
// {
//     return simplify({f1.numerator * f2.denominator + f2.numerator * f1.denominator,
//                      f1.denominator * f2.denominator});
// }

Fraction operator-(Fraction f1, Fraction const &f2)
{
    f1 -= f2;
    return f1;
}
// Fraction operator-(Fraction const &f1, Fraction const &f2)
// {
//     return simplify({f1.numerator * f2.denominator - f2.numerator * f1.denominator,
//                      f1.denominator * f2.denominator});
//     // Fraction f;
//     // f.numerator = f1.numerator * f2.denominator - f2.numerator * f1.denominator;
//     // f.denominator = f1.denominator * f2.denominator;
//     // return simplify(f);
// }

Fraction operator*(Fraction f1, Fraction const &f2)
{
    f1 *= f2;
    return f1;
}
// Fraction operator*(Fraction const &f1, Fraction const &f2)
// {
//     return simplify({f1.numerator * f2.numerator,
//                      f1.denominator * f2.denominator});
// }

Fraction operator/(Fraction f1, Fraction const &f2)
{
    f1 /= f2;
    return f1;
}

// Fraction operator/(Fraction const &f1, Fraction const &f2)
// {
//     return simplify({f1.numerator / f2.denominator,
//                      f1.denominator / f2.numerator});
// }

Fraction &Fraction::operator+=(Fraction const &f2)
{
    numerator = numerator * f2.denominator + f2.numerator * denominator;
    denominator = denominator * f2.denominator;

    simplify_itself(*this); //on simplifie tout mais on ne retourne rien
    return *this;
}

Fraction &Fraction::operator-=(Fraction const &f2)
{
    numerator = numerator * f2.denominator - f2.numerator * denominator;
    denominator = denominator * f2.denominator;

    simplify_itself(*this);
    return *this;
}

Fraction &Fraction::operator*=(Fraction const &f2)
{
    numerator *= f2.numerator;
    denominator *= f2.denominator;

    simplify_itself(*this);
    return *this;
}

Fraction &Fraction::operator/=(Fraction const &f2)
{
    numerator /= f2.numerator;
    denominator /= f2.denominator;

    simplify_itself(*this);
    return *this;
}

std::ostream &operator<<(std::ostream &os, Fraction &f)
{
    return os << f.numerator << " / " << f.denominator;
}

//ATTENTION C'EST "bool" et pas "Fraction" car le contenu est une test
bool operator==(Fraction const &f1, Fraction const &f2)
{
    simplify(f1); //est ce qu'il faut mettre une epserluette ici ?
    simplify(f2); //est ce qu'il faut mettre une epserluette ici ?

    return f1.denominator == f2.denominator && f1.numerator == f2.numerator;
}

bool operator!=(Fraction const &f1, Fraction const &f2)
{
    return !(f1 == f2);
}

bool operator<(Fraction const &f1, Fraction const &f2)
{
    simplify(f1); //est ce qu'il faut mettre une epserluette ici ?
    simplify(f2);
    return f1.numerator < f2.numerator && f1.denominator >= f2.denominator;
}

bool operator<=(Fraction const &f1, Fraction const &f2)
{

    return (f1 < f2) || (f1 == f2);
}

bool operator>(Fraction const &f1, Fraction const &f2)
{
    return !(f1 < f2);
}

bool operator>=(Fraction const &f1, Fraction const &f2)
{
    return !(f1 < f2) || (f1 == f2);
}
