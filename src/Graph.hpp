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

using namespace std;

class Graph {
public:
    // vector containing pointers to all nodes in graph
    vector<Node*> nodes;
    
    // hash map that maps a node's id to a pointer to its node
    unordered_map<string,Node*> nodeMap;
    
    Graph();
    
    ~Graph();
    
    bool loadFromFile(const char* in_filename);
    
    string pathfinder(Node* from, Node* to);
    
    vector<Node*> socialgathering(const int k);
    
    void addNodes(string from, string to);
    
    bool containsNode(string id);
    
    Node* getNode(string id);
    
    static bool compareDegrees(Node* n1, Node* n2);
    static bool compareIds(Node* n1, Node* n2);
};

#endif  // GRAPH_HPP
