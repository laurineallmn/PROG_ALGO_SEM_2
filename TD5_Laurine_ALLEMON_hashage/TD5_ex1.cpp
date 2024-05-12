// #include <iostream>
// #include <vector>
// #include <string>

///////////////// TD5 ///////////

#include <iostream>
#include <vector>
#include <string>

//EXERCICE 1

//QUESTION 1
size_t folding_string_hash(std::string const &chaine, size_t max)
{
    int somme{};
    size_t resultat{};
    int coeff{};
    for (size_t i{0}; i < chaine.size(); i++)
    {
        std::cout << chaine[i] << " a pour valeur ascii : " << static_cast<int>(chaine[i]) << std::endl;
        somme += static_cast<int>(chaine[i]);
    }

    if (somme > max)
    {
        coeff = somme / max;
        resultat = somme - (coeff * max);
        std::cout << "En appliquant le modulo par rapport à \"max\" sur la somme, on obtient une somme egale a : ";
        return resultat;
    }
    else
    {
        resultat = somme;
        std::cout << "La somme de toutes les valeurs ascii est : ";
        return resultat;
    }
}

int main()
{
    std::string const &mot{"bonjour"};
    // size_t max{mot.size()};
    std::cout << folding_string_hash(mot, 1024);

    return 0;
}

//QUESITON 2
// size_t folding_string_ordered_hash(std::string const &s, size_t max);