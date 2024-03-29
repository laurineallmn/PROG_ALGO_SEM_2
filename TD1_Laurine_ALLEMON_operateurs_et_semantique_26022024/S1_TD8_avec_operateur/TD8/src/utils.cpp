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

// simplify pour ne pas retourner une nouvelle fraction mais direct pour avoir la fraction simplifiée et la retourné
void simplify_itself(Fraction &f)
{
    unsigned int divisor{gcd(f.numerator, f.denominator)};
    f.numerator = f.numerator / divisor;
    f.denominator = f.denominator / divisor;
}