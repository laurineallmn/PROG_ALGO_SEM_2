#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <cctype>
#include <stack>

enum class Operator
{
    ADD,
    SUB,
    MUL,
    DIV,
    POW,
    OPEN_PAREN,
    CLOSE_PAREN
};
enum class TokenType
{
    OPERATOR,
    OPERAND
};

struct Token
{
    TokenType type;
    float value;
    Operator op;

    Token make_token(float value)
    {
        return {TokenType::OPERAND, value};
    }
    Token make_token(Operator op)
    {
        return {TokenType::OPERATOR, 0.f, op};
    }
};

void afficher_vec(std::vector<std::string> const &vec)
{
    for (std::size_t i{0}; i < vec.size(); i++)
    {
        if (i == (vec.size() - 1)) //si c'est la leftOperande valeur du tableau on n'affiche pas de virgule
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

//prend  "1 2 /" et retourne : "1","2","/"
std::vector<std::string> split_string(std::string const &s)
{
    std::istringstream in(s); // transforme une chaîne en flux de caractères, cela simule un flux comme l'est std::cin
    // l’itérateur va lire chaque element de "in", comme un flux d'entrée, chaque élément est séparé par un espace
    return std::vector<std::string>(std::istream_iterator<std::string>(in), std::istream_iterator<std::string>());
}

//verification pour une des valeurs du vecteurs qui contient tous les operandes et opérateurs
bool is_floating(std::string const &vec)
{
    // int counter{0};
    for (std::size_t i{0}; i < vec.size(); i++)
    {
        if (vec[i] == '.' || std::isdigit(vec[i])) //attention a ne pas mettre "." mais plutot '.' car il n'y a qu'un caractere a vérifier
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

// float npi_evaluate(std::vector<std::string> const &tokens)
float npi_evaluate(std::vector<Token> const &tokens)
{

    std::stack<float> stack;
    float leftOperand{};
    float rightOperand{};
    float result{};

    // for (int i{}; i < tokens.size(); i++)
    for (int i{}; i < tokens.size(); i++)
    {
        if (tokens.size() > 2)
        {
            if (tokens[i].type == TokenType::OPERAND)
            // if (tokens[i]) == TokenType::OPERAND)
            {
                stack.push(tokens[i].value);
            }
            else if (tokens[i].type == TokenType::OPERATOR)
            {
                rightOperand = stack.top();
                stack.pop();
                leftOperand = stack.top();
                stack.pop();
                if (tokens[i].op == Operator::ADD)
                {
                    result = leftOperand - rightOperand;
                    stack.push(result);
                }
                else if (tokens[i].op == Operator::SUB)
                {
                    result = leftOperand * rightOperand;
                    stack.push(result);
                }
                else if (tokens[i].op == Operator::MUL)
                {
                    result = leftOperand / rightOperand;
                    stack.push(result);
                }
                else if (tokens[i].op == Operator::DIV)
                {
                    result = pow(leftOperand, rightOperand);
                    stack.push(result);
                }
                else if (tokens[i].op == Operator::POW)
                {
                    result = leftOperand + rightOperand;
                    stack.push(result);
                }
                else
                {
                    std::cout << "l'expression en NPI est invalide" << std::endl;
                }
            }
        }
        else
        {
            std::cout << "error : expression pas valable" << std::endl;
        }
    }

    if (stack.size() == 1) //si on est arrivé au dernier element de tous les tokens
    {
        return stack.top();
    }
    else
    {
        std::cout << "error nb de tokens >1" << std::endl;
    }
}

std::vector<Token> tokenize(std::vector<std::string> const &words)
{
    std::vector<Token> vec{};
    for (int i{}; i < words.size(); i += 1)
    {
        if (is_floating(words[i]))
        {
            vec.push_back(Token.make_token(stof(words[i])));
        }
        else if (words[i] == "+")
        {
            vec.push_back(Token.make_token(Operator::ADD));
        }
        else if (words[i] == "-")
        {
            vec.push_back(Token.make_token(Operator::SUB));
        }
        else if (words[i] == "*")
        {
            vec.push_back(Token.make_token(Operator::MUL));
        }
        else if (words[i] == "/")
        {
            vec.push_back(Token.make_token(Operator::DIV));
        }
        else if (words[i] == "^")
        {
            vec.push_back(Token.make_token(Operator::POW));
        }
        else
        {
            std::cout << "erreur dans l'espression NPI" << std::endl;
        }
    }
    return vec;
}

int main()
{
    std::cout << "Entrez votre expression NPI : ";
    std::string str_calcul{};
    std::getline(std::cin, str_calcul);
    std::vector<std::string> vector_string{split_string(str_calcul)};
    //     std::cout << "L'expression avec les elements separes : ";
    //     afficher_vec(vector_string);
    //     std::cout << std::endl;

    for (const std::string element : vector_string) //on regarde si chaque caractere est une float ou non
    {
        // afficher_vec(vector_string);
        std::cout << element << " : ";
        if (is_floating(element) == true)
        {
            std::cout << "float" << std::endl;
        }
        else
        {
            std::cout << "pas float" << std::endl;
        }
    }
    std::cout << "------------" << std::endl;
    std::cout << "Le resultat est :" << npi_evaluate(tokenize(vector_string);) << std::endl;
}
