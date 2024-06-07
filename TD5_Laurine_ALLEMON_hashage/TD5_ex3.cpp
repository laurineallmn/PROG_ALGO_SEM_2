#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <cstdlib>

////////////////////////////////////////////////:
/////////////////  EX 3  //////////////////////:
////////////////////////////////////////////////:

enum class CardKind
{
    Heart,
    Diamond,
    Club,
    Spade,
};

enum class CardValue
{
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    Ace,
};

struct Card
{
    CardKind kind;
    CardValue value;
    // QUESTION 3 et QUESTION 2
    int hash() const
    {
        return static_cast<int>(kind) * 13 + static_cast<int>(value);
    }
    //////
};

//QUESITON 1
bool operator==(Card const &carte1, Card const &carte2)
{
    return carte1.kind == carte2.kind && carte1.value == carte2.value; //si couleur ou valeur de 2 cartes sont égale
}
//QUESTION 3
namespace std
{
    template <>
    struct hash<Card>
    {
        size_t operator()(Card const &card) const
        {
            return card.hash();
        }
    };
}
// QUESTION 4
#include <vector>
std::vector<Card> get_cards(size_t const size)
{
    std::vector<Card> cards{};
    cards.reserve(size);
    for (size_t i{0}; i < size; ++i)
    {
        cards.push_back({static_cast<CardKind>(rand() % 4), static_cast<CardValue>(rand() % 13)});
    }
    return cards;
}

std::string card_name(Card const &card)
{
    std::string name{};

    unsigned int card_value{(static_cast<unsigned int>(card.value) + 2) % 14};

    if (card_value < 10)
    {
        name += '0' + card_value;
    }
    else if (card_value == 10)
    {
        name += "10";
    }
    else if (card_value == 11)
    {
        name += 'V';
    }
    else if (card_value == 12)
    {
        name += 'Q';
    }
    else if (card_value == 13)
    {
        name += 'K';
    }

    name += " of ";

    if (card.kind == CardKind::Heart)
    {
        name += "Heart";
    }
    else if (card.kind == CardKind::Diamond)
    {
        name += "Diamond";
    }
    else if (card.kind == CardKind::Club)
    {
        name += "Club";
    }
    else if (card.kind == CardKind::Spade)
    {
        name += "Spade";
    }
    return name;
}

std::unordered_map<Card, int> nombre_apparence(std::vector<Card> card_list)
{
    std::unordered_map<Card, int> counter_map{};
    for (int i{0}; i < card_list.size(); i++)
    {
        if (counter_map.find(card_list[i]) == counter_map.end())
        {
            counter_map.insert(std::make_pair(card_list[i], 1));
        }
        else
        {
            counter_map[card_list[i]]++;
        }
    }
    return counter_map;
}

int main()
{
    std::vector<Card> card_list{get_cards(100)};

    std::unordered_map<Card, int> nb_cartes{nombre_apparence(card_list)};

    for (auto &carte : nb_cartes)
    {
        std::cout << "La carte : " << card_name(carte.first) << " apparait :" << carte.second << " fois" << std::endl;
    }

    return 0;
}