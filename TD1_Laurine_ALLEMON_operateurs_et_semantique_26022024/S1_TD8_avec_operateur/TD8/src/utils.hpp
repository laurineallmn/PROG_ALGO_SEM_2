#pragma once

#include "fraction.hpp"

unsigned int gcd(unsigned int a, unsigned int b);
Fraction simplify(Fraction const &f);
// Fraction simplify(Fraction const& f);
bool operator==(Fraction const &f1, Fraction const &f2);
bool operator<(Fraction const &f1, Fraction const &f2);
bool operator<=(Fraction const &f1, Fraction const &f2);
bool operator>(Fraction const &f1, Fraction const &f2);
bool operator>=(Fraction const &f1, Fraction const &f2);
