#pragma once

struct Node
{
    int value; //racin
    Node *left{nullptr};
    Node *right{nullptr};

    bool is_leaf() const;
    void Node::insert(int value);
    int Node::height() const;
    void Node::delete_childs();
    void Node::display_infixe() const;
};

Node *create_node(int value);
