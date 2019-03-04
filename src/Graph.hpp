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
    //MAYBE ADD CLASS DATA STRUCTURE(S) HERE
    vector<Node*> nodes;
    vector<Edge*> edges;
    unordered_map<string,Node*> nodeMap;
    
    //const int INFINITY = numeric_limits<int>::max();
    
    Graph();
    
    ~Graph();
    
    //MAYBE ADD SOME MORE METHODS HERE SO AS TO ANSWER QUESTIONS IN YOUR PA
    
    /* YOU CAN MODIFY THIS IF YOU LIKE , in_filename : THE INPUT FILENAME */
    
    bool loadFromFile(const char* in_filename);
    
    string pathfinder(Node* from, Node* to);
    
    void socialgathering(vector<string>& invitees, const int& k);
    
    void addNodesAndEdge(string from, string to);
    
    bool containsNode(string id);
    
    Node* getNode(string id);
};

#endif  // GRAPH_HPP
