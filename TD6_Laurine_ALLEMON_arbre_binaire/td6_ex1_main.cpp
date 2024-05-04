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
    Node *root{new Node{10, nullptr, nullptr}};
    root->left = {new Node{7, nullptr, nullptr}};
    root->right = {new Node{12, nullptr, nullptr}};
    root->left->left = {new Node{6, nullptr, nullptr}};
    root->left->right = {new Node{9, nullptr, nullptr}};
    root->right->left = {new Node{11, nullptr, nullptr}};
    root->right->right = {new Node{15, nullptr, nullptr}};
    // root->left->left = {new Node{6, nullptr, nullptr}};
}