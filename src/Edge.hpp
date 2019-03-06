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
    // two pointers to nodes that edge is connecting
    Node* n1;
    Node* n2;
    
    // weight of edge (default = 1)
    int weight;
    
    Edge() : n1(NULL), n2(NULL), weight(1) {}
    Edge(Node* node1, Node* node2) : n1(node1), n2(node2), weight(1) {}
};

#endif  // EDGE_HPP
