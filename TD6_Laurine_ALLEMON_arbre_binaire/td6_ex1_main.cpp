#include <iostream>
#include <vector>
#include "td6_ex1_node.hpp"

void pretty_print_left_right(Node const &node, std::string const &prefix, bool is_left)
{
    if (node.right)
    {
        pretty_print_left_right(*node.right, prefix + (is_left ? "|   " : "    "), false);
    }
    std::cout << prefix << (is_left ? "+-- " : "+-- ") << node.value << std::endl;
    if (node.left)
    {
        pretty_print_left_right(*node.left, prefix + (is_left ? "    " : "|   "), true);
    }
}

void pretty_print_left_right(Node const &node)
{
    pretty_print_left_right(node, "", true);
}

int main()
{

    Node *root = create_node(10);
    root->insert(7);
    root->insert(12);
    root->insert(6);
    root->insert(9);
    root->insert(11);
    root->insert(15);
    root->insert(6);

    std::cout << "Chemin infixe : ";
    root->display_infixe();
    std::cout << std::endl;

    std::cout << "Chemin prefixe :" << std::endl;
    std::vector<Node const *> prefix_nodes = root->prefixe();
    for (const Node *node : prefix_nodes)
    {
        std::cout << node->value << ", ";
    }
    std::cout << std::endl;

    std::cout << "Chemin postfixe:" << std::endl;
    std::vector<Node const *> postfix_nodes = root->postfixe();
    for (const Node *node : postfix_nodes)
    {
        std::cout << node->value << ", ";
    }
    std::cout << std::endl;

    //pour ne pas écraser de donnée
    root->delete_childs();
    delete root;

    return 0;
}