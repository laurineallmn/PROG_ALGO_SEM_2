#include <iostream>
#include "fraction.hpp"

int main()
{
    Fraction f1{3, 4};
    Fraction f2{1, 2};

    std::cout << "f1 = ";
    // f1.display();
    std::cout << f1; // on appelle l'opérateur <<

    std::cout << " f2 = ";
    // f2.display();
    std::cout << f2;
    std::cout << std::endl;

    // Fraction f3 { add(f1, f2) };
    Fraction f3{f1 + f2};

    std::cout << "add(f1, f2) = ";
    // f3.display;
    std::cout << f3.numerator << f3.denominator;

    Fraction f4{f1 - f2};
    std::cout << std::endl
              << "sub(f1, f2) = ";
    // (sub(f1, f2)).display();
    std::cout << f4.denominator << f4.numerator;

    Fraction f5{f1 * f2};
    std::cout << std::endl
              << "mul(f1, f2) = ";
    // (mul(f1, f2)).display();
    std::cout << f5.denominator << f5.numerator;

    Fraction f6{f1 / f2};
    std::cout << std::endl
              << "div(f1, f2) = ";
    // (div(f1, f2)).display();
    std::cout << f6.denominator << f6.numerator;

    // Fraction f7{{1, 6} + {2, 6}};
    // std::cout << std::endl
    //           << "add(1/6, 2/6) = ";
    // (add({1, 6}, {2, 6})).display();
    // f7.denominator << f7.numerator;

    return 0;
}