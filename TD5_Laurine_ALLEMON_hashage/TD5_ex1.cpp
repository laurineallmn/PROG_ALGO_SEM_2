#include <iostream>
#include <vector>
#include <string>

// ///////////////// TD5 ///////////

// EXERCICE 1
// QUESTION 1
size_t folding_string_hash(std::string const &chaine, size_t max)
{
    int somme{};
    std::cout << std::endl;

    for (size_t i{0}; i < chaine.size(); i++)
    {
        std::cout << chaine[i] << " a pour valeur ascii : " << static_cast<int>(chaine[i]) << std::endl;
        somme += static_cast<int>(chaine[i]);
    }
    std::cout << "En appliquant le modulo par rapport a \"max\" sur la somme, on obtient une somme egale a : ";
    return somme % max;
}

// QUESTION 2
size_t folding_string_ordered_hash(std::string const &chaine, size_t max)
{
    int somme{};
    std::cout << std::endl;

    for (size_t i{0}; i < chaine.size(); i++)
    {
        int mult{static_cast<int>(chaine[i]) * static_cast<int>(i)};
        std::cout << chaine[i] << " a pour valeur ascii : " << static_cast<int>(chaine[i]) << std::endl;
        std::cout << "on multiplie la valeur ascii par sa position dans la chaine de caractere, ce qui donne : " << mult << std::endl;
        somme += mult;
    }
    std::cout << " ---- En appliquant le modulo par rapport a \"max\" sur la somme, on obtient une somme egale a : ";
    return somme % max;
}

// QUESTION 3
size_t polynomial_rolling_hash(const std::string &s, size_t p, size_t m)
{
    size_t somme{0};
    size_t power{1};
    for (size_t i = 0; i < s.size(); i++)
    {
        somme += s[i] * power;
        power *= p;
    }
    return somme % m;
}

int main()
{
    std::string const &mot1{"salut"};
    std::string const &mot2{"bonjour"};
    std::string const &mot3{"jourbon"};

    std::cout << "__________________________________________________________________________" << std::endl;
    std::cout << "---------------  EX 1 -- quest 1 -- mot1 ------------" << std::endl;
    std::cout << "__________________________________________________________________________" << std::endl;
    std::cout << "POUR \"SALUT\" : " << folding_string_hash(mot1, 1024);
    std::cout << std::endl;

    std::cout << "__________________________________________________________________________" << std::endl;
    std::cout << "---------------  EX 1 -- quest 2 -- mot2 ------------" << std::endl;
    std::cout << "__________________________________________________________________________" << std::endl;
    std::cout << "POUR \"BONJOUR\" : " << folding_string_ordered_hash(mot2, 1024) << std::endl; //Le valeur hachée de \"bonjour\" est : "

    std::cout << "__________________________________________________________________________" << std::endl;
    std::cout << "--------------- EX 1 -- quest 2 -- mot3  --------------- " << std::endl;
    std::cout << "__________________________________________________________________________" << std::endl;
    std::cout << "POUR \"JOURBON\" : " << folding_string_ordered_hash(mot3, 1024) << std::endl; //Le valeur hachée de \"jourbon\" est : "

    std::cout << "__________________________________________________________________________" << std::endl;
    std::cout << "---------------  EX 1 -- quest 3 -- mot1 ------------" << std::endl;
    std::cout << "__________________________________________________________________________" << std::endl;
    std::cout << "POUR \"SALUT\" : " << polynomial_rolling_hash(mot1, 2, 1024) << std::endl;
    std::cout << "__________________________________________________________________________" << std::endl;
    std::cout << "---------------  EX 1 -- quest 3 -- mot2 ------------" << std::endl;
    std::cout << "__________________________________________________________________________" << std::endl;
    std::cout << "POUR \"BONJOUR\" : " << polynomial_rolling_hash(mot2, 2, 1024) << std::endl;
    std::cout << "__________________________________________________________________________" << std::endl;
    std::cout << "---------------  EX 1 -- quest 3 -- mot3 ------------" << std::endl;
    std::cout << "__________________________________________________________________________" << std::endl;
    std::cout << "POUR \"JOURBON\" : " << polynomial_rolling_hash(mot3, 2, 1024) << std::endl;
    return 0;
}