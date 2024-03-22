#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include "ScopedTimer.hpp"

//NE TRIE QUE LE DEBUT DU TABLEAU JE SAIS PAS PK

// template <typename T>
void afficher_vec_int(std::vector<int> const &vec)
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

void afficher_vec_float(std::vector<float> const &vec)
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
    return std::is_sorted(vec.begin(), vec.end());
}

////////// BUBBLE SORT ////////////////
void bubble_sort(std::vector<int> &vec)
{
    // {
    // ScopedTimer timer("chrono bubble sort");
    // code à chronométrer

    std::cout << "Tableau trie :" << std::endl;
    while (!(is_sorted(vec)))
    {
        for (std::size_t i{0}; i < vec.size() - 1; i++)
        {
            if (vec[i] >= vec[i + 1])
            {
                std::swap(vec[i], vec[i + 1]);
            }
        }
    }
    // }
}

////////  MERGE SORT ////////

void merge_sort_merge(std::vector<float> &vec, size_t const left, size_t const middle, size_t const right)
{
    // On crée deux vecteurs temporaires pour stocker les copies des deux sous-parties à fusionner
    size_t const left_size{middle - left + 1};
    size_t const right_size{right - middle};
    std::vector<float> left_vec(vec.begin() + left, vec.begin() + middle + 1);
    std::vector<float> right_vec(vec.begin() + middle + 1, vec.begin() + right + 1);

    // Deux index pour parcourir les deux sous-parties et remplir le vecteur original
    size_t left_index{0};
    size_t right_index{0};

    size_t index{left};

    // Tant que nous avons pas parcouru tous les éléments d'au moins une des deux sous-parties
    while (left_index < left_size && right_index < right_size)
    {
        // On compare les éléments des deux sous-parties et on place le plus petit dans le vecteur original
        // on met à jour les index pour parcourir les sous-parties en conséquence
        if (left_vec[left_index] <= right_vec[right_index])
        {
            vec[index] = left_vec[left_index]; //vec[left_index + right_index] = left_vec[left_index];
            left_index++;
        }
        else
        {
            vec[index] = right_vec[right_index]; //vec[left_index + right_index] = right_vec[right_index];
            right_index++;
        }
        index++;
    }

    // S'il reste des éléments dans une des deux sous-parties, on les place dans le vecteur original
    while (left_index < left_size)
    {
        vec[index] = left_vec[left_index];
        left_index++;
    }
    while (right_index < right_size)
    {
        vec[index] = right_vec[right_index];
        right_index++;
    }
}

void merge_sort(std::vector<float> &vec, size_t const left, size_t const right)
{
    if (left >= right)
    {
        return;
        // std::cout << "error" << std::endl;
    }
    // 1. Choix de l'index au milieu de la partition
    size_t const middle = (left + right) / 2;
    // 2. Appels récursifs sur les deux sous-parties
    merge_sort(vec, left, middle - 1);
    merge_sort(vec, middle + 1, right);
    // 3. Fusion des deux sous-parties
    merge_sort_merge(vec, left, middle, right);
}

// Même mécanisme que pour le tri rapide
void merge_sort(std::vector<float> &vec)
{
    merge_sort(vec, 0, vec.size() - 1);
}

/////////  DICHOTOMIE  /////////
int search(std::vector<int> vec, int const valeur_cherche)
{
    bool trouve{false};
    int left{0};
    std::size_t right{vec.size() - 1}; //std::size_t
    int middle{(left + static_cast<int>(right)) / 2};
    if (is_sorted(vec))
    {
        while (trouve == false)
        {
            if (vec[middle] == valeur_cherche)
            {
                trouve = true;
                return middle;
            }
            else if (vec[middle] < valeur_cherche)
            {
                left = middle + 1;
            }
            else if (vec[middle] > valeur_cherche)
            {
                right = middle - 1;
            }
            middle = (left + right) / 2;
        }
    }
    if (trouve == false)
    {
        return 1000000; //erreur 1000000 = valeur pas trouve
    }
    else
    {
        return 20000000; //erreur 20000000 = tableau pas trie
    }
}

int main()
{
    //BUBBLE SORT
    std::vector<int> array{10, 2, 13, 7, 3, 6, 7, 1, 9};
    std::cout << "--- BUBBLE SORT ---" << std::endl;
    std::cout << "array : ";
    afficher_vec_int(array);

    if (!(is_sorted(array)))
    {
        bubble_sort(array);
    }
    afficher_vec_int(array);

    {
        ScopedTimer timer("chrono bubble sort array");
        std::vector<int> array{10, 2, 13, 7, 3, 6, 7, 1, 9};
        bubble_sort(array);
    }
    //pourquoi le temps calculer par le chrno est si different si on met ScopedTimer dans la fonction bubble ou dans le main ?
    //dans la focntion bubble = 0.114, dans le main = 0.8049ms

    //MERGE SORT

    std::cout << "--- MERGE SORT ---" << std::endl;

    std::vector<float> vec1{1.f, 3.f, 7.f, 3.f, 4.f, 8.f, 12.f};
    std::cout << "vec 1 : ";
    afficher_vec_float(vec1);
    merge_sort(vec1);
    std::cout << "vec 1 trie : ";
    afficher_vec_float(vec1);

    std::vector<float> vec2{1, 6, 4, 15, 3, 7, 12};
    std::cout << "vec 2 : ";
    afficher_vec_float(vec2);
    merge_sort(vec2);
    std::cout << "vec 2 trie : ";
    afficher_vec_float(vec2);

    {
        ScopedTimer timer("chrono merge sort vec 2");
        std::vector<float> vec2{1, 6, 4, 15, 3, 7, 12};
        merge_sort(vec2);
    }

    //STD::SORT
    std::cout << "--- STD::SORT ---" << std::endl;

    {
        ScopedTimer timer("chrono std::sort (bibliotheque standard");
        std::vector<int> array{1, 15, 7, 4, 5, 3, 9, 8, 2};
        std::sort(array.begin(), array.end());
    }

    //DICHOTOMIE
    std::cout << "--- DICHOTOMIE ---" << std::endl;

    std::vector<int> vec{1, 3, 6, 8, 10, 32};
    int valeur_cherche{10};
    std::cout << "le tableau : ";
    afficher_vec_int(vec);
    std::cout << "la valeur recherchee : " << valeur_cherche << std::endl;
    std::cout << "L'indice de la valeur recherchee dans le tableau est : ";
    std::cout << search(vec, valeur_cherche) << std::endl;

    return 0;
}
