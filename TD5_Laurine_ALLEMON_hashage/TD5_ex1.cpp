// // #include <iostream>
// // #include <vector>
// // #include <string>

// ///////////////// TD5 ///////////

// EXERCICE 1
// QUESTION 1
size_t folding_string_hash(std::string const &chaine, size_t max)
{
    int somme{};
    size_t resultat{};
    int coeff{};
    std::cout << std::endl;

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
        std::cout << "---- La somme de toutes les valeurs ascii est : ";
        return resultat;
    }
}

// QUESTION 2
size_t folding_string_ordered_hash(std::string const &chaine, size_t max)
{
    int somme{};
    size_t resultat{};
    int coeff{};
    std::cout << std::endl;

    for (size_t i{0}; i < chaine.size(); i++)
    {
        int mult{static_cast<int>(chaine[i]) * static_cast<int>(i)};
        std::cout << chaine[i] << " a pour valeur ascii : " << static_cast<int>(chaine[i]) << std::endl;
        std::cout << "on multiplie la valeur ascii par sa position dans la chaine de caractere, ce qui donne : " << mult << std::endl;
        somme += mult;
    }

    if (somme > max)
    {
        coeff = somme / max;
        resultat = somme - (coeff * max);
        std::cout << " ---- En appliquant le modulo par rapport a \"max\" sur la somme, on obtient une somme egale a : ";
        return resultat;
    }
    else
    {
        resultat = somme;
        std::cout << " ---- La somme de toutes les valeurs ascii est : ";
        return resultat;
    }
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

    return 0;
}