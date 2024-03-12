#include "utils.hpp"

unsigned int gcd(unsigned int a, unsigned int b)
{
    while (b != 0)
    {
        unsigned int modulo{a % b};
        a = b;
        b = modulo;
    }

    return a;
}
// recursive version
// unsigned int gcd(unsigned int a, unsigned int b) {
//     if (b == 0) {
//         return a;
//     }
//
//     return gcd(b, a % b);
// }
// ternary operator version
// unsigned int gcd(unsigned int a, unsigned int b) {
//     return b == 0 ? a : gcd(b, a % b);
// }

// Fraction simplify(Fraction const &f1)
// {
//     unsigned int divisorf1{gcd(f1.numerator, f1.denominator)};
//     return
//     {
//         f1.numerator / divisorf1,
//             f1.denominator / divisorf1
//     }
// }

Fraction simplify(Fraction const &f)
{
    unsigned int divisor{gcd(f.numerator, f.denominator)};
    return {f.numerator / divisor, f.denominator / divisor};
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
    //ou f1-f2<0
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