#include <iostream>
#include <vector>
#include <algorithm>
#include "ScopedTimer.hpp"

std::vector<int> generate_random_vector(size_t const size, int const max = 100)
{
    std::vector<int> vec(size);
    std::generate(vec.begin(), vec.end(), [&max]()
                  { return std::rand() % max; });
    return vec;
}

template <typename T>
void afficher_vec(std::vector<T> const &vec)
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

bool is_sorted(std::vector<int> const &vec)
{
    return std::is_sorted(vec.begin(), vec.end()); //dit si le tableau est trié ou non
}

//std::swap(a,b)
void bubble_sort(std::vector<int> &vec)
{
    {
        ScopedTimer timer("chrono bubble sort");
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
    }
}

// int search(std::vector<int> const vec, int const valeur_recherche)
// {
//     int left{0};
//     std::size_t right{vec.size()};
//     int middle{(left + static_cast<int>(right)) / 2};
//     int compteur{0}; //servira à savoir si la valeur recherchée est dans le tableau ou non

//     if (valeur_recherche <= vec[middle])
//     {
//         right = middle; //on definit cette partie de tableau comme commencant à left et terminant à middle. Pour plus de lisibilité on va appele middle : right
//         for (int i{left}; i <= right; i++)
//         {
//             if (vec[i] == valeur_recherche)
//             {
//                 return i;
//             }
//             else
//             {
//                 compteur += 1;
//             }
//         }
//         if (compteur == right)
//         {
//             return -1;
//         }
//     }
//     if (valeur_recherche > vec[middle])
//     {
//         left = middle + 1; //pour plus de lisibilité on dit que cette partie du tableau commence à middle. Donc left prend la valeur middle +1 et elle se finit à right.
//         for (int i{left}; i <= right; i++)
//         {
//             if (vec[i] == valeur_recherche)
//             {
//                 return i;
//             }
//             else
//             {
//                 compteur += 1;
//             }
//         }
//         if (compteur == right - left)
//         {
//             return -1;
//         }
//     }
// }

// int search(std::vector<int> vec, int const valeur_recherche)
// {
//     int left{0};
//     std::size_t right{vec.size()};
//     int middle{(left + static_cast<int>(right)) / 2};

//     int tour{0};
//     std::vector<int> new_vec{};
//     bool nb_trouve{true};

//     while (!nb_trouve)
//     {
//         if (valeur_recherche == vec[middle])
//         {
//             nb_trouve;
//             // std::cout << middle << std::endl;
//             return middle;
//         }

//         else if (valeur_recherche < vec[middle])
//         {
//             while (tour < vec.size() / 2)
//             {
//                 vec.pop_back();
//                 tour++;
//             }
//             right = vec.size();
//             middle = (left + static_cast<int>(right)) / 2;
//             continue;
//         }

//         else if (valeur_recherche > vec[middle])
//         {
//             for (int i{static_cast<int>(right) + 1}; i <= vec.size(); i++)
//             {
//                 new_vec.push_back(vec[i]);
//             }
//             vec.clear();
//             vec = new_vec;
//             new_vec.clear();
//             // right = vec.size(); //je sais pas si on ne met pas cette ligne si middle prend la nouvelle valeur de right ou pas. Au cas ou je réinitialise la valuer de right ici
//             middle = (left + static_cast<int>(right)) / 2;

//             continue;
//         }
//         if (middle < 0)
//         {
//             break;
//         }
//     }
// }

// std::ostream &operator<<(std::ostream &os, std::vector<float> const &vector)
// {
//     for (size_t i = 0; i < vector.size() - 1; i++)
//     {
//         os << vector[i];
//     }
//     os << vector[vector.size() - 1] ;
//     return os;
// }

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

    // Tant que nous avons pas parcouru tout les éléments d'au moins une des deux sous-parties
    while (left_index < left_size && right_index < right_size)
    {
        // On compare les éléments des deux sous-parties et on place le plus petit dans le vecteur original
        // on met à jour les index pour parcourir les sous-parties en conséquence
        if (left_vec[left_index] <= right_vec[right_index])
        {
            vec[left_index + right_index] = left_vec[left_index]; //vec[index] = left_vec[left_index]; /* TODO */
            left_index++;
        }
        else
        {
            vec[left_index + right_index] = right_vec[right_index]; //vec[index] = right_vec[right_index]; /* TODO */
            right_index++;
        }
    }

    // S'il reste des éléments dans une des deux sous-parties, on les place dans le vecteur original
    while (left_index < left_size)
    {
        /* TODO */
        vec[left_index + right_index] = left_vec[left_index];
        left_index++;
    }
    while (right_index < right_size)
    {
        vec[left_index + right_index] = right_vec[right_index];
        right_index++;
    }
}

void merge_sort(std::vector<float> &vec, size_t const left, size_t const right)
{

    if (left >= right)
    {
        // std::cout << "error" << std::endl;
        return;
    }
    // 1. Choix de l'index au milieu de la partition
    std::size_t middle{(left + right) / 2};
    // 2. Appels récursifs sur les deux sous-parties
    merge_sort(vec, left, middle - 1);
    merge_sort(vec, middle, right);
    // 3. Fusion des deux sous-parties
    merge_sort_merge(vec, left, middle, right);
}

// Même mécanisme que pour le tri rapide
//on la place en dessous de l'autre fonction sinon il y a pb avec le nb de parametre
void merge_sort(std::vector<float> &vec)
{
    merge_sort(vec, 0, vec.size() - 1);
}

int main()
{
    //BUBBLE SORT
    std::vector<int> array{10, 2, 13, 7, 3, 6, 7, 1, 9};
    afficher_vec(array);

    if (!(is_sorted(array)))
    {
        bubble_sort(array);
    }
    afficher_vec(array);

    // // DICHOTOMIE
    // std::vector<int> const vec1{1, 2, 2, 3, 4, 8, 12};
    // std::vector<int> const vec2{1, 2, 3, 3, 6, 14, 12, 15};
    // std::vector<int> const vec3{2, 2, 3, 4, 5, 8, 12, 15, 16};
    // std::vector<int> const vec4{5, 6, 7, 8, 9, 10, 11, 12, 13};
    // std::vector<int> const vec5{1, 2, 3, 4, 5, 6, 7, 8, 9};
    // //est ce que ca marhce de mettre search({1, 2, 2, 3, 4, 8, 12}, 8); ?
    // std::cout << "vec 1 : " << search(vec1, 8) << std::endl;
    // std::cout << "vec 2 : " << search(vec5, 15) << std::endl;
    // std::cout << "vec 3 : " << search(vec3, 16) << std::endl;
    // std::cout << "vec 4 : " << search(vec3, 6) << std::endl;
    // std::cout << "vec 5 : " << search(vec4, 10) << std::endl;
    std::vector<float> vec1{1.f, 3.f, 7.f, 3.f, 4.f, 8.f, 12.f};
    std::cout << "vec 1 : ";
    afficher_vec(vec1);
    merge_sort(vec1);
    std::cout << "vec 1 trie : ";
    afficher_vec(vec1);
}

//     if (is_sorted(array))
//     {
//         std::cout << "Le tableau est trie" << std::endl;
//     }

//     else
//     {
//         std::cout << "Le tableau n est pas trie" << std::endl;
//     }
//     return 0;
// }
