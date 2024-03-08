#include <iostream>
#include <vector>
#include <algorithm>
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

bool is_sorted(std::vector<int> const &vec)
{
    return std::is_sorted(vec.begin(), vec.end());
}

//std::swap(a,b)
void bubble_sort(std::vector<int> &vec)
{
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

int main()
{
    std::vector<int> array{10, 2, 13, 7, 3, 6, 7, 1, 9};
    afficher_vec(array);

    if (!(is_sorted(array)))
    {
        bubble_sort(array);
    }
    afficher_vec(array);
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
