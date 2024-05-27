#pragma once
#include <vector>

struct Node
{
    int value; //racin
    Node *left{nullptr};
    Node *right{nullptr};

    bool is_leaf() const;
    void insert(int value);
    int height() const;
    void delete_childs();

    void display_infixe() const;
    void display_prefixe() const;
    void display_postfixe() const;
    std::vector<Node const *> prefixe() const;
    std::vector<Node const *> postfixe() const;

    Node *&most_left(Node *&node);
};

Node *create_node(int value);
