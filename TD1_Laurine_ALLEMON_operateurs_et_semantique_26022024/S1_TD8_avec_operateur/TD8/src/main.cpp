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
    std::cout << f3.numerator << "/" << f3.denominator;

    Fraction f4{f1 - f2};
    std::cout << std::endl;
    std::cout << "sub(f1, f2) = ";
    // (sub(f1, f2)).display();
    std::cout << f4.numerator << "/" << f4.denominator;

    Fraction f5{f1 * f2};
    std::cout << std::endl;
    std::cout << "mul(f1, f2) = ";
    // (mul(f1, f2)).display();
    std::cout << f5.numerator << "/" << f5.denominator;

    Fraction f6{f1 / f2};
    std::cout << std::endl;
    std::cout << "div(f1, f2) = ";
    // (div(f1, f2)).display();
    std::cout << f6.numerator << "/" << f6.denominator;
    std::cout << std::endl;

    // Fraction f7{{1, 6} + {2, 6}};
    // std::cout << std::endl
    //           << "add(1/6, 2/6) = ";
    // (add({1, 6}, {2, 6})).display();
    // f7.denominator << f7.numerator;

    std::cout << (f2 < f1) << std::endl; //c censé être vrai
    std::cout << (f6 < f1) << std::endl;
    std::cout << f2.to_float() << std::endl; //comme to_float est une methode, on fait f2.to_float et pas fraction::to_float(f2);

    return 0;
}