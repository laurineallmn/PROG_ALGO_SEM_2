#pragma once

struct Node
{
    int value; //racin
    Node *left{nullptr};
    Node *right{nullptr};

    bool const is_leaf()
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

    //A FAIRE
    //IL faut encore que je modifie la valeur de this-> left a chaque tour pour pouvoir ajouter a l'infini
    //Parce que sinon a partir du moment ou notre premeire racin à deux fils, on est bloquée

    void insert(int value) //value différente de la value intialisé plus haut. La value d'ici sera le fils de la value d'en haut
    {
        if (value < this->value) //this-> value = valeur/fils a ajouté
        {
            this->left = create_node(value);
        }
        else
        {
            this->right = create_node(value);
        }
    };
    int height()
    {
        int compteur{1};
        compteur += 1;
        height();
        return compteur;
    };

    //SUR LE SITE
    // int treeHeight(BinTreeNode *n)
    // {
    //     int lh, rh;

    //     if (n == nullptr)
    //         return -1;
    //     else
    //     {
    //         lh = treeHeight(n->left);
    //         rh = treeHeight(n->right);
    //         return 1 + (lh > rh ? lh : rh);
    //     }
    // }

    //EN RECURSIF IF EST L'EQUIVALENT D'UN WHILE PUISQU'IL RAPPELLE LA FONCTION D+TANT QUE LA CONDTION N'EST PAS VERIFIE
    void delete_childs() //c important de delete la donnée qu'on vient de récupéréer pour le heap (si on ajoute une donnée, il faut direct l'effacer une fois qu'on l'a utiolisé pour ne pas ecraser d'autre données)
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

    void display_infixe() const
    {
        value->left;
        if (is_leaf == true)
        {
            return value
        }
    };
};

Node *create_node(int value)
{
    Node *root{new Node{value, nullptr, nullptr}};
}
