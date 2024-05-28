#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>

///////// TD8 ////////

// EX 1
/// QUEST 1
//est ce qu'il faut mettre un 1 devant une lettre unique ??
void encodage(std::string const code)
{
    std::string compress_code{};
    int compteur{0};
    for (int i{}; i < code.size(); i++)
    {
        if (code[i] == code[i + 1])
        {
            compteur += 1;
        }
        else if (code[i] != code[i + 1] && compteur != 0)
        {

            compress_code.push_back('0' + compteur); //on prend la valeur 0 du tableau ascii et on lui ajoute la valuer de compteur pour avoir
            compress_code.push_back(code[i]);
            compteur = 0;
        }
        else //if (code[i] != code[i + 1] && compteur == 0)
        {
            compteur = 0;
            compress_code.push_back(code[i]);
        }
    }
    std::cout << "le code compresse donne : " << compress_code << std::endl;
}

//QUEST2
void decodage(std::string const code)
{
    std::string code_decode{};
    for (int i{}; i < code.size(); i++)
    {
        // if (code[i] == "1" || code[i] == "2" || code[i] == "3" || code[i] == "4" || code[i] == "5" || code[i] == "6" || code[i] == "7" || code[i] == "8" || code[i] == "9")
        if (code[i] == 1 || code[i] == 2 || code[i] == 3 || code[i] == 4 || code[i] == 5 || code[i] == 6 || code[i] == 7 || code[i] == 8 || code[i] == 9)
        {
            for (int j{}; j < static_cast<int>(code[i]); j++)
            {
                code_decode.push_back(code[i + 1]);
            }
        }
        //COMMENT FAIRE POUR DEMANDE SI CEST UN STR OU UN INT ???
        // else if (code[i]) //Cas ou il n'y a pas de 1 avec la lettre
        // {
        // }
        else //
        {
            continue;
        }
    }
    std::cout << "Le code decode donne : " << code_decode << std::endl;
}

int main()
{
    std::string const code{"AABBBBJJLQQQQ"};
    std::cout << "le code de depart : " << code << std::endl;
    encodage(code);
    std::string const code_compresse{"2A3B2J1L4Q"};
    std::cout << "le code compresse de depart : " << code_compresse << std::endl;
    decodage(code_compresse);
}