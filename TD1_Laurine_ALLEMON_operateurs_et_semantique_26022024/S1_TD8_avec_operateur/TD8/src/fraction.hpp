#pragma once
#include <iostream>

struct Fraction
{
    unsigned int numerator;
    unsigned int denominator;

    // void display();
    //on ne va modifié que la valeur de f1 car on lui ajoute directement f2 (=> f2 peut etre const)
    Fraction &operator+=(Fraction const &f2);
    Fraction &operator-=(Fraction const &f2);
    Fraction &operator*=(Fraction const &f2);
    Fraction &operator/=(Fraction const &f2);

    float to_float()
    {
        return static_cast<float>(numerator) / static_cast<float>(denominator);
        // return numerator / denominator;
    }
};

std::ostream &operator<<(std::ostream &os, Fraction &f);

// Fraction add(Fraction const &f1, Fraction const &f2);
// Fraction sub(Fraction const &f1, Fraction const &f2);
// Fraction mul(Fraction const &f1, Fraction const &f2);
// Fraction div(Fraction const &f1, Fraction const &f2);

Fraction operator+(Fraction f1, Fraction const &f2);
Fraction operator-(Fraction f1, Fraction const &f2);
Fraction operator*(Fraction f1, Fraction const &f2);
Fraction operator/(Fraction f1, Fraction const &f2);

std::ostream &operator<<(std::ostream &os, Fraction &f);

bool operator==(Fraction const &f1, Fraction const &f2);
bool operator<(Fraction const &f1, Fraction const &f2);
bool operator<=(Fraction const &f1, Fraction const &f2);
bool operator>(Fraction const &f1, Fraction const &f2);
bool operator>=(Fraction const &f1, Fraction const &f2);

// Fraction::operator float() const;