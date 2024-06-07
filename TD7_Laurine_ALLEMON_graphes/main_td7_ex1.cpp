#include <vector>
#include <unordered_map>
#include <utility>
#include <iostream>
#include "graph_td7_ex1.hpp"

/////////////////////////////////////////////////////////////////:

// using namespace Graph;

// void WeightedGraph::add_vertex(int const sommet)
// {
//     if ((adjacency_list.find(sommet)) == adjacency_list.end())
//     {
//         adjacency_list[sommet] = {};
//     }
// }
// void afficher_vec(std::vector<int> const &vec);

// void add_directed_edge(int const from, int const to, float const weight = 1.0f)
// {
// }
// void add_undirected_edge(int const from, int const to, float const weight = 1.0f)
// {
// }

int main()
{
    std::vector<std::vector<float>> matrice{{0.f, 2.f, 0.f, 0.f},
                                            {0.f, 3.f, 0.f, 1.2f},
                                            {0.5f, 0.f, 1.5f, 0.f},
                                            {0.f, 0.0f, 0.f, 2.2f}};

    // création d'un graphe en utilisant nos fonctions
    WeightedGraph graph{};
    graph.add_vertex(0);
    graph.add_vertex(1);
    graph.add_vertex(2);
    graph.add_vertex(3);
    graph.add_directed_edge(0, 1, 2.f);
    graph.add_directed_edge(1, 1, 3.f);
    graph.add_directed_edge(1, 3, 1.2f);
    graph.add_directed_edge(2, 0, 0.5f);
    graph.add_undirected_edge(2, 2, 1.5f);
    graph.add_undirected_edge(3, 3, 2.2f);

    return 0;
}
