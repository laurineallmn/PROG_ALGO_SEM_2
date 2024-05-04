#include "td6_ex1_node.hpp"

Node *create_node(int value);
bool is_leaf() const;
void Node::insert(int value);
int Node::height() const;
void Node::delete_childs();
void Node::display_infixe() const;
