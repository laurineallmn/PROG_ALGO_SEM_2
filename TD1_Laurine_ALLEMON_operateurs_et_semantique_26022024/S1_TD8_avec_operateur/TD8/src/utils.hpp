#pragma once

#include "fraction.hpp"

unsigned int gcd(unsigned int a, unsigned int b);
Fraction simplify(Fraction const &f);
// Fraction simplify(Fraction const& f);

void simplify_itself(Fraction &f);