#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <numeric>

bool palindrome(std::string const &str)
{
    return std::equal(str.begin(), str.end(), str.rbegin());
}

int main()
{
    std::string mot1{"nsiih"};
    std::string mot2{"lol"};
    if (palindrome(mot1))
    {
        std::cout << "Le mot : " << mot1 << " est un palindrome" << std::endl;
    }
    else
    {
        std::cout << "Le mot : " << mot1 << "n'est pas un palindrome" << std::endl;
    }
    if (palindrome(mot2))
    {
        std::cout << "Le mot : " << mot2 << " est un palindrome" << std::endl;
    }
    else
    {
        std::cout << "Le mot : " << mot2 << "n'est pas un palindrome" << std::endl;
    }
}
