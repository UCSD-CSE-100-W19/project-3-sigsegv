//
// Sunny Lau     cs100wav
// Lacey Umamoto lumamoto
// 2/26/19
//
// node.hpp
// CSE 100 Project 3

#ifndef EDGE_HPP
#define EDGE_HPP

#include <iostream>
#include <limits>
#include <vector>
#include <queue>

using namespace std;

struct Edge {
public:
     Node* from;
     Node* to;
     int weight;

     Edge(Node* id1, Node* id2, int edgeWeight){
         from = id1;
         to = id2;
         weight = edgeWeight;
     }
};

#endif
