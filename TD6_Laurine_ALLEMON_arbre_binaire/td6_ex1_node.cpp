#include "td6_ex1_node.hpp"
#include <algorithm>
#include <iostream>
#include <vector>

bool Node::is_leaf() const
{
    if (left == nullptr && right == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//A FAIRE => FAIT
//IL faut encore que je modifie la valeur de this-> left a chaque tour pour pouvoir ajouter a l'infini
//Parce que sinon a partir du moment ou notre premeire racin à deux fils, on est bloquée et on efface les racines pour leur remettre a chasue fois une nouvelle valeur

void Node::insert(int new_value) //value différente de la value intialisé plus haut. La value d'ici sera le fils de la valeur d'en haut
{
    if (new_value < this->value) //on accede a la partie gauche de l'arbre
    {
        if (this->left != nullptr) //on verifie que l'enfant du noeud n'est pas deja un noeud lui même
        {
            this->left->insert(new_value);
        }
        else
        {
            this->left = create_node(new_value); //si l'enfant du noeud de depart n'est pas rempli alors on peut ajouter notre valeur a cet emplacement
        }
    }
    else //on accede a la partie droite de l'arbre
    {
        if (this->right != nullptr)
        {
            this->right->insert(new_value);
        }
        else
        {
            this->right = create_node(new_value);
        }
    }
};
int Node::height() const
{
    if (left == nullptr && right == nullptr)
    {
        return 0; // Un nœud feuille a une hauteur de 0
    }
    else
    {
        int left_height = 0;
        int right_height = 0;
        if (left != nullptr)
        {
            left_height = left->height(); //on appelle la focntion height sur le sous-arbre gauche du noeud actuel
        }
        if (right != nullptr)
        {
            right_height = right->height(); //on appelle la focntion height sur le sous-arbre droite< du noeud actuel
        }
        //si le noeud n'a pas d'enfants on renvoie 1
        if (right == nullptr && left == nullptr)
        {
            return 1;
        }
        // Retourne la hauteur maximale des sous-arbres gauche et droit plus un pour la racine
        return 1 + std::max(left_height, right_height);
    }
};

//EN RECURSIF IF EST L'EQUIVALENT D'UN WHILE PUISQU'IL RAPPELLE LA FONCTION D+TANT QUE LA CONDTION N'EST PAS VERIFIE
void Node::delete_childs() //c important de delete la donnée qu'on vient de récupéréer pour le heap (si on ajoute une donnée, il faut direct l'effacer une fois qu'on l'a utiolisé pour ne pas ecraser d'autre données)
{

    // Bien en soit mais on fait buger cpp en faisant ca
    // if (is_leaf() == false)
    // {
    //     delete_childs();
    // }
    // if (is_leaf() == true)
    // {
    //     delete this;
    //     this = nullptr;
    // }
    if (this->left != nullptr)
    {
        this->left->delete_childs(); //on demande si la racine elle meme peut faire la même chose avec ses fils (est ce qu'elle peut les effacer)
        delete this->left;
        this->left = nullptr;
    }
    if (this->right != nullptr)
    {
        this->right->delete_childs();
        delete this->right;
        this->right = nullptr;
    }
};

void Node::display_infixe() const
{
    if (this->left != nullptr)
    {
        this->left->display_infixe();
    }
    std::cout << value << std::endl;
    if (this->right != nullptr)
    {
        this->right->display_infixe();
    }
};

std::vector<Node const *> Node::prefixe() const
{
    std::vector<Node const *> nodes;
    nodes.push_back(this);
    if (this->left != nullptr)
    {
        auto left_nodes = left->prefixe();
        nodes.insert(nodes.end(), left_nodes.begin(), left_nodes.end()); // insert permet d’insérer plusieurs éléments à l'aide d’itérateurs
    }
    if (this->right != nullptr)
    {
        auto right_nodes = right->prefixe();
        nodes.insert(nodes.end(), right_nodes.begin(), right_nodes.end()); // insert permet d’insérer plusieurs éléments à l'aide d’itérateurs
    }
    return nodes;
};

std::vector<Node const *> Node::postfixe() const
{
    std::vector<Node const *> nodes;
    if (this->left != nullptr)
    {
        auto left_nodes = this->left->postfixe();
        nodes.insert(nodes.end(), left_nodes.begin(), left_nodes.end()); // insert permet d’insérer plusieurs éléments à l'aide d’itérateurs
    }
    if (this->right != nullptr)
    {
        auto right_nodes = this->right->postfixe();
        nodes.insert(nodes.end(), right_nodes.begin(), right_nodes.end()); // insert permet d’insérer plusieurs éléments à l'aide d’itérateurs
    }
    nodes.push_back(this);
    return nodes;
};

Node *&Node::most_left(Node *&node)
{
    if (!(node == nullptr || node->left == nullptr)) //si aucun noeud n'est feuille
    {
        return most_left(node->left); //on cherche dans le noeud de gauche suivant
    }
    return node;
};

bool remove(Node *&node, int value)
{
    if (value == node->value && node->is_leaf())
    {
        // On supprime le nœud courant
        delete node;
        // Comme on a une référence sur le pointeur du nœud courant, on le met à jour avec nullptr
        // Ainsi le parent du nœud courant aura un pointeur vers nullptr
        node = nullptr;
        // on retourne true car la suppression a été effectuée
        return true;
    }
    //si le noeud à un fils à droite
    else if (value == node->value && node->right != nullptr && node->left == nullptr)
    {
        Node *right{node->right};
        delete node;
        node = right;
        return true;
    }
    //si le noeud à un fils à gauche
    else if (value == node->value && node->right == nullptr && node->left != nullptr)
    {
        Node *left{node->left};
        delete node;
        node = left;
        return true;
    }
    //si le noeud à 2 fils un a droite et un a gauche
    else if (value == node->value && node->right != nullptr && node->left != nullptr)
    {
        node->value = most_left(node)->value;
        remove(most_left(node), most_left(node)->value);
        delete most_left(node->left);
        return true;
    }
    return false;
}

int min(Node *node)
{
    if (node == nullptr)
    {
        return -1; // si le noeud de depart est nul
    }
    return most_left(node)->value;
}

int max(Node *node)
{
    if (node == nullptr)
    {
        return -1; // si le noeud de depart est nul
    }
    if (node->right != nullptr)
    {
        return max(node->right);
    }
    return node->value;
}

int somme(Node const *root)
{
    std::vector<Node const *> nodes{root->prefixe()};
    int somme{0};

    if (root == nullptr)
    {
        return 0;
    }

    for (const Node *node : nodes)
    {
        somme += node->value;
    }
    return somme;
}

Node *create_node(int value)
{
    Node *root{new Node{value, nullptr, nullptr}};
    return root;
}

void delete_tree(Node *node)
{
    node->delete_childs();
    delete node;    //pour ne pas ecraser de memoire
    node = nullptr; //on met le noeud à 0
}
