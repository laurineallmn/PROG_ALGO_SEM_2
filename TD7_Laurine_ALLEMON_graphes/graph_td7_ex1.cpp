#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
#include <cstdlib>
#include <stack>
#include <queue>

#include "graph_td7_ex1.hpp"

void WeightedGraph::add_vertex(int const id_sommet)
{
    if (this->adjacency_list.find(id_sommet) == this->adjacency_list.end())
    {                                                 //si le sommet n'existe pas
        this->adjacency_list.insert({id_sommet, {}}); //s'il n'existe pas dans le tableau associatif on l'ajoute à l'adjency liste qui à deux parametres
    }
}

void WeightedGraph::add_directed_edge(int const from, int const to, float const weight = 1.0f)
{
    //on ajoute les sommets à relier
    this->add_vertex(from);
    this->add_vertex(to);
    this->adjacency_list[from].push_back({to, weight});
}

void WeightedGraph::add_undirected_edge(int const from, int const to, float const weight = 1.0f)
{
    //on ajoute les sommets à relier
    this->add_vertex(from);
    this->add_vertex(to);
    //on les connecte des deux sens
    add_directed_edge(from, to, weight);
    add_directed_edge(to, from, weight);
}
