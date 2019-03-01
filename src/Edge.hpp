#ifndef EDGE_HPP
#define EDGE_HPP

#include <iostream>

using namespace std;

class Edge {
 protected:
    Node* n1; // two Nodes that Edge is connecting
    Node* n2;
    int weight; // weight of edge (default = 1)
 public:
    Edge(Node node1, Node node2) : n1(node1), n2(node2), weight(1) {}
};

#endif  // EDGE_HPP
