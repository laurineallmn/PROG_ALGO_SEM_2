#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <numeric>

//TD4
// EX 1 (l'ex 2 n'est pas dans le fichier main.cpp mais dans un fichier a part : td4_ex2.cpp)
void afficher_vec(std::vector<int> const &vec)
{
    for (std::size_t i{0}; i < vec.size(); i++)
    {
        if (i == vec.size() - 1) //si c'est la derniere valeur du tableau on n'affiche pas de virgule
        {
            std::cout << vec[i];
        }
        else
        {
            std::cout << vec[i] << ",";
        }
    }
    std::cout << std::endl;
}

std::vector<int> generate_random_vector(size_t const size, int const max = 100)
{
    std::vector<int> vec(size);
    std::generate(vec.begin(), vec.end(), [&max]()
                  { return std::rand() % max; });
    return vec;
}

bool is_sorted(std::vector<int> const &vec)
{
    return std::is_sorted(vec.begin(), vec.end()); //dit si le tableau est trié ou non
}

int main()
{

    int aleatoire{std::rand() % 100 + 1};
    int valeur_cherche{5};

    //affiche tout le temps le meme vecteur
    // std::vector<int> v{};
    // for (int i{}; i < 10; i++)
    // {
    //     v.push_back(aleatoire);
    // }

    //OU : appeler la fonction generate_random_vector
    std::vector<int> v{generate_random_vector(10)};

    //SORT
    std::sort(v.begin(), v.end());

    //AFFICHAGE DU VECTEUR
    for (auto it{v.begin()}; it < v.end(); it++)
    {
        std::cout << *it << ", ";
    }
    std::cout << std::endl;

    //FIND
    // auto it{std::find(v.begin(), v.end(), valeur_cherche)};

    // if (it != v.end())
    // {
    //     std::cout << "l'element " << valeur_cherche << " est bien dans le vecteur est a l'index : " << *it << std::endl;
    // }
    // else
    // {
    //     std::cout << "L'element n'a pas ete trouve" << std::endl;
    // }

    if (std::find(v.begin(), v.end(), valeur_cherche) != v.end())
    {
        std::cout << "l'element " << valeur_cherche << " est bien dans le vecteru " << std::endl;
    }
    else
    {
        std::cout << "L'element n'a pas ete trouve" << std::endl;
    }

    //COUNT

    std::cout << "La valeur " << valeur_cherche << " apparait " << std::count(v.begin(), v.end(), valeur_cherche) << " fois dans le vecteur" << std::endl;

    //ACCUMULATE
    std::cout << "la somme des valerus du vecteurs donne : " << std::accumulate(v.begin(), v.end(), 0) << std::endl;
}
