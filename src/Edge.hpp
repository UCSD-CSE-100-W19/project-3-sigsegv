//
// Sunny Lau     cs100wav
// Lacey Umamoto lumamoto
// 2/26/19 
//
// Edge.hpp
// CSE 100 Project 3

#ifndef EDGE_HPP
#define EDGE_HPP

#include <iostream>

using namespace std;

class Edge {
 public:
    Node* n1; // two Nodes that Edge is connecting
    Node* n2;
    int weight; // weight of edge (default = 1)

    // Edge constructors
    Edge() : n1(NULL), n2(NULL), weight(1) {}
    Edge(Node* node1, Node* node2) : n1(node1), n2(node2), weight(1) {}
};

#endif  // EDGE_HPP
