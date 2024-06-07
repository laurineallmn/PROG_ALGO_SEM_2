#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <cstdlib>

////////////////////////////////////////////////:
/////////////////  EX 2  //////////////////////:
////////////////////////////////////////////////:

std::string random_name(size_t size)
{
    std::string name{""};
    // Optimisation pour que la chaîne de caractère ne réalloue pas de la mémoire à chaque caractère ajouté
    // https://cplusplus.com/reference/string/string/reserve/
    name.reserve(size);
    for (size_t i{0}; i < size; ++i)
    {
        name.push_back('A' + std::rand() % 26);
    }
    return name;
}

std::vector<std::pair<std::string, float>> get_robots_fix(size_t size)
{
    std::vector<std::pair<std::string, float>> robots_fix{};
    // Meme optimisation que dans random_name()
    // https://cplusplus.com/reference/vector/vector/reserve/
    robots_fix.reserve(size);
    for (size_t i{0}; i < size; ++i)
    {
        // random name
        std::string robotName{random_name(2)};
        // random cost
        float cost{static_cast<float>(std::rand()) / RAND_MAX * 1000.0f};
        robots_fix.push_back(std::make_pair(robotName, cost));
    }
    return robots_fix;
}

//////// QUESTION 1 //////////:

std::unordered_map<std::string, std::vector<float>> robots_fixes_map(std::vector<std::pair<std::string, float>> const &robots_fixes)
{
    std::unordered_map<std::string, std::vector<float>> map1;
    for (int i = 0; i < robots_fixes.size(); i++)
    {
        map1[robots_fixes[i].first].push_back(robots_fixes[i].second);
    }
    return map1;
};

//////// QUESTION 2 //////////:
float somme(std::vector<float> vec)
{
    float somme_valeurs{0.f};
    for (int i{0}; i < vec.size(); i++)
    {
        somme_valeurs += vec[i];
    }
    return somme_valeurs;
}

////////////////////////////////////////////////:

int main()
{
    std::vector<std::pair<std::string, float>> robots_fixes{get_robots_fix(100)};
    std::unordered_map<std::string, std::vector<float>> map2{robots_fixes_map(robots_fixes)};

    //////QUESTION 3
    for (std::pair<std::string, std::vector<float>> pair : map2)
    {
        std::cout << "La somme des réparations du robot " << pair.first << " est : "; //on récupère le nom du robot
        for (float cost : pair.second)                                                //on récupere tous les couts de reparation pour chaque robot
        {
            std::cout << cost << " + ";
        }
        // Somme des cout de réparations
        std::cout << " = " << somme(pair.second) << std::endl;
    }
    return 0;
}
