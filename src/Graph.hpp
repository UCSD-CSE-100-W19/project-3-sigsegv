//
// Sunny Lau     cs100wav
// Lacey Umamoto lumamoto
// 2/26/19 
//
// Graph.hpp
// CSE 100 Project 3

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>
#include <unordered_map>
#include "Node.hpp"
#include "Edge.hpp"

using namespace std;

class Graph {
public:
    // vector containing pointers to all nodes in graph
    vector<Node*> nodes;
    
    // vector containing pointers to all edges in graph
    vector<Edge*> edges;
    
    // hash map that maps a node's id to a pointer to its node
    unordered_map<string,Node*> nodeMap;
    
    Graph();
    
    ~Graph();
    
    bool loadFromFile(const char* in_filename);
    
    string pathfinder(Node* from, Node* to);
    
    void socialgathering(vector<string>& invitees, const int& k);
    
    void addNodesAndEdge(string from, string to);
    
    bool containsNode(string id);
    
    Node* getNode(string id);
};

#endif  // GRAPH_HPP
