#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>
#include "Node.hpp"
#include "Edge.hpp"

using namespace std;

class Graph {
public:
    //MAYBE ADD CLASS DATA STRUCTURE(S) HERE
    vector<Node> nodes;
    vector<Edge> edges;
    
    Graph(void);
    
    ~Graph(void);
    
    //MAYBE ADD SOME MORE METHODS HERE SO AS TO ANSWER QUESTIONS IN YOUR PA
    
    /* YOU CAN MODIFY THIS IF YOU LIKE , in_filename : THE INPUT FILENAME */
    
    bool loadFromFile(const char* in_filename);
    
    bool pathfinder(Node* from, Node* to);
    
    void socialgathering(vector<string>& invitees, const int& k);
    
    void addNodeAndEdge(string from, string to);
};

#endif  // GRAPH_HPP
