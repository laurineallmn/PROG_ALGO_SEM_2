#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <numeric>

//l'exercice 1 se situe dans le main.cpp

///EX 2
//QUESITON 1
auto const is_space = [](char letter)
{ return letter == ' '; };

int nb_lettre_premier_mot(std::string const &phrase)
{
    int nb_lettre{};
    std::string::const_iterator premiere_lettre{std::find_if_not(phrase.begin(), phrase.end(), is_space)};
    std::string::const_iterator expace{std::find_if(premiere_lettre, phrase.end(), is_space)};

    nb_lettre = std::distance(premiere_lettre, expace);

    return nb_lettre;
}
//QUESITON 2
std::vector<std::string> split_string(std::string const &str)
{

    auto premiere_lettre{str.begin()};
    auto derniere_lettre{std::find_if(premiere_lettre, str.end(), is_space)};
    std::vector<std::string> vecteur_mots{};

    while (derniere_lettre != str.end())
    {
        vecteur_mots.push_back(std::string(premiere_lettre, derniere_lettre));
        premiere_lettre = derniere_lettre + 1; //la premiere lettre devient la premiere lettre du mot suivant (apres l'espace => derniere_lettre+1)
        derniere_lettre = std::find_if(premiere_lettre, str.end(), is_space);
    }

    return vecteur_mots;
}

int main()
{

    // QUSTION 1
    std::string phrase1{"Salut comment ca va ?"};
    std::string phrase2{"anticonstitutionellement cool"};

    std::cout << "la phrase : " << phrase1 << " contient " << nb_lettre_premier_mot(phrase1) << "lettres" << std::endl;
    std::cout << "la phrase : " << phrase2 << " contient " << nb_lettre_premier_mot(phrase2) << "lettres" << std::endl;

    //////QUESITON 2
    std::cout << "la phrase : " << phrase1 << " contient les mots : " << std::endl;
    for (std::string mot : split_string(phrase1))
    {
        std::cout << mot << ", ";
    }
    std::cout << std::endl;
}
